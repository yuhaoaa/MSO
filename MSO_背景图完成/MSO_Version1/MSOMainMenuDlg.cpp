// MSOMainMenuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOMainMenuDlg.h"
#include "afxdialogex.h"


// MSOMainMenuDlg 对话框

IMPLEMENT_DYNAMIC(MSOMainMenuDlg, CDialog)

MSOMainMenuDlg::MSOMainMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOMainMenuDlg::IDD, pParent)
{

}

MSOMainMenuDlg::~MSOMainMenuDlg()
{
}

void MSOMainMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOMainMenuDlg, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHOOSEDOMAIN, &MSOMainMenuDlg::OnBnClickedChoosedomain)
	ON_BN_CLICKED(IDC_ADDMEASURE, &MSOMainMenuDlg::OnBnClickedAddmeasure)
	ON_BN_CLICKED(IDC_DELETEMEASURE, &MSOMainMenuDlg::OnBnClickedDeletemeasure)
	ON_BN_CLICKED(IDC_HISTOGRAM, &MSOMainMenuDlg::OnBnClickedHistogram)
	ON_BN_CLICKED(IDC_MORE, &MSOMainMenuDlg::OnBnClickedMore)
	ON_BN_CLICKED(IDC_FREQCHOOSE, &MSOMainMenuDlg::OnBnClickedFreqchoose)
END_MESSAGE_MAP()


// MSOMainMenuDlg 消息处理程序


void MSOMainMenuDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CRect   rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(57,73,148));  //修改颜色，便于调试RGB(57,73,148)
	
}


BOOL MSOMainMenuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//MoveWindow(280,849,1021,54);
	
	m_buttonChooseDomain.SubclassDlgItem(IDC_CHOOSEDOMAIN,this); 
	OnInitButton(&m_buttonChooseDomain);
	m_buttonChooseDomain.SetWindowPos(NULL,80,0,113,54,SWP_NOZORDER);
	m_buttonChooseDomain.SetBitmaps(IDB_BITMAP_CHOOSEDOMAIN1,RGB(0,0,0));
	ChooseDomain=TRUE;

	m_buttonAddMeasure.SubclassDlgItem(IDC_ADDMEASURE,this);
	OnInitButton(&m_buttonAddMeasure);
	m_buttonAddMeasure.SetWindowPos(NULL,224,0,114,55,SWP_NOZORDER);
	m_buttonAddMeasure.SetBitmaps(IDB_BITMAP_ADDMEASURE1,RGB(0,0,0));
	AddMeasure = TRUE;

	m_buttondeleteMeasure.SubclassDlgItem(IDC_DELETEMEASURE,this);
	OnInitButton(&m_buttondeleteMeasure);
	m_buttondeleteMeasure.SetWindowPos(NULL,368,0,114,55,SWP_NOZORDER);
	m_buttondeleteMeasure.SetBitmaps(IDB_BITMAP_DELETEMEASURE1,RGB(0,0,0));
	DeleteMeasure = TRUE;

	m_buttonIndicator.SubclassDlgItem(IDC_INDICATOR,this);
	OnInitButton(&m_buttonIndicator);
	m_buttonIndicator.SetWindowPos(NULL,512,0,114,55,SWP_NOZORDER);
	m_buttonIndicator.SetBitmaps(IDB_BITMAP_INDICATOR1,RGB(0,0,0));

	m_buttonHistogram.SubclassDlgItem(IDC_HISTOGRAM,this);
	OnInitButton(&m_buttonHistogram);
	m_buttonHistogram.SetWindowPos(NULL,656,0,114,55,SWP_NOZORDER);
	m_buttonHistogram.SetBitmaps(IDB_BITMAP_HISTOGRAM1,RGB(0,0,0));
	Histogram=TRUE;

	m_buttonMore.SubclassDlgItem(IDC_MORE,this);
	OnInitButton(&m_buttonMore);
	m_buttonMore.SetWindowPos(NULL,800,0,114,55,SWP_NOZORDER);
	m_buttonMore.SetBitmaps(IDB_BITMAP_MORE,RGB(0,0,0));

	m_buttonShowCursorInScr.SubclassDlgItem(IDC_SHOWCURSORINSCR,this);
	OnInitButton(&m_buttonShowCursorInScr);
	m_buttonShowCursorInScr.SetWindowPos(NULL,944,0,114,55,SWP_NOZORDER);
	m_buttonShowCursorInScr.SetBitmaps(IDB_BITMAP_SHOWCURSORINSCR,RGB(0,0,0));

	//选择频域时的按钮
	m_buttonFreqChoose.SubclassDlgItem(IDC_FREQCHOOSE,this);
	OnInitButton(&m_buttonFreqChoose);
	m_buttonFreqChoose.SetWindowPos(NULL,224,0,117,55,SWP_HIDEWINDOW);
	m_buttonFreqChoose.SetBitmaps(IDB_BITMAP_FREQCHOOSE1,RGB(0,0,0));
	FreqChoose=TRUE;

	m_BtMoreChildDlg.Create(IDD_MSOBTMORECHILDDLG,NULL);   //创建More按钮的子窗口 NULL-无父窗口，如果为this的话，必须关闭子窗口后才能操作父窗口
	m_BtHistogramDlg.Create(IDD_MSOBTHISTOGRAMDLG,NULL);
	m_BtDeleteChildDlg.Create(IDD_MSOBTDELETECHILDDLG,NULL);
	m_BtFreqChooseDlg.Create(IDD_MSOBTFREQCHOOSEDLG,NULL);
