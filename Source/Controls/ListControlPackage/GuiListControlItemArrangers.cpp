#include "GuiListControlItemArrangers.h"
#include "../Templates/GuiControlTemplates.h"
#include "../Templates/GuiThemeStyleFactory.h"

namespace vl
{
	namespace presentation
	{
		namespace controls
		{
			using namespace collections;
			using namespace elements;
			using namespace compositions;

			namespace list
			{

/***********************************************************************
RangedItemArrangerBase
***********************************************************************/

				void RangedItemArrangerBase::InvalidateAdoptedSize()
				{
					if (listControl)
					{
						listControl->AdoptedSizeInvalidated.Execute(listControl->GetNotifyEventArguments());
					}
				}

				vint RangedItemArrangerBase::CalculateAdoptedSize(vint expectedSize, vint count, vint itemSize)
				{
					vint visibleCount = expectedSize / itemSize;
					if (count < visibleCount)
					{
						visibleCount = count;
					}
					else if (count > visibleCount)
					{
						vint deltaA = expectedSize - count * itemSize;
						vint deltaB = itemSize - deltaA;
						if (deltaB < deltaA)
						{
							visibleCount++;
						}
					}
					return visibleCount * itemSize;
				}

				RangedItemArrangerBase::ItemStyleRecord RangedItemArrangerBase::CreateStyle(vint index)
				{
					GuiSelectableButton* backgroundButton = nullptr;
					if (listControl->GetDisplayItemBackground())
					{
						backgroundButton = new GuiSelectableButton(theme::ThemeName::ListItemBackground);
						if (auto style = listControl->GetControlTemplateObject()->GetBackgroundTemplate())
						{
							backgroundButton->SetControlTemplate(style);
						}
						backgroundButton->SetAutoSelection(false);
					}

					auto itemStyle = callback->RequestItem(index, backgroundButton->GetBoundsComposition());
					if (backgroundButton)
					{
						itemStyle->SetAlignmentToParent(Margin(0, 0, 0, 0));
						itemStyle->SelectedChanged.AttachLambda([=](GuiGraphicsComposition* sender, GuiEventArgs& arguments)
						{
							backgroundButton->SetSelected(itemStyle->GetSelected());
						});
						backgroundButton->GetContainerComposition()->AddChild(itemStyle);
					}
					return { itemStyle, backgroundButton };
				}

				void RangedItemArrangerBase::DeleteStyle(ItemStyleRecord style)
				{
					callback->ReleaseItem(style.key);
					if (style.value)
					{
						SafeDeleteControl(style.value);
					}
				}

				compositions::GuiBoundsComposition* RangedItemArrangerBase::GetStyleBounds(ItemStyleRecord style)
				{
					return style.value ? style.value->GetBoundsComposition() : style.key;
				}

				void RangedItemArrangerBase::ClearStyles()
				{
					startIndex = 0;
					if (callback)
					{
						for (vint i = 0; i < visibleStyles.Count(); i++)
						{
							DeleteStyle(visibleStyles[i]);
						}
					}
					visibleStyles.Clear();
					viewBounds = Rect(0, 0, 0, 0);
					InvalidateItemSizeCache();
					InvalidateAdoptedSize();
				}

