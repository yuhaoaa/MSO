// MSOBtMoreChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreChildDlg.h"
#include "afxdialogex.h"


// MSOBtMoreChildDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtMoreChildDlg, CDialogEx)

MSOBtMoreChildDlg::MSOBtMoreChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreChildDlg::IDD, pParent)
{

}

MSOBtMoreChildDlg::~MSOBtMoreChildDlg()
{
}

void MSOBtMoreChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreChildDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_STATISTICS, &MSOBtMoreChildDlg::OnBnClickedButtonStatistics)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSE, &MSOBtMoreChildDlg::OnBnClickedButtonChoose)
	ON_BN_CLICKED(IDC_BUTTON_LEVEL, &MSOBtMoreChildDlg::OnBnClickedButtonLevel)
	ON_BN_CLICKED(IDC_BUTTON_METHOD, &MSOBtMoreChildDlg::OnBnClickedButtonMethod)
END_MESSAGE_MAP()


// MSOBtMoreChildDlg 消息处理程序


BOOL MSOBtMoreChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(1078,687,120,163);
	m_buttonMore_statistics.SubclassDlgItem(IDC_BUTTON_STATISTICS,this); 
	OnInitButton(&m_buttonMore_statistics);
	m_buttonMore_statistics.SetWindowPos(NULL,5,5,110,37,SWP_NOZORDER);
	m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS1,RGB(0,0,0));
	more_Statistics=TRUE;

	 m_buttonMore_choose.SubclassDlgItem(IDC_BUTTON_CHOOSE,this);
	 OnInitButton(&m_buttonMore_choose);
	 m_buttonMore_choose.SetWindowPos(NULL,3,44,112,37,SWP_NOZORDER);
	 m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE1,RGB(0,0,0));
	 more_Choose=TRUE;

	 m_buttonMore_level.SubclassDlgItem(IDC_BUTTON_LEVEL,this); 
	 OnInitButton(&m_buttonMore_level);
	 m_buttonMore_level.SetWindowPos(NULL,3,83,112,37,SWP_NOZORDER);
	 m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL1,RGB(0,0,0));
	 more_Level=TRUE;

	 m_buttonMore_method.SubclassDlgItem(IDC_BUTTON_METHOD,this); 
	 OnInitButton(&m_buttonMore_method);
	 m_buttonMore_method.SetWindowPos(NULL,3,123,112,37,SWP_NOZORDER);
	 m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD1,RGB(0,0,0));
	 more_Method=TRUE;

    //创建按钮的子对话框
	m_MoreMethodDlg.Create(IDD_MSOBTMOREMETHODDLG,NULL);
	m_MoreStatisticsDlg.Create(IDD_MSOBTMORESTATISTICSDLG,NULL);
	m_MoreChooseDlg.Create(IDD_MSOBTMORECHOOSEDLG,NULL);
	m_MoreLevelDlg.Create(IDD_MSOBTMORELEVELDLG,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtMoreChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORECHILDDLG);  

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
void  MSOBtMoreChildDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}

void MSOBtMoreChildDlg::OnBnClickedButtonStatistics()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Statistics = !more_Statistics;
	if(!more_Statistics)
	{
		m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS2,RGB(0,0,0));
		m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE1,RGB(0,0,0));
		more_Choose =TRUE;
		m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL1,RGB(0,0,0));
		more_Level=TRUE;
		m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD1,RGB(0,0,0));
		more_Method=TRUE;

		m_MoreStatisticsDlg.ShowWindow(SW_SHOW);
		m_MoreChooseDlg.ShowWindow(SW_HIDE);
		m_MoreLevelDlg.ShowWindow(SW_HIDE);
		m_MoreMethodDlg.ShowWindow(SW_HIDE);
	}
	else
	{
		m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS1,RGB(0,0,0));

		m_MoreStatisticsDlg.ShowWindow(SW_HIDE);
	}
	m_buttonMore_statistics.Invalidate(TRUE);
}


void MSOBtMoreChildDlg::OnBnClickedButtonChoose()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Choose = !more_Choose;
	if(!more_Choose)
	{
		m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE2,RGB(0,0,0));
		m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS1,RGB(0,0,0));
		more_Statistics=TRUE;
		m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL1,RGB(0,0,0));
		more_Level=TRUE;
		m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD1,RGB(0,0,0));
		more_Method=TRUE;

		m_MoreChooseDlg.ShowWindow(SW_SHOW);
		m_MoreStatisticsDlg.ShowWindow(SW_HIDE);
		m_MoreLevelDlg.ShowWindow(SW_HIDE);
		m_MoreMethodDlg.ShowWindow(SW_HIDE);
	}
	else
	{
		m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE1,RGB(0,0,0));
		m_MoreChooseDlg.ShowWindow(SW_HIDE);
	}
	m_buttonMore_choose.Invalidate(TRUE);
}


void MSOBtMoreChildDlg::OnBnClickedButtonLevel()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Level=!more_Level;
	if(!more_Level)
	{
		 m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL2,RGB(0,0,0));
		 m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS1,RGB(0,0,0));
		 more_Statistics=TRUE;
		 m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE1,RGB(0,0,0));
		 more_Choose=TRUE;
		 m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD1,RGB(0,0,0));
		 more_Method=TRUE;

		 m_MoreLevelDlg.ShowWindow(SW_SHOW);
		 m_MoreChooseDlg.ShowWindow(SW_HIDE);
		 m_MoreStatisticsDlg.ShowWindow(SW_HIDE);
		 m_MoreMethodDlg.ShowWindow(SW_HIDE);
	}
	else
	{
		 m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL1,RGB(0,0,0));
		  m_MoreLevelDlg.ShowWindow(SW_HIDE);
	}
	m_buttonMore_level.Invalidate(TRUE);
}


void MSOBtMoreChildDlg::OnBnClickedButtonMethod()
{
	// TODO: 在此添加控件通知处理程序代码
	more_Method = !more_Method;
	if (!more_Method)
	{
		m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD2,RGB(0,0,0));
		m_buttonMore_statistics.SetBitmaps(IDB_BITMAP_MORE_STATISTICS1,RGB(0,0,0));
		more_Statistics=TRUE;
		m_buttonMore_choose.SetBitmaps(IDB_BITMAP_MORE_CHOOSE1,RGB(0,0,0));
		more_Choose=TRUE;
		m_buttonMore_level.SetBitmaps(IDB_BITMAP_MORE_LEVEL1,RGB(0,0,0));
		more_Level=TRUE;

		m_MoreMethodDlg.ShowWindow(SW_SHOW);
		m_MoreLevelDlg.ShowWindow(SW_HIDE);
		m_MoreChooseDlg.ShowWindow(SW_HIDE);
		m_MoreStatisticsDlg.ShowWindow(SW_HIDE);		
	}
	else
	{
		m_buttonMore_method.SetBitmaps(IDB_BITMAP_MORE_METHOD1,RGB(0,0,0));
		m_MoreMethodDlg.ShowWindow(SW_HIDE);
	}
	m_buttonMore_method.Invalidate(TRUE);
}
