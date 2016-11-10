// MSOWave.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOWave.h"


// MSOWave

IMPLEMENT_DYNAMIC(MSOWave, CWnd)

MSOWave::MSOWave()
{
	m_crGridColor = RGB(148,138,107);
	m_brushBack.CreateSolidBrush(RGB(0,0,0));
	m_penBorederBlue.CreatePen(PS_SOLID,1,RGB(156,207,255));
	m_pendarkYellow.CreatePen(PS_SOLID,1,m_crGridColor);
	m_penBlack.CreatePen(PS_SOLID,1,RGB(255,255,0));
	m_penBlack1.CreatePen(PS_SOLID,1,RGB(255,255,0));
}

MSOWave::~MSOWave()
{
}


BEGIN_MESSAGE_MAP(MSOWave, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// MSOWave 消息处理程序

void MSOWave::InitiaDrawTools()
{
	CClientDC dc(this);

	//创建表格设备环境以及创建相应缓冲区
	if(m_dcGrid.GetSafeHdc()==NULL)
	{
		m_dcGrid.CreateCompatibleDC(&dc);
		m_bitmapGrid.CreateCompatibleBitmap(&dc,m_rcCanvas.Width(),m_rcCanvas.Height());
		m_pOldBitmapGrid = m_dcGrid.SelectObject(&m_bitmapGrid);
	}

	//创建画图设备环境以及创建相应缓冲区
	if (m_dcLine.GetSafeHdc() == NULL)
	{
		m_dcLine.CreateCompatibleDC(&dc);
		m_bitmapLine.CreateCompatibleBitmap(&dc,m_rcCanvas.Width(),m_rcCanvas.Height());
		m_pOldBitmapLine = m_dcLine.SelectObject(&m_bitmapLine);
	}
}

void MSOWave::InitialBackGround()
{
	//中间填黑
	GetClientRect(m_rcCanvas);
	m_oldPen=m_dcGrid.SelectObject(&m_penBorederBlue);
	m_oldBrush=m_dcGrid.SelectObject(&m_brushBack);
	m_dcGrid.Rectangle(m_rcCanvas);
	m_penBorederBlue.DeleteObject();
	m_brushBack.DeleteObject();

	m_oldPen = m_dcGrid.SelectObject(&m_pendarkYellow);

	int nYLittleGap = (int)( m_rcCanvas.Height() / 50.0);//竖着有五十小格
	int nYBigGap = nYLittleGap * 5 ;//一大格里有五小格
	int nXLittleGap = (int)( m_rcCanvas.Width() / 50.0);//横着有五十小格
	int nXBigGap = nXLittleGap * 5; //一大格里有五小格

	//横向点的绘制
	for(int i = nYLittleGap; i <m_rcCanvas.Height()-1 ;i += nYLittleGap)  
	{
		//左边线绘制
		m_dcGrid.MoveTo(m_rcCanvas.left , m_rcCanvas.top + i);
		m_dcGrid.LineTo(m_rcCanvas.left + 4, m_rcCanvas.top + i);
		for(int j = nXBigGap; j <= m_rcCanvas.Width(); j += nXBigGap)
		{
			m_dcGrid.SetPixel(m_rcCanvas.left + j, m_rcCanvas.top + i, m_crGridColor);
		}
		//中间线绘制
		m_dcGrid.MoveTo(m_rcCanvas.CenterPoint().x - 2,m_rcCanvas.top + i);
		m_dcGrid.LineTo(m_rcCanvas.CenterPoint().x + 3,m_rcCanvas.top + i);
		for(int x=0;x<m_rcCanvas.Height();x+=2)
		{
			m_dcGrid.SetPixel(m_rcCanvas.CenterPoint().x, m_rcCanvas.top + x, m_crGridColor);
		}
		//右边线绘制
		 m_dcGrid.MoveTo(m_rcCanvas.right - 4, m_rcCanvas.top + i);
	     m_dcGrid.LineTo(m_rcCanvas.right, m_rcCanvas.top + i);
	}
	//突出纵向的大格
	for(int i = nYBigGap; i <m_rcCanvas.Height()-1 ;i += nYBigGap)  
	{
		m_dcGrid.MoveTo(m_rcCanvas.left , m_rcCanvas.top + i);
		m_dcGrid.LineTo(m_rcCanvas.left + 7, m_rcCanvas.top + i);
		m_dcGrid.MoveTo(m_rcCanvas.right - 7, m_rcCanvas.top + i);
		m_dcGrid.LineTo(m_rcCanvas.right, m_rcCanvas.top + i);
	}

	//纵向的点绘制
	for(int i = nXLittleGap; i < m_rcCanvas.Width()-1; i += nXLittleGap)
	{
		//上面线绘制
		m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.top);
		m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.top + 4);
		for(int j = nYBigGap; j < m_rcCanvas.Height(); j+=nYBigGap)
		{
			m_dcGrid.SetPixel(m_rcCanvas.left + i, m_rcCanvas.top + j, m_crGridColor);
		}
		//中间线绘制
		m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.CenterPoint().y - 2);
		m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.CenterPoint().y + 3);
		for(int y=0;y<m_rcCanvas.Width();y+=2)
		{
			m_dcGrid.SetPixel(m_rcCanvas.left + y, m_rcCanvas.CenterPoint().y, m_crGridColor);
		}
		//下边线绘制
		m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.bottom - 4);
		m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.bottom);
	}
	//突出横向的大格
	for(int i = nXBigGap; i <m_rcCanvas.Width() ;i += nXBigGap)  
	{
		m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.top);
		m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.top + 7);
		m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.bottom - 7);
		m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.bottom);
	}

	m_dcGrid.SelectObject(m_oldPen);
	//从背景DC拷贝图像到做图dc
	m_dcLine.BitBlt(0,0,m_rcCanvas.Width(),m_rcCanvas.Height(),&m_dcGrid,0,0,SRCCOPY);
}


void MSOWave::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	dc.BitBlt(m_rcCanvas.left,m_rcCanvas.top,m_rcCanvas.Width(),m_rcCanvas.Height(),&m_dcLine,0,0,SRCCOPY);
}


BOOL MSOWave::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	BOOL result ;
	//注册窗体类
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//创建窗体类
	result = CWnd::CreateEx(NULL, className, NULL, dwStyle, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), (HMENU)nID) ;
	m_rcCanvas = CRect(rect);
	return result;
}
