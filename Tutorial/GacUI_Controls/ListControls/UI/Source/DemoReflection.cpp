﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "DemoReflection.h"

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

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			IMPL_CPP_TYPE_INFO(demo::ListViewTabPage)
			IMPL_CPP_TYPE_INFO(demo::ListViewTabPageConstructor)
			IMPL_CPP_TYPE_INFO(demo::MainWindow)
			IMPL_CPP_TYPE_INFO(demo::MainWindowConstructor)
			IMPL_CPP_TYPE_INFO(demo::MyTextItem)
			IMPL_CPP_TYPE_INFO(demo::TextListTabPage)
			IMPL_CPP_TYPE_INFO(demo::TextListTabPageConstructor)
			IMPL_CPP_TYPE_INFO(demo::TreeViewTabPage)
			IMPL_CPP_TYPE_INFO(demo::TreeViewTabPageConstructor)

#define _ ,
			BEGIN_CLASS_MEMBER(::demo::ListViewTabPage)
				CLASS_MEMBER_CONSTRUCTOR(::demo::ListViewTabPage*(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_instance_ctor_, NO_PARAMETER)
			END_CLASS_MEMBER(::demo::ListViewTabPage)

			BEGIN_CLASS_MEMBER(::demo::ListViewTabPageConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::ListViewTabPageConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_initialize_instance_, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(bindableListView)
				CLASS_MEMBER_FIELD(comboView)
				CLASS_MEMBER_FIELD(listView)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::demo::ListViewTabPageConstructor)

			BEGIN_CLASS_MEMBER(::demo::MainWindow)
				CLASS_MEMBER_CONSTRUCTOR(::demo::MainWindow*(), NO_PARAMETER)
			END_CLASS_MEMBER(::demo::MainWindow)

			BEGIN_CLASS_MEMBER(::demo::MainWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::MainWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_initialize_instance_, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(self)
			END_CLASS_MEMBER(::demo::MainWindowConstructor)

			BEGIN_CLASS_MEMBER(::demo::MyTextItem)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::MyTextItem>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetChecked, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetName, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetChecked, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetName, { L"__vwsn_value_" })
				CLASS_MEMBER_FIELD(__vwsn_prop_Checked)
				CLASS_MEMBER_FIELD(__vwsn_prop_Name)
				CLASS_MEMBER_PROPERTY(Checked, GetChecked, SetChecked)
				CLASS_MEMBER_PROPERTY(Name, GetName, SetName)
			END_CLASS_MEMBER(::demo::MyTextItem)

			BEGIN_CLASS_MEMBER(::demo::TextListTabPage)
				CLASS_MEMBER_CONSTRUCTOR(::demo::TextListTabPage*(), NO_PARAMETER)
				CLASS_MEMBER_FIELD(counter)
				CLASS_MEMBER_FIELD(itemsToBind)
			END_CLASS_MEMBER(::demo::TextListTabPage)

			BEGIN_CLASS_MEMBER(::demo::TextListTabPageConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::TextListTabPageConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_initialize_instance_, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_22)
				CLASS_MEMBER_FIELD(__vwsn_precompile_23)
				CLASS_MEMBER_FIELD(__vwsn_precompile_24)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(bindableTextList)
				CLASS_MEMBER_FIELD(comboView)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textList)
			END_CLASS_MEMBER(::demo::TextListTabPageConstructor)

			BEGIN_CLASS_MEMBER(::demo::TreeViewTabPage)
				CLASS_MEMBER_CONSTRUCTOR(::demo::TreeViewTabPage*(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_instance_ctor_, NO_PARAMETER)
				CLASS_MEMBER_FIELD(nodesToBind)
			END_CLASS_MEMBER(::demo::TreeViewTabPage)

			BEGIN_CLASS_MEMBER(::demo::TreeViewTabPageConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::TreeViewTabPageConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_initialize_instance_, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_22)
				CLASS_MEMBER_FIELD(__vwsn_precompile_23)
				CLASS_MEMBER_FIELD(__vwsn_precompile_24)
				CLASS_MEMBER_FIELD(__vwsn_precompile_25)
				CLASS_MEMBER_FIELD(__vwsn_precompile_26)
				CLASS_MEMBER_FIELD(__vwsn_precompile_27)
				CLASS_MEMBER_FIELD(__vwsn_precompile_28)
				CLASS_MEMBER_FIELD(__vwsn_precompile_29)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_30)
				CLASS_MEMBER_FIELD(__vwsn_precompile_31)
				CLASS_MEMBER_FIELD(__vwsn_precompile_32)
				CLASS_MEMBER_FIELD(__vwsn_precompile_33)
				CLASS_MEMBER_FIELD(__vwsn_precompile_34)
				CLASS_MEMBER_FIELD(__vwsn_precompile_35)
				CLASS_MEMBER_FIELD(__vwsn_precompile_36)
				CLASS_MEMBER_FIELD(__vwsn_precompile_37)
				CLASS_MEMBER_FIELD(__vwsn_precompile_38)
				CLASS_MEMBER_FIELD(__vwsn_precompile_39)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_40)
				CLASS_MEMBER_FIELD(__vwsn_precompile_41)
				CLASS_MEMBER_FIELD(__vwsn_precompile_42)
				CLASS_MEMBER_FIELD(__vwsn_precompile_43)
				CLASS_MEMBER_FIELD(__vwsn_precompile_44)
				CLASS_MEMBER_FIELD(__vwsn_precompile_45)
				CLASS_MEMBER_FIELD(__vwsn_precompile_46)
				CLASS_MEMBER_FIELD(__vwsn_precompile_47)
				CLASS_MEMBER_FIELD(__vwsn_precompile_48)
				CLASS_MEMBER_FIELD(__vwsn_precompile_49)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(bindableTreeView)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(treeView)
			END_CLASS_MEMBER(::demo::TreeViewTabPageConstructor)

#undef _
			class DemoTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::demo::ListViewTabPage)
					ADD_TYPE_INFO(::demo::ListViewTabPageConstructor)
					ADD_TYPE_INFO(::demo::MainWindow)
					ADD_TYPE_INFO(::demo::MainWindowConstructor)
					ADD_TYPE_INFO(::demo::MyTextItem)
					ADD_TYPE_INFO(::demo::TextListTabPage)
					ADD_TYPE_INFO(::demo::TextListTabPageConstructor)
					ADD_TYPE_INFO(::demo::TreeViewTabPage)
					ADD_TYPE_INFO(::demo::TreeViewTabPageConstructor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadDemoTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<DemoTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
