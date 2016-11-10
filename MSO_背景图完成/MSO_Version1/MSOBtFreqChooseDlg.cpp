// MSOBtFreqChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtFreqChooseDlg.h"
#include "afxdialogex.h"


// MSOBtFreqChooseDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtFreqChooseDlg, CDialogEx)

MSOBtFreqChooseDlg::MSOBtFreqChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtFreqChooseDlg::IDD, pParent)
{

}

MSOBtFreqChooseDlg::~MSOBtFreqChooseDlg()
{
}

void MSOBtFreqChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtFreqChooseDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtFreqChooseDlg 消息处理程序


BOOL MSOBtFreqChooseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(1508,340,135,347);
	m_newFont.CreatePointFont(130, _T("宋体")); 

	m_buttonfreq_OBW.SubclassDlgItem(IDC_BUTTON_FREQOBW,this);
	m_buttonfreq_OBW.SetFlat(TRUE);
	m_buttonfreq_OBW.DrawBorder(FALSE);
	m_buttonfreq_OBW.SetWindowPos(NULL,25,268,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQOBW)->SetFont(&m_newFont);//ID
	m_buttonfreq_OBW.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFreq_ACPR.SubclassDlgItem(IDC_BUTTON_FREQACPR,this);
	m_buttonFreq_ACPR.SetFlat(TRUE);
	m_buttonFreq_ACPR.DrawBorder(FALSE);
	m_buttonFreq_ACPR.SetWindowPos(NULL,25,196,96,65,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQACPR)->SetFont(&m_newFont);//ID
	m_buttonFreq_ACPR.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFreq_CP.SubclassDlgItem(IDC_BUTTON_FREQCP,this);
	m_buttonFreq_CP.SetFlat(TRUE);
	m_buttonFreq_CP.DrawBorder(FALSE);
	m_buttonFreq_CP.SetWindowPos(NULL,25,124,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQCP)->SetFont(&m_newFont);//ID
	m_buttonFreq_CP.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFreq_NO.SubclassDlgItem(IDC_BUTTON_FREQNO,this);
	m_buttonFreq_NO.SetFlat(TRUE);
	m_buttonFreq_NO.DrawBorder(FALSE);
	m_buttonFreq_NO.SetWindowPos(NULL,25,52,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQNO)->SetFont(&m_newFont);//ID
	m_buttonFreq_NO.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtFreqChooseDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_FREQCHOOSEDLGBK);  

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