;	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//初始化CButtonSt，设置为透明，平铺，不显示边框
void MSOMainMenuDlg::OnInitButton(CButtonST *button)
{
	 button->DrawTransparent(TRUE);
	 button->SetFlat(TRUE);
	 button->DrawBorder(FALSE);
}

void MSOMainMenuDlg::OnBnClickedChoosedomain()
{
	// TODO: 在此添加控件通知处理程序代码
	ChooseDomain= !ChooseDomain;
	if (!ChooseDomain)
	{
		m_buttonChooseDomain.SetBitmaps(IDB_BITMAP_CHOOSEDOMAIN2,RGB(0,0,0));  
		m_buttonAddMeasure.ShowWindow(SW_HIDE);
		m_buttondeleteMeasure.ShowWindow(SW_HIDE);
		m_buttonIndicator.ShowWindow(SW_HIDE);
		m_buttonHistogram.ShowWindow(SW_HIDE);
		m_buttonMore.ShowWindow(SW_HIDE);
		m_buttonShowCursorInScr.ShowWindow(SW_HIDE);
		m_buttonFreqChoose.ShowWindow(SW_SHOW);

	}
	else
	{	
		m_buttonChooseDomain.SetBitmaps(IDB_BITMAP_CHOOSEDOMAIN1,RGB(0,0,0)); 
		m_buttonAddMeasure.ShowWindow(SW_SHOW);
		m_buttondeleteMeasure.ShowWindow(SW_SHOW);
		m_buttonIndicator.ShowWindow(SW_SHOW);
		m_buttonHistogram.ShowWindow(SW_SHOW);
		m_buttonMore.ShowWindow(SW_SHOW);
		m_buttonShowCursorInScr.ShowWindow(SW_SHOW);
		m_buttonFreqChoose.ShowWindow(SW_HIDE);

		m_BtFreqChooseDlg.ShowWindow(SW_HIDE);
		m_buttonFreqChoose.SetBitmaps(IDB_BITMAP_FREQCHOOSE1,RGB(0,0,0));
		FreqChoose = TRUE;
	}
	m_buttonChooseDomain.Invalidate(TRUE);
}


