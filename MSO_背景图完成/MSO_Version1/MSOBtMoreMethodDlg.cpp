// MSOBtMoreMethodDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreMethodDlg.h"
#include "afxdialogex.h"


// MSOBtMoreMethodDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtMoreMethodDlg, CDialogEx)

MSOBtMoreMethodDlg::MSOBtMoreMethodDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreMethodDlg::IDD, pParent)
{

}

MSOBtMoreMethodDlg::~MSOBtMoreMethodDlg()
{
}

void MSOBtMoreMethodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreMethodDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtMoreMethodDlg 消息处理程序


BOOL MSOBtMoreMethodDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(1508,340,135,272);//style设置为child，坐标就是相对于1366*768的，否则是相对于整个屏幕,但是会被遮挡，还没找到方法，所以没有child
	m_newFont.CreatePointFont(130, _T("宋体")); 

	m_buttonMore_Method_Mintomax.SubclassDlgItem(IDC_BUTTON_MOREMINTOMAX,this);
	m_buttonMore_Method_Mintomax.SetFlat(TRUE);
	m_buttonMore_Method_Mintomax.DrawBorder(FALSE);
	m_buttonMore_Method_Mintomax.SetWindowPos(NULL,25,196,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREMINTOMAX)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_Mintomax.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));
	
	m_buttonMore_Method_Histogram.SubclassDlgItem(IDC_BUTTON_MOREHISTOGRAM,this);
	m_buttonMore_Method_Histogram.SetFlat(TRUE);
	m_buttonMore_Method_Histogram.DrawBorder(FALSE);
	m_buttonMore_Method_Histogram.SetWindowPos(NULL,25,124,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREHISTOGRAM)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_Histogram.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonMore_Method_AutoChoose.SubclassDlgItem(IDC_BUTTON_MOREAUTOCHOOSE,this);
	//m_buttonMore_Method_AutoChoose.DrawTransparent(TRUE);
	m_buttonMore_Method_AutoChoose.SetFlat(TRUE);
	m_buttonMore_Method_AutoChoose.DrawBorder(FALSE);
	m_buttonMore_Method_AutoChoose.SetWindowPos(NULL,25,52,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREAUTOCHOOSE)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_AutoChoose.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtMoreMethodDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MOREMETHODDLGBK);  

	//选入DC  
	//CClientDC cdc(this);   
	CDC comdc;  
	comdc.CreateCompatibleDC(&dc);  
	comdc.SelectObject(&bitmap);  

	//生成BITMAP  
	BITMAP bit;  
	bitmap.GetBitmap(&bit);  

	//客户区域  
	CRect rect;  
	GetClientRect(rect);  

	//用客户区的DC绘制所生成的BITMAP，并适应为窗口大小  
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&comdc,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY); 
}