				void RangedItemArrangerBase::OnViewChangedInternal(Rect oldBounds, Rect newBounds)
				{
					vint endIndex = startIndex + visibleStyles.Count() - 1;
					vint newStartIndex = 0;
					vint itemCount = itemProvider->Count();
					BeginPlaceItem(true, newBounds, newStartIndex);
					if (newStartIndex < 0) newStartIndex = 0;

					StyleList newVisibleStyles;
					for (vint i = newStartIndex; i < itemCount; i++)
					{
						auto style
							= startIndex <= i && i <= endIndex
							? visibleStyles[i - startIndex]
							: CreateStyle(i)
							;
						newVisibleStyles.Add(style);

						Rect bounds;
						Margin alignmentToParent;
						PlaceItem(true, i, style, newBounds, bounds, alignmentToParent);
						if (IsItemOutOfViewBounds(i, style, bounds, newBounds))
						{
							break;
						}

						bounds.x1 -= newBounds.x1;
						bounds.x2 -= newBounds.x1;
						bounds.y1 -= newBounds.y1;
						bounds.y2 -= newBounds.y1;
					}

					vint newEndIndex = newStartIndex + newVisibleStyles.Count() - 1;
					for (vint i = 0; i < visibleStyles.Count(); i++)
					{
						vint index = startIndex + i;
						if (index < newStartIndex || index > newEndIndex)
						{
							DeleteStyle(visibleStyles[i]);
						}
					}
					CopyFrom(visibleStyles, newVisibleStyles);

					if (EndPlaceItem(true, newBounds, newStartIndex))
					{
						callback->OnTotalSizeChanged();
						InvalidateAdoptedSize();
					}
					startIndex = newStartIndex;
				}

				void RangedItemArrangerBase::RearrangeItemBounds()
				{
					vint newStartIndex = startIndex;
					BeginPlaceItem(false, viewBounds, newStartIndex);
					for (vint i = 0; i < visibleStyles.Count(); i++)
					{
						auto style = visibleStyles[i];
						Rect bounds;
						Margin alignmentToParent(-1, -1, -1, -1);
						PlaceItem(false, startIndex + i, style, viewBounds, bounds, alignmentToParent);

						bounds.x1 -= viewBounds.x1;
						bounds.x2 -= viewBounds.x1;
						bounds.y1 -= viewBounds.y1;
						bounds.y2 -= viewBounds.y1;

						callback->SetStyleAlignmentToParent(GetStyleBounds(style), alignmentToParent);
						callback->SetStyleBounds(GetStyleBounds(style), bounds);
					}
					EndPlaceItem(false, viewBounds, startIndex);
				}

				RangedItemArrangerBase::RangedItemArrangerBase()
				{
				}

				RangedItemArrangerBase::~RangedItemArrangerBase()
				{
				}

				void RangedItemArrangerBase::OnAttached(GuiListControl::IItemProvider* provider)
				{
					itemProvider = provider;
					if (provider)
					{
						OnItemModified(0, 0, provider->Count());
					}
				}

				void RangedItemArrangerBase::OnItemModified(vint start, vint count, vint newCount)
				{
					if (callback && !itemProvider->IsEditing())
					{
						suppressOnViewChanged = true;
						{
							vint visibleCount = visibleStyles.Count();
							vint itemCount = itemProvider->Count();
							SortedList<ItemStyleRecord> reusedStyles;
							for (vint i = 0; i < visibleCount; i++)
							{
								vint index = startIndex + i;
								if (index >= itemCount)
								{
									break;
								}

								vint oldIndex = -1;
								if (index < start)
								{
									oldIndex = index;
								}
								else if (index >= start + newCount)
								{
									oldIndex = index - newCount + count;
								}

								if (oldIndex != -1)
								{
									if (oldIndex >= startIndex && oldIndex < startIndex + visibleCount)
									{
										auto style = visibleStyles[oldIndex - startIndex];
										reusedStyles.Add(style);
										visibleStyles.Add(style);
									}
									else
									{
										oldIndex = -1;
									}
								}
								if (oldIndex == -1)
								{
									visibleStyles.Add(CreateStyle(index));
								}
							}

							for (vint i = 0; i < visibleCount; i++)
							{
								auto style = visibleStyles[i];
								if (!reusedStyles.Contains(style))
								{
									DeleteStyle(style);
								}
							}

							visibleStyles.RemoveRange(0, visibleCount);
							for (vint i = 0; i < visibleStyles.Count(); i++)
							{
								visibleStyles[i].key->SetIndex(startIndex + i);
							}
						}
						suppressOnViewChanged = false;

						callback->OnTotalSizeChanged();
						callback->SetViewLocation(viewBounds.LeftTop());
						InvalidateAdoptedSize();
					}
				}

