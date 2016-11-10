// MSOBtMoreChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreChooseDlg.h"
#include "afxdialogex.h"


// MSOBtMoreChooseDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtMoreChooseDlg, CDialogEx)

MSOBtMoreChooseDlg::MSOBtMoreChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreChooseDlg::IDD, pParent)
{

}

MSOBtMoreChooseDlg::~MSOBtMoreChooseDlg()
{
}

void MSOBtMoreChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreChooseDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtMoreChooseDlg 消息处理程序

BOOL MSOBtMoreChooseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1508,340,135,272);
	m_newFont.CreatePointFont(130, _T("宋体")); 
	// TODO:  在此添加额外的初始化

	m_buttonMore_Choose_Cursor.SubclassDlgItem(IDC_BUTTON_MORE_CHOOSE_CURSOR,this);
	m_buttonMore_Choose_Cursor.SetFlat(TRUE);
	m_buttonMore_Choose_Cursor.DrawBorder(FALSE);
	m_buttonMore_Choose_Cursor.SetWindowPos(NULL,25,196,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MORE_CHOOSE_CURSOR)->SetFont(&m_newFont);//ID
	m_buttonMore_Choose_Cursor.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonMore_Choose_Screen.SubclassDlgItem(IDC_BUTTON_MORE_CHOOSE_SCREEN,this);
	m_buttonMore_Choose_Screen.SetFlat(TRUE);
	m_buttonMore_Choose_Screen.DrawBorder(FALSE);
	m_buttonMore_Choose_Screen.SetWindowPos(NULL,25,124,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MORE_CHOOSE_SCREEN)->SetFont(&m_newFont);//ID
	m_buttonMore_Choose_Screen.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonMore_Choose_Close.SubclassDlgItem(IDC_BUTTON_MORE_CHOOSE_CLOSE,this);
	m_buttonMore_Choose_Close.SetFlat(TRUE);
	m_buttonMore_Choose_Close.DrawBorder(FALSE);
	m_buttonMore_Choose_Close.SetWindowPos(NULL,25,52,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MORE_CHOOSE_CLOSE)->SetFont(&m_newFont);//ID
	m_buttonMore_Choose_Close.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void MSOBtMoreChooseDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORECHOOSEDLGBK);  

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