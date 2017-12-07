﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_DEMOPARTIALCLASSES
#define VCZH_WORKFLOW_COMPILER_GENERATED_DEMOPARTIALCLASSES

#include "GacUI.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace vl_workflow_global
{
	struct __vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	class __vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription;
}

namespace demo
{
	class MainWindowConstructor;
	class MainWindow;

	class MainWindowConstructor : public ::vl::Object, public ::vl::reflection::Description<MainWindowConstructor>
	{
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindowConstructor>;
#endif
	protected:
		::vl::presentation::controls::GuiSinglelineTextBox* textBoxName = static_cast<::vl::presentation::controls::GuiSinglelineTextBox*>(nullptr);
		::demo::MainWindow* __vwsn_precompile_0 = static_cast<::demo::MainWindow*>(nullptr);
		::vl::presentation::compositions::GuiTableComposition* __vwsn_precompile_1 = static_cast<::vl::presentation::compositions::GuiTableComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_2 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiLabel* __vwsn_precompile_3 = static_cast<::vl::presentation::controls::GuiLabel*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_4 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_5 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_6 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiLabel* __vwsn_precompile_7 = static_cast<::vl::presentation::controls::GuiLabel*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_8 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		void __vwsn_initialize_instance_(::demo::MainWindow* __vwsn_this_);
	public:
		MainWindowConstructor();
	};

	class MainWindow : public ::vl::presentation::controls::GuiWindow, public ::demo::MainWindowConstructor, public ::vl::reflection::Description<MainWindow>
	{
		friend class ::demo::MainWindowConstructor;
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindow>;
#endif
	public:
		MainWindow();
		~MainWindow();
	};

}
/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class Demo
	{
	public:

		static Demo& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__
	{
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__(::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()(const ::vl::reflection::description::Value& __vwsn_value_) const;
	};

	class __vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription(::demo::MainWindowConstructor* __vwsnctorthis_0);

		::vl::presentation::controls::GuiSinglelineTextBox* __vwsn_bind_cache_0 = nullptr;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0(::vl::presentation::compositions::GuiGraphicsComposition* __vwsn_bind_callback_argument_0, ::vl::presentation::compositions::GuiEventArgs* __vwsn_bind_callback_argument_1);
		bool Open() override;
		bool Update() override;
		bool Close() override;
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
