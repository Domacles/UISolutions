#include "GuiControlTemplates.h"
#include "../Templates/GuiThemeStyleFactory.h"
#include "../GuiWindowControls.h"
#include "../GuiScrollControls.h"
#include "../ListControlPackage/GuiListControls.h"

namespace vl
{
	namespace presentation
	{
		namespace controls
		{
			using namespace reflection::description;
			using namespace compositions;

/***********************************************************************
GuiComponent
***********************************************************************/
			
			GuiComponent::GuiComponent()
			{
			}

			GuiComponent::~GuiComponent()
			{
			}

			void GuiComponent::Attach(GuiInstanceRootObject* rootObject)
			{
			}

			void GuiComponent::Detach(GuiInstanceRootObject* rootObject)
			{
			}

/***********************************************************************
GuiInstanceRootObject
***********************************************************************/

			GuiInstanceRootObject::GuiInstanceRootObject()
			{
			}

			GuiInstanceRootObject::~GuiInstanceRootObject()
			{
			}

			void GuiInstanceRootObject::FinalizeInstance()
			{
				if (!finalized)
				{
					finalized = true;

					FOREACH(Ptr<IValueSubscription>, subscription, subscriptions)
					{
						subscription->Close();
					}
					FOREACH(GuiComponent*, component, components)
					{
						component->Detach(this);
					}

					subscriptions.Clear();
					for (vint i = 0; i<components.Count(); i++)
					{
						delete components[i];
					}
					components.Clear();
				}
			}

			bool GuiInstanceRootObject::IsFinalized()
			{
				return finalized;
			}

			void GuiInstanceRootObject::FinalizeInstanceRecursively(templates::GuiTemplate* thisObject)
			{
				if (!finalized)
				{
					NotifyFinalizeInstance(thisObject);
				}
			}

			void GuiInstanceRootObject::FinalizeInstanceRecursively(GuiCustomControl* thisObject)
			{
				if (!finalized)
				{
					NotifyFinalizeInstance(thisObject);
				}
			}

			void GuiInstanceRootObject::FinalizeInstanceRecursively(GuiControlHost* thisObject)
			{
				if (!finalized)
				{
					NotifyFinalizeInstance(thisObject);
				}
			}

			void GuiInstanceRootObject::FinalizeGeneralInstance(GuiInstanceRootObject* thisObject)
			{
			}

			void GuiInstanceRootObject::SetResourceResolver(Ptr<GuiResourcePathResolver> resolver)
			{
				resourceResolver = resolver;
			}

			Ptr<DescriptableObject> GuiInstanceRootObject::ResolveResource(const WString& protocol, const WString& path, bool ensureExist)
			{
				Ptr<DescriptableObject> object;
				if (resourceResolver)
				{
					object = resourceResolver->ResolveResource(protocol, path);
				}
				if (ensureExist && !object)
				{
					throw ArgumentException(L"Resource \"" + protocol + L"://" + path + L"\" does not exist.");
				}
				return object;
			}

			Ptr<description::IValueSubscription> GuiInstanceRootObject::AddSubscription(Ptr<description::IValueSubscription> subscription)
			{
				CHECK_ERROR(finalized == false, L"GuiInstanceRootObject::AddSubscription(Ptr<IValueSubscription>)#Cannot add subscription after finalizing.");
				if (subscriptions.Contains(subscription.Obj()))
				{
					return nullptr;
				}
				else
				{
					subscriptions.Add(subscription);
					subscription->Open();
					subscription->Update();
					return subscription;
				}
			}

			void GuiInstanceRootObject::UpdateSubscriptions()
			{
				FOREACH(Ptr<IValueSubscription>, subscription, subscriptions)
				{
					subscription->Update();
				}
			}

			bool GuiInstanceRootObject::AddComponent(GuiComponent* component)
			{
				CHECK_ERROR(finalized == false, L"GuiInstanceRootObject::AddComponent(GuiComponent*>)#Cannot add component after finalizing.");
				if(components.Contains(component))
				{
					return false;
				}
				else
				{
					components.Add(component);
					component->Attach(this);
					return true;
				}
			}

			bool GuiInstanceRootObject::AddControlHostComponent(GuiControlHost* controlHost)
			{
				return AddComponent(new GuiObjectComponent<GuiControlHost>(controlHost));
			}
		}
		namespace templates
		{
			using namespace collections;
			using namespace controls;
			using namespace compositions;
			using namespace elements;

/***********************************************************************
GuiTemplate
***********************************************************************/

			GuiTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_IMPL)

			GuiTemplate::GuiTemplate()
			{
				GuiTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_EVENT_INIT)
			}

			GuiTemplate::~GuiTemplate()
			{
				FinalizeInstanceRecursively(this);
			}

/***********************************************************************
Item GuiListItemTemplate
***********************************************************************/

			void GuiListItemTemplate::OnInitialize()
			{
			}

			GuiListItemTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_IMPL)

			GuiListItemTemplate::GuiListItemTemplate()
			{
				GuiListItemTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_EVENT_INIT)
			}

			GuiListItemTemplate::~GuiListItemTemplate()
			{
				FinalizeAggregation();
			}

			void GuiListItemTemplate::BeginEditListItem()
			{
				listControl->GetItemProvider()->PushEditing();
			}

			void GuiListItemTemplate::EndEditListItem()
			{
				CHECK_ERROR(listControl->GetItemProvider()->PopEditing(), L"GuiListItemTemplate::EndEditListItem()#BeginEditListItem and EndEditListItem calls are not paired.");
			}

			void GuiListItemTemplate::Initialize(controls::GuiListControl* _listControl)
			{
				CHECK_ERROR(listControl == nullptr, L"GuiListItemTemplate::Initialize(GuiListControl*)#This function can only be called once.");
				listControl = _listControl;
				OnInitialize();
			}

/***********************************************************************
Template Declarations
***********************************************************************/

			GUI_CONTROL_TEMPLATE_DECL(GUI_TEMPLATE_CLASS_IMPL)
			GUI_ITEM_TEMPLATE_DECL(GUI_TEMPLATE_CLASS_IMPL)
		}
	}
}