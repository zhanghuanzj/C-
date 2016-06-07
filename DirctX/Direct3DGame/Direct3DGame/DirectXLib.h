#ifndef DIRECTXLIB_H_
#define DIRECTXLIB_H_

#include<d3d9.h>
#include<d3dx9.h>
#include "Math.h"

class DirectX
{
public:
	//������ȡ
	static DirectX& instance()
	{
		static DirectX* pDirectX = new DirectX();
		return *pDirectX;
	}
	//��ʼ��DirectX
	bool initialDirectX(HINSTANCE hInstance, HWND hWnd, int width, int height);
	void lockSurface();
	void unlockSurface();
	//�������ص�������
	void drawPixel(int x,int y,DWORD color);

	//��������ת��ʾ
	void flipSurface();

	//����ֱ��
	void drawLine(const Vector2 &,const Vector2 &,DWORD color);

	//��ȡ�豸
	IDirect3DDevice9* getDevice();

	//��ȡ������
	IDirect3DSurface9* getSurface();

	DWORD ARGB(int a,int r,int g,int b){return DWORD((a<<24)+(r<<16)+(g<<8)+b);}
	//����
	~DirectX();
	D3DLOCKED_RECT LockRect;
private:
	DirectX():pD3DXDevice(nullptr),pD3DSurface(nullptr){}
	IDirect3DDevice9* pD3DXDevice;
	IDirect3DSurface9* pD3DSurface;
	 

};


#endif