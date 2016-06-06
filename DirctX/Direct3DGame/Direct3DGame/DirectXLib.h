#ifndef DIRECTXLIB_H_
#define DIRECTXLIB_H_

#include<d3d9.h>
#include<d3dx9.h>

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

	//�������ص�������
	int drawPixel(int x,int y,DWORD color);

	//��������ת��ʾ
	void flipSurface();

	//��ȡ�豸
	IDirect3DDevice9* getDevice();

	//��ȡ������
	IDirect3DSurface9* getSurface();

	DWORD color(int a,int r,int g,int b){return DWORD((a<<24)+(r<<16)+(g<<8)+b);}
	//����
	~DirectX();
private:
	DirectX():pD3DXDevice(nullptr),pD3DSurface(nullptr){}
	IDirect3DDevice9* pD3DXDevice;
	IDirect3DSurface9* pD3DSurface;

};


#endif