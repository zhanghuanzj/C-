#ifndef DIRECTXLIB_H_
#define DIRECTXLIB_H_

#include<d3d9.h>
#include<d3dx9.h>
#include <windows.h>
#include <iostream>
#include "Math.h"
#include "Camera.h"
#include "Model.h"

using namespace std;


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
	void fillSurface();
	void lockSurface();
	void unlockSurface();
	//�������ص�������
	void drawPixel(int x,int y,Color color);

	//��������ת��ʾ
	void flipSurface();

	//����ֱ��
	void drawLine(int ,int ,int ,int,Color  );

	//����������
	bool compare(const Vector2 &v1,const Vector2 &v2){return v1.y<v2.y;}
	void sortTriangleVector2( Vector2 &v1, Vector2 &v2, Vector2 &v3);
	void drawScanLine( Vector2 &v1, Vector2 &v2);
	void drawTriangleBottomFlat( Vector2 &v1, Vector2 &v2, Vector2 &v3);
	void drawTriangleTopFlat( Vector2 &v1, Vector2 &v2, Vector2 &v3);
	void drawTriangle( Vector2 &v1, Vector2 &v2, Vector2 &v3);

	//�����߿�ģ��
	void draw_wireframe_model(Model& model);
	//��ȡ�豸
	IDirect3DDevice9* getDevice();

	//��ȡ������
	IDirect3DSurface9* getSurface();

	DWORD ARGB(int a,int r,int g,int b){return DWORD((a<<24)+(r<<16)+(g<<8)+b);}
	//����
	~DirectX();
	D3DLOCKED_RECT LockRect;
private:
	DirectX():pD3DXDevice(nullptr),pD3DSurface(nullptr),camera(Camera::instance()){}
	IDirect3DDevice9* pD3DXDevice;
	IDirect3DSurface9* pD3DSurface;
	Camera &camera;
	int width_;
	int height_;
	 

};


#endif