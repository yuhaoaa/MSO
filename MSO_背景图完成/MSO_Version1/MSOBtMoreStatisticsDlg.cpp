// MSOBtMoreStatisticsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreStatisticsDlg.h"
#include "afxdialogex.h"


// MSOBtMoreStatisticsDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtMoreStatisticsDlg, CDialogEx)

MSOBtMoreStatisticsDlg::MSOBtMoreStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreStatisticsDlg::IDD, pParent)
{

}

MSOBtMoreStatisticsDlg::~MSOBtMoreStatisticsDlg()
{
}

void MSOBtMoreStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreStatisticsDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_STATISTICS_STATISTICS, &MSOBtMoreStatisticsDlg::OnBnClickedButtonStatisticsStatistics)
END_MESSAGE_MAP()


// MSOBtMoreStatisticsDlg 消息处理程序
BOOL MSOBtMoreStatisticsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(1508,340,135,272);

	m_buttonMore_statistics_statistics.SubclassDlgItem(IDC_BUTTON_STATISTICS_STATISTICS,this); 
	OnInitButton(&m_buttonMore_statistics_statistics);
	m_buttonMore_statistics_statistics.SetWindowPos(NULL,7,40,127,71,SWP_NOZORDER);
	m_buttonMore_statistics_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_STATISTICS1,RGB(0,0,0));
	more_Statistics_Statistics=TRUE;

	m_buttonMore_statistics_averge.SubclassDlgItem(IDC_BUTTON_STATISTICS_AVERGE,this); 
	OnInitButton(&m_buttonMore_statistics_averge);
	m_buttonMore_statistics_averge.SetWindowPos(NULL,7,115,127,71,SWP_NOZORDER);
	m_buttonMore_statistics_averge.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_AVERGE,RGB(0,0,0));

	m_buttonMore_statistics_reset.SubclassDlgItem(IDC_BUTTON_STATISTICS_RESET,this); 
	OnInitButton(&m_buttonMore_statistics_reset);
	m_buttonMore_statistics_reset.SetWindowPos(NULL,7,190,127,71,SWP_NOZORDER);
	m_buttonMore_statistics_reset.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_RESET1,RGB(0,0,0));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtMoreStatisticsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORESTATISTICSDLGBK);  

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

//初始化CButtonSt，设置为透明，平铺，不显示边框
void  MSOBtMoreStatisticsDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}


void MSOBtMoreStatisticsDlg::OnBnClickedButtonStatisticsStatistics()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Statistics_Statistics = !more_Statistics_Statistics;;
	if (!more_Statistics_Statistics)
	{
		m_buttonMore_statistics_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_STATISTICS2,RGB(0,0,0));
		m_buttonMore_statistics_reset.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_RESET2,RGB(0,0,0));
	}
	else
	{
		m_buttonMore_statistics_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_STATISTICS1,RGB(0,0,0));
		m_buttonMore_statistics_reset.SetBitmaps(IDB_BITMAP_MORE_STATISTICS_RESET1,RGB(0,0,0));
	}
	m_buttonMore_statistics_statistics.Invalidate(TRUE);
}