				void RangedItemArrangerBase::AttachListControl(GuiListControl* value)
				{
					listControl = value;
					InvalidateAdoptedSize();
				}

				void RangedItemArrangerBase::DetachListControl()
				{
					listControl = 0;
				}

				GuiListControl::IItemArrangerCallback* RangedItemArrangerBase::GetCallback()
				{
					return callback;
				}

				void RangedItemArrangerBase::SetCallback(GuiListControl::IItemArrangerCallback* value)
				{
					if (callback != value)
					{
						ClearStyles();
						callback = value;
					}
				}

				Size RangedItemArrangerBase::GetTotalSize()
				{
					if (callback)
					{
						return OnCalculateTotalSize();
					}
					else
					{
						return Size(0, 0);
					}
				}

				GuiListControl::ItemStyle* RangedItemArrangerBase::GetVisibleStyle(vint itemIndex)
				{
					if (startIndex <= itemIndex && itemIndex < startIndex + visibleStyles.Count())
					{
						return visibleStyles[itemIndex - startIndex].key;
					}
					else
					{
						return 0;
					}
				}

				vint RangedItemArrangerBase::GetVisibleIndex(GuiListControl::ItemStyle* style)
				{
					for (vint i = 0; i < visibleStyles.Count(); i++)
					{
						if (visibleStyles[i].key == style)
						{
							return i + startIndex;
						}
					}
					return -1;
				}

				void RangedItemArrangerBase::ReloadVisibleStyles()
				{
					ClearStyles();
				}

				void RangedItemArrangerBase::OnViewChanged(Rect bounds)
				{
					if (!suppressOnViewChanged)
					{
						suppressOnViewChanged = true;
						Rect oldBounds = viewBounds;
						viewBounds = bounds;
						if (callback)
						{
							OnViewChangedInternal(oldBounds, viewBounds);
							RearrangeItemBounds();
						}
						suppressOnViewChanged = false;
					}
				}

/***********************************************************************
FixedHeightItemArranger
***********************************************************************/

				vint FixedHeightItemArranger::GetWidth()
				{
					return -1;
				}

				vint FixedHeightItemArranger::GetYOffset()
				{
					return 0;
				}

				void FixedHeightItemArranger::BeginPlaceItem(bool forMoving, Rect newBounds, vint& newStartIndex)
				{
					pi_width = GetWidth();
					if (forMoving)
					{
						pim_rowHeight = rowHeight;
						newStartIndex = (newBounds.Top() - GetYOffset()) / rowHeight;
					}
				}

				void FixedHeightItemArranger::PlaceItem(bool forMoving, vint index, ItemStyleRecord style, Rect viewBounds, Rect& bounds, Margin& alignmentToParent)
				{
					vint top = GetYOffset() + index * rowHeight;
					if (pi_width == -1)
					{
						alignmentToParent = Margin(0, -1, 0, -1);
						bounds = Rect(Point(0, top), Size(0, rowHeight));
					}
					else
					{
						alignmentToParent = Margin(-1, -1, -1, -1);
						bounds = Rect(Point(0, top), Size(pi_width, rowHeight));
					}
					if (forMoving)
					{
						vint styleHeight = callback->GetStylePreferredSize(GetStyleBounds(style)).y;
						if (pim_rowHeight < styleHeight)
						{
							pim_rowHeight = styleHeight;
						}
					}
				}

				bool FixedHeightItemArranger::IsItemOutOfViewBounds(vint index, ItemStyleRecord style, Rect bounds, Rect viewBounds)
				{
					return bounds.Top() >= viewBounds.Bottom();
				}

