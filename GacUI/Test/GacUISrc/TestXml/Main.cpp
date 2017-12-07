#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "../Host/ResourceCompiler.h"
#include "../TestCppCodegen/Source/DarkSkinIncludes.h"
#include <Windows.h>

using namespace vl;
using namespace vl::stream;
using namespace vl::reflection::description;

//#define GUI_GRAPHICS_RENDERER_GDI
#define GUI_GRAPHICS_RENDERER_DIRECT2D

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
#ifdef GUI_GRAPHICS_RENDERER_GDI
	int result = SetupWindowsGDIRenderer();
#endif
#ifdef GUI_GRAPHICS_RENDERER_DIRECT2D
	int result = SetupWindowsDirect2DRenderer();
#endif

#if VCZH_CHECK_MEMORY_LEAKS
	_CrtDumpMemoryLeaks();
#endif
	return result;
}

#ifndef VCZH_DEBUG_NO_REFLECTION

void OpenMainWindow()
{
	{
		auto theme = MakePtr<darkskin::Theme>();
		RegisterTheme(L"DarkSkin", theme);
	}
	{
		auto window = UnboxValue<GuiWindow*>(Value::Create(L"demo::MainWindow"));
		window->ForceCalculateSizeImmediately();
		window->MoveToScreenCenter();
		GetApplication()->Run(window);
		delete window;
	}
}

#endif

void GuiMain()
{
#ifndef VCZH_DEBUG_NO_REFLECTION
	CompileResources(L"Demo", LR"(Resources/Resource.xml)",	L"./", L"", false);
	OpenMainWindow();
#endif
}