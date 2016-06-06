#include <windows.h>
#include <assert.h>
#include <iostream>
#include "DirectXLib.h"
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
DirectX &g_directX = DirectX::instance();


LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lParam)
{
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
	wndClass.lpszClassName = wcName.c_str();
	wndClass.lpfnWndProc = WndProc;
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);

	//2.注册窗口类
	assert(RegisterClassEx(&wndClass));

	//3.创建窗口
	HWND hwnd = CreateWindow(wcName.c_str(),title.c_str(),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,WIDTH,HEIGHT,NULL,NULL,hInstance,NULL);

	//4.移动，显示，更新
	MoveWindow(hwnd,300,100,WIDTH,HEIGHT,true);
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);

	//DirectX初始化
	g_directX.initialDirectX(hInstance,hwnd,WIDTH,HEIGHT);

	return hwnd;
}

void GameUpdate(HWND hwnd)
{
	for (int i=0;i<30;++i)
	{
		for (int j=0;j<30;++j)
		{
			g_directX.instance().drawPixel(i,j,g_directX.color(0,255,0,0));
		}
	}
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
			if (curTime-preTime>100)
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