				bool FixedHeightItemArranger::EndPlaceItem(bool forMoving, Rect newBounds, vint newStartIndex)
				{
					if (forMoving)
					{
						if (pim_rowHeight != rowHeight)
						{
							vint offset = (pim_rowHeight - rowHeight) * newStartIndex;
							rowHeight = pim_rowHeight;
							callback->SetViewLocation(Point(0, newBounds.Top() + offset));
							return true;
						}
					}
					return false;
				}

				void FixedHeightItemArranger::InvalidateItemSizeCache()
				{
					rowHeight = 1;
				}

				Size FixedHeightItemArranger::OnCalculateTotalSize()
				{
					vint width = GetWidth();
					if (width < 0) width = 0;
					return Size(width, rowHeight * itemProvider->Count() + GetYOffset());
				}

				FixedHeightItemArranger::FixedHeightItemArranger()
					:rowHeight(1)
				{
				}

				FixedHeightItemArranger::~FixedHeightItemArranger()
				{
				}

				vint FixedHeightItemArranger::FindItem(vint itemIndex, compositions::KeyDirection key)
				{
					vint count = itemProvider->Count();
					if (count == 0) return -1;
					vint groupCount = viewBounds.Height() / rowHeight;
					if (groupCount == 0) groupCount = 1;
					switch (key)
					{
					case KeyDirection::Up:
						itemIndex--;
						break;
					case KeyDirection::Down:
						itemIndex++;
						break;
					case KeyDirection::Home:
						itemIndex = 0;
						break;
					case KeyDirection::End:
						itemIndex = count;
						break;
					case KeyDirection::PageUp:
						itemIndex -= groupCount;
						break;
					case KeyDirection::PageDown:
						itemIndex += groupCount;
						break;
					default:
						return -1;
					}

					if (itemIndex < 0) return 0;
					else if (itemIndex >= count) return count - 1;
					else return itemIndex;
				}

				bool FixedHeightItemArranger::EnsureItemVisible(vint itemIndex)
				{
					if (callback)
					{
						if (itemIndex < 0 || itemIndex >= itemProvider->Count())
						{
							return false;
						}
						while (true)
						{
							vint yOffset = GetYOffset();
							vint top = itemIndex*rowHeight;
							vint bottom = top + rowHeight + yOffset;

							if (viewBounds.Height() < rowHeight)
							{
								if (viewBounds.Top() < bottom && top < viewBounds.Bottom())
								{
									break;
								}
							}

							Point location = viewBounds.LeftTop();
							if (top < viewBounds.Top())
							{
								location.y = top;
							}
							else if (viewBounds.Bottom() < bottom)
							{
								location.y = bottom - viewBounds.Height();
							}
							else
							{
								break;
							}
							callback->SetViewLocation(location);
						}
						return true;
					}
					return false;
				}

				Size FixedHeightItemArranger::GetAdoptedSize(Size expectedSize)
				{
					if (itemProvider)
					{
						vint yOffset = GetYOffset();
						vint y = expectedSize.y - yOffset;
						vint itemCount = itemProvider->Count();
						return Size(expectedSize.x, yOffset + CalculateAdoptedSize(y, itemCount, rowHeight));
					}
					return expectedSize;
				}

/***********************************************************************
FixedSizeMultiColumnItemArranger
***********************************************************************/

				void FixedSizeMultiColumnItemArranger::BeginPlaceItem(bool forMoving, Rect newBounds, vint& newStartIndex)
				{
					if (forMoving)
					{
						pim_itemSize = itemSize;
						vint rows = newBounds.Top() / itemSize.y;
						if (rows < 0) rows = 0;
						vint cols = newBounds.Width() / itemSize.x;
						if (cols < 1) cols = 1;
						newStartIndex = rows * cols;
					}
				}

