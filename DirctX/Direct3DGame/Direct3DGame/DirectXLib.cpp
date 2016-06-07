#include "DirectXLib.h"
#include <iostream>
#include <windows.h>
#include <sstream>
using namespace std;


bool DirectX::initialDirectX(HINSTANCE hInstance, HWND hWnd, int width, int height)
{
	//1.创建接口
	IDirect3D9* d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	//2.获取硬件信息，确定顶点处理方式
	D3DCAPS9 caps;
	int vertexProcessing;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,&caps);    //(当前显卡，硬件设备)
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		vertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	//3.填写D3D参数
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = width;
	d3dpp.BackBufferHeight           = height;
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount            = 1;
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality         = 0;
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow              = hWnd;
	d3dpp.Windowed                   = true;
	d3dpp.EnableAutoDepthStencil     = true;
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
	d3dpp.Flags                      = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	//4.创建设备
	d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pD3DXDevice);
	d3d9->Release();

	pD3DXDevice->CreateOffscreenPlainSurface(width, height, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &pD3DSurface, 0);
	
	return true;
}
void DirectX::lockSurface()
{
	// 创建并初始化锁定区域
	memset(&LockRect, 0, sizeof(LockRect));
	// 锁定
	pD3DSurface->LockRect(&LockRect,NULL,D3DLOCK_DISCARD);
}

void DirectX::unlockSurface()
{
	// 解锁
	pD3DSurface->UnlockRect();
}
void DirectX::drawPixel(int x,int y, DWORD color)
{
	/* 像素着色
	Pointer to the locked bits. 
	If a RECT was provided to the LockRect call, 
	pBits will be appropriately offset from the start of the surface.*/
	DWORD* pBits = (DWORD*)LockRect.pBits;
	pBits[x + y * (LockRect.Pitch >> 2)] = color;      

}

/************************************************************************/
/* 绘制直线
 * 隐式方程f(x,y)=(y0-y1)x+(x1-x0)y+x0y1-x1y0=0
 */
/************************************************************************/
void DirectX::drawLine(const Vector2 &v1,const Vector2 &v2,DWORD color)
{
	double A = v1.y-v2.y;
	double B = v2.x-v1.x;
	double C = v1.x*v2.y-v2.x*v1.y;
	double x,y=v1.y;
	for (x=v1.x;x<=v2.x;++x)
	{
		drawPixel(x,y,color);
		if ((A*(x+1)+B*(y+0.5)+C)<0)
		{
			++y;
		}
	}
}


void DirectX::flipSurface()
{
	// 获取后台缓存
	IDirect3DSurface9* backBuffer = 0;
	pD3DXDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	// 使用自定义表面填充后台缓存
	pD3DXDevice->StretchRect(pD3DSurface, 0, backBuffer, 0, D3DTEXF_NONE);

	// GetBackBuffer所得的缓存需要被释放，否则会内存泄露
	backBuffer->Release();

	// 将交换链中的后台缓存显示
	pD3DXDevice->Present(NULL, NULL, NULL, NULL);
}

IDirect3DDevice9* DirectX::getDevice()
{
	return pD3DXDevice;
}

IDirect3DSurface9* DirectX::getSurface()
{
	return pD3DSurface;
}

DirectX::~DirectX()
{
	if (pD3DSurface!=NULL)
	{
		pD3DSurface->Release();
	}
	if (pD3DXDevice!=NULL)
	{
		pD3DXDevice->Release();
	}
}