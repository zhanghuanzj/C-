#include <windows.h>
#include <assert.h>
#include <iostream>
#include "DirectXLib.h"
#include "Math.h"
#include <WindowsX.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
DirectX &g_directX = DirectX::instance();


LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_KEYDOWN:
		if (wparam==VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			return 0;
		} break;
	default:
		return DefWindowProc(hwnd,message,wparam,lParam);
	}
	return 0;
}

HWND GameStart(HINSTANCE hInstance,int nShowCmd,string wcName,string title)
{
	//1.创建窗口类
	WNDCLASSEX wndClass = {};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = wcName.c_str();

	//2.注册窗口类
	assert(RegisterClassEx(&wndClass));

	//3.创建窗口
	HWND hwnd = CreateWindow(wcName.c_str(),title.c_str(),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,WIDTH,HEIGHT,NULL,NULL,hInstance,NULL);

	//4.调整大小，移动，显示，更新
	RECT window_rect = {0,0,WIDTH,HEIGHT};
	AdjustWindowRectEx(&window_rect, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL, GetWindowExStyle(hwnd));
	MoveWindow(hwnd,300,150,window_rect.right-window_rect.left, window_rect.bottom-window_rect.top,false);
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);

	//DirectX初始化
	g_directX.initialDirectX(hInstance,hwnd,WIDTH,HEIGHT);

	return hwnd;
}

void GameUpdate(HWND hwnd)
{
	g_directX.lockSurface();
	g_directX.drawLine(Vector2(100,100),Vector2(400,400),g_directX.ARGB(0,255,0,0));
	g_directX.unlockSurface();
	g_directX.flipSurface();
}

void GameEnd(string wcName,HINSTANCE hInstance)
{
	//5.注销窗口类
	UnregisterClass(wcName.c_str(),hInstance);
}


int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
	//1.创建窗口
	string windowClassName = "MyWindow";
	string title = "First";
	HWND hwnd = GameStart(hInstance,nShowCmd,windowClassName,title);

	//时间初始化
	DWORD curTime = GetTickCount();
	DWORD preTime = GetTickCount();
	//2.消息循环
	MSG msg = {0};
	while (msg.message!=WM_QUIT)
	{
		//获取消息
		if (PeekMessage(&msg,0,NULL,NULL,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			curTime = GetTickCount();
			if (curTime-preTime>30)
			{
				preTime = curTime;
				GameUpdate(hwnd);
			}
		}
	}

	//3.游戏结束
	GameEnd(windowClassName,hInstance);
	return 0;
}

