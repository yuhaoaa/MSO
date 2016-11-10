// MSOBtMoreLevelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreLevelDlg.h"
#include "afxdialogex.h"


// MSOBtMoreLevelDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtMoreLevelDlg, CDialogEx)

MSOBtMoreLevelDlg::MSOBtMoreLevelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreLevelDlg::IDD, pParent)
{

}

MSOBtMoreLevelDlg::~MSOBtMoreLevelDlg()
{
}

void MSOBtMoreLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreLevelDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_MORE_LEVEL_SETLEVEL, &MSOBtMoreLevelDlg::OnBnClickedButtonMoreLevelSetlevel)
END_MESSAGE_MAP()


// MSOBtMoreLevelDlg 消息处理程序


BOOL MSOBtMoreLevelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1508,340,135,420);
	// TODO:  在此添加额外的初始化

	m_buttonMore_Level_SetLevel.SubclassDlgItem(IDC_BUTTON_MORE_LEVEL_SETLEVEL,this); 
	OnInitButton(&m_buttonMore_Level_SetLevel);
	m_buttonMore_Level_SetLevel.SetWindowPos(NULL,7,40,127,71,SWP_NOZORDER);
	m_buttonMore_Level_SetLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_SETLEVEL1,RGB(0,0,0));
	more_Level_SetLevel=TRUE;

	m_buttonMore_Level_HighRefLevel.SubclassDlgItem(IDC_BUTTON_MORE_LEVEL_HIGHREFLEVEL,this); 
	OnInitButton(&m_buttonMore_Level_HighRefLevel);
	m_buttonMore_Level_HighRefLevel.SetWindowPos(NULL,7,115,127,71,SWP_NOZORDER);
	m_buttonMore_Level_HighRefLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_HIGHREFLEVEL,RGB(0,0,0));
	
	m_buttonMore_Level_MedRefLevel.SubclassDlgItem(IDC_BUTTON_MORE_LEVEL_MEDREFLEVEL,this); 
	OnInitButton(&m_buttonMore_Level_MedRefLevel);
	m_buttonMore_Level_MedRefLevel.SetWindowPos(NULL,7,190,127,71,SWP_NOZORDER);
	m_buttonMore_Level_MedRefLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_MEDREFLEVEL,RGB(0,0,0));

	m_buttonMore_Level_LowRefLevel.SubclassDlgItem(IDC_BUTTON_MORE_LEVEL_LOWREFLEVEL,this); 
	OnInitButton(&m_buttonMore_Level_LowRefLevel);
	m_buttonMore_Level_LowRefLevel.SetWindowPos(NULL,7,265,127,71,SWP_NOZORDER);
	m_buttonMore_Level_LowRefLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_LOWREFLEVEL,RGB(0,0,0));

	m_buttonMore_Level_SetDefaultLevel.SubclassDlgItem(IDC_BUTTON_MORE_LEVEL_SETDEFAULTLEVEL,this); 
	OnInitButton(&m_buttonMore_Level_SetDefaultLevel);
	m_buttonMore_Level_SetDefaultLevel.SetWindowPos(NULL,7,340,127,71,SWP_NOZORDER);
	m_buttonMore_Level_SetDefaultLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_SETDEFAULTLEVEL,RGB(0,0,0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtMoreLevelDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORELEVELDLGBK);  

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

void  MSOBtMoreLevelDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}

void MSOBtMoreLevelDlg::OnBnClickedButtonMoreLevelSetlevel()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Level_SetLevel =! more_Level_SetLevel;
	if (!more_Level_SetLevel)
	{
		m_buttonMore_Level_SetLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_SETLEVEL2,RGB(0,0,0));
	}
	else
	{
		m_buttonMore_Level_SetLevel.SetBitmaps(IDB_BITMAP_MORE_LEVEL_SETLEVEL1,RGB(0,0,0));
	}
	m_buttonMore_Level_SetLevel.Invalidate(TRUE);
}
