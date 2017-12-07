﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "Demo.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, DemoReflection.h) */
#include "DemoReflection.h"
#endif
/* CodePack:EndIgnore() */

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

#define GLOBAL_SYMBOL ::vl_workflow_global::Demo::
#define GLOBAL_NAME ::vl_workflow_global::Demo::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::Demo::Instance()
#define USERIMPL(...)

/***********************************************************************
Class (::demo::FindWindow)
***********************************************************************/

namespace demo
{
	USERIMPL(/* ::demo::FindWindow */)
	bool FindWindow::FindNext(const ::vl::WString& toFind, bool caseSensitive, bool down)
	{
		auto position = textBox->GetCaretEnd();
		auto rowCount = textBox->GetRowCount();
		auto normalization = caseSensitive ? Locale::None : Locale::IgnoreCase;

		for (vint i = position.row; 0 <= i&&i < rowCount; (down ? i++ : i--))
		{
			auto rowText = textBox->GetRowText(i);
			auto fragment = rowText;
			if (i == position.row)
			{
				if (down)
				{
					fragment = rowText.Right(rowText.Length() - position.column);
				}
				else
				{
					fragment = rowText.Left(position.column);
				}
			}

			auto pair = down
				? INVLOC.FindFirst(fragment, toFind, normalization)
				: INVLOC.FindLast(fragment, toFind, normalization)
				;

			if (pair.key != -1)
			{
				TextPos begin, end;
				if (i == position.row && down)
				{
					begin = TextPos(i, pair.key + position.column);
				}
				else
				{
					begin = TextPos(i, pair.key);
				}

				if (down)
				{
					end = TextPos(begin.row, begin.column + pair.value);
				}
				else
				{
					end = TextPos(begin.row, begin.column);
					begin.column += pair.value;
				}

				textBox->Select(begin, end);
				textBox->SetFocus();
				return true;
			}
		}

		return false;
	}

	FindWindow::FindWindow()
		: ::vl::presentation::controls::GuiWindow(::vl::presentation::theme::ThemeName::Window)
	{
		auto __vwsn_resource_ = ::vl::__vwsn::This(::vl::presentation::GetResourceManager())->GetResourceFromClassName(::vl::WString(L"demo::FindWindow", false));
		auto __vwsn_resolver_ = ::vl::Ptr<::vl::presentation::GuiResourcePathResolver>(new ::vl::presentation::GuiResourcePathResolver(__vwsn_resource_, ::vl::__vwsn::This(__vwsn_resource_.Obj())->GetWorkingDirectory()));
		::vl::__vwsn::This(this)->SetResourceResolver(__vwsn_resolver_);
		::vl::__vwsn::This(this)->__vwsn_initialize_instance_(this);
	}

	FindWindow::~FindWindow()
	{
		this->FinalizeInstanceRecursively(static_cast<::vl::presentation::controls::GuiControlHost*>(this));
	}

}
#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