				void FixedSizeMultiColumnItemArranger::PlaceItem(bool forMoving, vint index, ItemStyleRecord style, Rect viewBounds, Rect& bounds, Margin& alignmentToParent)
				{
					vint rowItems = viewBounds.Width() / itemSize.x;
					if (rowItems < 1) rowItems = 1;

					vint row = index / rowItems;
					vint col = index % rowItems;
					bounds = Rect(Point(col * itemSize.x, row * itemSize.y), itemSize);
					if (forMoving)
					{
						Size styleSize = callback->GetStylePreferredSize(GetStyleBounds(style));
						if (pim_itemSize.x < styleSize.x) pim_itemSize.x = styleSize.x;
						if (pim_itemSize.y < styleSize.y) pim_itemSize.y = styleSize.y;
					}
				}

				bool FixedSizeMultiColumnItemArranger::IsItemOutOfViewBounds(vint index, ItemStyleRecord style, Rect bounds, Rect viewBounds)
				{
					return bounds.Top() >= viewBounds.Bottom();
				}

				bool FixedSizeMultiColumnItemArranger::EndPlaceItem(bool forMoving, Rect newBounds, vint newStartIndex)
				{
					if (forMoving)
					{
						if (pim_itemSize != itemSize)
						{
							itemSize = pim_itemSize;
							return true;
						}
					}
					return false;
				}

				void FixedSizeMultiColumnItemArranger::CalculateRange(Size itemSize, Rect bounds, vint count, vint& start, vint& end)
				{
					vint startRow = bounds.Top() / itemSize.y;
					if (startRow < 0) startRow = 0;
					vint endRow = (bounds.Bottom() - 1) / itemSize.y;
					vint cols = bounds.Width() / itemSize.x;
					if (cols < 1) cols = 1;

					start = startRow*cols;
					end = (endRow + 1)*cols - 1;
					if (end >= count) end = count - 1;
				}

				void FixedSizeMultiColumnItemArranger::InvalidateItemSizeCache()
				{
					itemSize = Size(1, 1);
				}

				Size FixedSizeMultiColumnItemArranger::OnCalculateTotalSize()
				{
					vint rowItems = viewBounds.Width() / itemSize.x;
					if (rowItems < 1) rowItems = 1;
					vint rows = itemProvider->Count() / rowItems;
					if (itemProvider->Count() % rowItems) rows++;

					return Size(itemSize.x * rowItems, itemSize.y*rows);
				}

				FixedSizeMultiColumnItemArranger::FixedSizeMultiColumnItemArranger()
					:itemSize(1, 1)
				{
				}

				FixedSizeMultiColumnItemArranger::~FixedSizeMultiColumnItemArranger()
				{
				}

				vint FixedSizeMultiColumnItemArranger::FindItem(vint itemIndex, compositions::KeyDirection key)
				{
					vint count = itemProvider->Count();
					vint columnCount = viewBounds.Width() / itemSize.x;
					if (columnCount == 0) columnCount = 1;
					vint rowCount = viewBounds.Height() / itemSize.y;
					if (rowCount == 0) rowCount = 1;

					switch (key)
					{
					case KeyDirection::Up:
						itemIndex -= columnCount;
						break;
					case KeyDirection::Down:
						itemIndex += columnCount;
						break;
					case KeyDirection::Left:
						itemIndex--;
						break;
					case KeyDirection::Right:
						itemIndex++;
						break;
					case KeyDirection::Home:
						itemIndex = 0;
						break;
					case KeyDirection::End:
						itemIndex = count;
						break;
					case KeyDirection::PageUp:
						itemIndex -= columnCount*rowCount;
						break;
					case KeyDirection::PageDown:
						itemIndex += columnCount*rowCount;
						break;
					case KeyDirection::PageLeft:
						itemIndex -= itemIndex%columnCount;
						break;
					case KeyDirection::PageRight:
						itemIndex += columnCount - itemIndex%columnCount - 1;
						break;
					default:
						return -1;
					}

					if (itemIndex < 0) return 0;
					else if (itemIndex >= count) return count - 1;
					else return itemIndex;
				}

