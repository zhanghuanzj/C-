#ifndef DIRECTXLIB_H_
#define DIRECTXLIB_H_

#include<d3d9.h>
#include<d3dx9.h>

class DirectX
{
public:
	//单例获取
	static DirectX& instance()
	{
		static DirectX* pDirectX = new DirectX();
		return *pDirectX;
	}
	//初始化DirectX
	bool initialDirectX(HINSTANCE hInstance, HWND hWnd, int width, int height);

	//绘制像素到缓冲区
	int drawPixel(int x,int y,DWORD color);

	//缓冲区翻转显示
	void flipSurface();

	//获取设备
	IDirect3DDevice9* getDevice();

	//获取缓冲区
	IDirect3DSurface9* getSurface();

	DWORD color(int a,int r,int g,int b){return DWORD((a<<24)+(r<<16)+(g<<8)+b);}
	//析构
	~DirectX();
private:
	DirectX():pD3DXDevice(nullptr),pD3DSurface(nullptr){}
	IDirect3DDevice9* pD3DXDevice;
	IDirect3DSurface9* pD3DSurface;

};


#endif