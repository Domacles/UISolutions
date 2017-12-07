/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Control Styles::Common Style Helpers

Interfaces:
***********************************************************************/

#ifndef VCZH_PRESENTATION_CONTROLS_GUITHEMESTYLEFACTORY
#define VCZH_PRESENTATION_CONTROLS_GUITHEMESTYLEFACTORY

#include "GuiControlTemplates.h"
#include "GuiCommonTemplates.h"

namespace vl
{
	namespace presentation
	{
		namespace theme
		{
#define GUI_CONTROL_TEMPLATE_TYPES(F) \
			F(WindowTemplate,				Window) \
			F(ControlTemplate,				CustomControl) \
			F(WindowTemplate,				Tooltip) \
			F(LabelTemplate,				Label) \
			F(LabelTemplate,				ShortcutKey) \
			F(ScrollViewTemplate,			ScrollView) \
			F(ControlTemplate,				GroupBox) \
			F(TabTemplate,					Tab) \
			F(ComboBoxTemplate,				ComboBox) \
			F(MultilineTextBoxTemplate,		MultilineTextBox) \
			F(SinglelineTextBoxTemplate,	SinglelineTextBox) \
			F(DocumentViewerTemplate,		DocumentViewer) \
			F(DocumentLabelTemplate,		DocumentLabel) \
			F(DocumentLabelTemplate,		DocumentTextBox) \
			F(ListViewTemplate,				ListView) \
			F(TreeViewTemplate,				TreeView) \
			F(TextListTemplate,				TextList) \
			F(SelectableButtonTemplate,		ListItemBackground) \
			F(SelectableButtonTemplate,		TreeItemExpander) \
			F(SelectableButtonTemplate,		CheckTextListItem) \
			F(SelectableButtonTemplate,		RadioTextListItem) \
			F(MenuTemplate,					Menu) \
			F(ControlTemplate,				MenuBar) \
			F(ControlTemplate,				MenuSplitter) \
			F(ToolstripButtonTemplate,		MenuBarButton) \
			F(ToolstripButtonTemplate,		MenuItemButton) \
			F(ControlTemplate,				ToolstripToolBar) \
			F(ToolstripButtonTemplate,		ToolstripButton) \
			F(ToolstripButtonTemplate,		ToolstripDropdownButton) \
			F(ToolstripButtonTemplate,		ToolstripSplitButton) \
			F(ControlTemplate,				ToolstripSplitter) \
			F(ButtonTemplate,				Button) \
			F(SelectableButtonTemplate,		CheckBox) \
			F(SelectableButtonTemplate,		RadioButton) \
			F(DatePickerTemplate,			DatePicker) \
			F(ScrollTemplate,				HScroll) \
			F(ScrollTemplate,				VScroll) \
			F(ScrollTemplate,				HTracker) \
			F(ScrollTemplate,				VTracker) \
			F(ScrollTemplate,				ProgressBar) \

			enum class ThemeName
			{
				Unknown,
#define GUI_DEFINE_THEME_NAME(TEMPLATE, CONTROL) CONTROL,
				GUI_CONTROL_TEMPLATE_TYPES(GUI_DEFINE_THEME_NAME)
#undef GUI_DEFINE_THEME_NAME
			};

			/// <summary>Theme interface. A theme creates appropriate style controllers or style providers for default controls. Call [M:vl.presentation.theme.GetCurrentTheme] to access this interface.</summary>
			class ITheme : public virtual IDescriptable, public Description<ITheme>
			{
			public:
				virtual TemplateProperty<templates::GuiControlTemplate>				CreateStyle(ThemeName themeName) = 0;
			};

			class Theme;

			/// <summary>Partial control template collections. [F:vl.presentation.theme.GetCurrentTheme] will returns an object, which walks through multiple registered [T:vl.presentation.theme.ThemeTemplates] to create a correct template object for a control.</summary>
			class ThemeTemplates : public controls::GuiInstanceRootObject, public AggregatableDescription<ThemeTemplates>
			{
				friend class Theme;
			protected:
				ThemeTemplates*														previous = nullptr;
				ThemeTemplates*														next = nullptr;

			public:
				~ThemeTemplates();

#define GUI_DEFINE_ITEM_PROPERTY(TEMPLATE, CONTROL) TemplateProperty<templates::Gui##TEMPLATE> CONTROL;
				GUI_CONTROL_TEMPLATE_TYPES(GUI_DEFINE_ITEM_PROPERTY)
#undef GUI_DEFINE_ITEM_PROPERTY
			};

			/// <summary>Get the current theme style factory object. The default theme is [T:vl.presentation.win7.Win7Theme]. Call [M:vl.presentation.theme.SetCurrentTheme] to change the default theme.</summary>
			/// <returns>The current theme style factory object.</returns>
			extern ITheme*						GetCurrentTheme();
			extern void							InitializeTheme();
			extern void							FinalizeTheme();
			/// <summary>Register a control template collection object.</summary>
			/// <param name="name">The name of the theme.</param>
			/// <param name="theme">The control template collection object.</param>
			extern bool							RegisterTheme(const WString& name, Ptr<ThemeTemplates> theme);
			/// <summary>Unregister a control template collection object.</summary>
			/// <returns>The registered object. Returns null if it does not exist.</returns>
			/// <param name="name">The name of the theme.</param>
			extern Ptr<ThemeTemplates>			UnregisterTheme(const WString& name);
		}
	}
}

#endif