				bool FixedSizeMultiColumnItemArranger::EnsureItemVisible(vint itemIndex)
				{
					if (callback)
					{
						if (itemIndex < 0 || itemIndex >= itemProvider->Count())
						{
							return false;
						}
						while (true)
						{
							vint rowHeight = itemSize.y;
							vint columnCount = viewBounds.Width() / itemSize.x;
							if (columnCount == 0) columnCount = 1;
							vint rowIndex = itemIndex / columnCount;

							vint top = rowIndex*rowHeight;
							vint bottom = top + rowHeight;

							if (viewBounds.Height() < rowHeight)
							{
								if (viewBounds.Top() < bottom && top < viewBounds.Bottom())
								{
									break;
								}
							}

							Point location = viewBounds.LeftTop();
							if (top < viewBounds.Top())
							{
								location.y = top;
							}
							else if (viewBounds.Bottom() < bottom)
							{
								location.y = bottom - viewBounds.Height();
							}
							else
							{
								break;
							}
							callback->SetViewLocation(location);
						}
						return true;
					}
					return false;
				}

				Size FixedSizeMultiColumnItemArranger::GetAdoptedSize(Size expectedSize)
				{
					if (itemProvider)
					{
						vint count = itemProvider->Count();
						vint columnCount = viewBounds.Width() / itemSize.x;
						vint rowCount = viewBounds.Height() / itemSize.y;
						return Size(
							CalculateAdoptedSize(expectedSize.x, columnCount, itemSize.x),
							CalculateAdoptedSize(expectedSize.y, rowCount, itemSize.y)
						);
					}
					return expectedSize;
				}

/***********************************************************************
FixedHeightMultiColumnItemArranger
***********************************************************************/

				void FixedHeightMultiColumnItemArranger::BeginPlaceItem(bool forMoving, Rect newBounds, vint& newStartIndex)
				{
					pi_currentWidth = 0;
					pi_totalWidth = 0;
					if (forMoving)
					{
						pim_itemHeight = itemHeight;
						vint rows = newBounds.Height() / itemHeight;
						if (rows < 1) rows = 1;
						vint columns = newBounds.Left() / newBounds.Width();
						newStartIndex = rows * columns;
					}
				}

				void FixedHeightMultiColumnItemArranger::PlaceItem(bool forMoving, vint index, ItemStyleRecord style, Rect viewBounds, Rect& bounds, Margin& alignmentToParent)
				{
					vint rows = viewBounds.Height() / itemHeight;
					if (rows < 1) rows = 1;

					vint row = index % rows;
					if (row == 0)
					{
						pi_totalWidth += pi_currentWidth;
						pi_currentWidth = 0;
					}

					Size styleSize = callback->GetStylePreferredSize(GetStyleBounds(style));
					if (pi_currentWidth < styleSize.x) pi_currentWidth = styleSize.x;
					bounds = Rect(Point(pi_totalWidth + viewBounds.Left(), itemHeight * row), Size(0, 0));
					if (forMoving)
					{
						if (pim_itemHeight < styleSize.y) pim_itemHeight = styleSize.y;
					}
				}

				bool FixedHeightMultiColumnItemArranger::IsItemOutOfViewBounds(vint index, ItemStyleRecord style, Rect bounds, Rect viewBounds)
				{
					return bounds.Left() >= viewBounds.Right();
				}

				bool FixedHeightMultiColumnItemArranger::EndPlaceItem(bool forMoving, Rect newBounds, vint newStartIndex)
				{
					if (forMoving)
					{
						if (pim_itemHeight != itemHeight)
						{
							itemHeight = pim_itemHeight;
							return true;
						}
					}
					return false;
				}