void MSOMainMenuDlg::OnBnClickedAddmeasure()
{
	// TODO: 在此添加控件通知处理程序代码
	AddMeasure=!AddMeasure;
	if(!AddMeasure)
	{
		m_buttonAddMeasure.SetBitmaps(IDB_BITMAP_ADDMEASURE2,RGB(0,0,0));
	}
	else
	{
		m_buttonAddMeasure.SetBitmaps(IDB_BITMAP_ADDMEASURE1,RGB(0,0,0));
	}
	m_buttonAddMeasure.Invalidate(TRUE);
}


void MSOMainMenuDlg::OnBnClickedDeletemeasure()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteMeasure =!DeleteMeasure;
	if (!DeleteMeasure)
	{
		m_buttondeleteMeasure.SetBitmaps(IDB_BITMAP_DELETEMEASURE2,RGB(0,0,0));

		m_BtDeleteChildDlg.ShowWindow(SW_SHOW);
		m_BtHistogramDlg.ShowWindow(SW_HIDE);
	    Histogram = TRUE;
		m_buttonHistogram.SetBitmaps(IDB_BITMAP_HISTOGRAM1,RGB(0,0,0));
		m_BtMoreChildDlg.ShowWindow(SW_HIDE);
	}
	else
	{
		m_buttondeleteMeasure.SetBitmaps(IDB_BITMAP_DELETEMEASURE1,RGB(0,0,0));
		m_BtDeleteChildDlg.ShowWindow(SW_HIDE);
	}
	m_buttondeleteMeasure.Invalidate(TRUE);
}


void MSOMainMenuDlg::OnBnClickedHistogram()
{
	// TODO: 在此添加控件通知处理程序代码
	Histogram=!Histogram;
	if (!Histogram)
	{
		m_buttonHistogram.SetBitmaps(IDB_BITMAP_HISTOGRAM2,RGB(0,0,0));

		m_BtHistogramDlg.ShowWindow(SW_SHOW);
		m_BtDeleteChildDlg.ShowWindow(SW_HIDE);
		DeleteMeasure = TRUE;
		m_buttondeleteMeasure.SetBitmaps(IDB_BITMAP_DELETEMEASURE1,RGB(0,0,0));
		m_BtMoreChildDlg.ShowWindow(SW_HIDE);
	}
	else
	{
		m_buttonHistogram.SetBitmaps(IDB_BITMAP_HISTOGRAM1,RGB(0,0,0));
		m_BtHistogramDlg.ShowWindow(SW_HIDE);
	}
	m_buttonHistogram.Invalidate(TRUE);
}

void MSOMainMenuDlg::OnBnClickedMore()
{
	if (!m_BtMoreChildDlg.IsWindowVisible())
	{	
		m_BtMoreChildDlg.ShowWindow(SW_SHOW);
		m_BtDeleteChildDlg.ShowWindow(SW_HIDE);
		DeleteMeasure = TRUE;
		m_buttondeleteMeasure.SetBitmaps(IDB_BITMAP_DELETEMEASURE1,RGB(0,0,0));
		m_BtHistogramDlg.ShowWindow(SW_HIDE);
		Histogram = TRUE;
		m_buttonHistogram.SetBitmaps(IDB_BITMAP_HISTOGRAM1,RGB(0,0,0));
	}
	else
	{
		m_BtMoreChildDlg.ShowWindow(SW_HIDE);
	}
}

void MSOMainMenuDlg::OnBnClickedFreqchoose()
{
	// TODO: 在此添加控件通知处理程序代码
	FreqChoose=!FreqChoose;
	if (!FreqChoose)
	{
		m_buttonFreqChoose.SetBitmaps(IDB_BITMAP_FREQCHOOSE2,RGB(0,0,0));
		m_BtFreqChooseDlg.ShowWindow(SW_SHOW);
	}
	else
	{
		m_buttonFreqChoose.SetBitmaps(IDB_BITMAP_FREQCHOOSE1,RGB(0,0,0));
		m_BtFreqChooseDlg.ShowWindow(SW_HIDE);
	}
	m_buttonFreqChoose.Invalidate(TRUE);
}
