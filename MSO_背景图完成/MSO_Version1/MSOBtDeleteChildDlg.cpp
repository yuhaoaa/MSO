// MSOBtDeleteChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtDeleteChildDlg.h"
#include "afxdialogex.h"


// MSOBtDeleteChildDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtDeleteChildDlg, CDialogEx)

MSOBtDeleteChildDlg::MSOBtDeleteChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtDeleteChildDlg::IDD, pParent)
{

}

MSOBtDeleteChildDlg::~MSOBtDeleteChildDlg()
{
}

void MSOBtDeleteChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtDeleteChildDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtDeleteChildDlg 消息处理程序


BOOL MSOBtDeleteChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1508,340,135,420);
	// TODO:  在此添加额外的初始化

	m_button_Delete_DeleteAll.SubclassDlgItem(IDC_BUTTON_DELETE_DELETEALL,this); 
	OnInitButton(&m_button_Delete_DeleteAll);
	m_button_Delete_DeleteAll.SetWindowPos(NULL,7,40,127,71,SWP_NOZORDER);
	m_button_Delete_DeleteAll.SetBitmaps(IDB_BITMAP_DELETE_DELETEALL,RGB(0,0,0));

	m_button_Delete_Choose.SubclassDlgItem(IDC_BUTTON_DELETE_CHOOSE,this); 
	OnInitButton(&m_button_Delete_Choose);
	m_button_Delete_Choose.SetWindowPos(NULL,7,115,127,71,SWP_NOZORDER);
	m_button_Delete_Choose.SetBitmaps(IDB_BITMAP_DELETE_CHOOSE,RGB(0,0,0));

	m_button_Delete_Ok.SubclassDlgItem(IDC_BUTTON_DELETE_OK,this); 
	OnInitButton(&m_button_Delete_Ok);
	m_button_Delete_Ok.SetWindowPos(NULL,7,340,127,71,SWP_NOZORDER);
	m_button_Delete_Ok.SetBitmaps(IDB_BITMAP_DELETE_OK,RGB(0,0,0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtDeleteChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_DELETECHILDDLGBK);  

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

void  MSOBtDeleteChildDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}