				void FixedHeightMultiColumnItemArranger::CalculateRange(vint itemHeight, Rect bounds, vint& rows, vint& startColumn)
				{
					rows = bounds.Height() / itemHeight;
					if (rows < 1) rows = 1;
					startColumn = bounds.Left() / bounds.Width();
				}

				void FixedHeightMultiColumnItemArranger::InvalidateItemSizeCache()
				{
					itemHeight = 1;
				}

				Size FixedHeightMultiColumnItemArranger::OnCalculateTotalSize()
				{
					vint rows = viewBounds.Height() / itemHeight;
					if (rows < 1) rows = 1;
					vint columns = itemProvider->Count() / rows;
					if (itemProvider->Count() % rows) columns += 1;
					return Size(viewBounds.Width() * columns, 0);
				}

				FixedHeightMultiColumnItemArranger::FixedHeightMultiColumnItemArranger()
					:itemHeight(1)
				{
				}

				FixedHeightMultiColumnItemArranger::~FixedHeightMultiColumnItemArranger()
				{
				}

				vint FixedHeightMultiColumnItemArranger::FindItem(vint itemIndex, compositions::KeyDirection key)
				{
					vint count = itemProvider->Count();
					vint groupCount = viewBounds.Height() / itemHeight;
					if (groupCount == 0) groupCount = 1;
					switch (key)
					{
					case KeyDirection::Up:
						itemIndex--;
						break;
					case KeyDirection::Down:
						itemIndex++;
						break;
					case KeyDirection::Left:
						itemIndex -= groupCount;
						break;
					case KeyDirection::Right:
						itemIndex += groupCount;
						break;
					case KeyDirection::Home:
						itemIndex = 0;
						break;
					case KeyDirection::End:
						itemIndex = count;
						break;
					case KeyDirection::PageUp:
						itemIndex -= itemIndex%groupCount;
						break;
					case KeyDirection::PageDown:
						itemIndex += groupCount - itemIndex%groupCount - 1;
						break;
					default:
						return -1;
					}

					if (itemIndex < 0) return 0;
					else if (itemIndex >= count) return count - 1;
					else return itemIndex;
				}

				bool FixedHeightMultiColumnItemArranger::EnsureItemVisible(vint itemIndex)
				{
					if (callback)
					{
						if (itemIndex < 0 || itemIndex >= itemProvider->Count())
						{
							return false;
						}
						while (true)
						{
							vint rowCount = viewBounds.Height() / itemHeight;
							if (rowCount == 0) rowCount = 1;
							vint columnIndex = itemIndex / rowCount;
							vint minIndex = startIndex;
							vint maxIndex = startIndex + visibleStyles.Count() - 1;

							Point location = viewBounds.LeftTop();
							if (minIndex <= itemIndex && itemIndex <= maxIndex)
							{
								Rect bounds = callback->GetStyleBounds(GetStyleBounds(visibleStyles[itemIndex - startIndex]));
								if (0 < bounds.Bottom() && bounds.Top() < viewBounds.Width() && bounds.Width() > viewBounds.Width())
								{
									break;
								}
								else if (bounds.Left() < 0)
								{
									location.x -= viewBounds.Width();
								}
								else if (bounds.Right() > viewBounds.Width())
								{
									location.x += viewBounds.Width();
								}
								else
								{
									break;
								}
							}
							else if (columnIndex < minIndex / rowCount)
							{
								location.x -= viewBounds.Width();
							}
							else if (columnIndex >= maxIndex / rowCount)
							{
								location.x += viewBounds.Width();
							}
							else
							{
								break;
							}
							callback->SetViewLocation(location);
						}
						return true;
					}
					return false;
				}

				Size FixedHeightMultiColumnItemArranger::GetAdoptedSize(Size expectedSize)
				{
					if (itemProvider)
					{
						vint count = itemProvider->Count();
						return Size(expectedSize.x, CalculateAdoptedSize(expectedSize.y, count, itemHeight));
					}
					return expectedSize;
				}
			}
		}
	}
}