#include "DirectXLib.h"


bool DirectX::initialDirectX(HINSTANCE hInstance, HWND hWnd, int width, int height)
{
	//1.�����ӿ�
	IDirect3D9* d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	//2.��ȡӲ����Ϣ��ȷ�����㴦��ʽ
	D3DCAPS9 caps;
	int vertexProcessing;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,&caps);    //(��ǰ�Կ���Ӳ���豸)
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		vertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	//3.��дD3D����
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

	//4.�����豸
	d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pD3DXDevice);
	d3d9->Release();

	pD3DXDevice->CreateOffscreenPlainSurface(width, height, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &pD3DSurface, 0);
	
	return true;
}
void DirectX::lockSurface()
{
	// ��������ʼ����������
	memset(&LockRect, 0, sizeof(LockRect));
	// ����
	pD3DSurface->LockRect(&LockRect,NULL,D3DLOCK_DISCARD);
}

void DirectX::unlockSurface()
{
	// ����
	pD3DSurface->UnlockRect();
}
void DirectX::drawPixel(int x,int y, Color color)
{
	/* ������ɫ
	Pointer to the locked bits. 
	If a RECT was provided to the LockRect call, 
	pBits will be appropriately offset from the start of the surface.*/
	DWORD* pBits = (DWORD*)LockRect.pBits;
	pBits[x + y * (LockRect.Pitch >> 2)] = ARGB( color.a_ , color.r_ , color.g_ , color.b_ );      

}

/************************************************************************/
/* ����ֱ��(�е㷨)
 * ��ʽ����f(x,y)=(y0-y1)x+(x1-x0)y+x0y1-x1y0=0
 */
/************************************************************************/
void DirectX::drawLine(int x1,int y1,int x2,int y2,Color color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx>=dy)
	{
		if (x1>x2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		double A = y2-y1;
		double B = x1-x2;
		double C = x2*y1-x1*y2;
		int incrementY = (y2>y1)?1:-1;
		for (int x=x1,y=y1;x<=x2;++x)
		{
			drawPixel(x,y,color);
			double k = A*(x+1)+B*(y+incrementY)+C;
			if (k*incrementY>=0)
			{
				y += incrementY;
			}
		}
	}
	else
	{
		if (y1>y2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		double A = y2-y1;
		double B = x1-x2;
		double C = x2*y1-x1*y2;
		int incrementX = (x2>x1)?1:-1;
		for (int x=x1,y=y1;y<=y2;++y)
		{
			drawPixel(x,y,color);
			double k = A*(x+incrementX)+B*(y+1)+C;
			if (k*incrementX<=0)
			{
				x += incrementX;
			}
		}
	}	
}

/************************************************************************/
/* �������ζ�����y��С��������                                            */
/************************************************************************/
void DirectX::sortTriangleVector2( Vector2 &v1, Vector2 &v2, Vector2 &v3)
{
	if (v1.y>v2.y)
	{
		swap(v1,v2);
	}
	if (v3.y<v1.y)
	{
		swap(v1,v3);
		swap(v2,v3);
	}
	else if(v3.y<v2.y)
	{
		swap(v2,v3);
	}
}

/************************************************************************/
/* ���Ʋ�ֵ����ɫ�仯��ֱ��                                               */
/************************************************************************/
void DirectX::drawScanLine( Vector2 &v1, Vector2 &v2)
{
	if (v1.x>v2.x)
	{
		swap(v1,v2);
	}
	int x_end = v2.x;
	Color color = v1.color;
	Color d_color = v2.color-v1.color;
	for (int x=v1.x;x<=x_end;++x)
	{
		drawPixel(x,v1.y,color);
		color = v1.color + d_color*(x-v1.x)/(v2.x-v1.x); 
	}
}
/************************************************************************/
/* ���Ƶ�ƽ������	 v1Ϊ�϶���												*/
/************************************************************************/
void DirectX::drawTriangleBottomFlat( Vector2 &v1, Vector2 &v2, Vector2 &v3)
{
	int startY = v1.y;
	int endY = v2.y;
	double LX = v1.x,RX = v1.x;
	double ldx = (v2.x - v1.x) / (v2.y - v1.y);
	double rdx = (v3.x - v1.x) / (v3.y - v1.y);
	Color d_left_color = v2.color-v1.color;
	Color d_right_color = v3.color-v1.color;
	for (;startY<=endY;++startY)
	{
		double factor = (startY-v1.y)/(endY-v1.y);
		Color  co = d_left_color*factor;
		Color left_color = v1.color + d_left_color*factor;
		Color right_color = v1.color + d_right_color*factor;
		drawScanLine(Vector2(LX,startY,left_color),Vector2(RX,startY,right_color));
		//drawScanLine(Vector2(LX,startY,Color(0,0,255,0)),Vector2(RX,startY,Color(0,0,0,0)));
		LX += ldx;
		RX += rdx;
	}
}

/************************************************************************/
/* ���ƶ�ƽ������		v3Ϊ�׶���											*/
/************************************************************************/
void DirectX::drawTriangleTopFlat(Vector2 &v1, Vector2 &v2, Vector2 &v3)
{
	int startY = v3.y;
	int endY = v2.y;
	double LX = v3.x,RX = v3.x;
	double ldx = ((double)(v3.x - v1.x)) / (v3.y - v1.y);
	double rdx = ((double)(v3.x - v2.x)) / (v3.y - v2.y);
	for (;startY>=endY;--startY)
	{
		double factor = (v3.y-startY)/(v3.y-endY);
		Color left_color = v3.color + (v1.color-v3.color)*factor;
		Color right_color = v3.color + (v2.color-v3.color)*factor;
		drawScanLine(Vector2(LX,startY,left_color),Vector2(RX,startY,right_color));
		LX -= ldx;
		RX -= rdx;
	}
}

void DirectX::drawTriangle( Vector2 &v1, Vector2 &v2, Vector2 &v3)
{
	sortTriangleVector2(v1,v2,v3);
	if (v1==v2&&v2==v3)
	{
		drawPixel(v1.x,v2.x,v1.color);
	}
	else if (v1==v2)
	{
		drawLine(v1.x,v1.y,v3.x,v3.y,v1.color);
	}
	else if(v1==v3)
	{
		 drawLine(v1.x,v1.y,v2.x,v2.y,v1.color);
	}
	else if (v2==v3)
	{
		drawLine(v1.x,v1.y,v3.x,v3.y,v1.color);
	}
	else
	{
		if (v1.y==v2.y)
		{
			drawTriangleTopFlat(v1,v2,v3);
		}
		else if (v2.y==v3.y)
		{
			drawTriangleBottomFlat(v1,v2,v3);
		}
		else
		{
			Color color = v3.color + (v1.color-v3.color)*(v2.y-v3.y)/(v1.y-v3.y);
			Vector2 v4(v1.x+(double(v2.y-v1.y)/(v3.y-v1.y))*(v3.x-v1.x),v2.y,color);
			drawTriangleBottomFlat(v1,v2,v4);
			drawTriangleTopFlat(v2,v4,v3);
		}
	}
}


void DirectX::flipSurface()
{
	// ��ȡ��̨����
	IDirect3DSurface9* backBuffer = 0;
	pD3DXDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	// ʹ���Զ����������̨����
	pD3DXDevice->StretchRect(pD3DSurface, 0, backBuffer, 0, D3DTEXF_NONE);

	// GetBackBuffer���õĻ�����Ҫ���ͷţ�������ڴ�й¶
	backBuffer->Release();

	// ���������еĺ�̨������ʾ
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