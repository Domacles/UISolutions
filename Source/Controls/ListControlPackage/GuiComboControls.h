/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Control System

Interfaces:
***********************************************************************/

#ifndef VCZH_PRESENTATION_CONTROLS_GUICOMBOCONTROLS
#define VCZH_PRESENTATION_CONTROLS_GUICOMBOCONTROLS

#include "../GuiWindowControls.h"
#include "GuiTextListControls.h"
#include "GuiListViewControls.h"
#include "GuiTreeViewControls.h"

namespace vl
{
	namespace presentation
	{
		namespace controls
		{

/***********************************************************************
ComboBox Base
***********************************************************************/

			/// <summary>The base class of combo box control.</summary>
			class GuiComboBoxBase : public GuiMenuButton, public Description<GuiComboBoxBase>
			{
				GUI_SPECIFY_CONTROL_TEMPLATE_TYPE(ComboBoxTemplate, GuiMenuButton)
			protected:

				class CommandExecutor : public Object, public virtual IComboBoxCommandExecutor
				{
				protected:
					GuiComboBoxBase*						combo;

				public:
					CommandExecutor(GuiComboBoxBase* _combo);
					~CommandExecutor();

					void									SelectItem()override;
				};

				Ptr<CommandExecutor>						commandExecutor;
				
				bool										IsAltAvailable()override;
				IGuiMenuService::Direction					GetSubMenuDirection()override;
				virtual void								SelectItem();
				void										OnBoundsChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
			public:
				/// <summary>Create a control with a specified style controller.</summary>
				/// <param name="themeName">The theme name for retriving a default control template.</param>
				GuiComboBoxBase(theme::ThemeName themeName);
				~GuiComboBoxBase();

				/// <summary>Item selected event.</summary>
				compositions::GuiNotifyEvent				ItemSelected;
			};

/***********************************************************************
ComboBox with GuiListControl
***********************************************************************/

			/// <summary>Combo box list control. This control is a combo box with a list control in its popup.</summary>
			class GuiComboBoxListControl : public GuiComboBoxBase, public Description<GuiComboBoxListControl>
			{
			public:
				using ItemStyleProperty = TemplateProperty<templates::GuiTemplate>;

			protected:
				GuiSelectableListControl*					containedListControl = nullptr;
				ItemStyleProperty							itemStyleProperty;
				templates::GuiTemplate*						itemStyleController = nullptr;
				Ptr<compositions::IGuiGraphicsEventHandler>	boundsChangedHandler;

				void										BeforeControlTemplateUninstalled()override;
				void										AfterControlTemplateInstalled(bool initialize)override;
				bool										IsAltAvailable()override;
				void										OnActiveAlt()override;
				void										RemoveStyleController();
				void										InstallStyleController(vint itemIndex);
				virtual void								DisplaySelectedContent(vint itemIndex);
				void										AdoptSubMenuSize();
				void										OnTextChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void										OnFontChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void										OnVisuallyEnabledChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void										OnListControlAdoptedSizeInvalidated(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void										OnListControlBoundsChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void										OnListControlSelectionChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
			public:
				/// <summary>Create a control with a specified style controller and a list control that will be put in the popup control to show all items.</summary>
				/// <param name="themeName">The theme name for retriving a default control template.</param>
				/// <param name="_containedListControl">The list controller.</param>
				GuiComboBoxListControl(theme::ThemeName themeName, GuiSelectableListControl* _containedListControl);
				~GuiComboBoxListControl();
				
				/// <summary>Style provider changed event.</summary>
				compositions::GuiNotifyEvent				ItemTemplateChanged;
				/// <summary>Selected index changed event.</summary>
				compositions::GuiNotifyEvent				SelectedIndexChanged;
				
				/// <summary>Get the list control.</summary>
				/// <returns>The list control.</returns>
				GuiSelectableListControl*					GetContainedListControl();

				/// <summary>Get the item style provider.</summary>
				/// <returns>The item style provider.</returns>
				virtual ItemStyleProperty					GetItemTemplate();
				/// <summary>Set the item style provider</summary>
				/// <param name="value">The new item style provider</param>
				virtual void								SetItemTemplate(ItemStyleProperty value);
				
				/// <summary>Get the selected index.</summary>
				/// <returns>The selected index.</returns>
				vint										GetSelectedIndex();
				/// <summary>Set the selected index.</summary>
				/// <param name="value">The selected index.</param>
				void										SetSelectedIndex(vint value);

				/// <summary>Get the selected item.</summary>
				/// <returns>The selected item.</returns>
				description::Value							GetSelectedItem();
				/// <summary>Get the item provider in the list control.</summary>
				/// <returns>The item provider in the list control.</returns>
				GuiListControl::IItemProvider*				GetItemProvider();
			};
		}
	}
}

#endif