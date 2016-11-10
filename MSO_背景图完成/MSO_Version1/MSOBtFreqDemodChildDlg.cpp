// MSOBtFreqDemodChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtFreqDemodChildDlg.h"
#include "afxdialogex.h"
#include "global.h"

// MSOBtFreqDemodChildDlg 对话框

IMPLEMENT_DYNAMIC(MSOBtFreqDemodChildDlg, CDialogEx)

MSOBtFreqDemodChildDlg::MSOBtFreqDemodChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtFreqDemodChildDlg::IDD, pParent)
{

}

MSOBtFreqDemodChildDlg::~MSOBtFreqDemodChildDlg()
{
}

void MSOBtFreqDemodChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtFreqDemodChildDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_FREQDEMOD_PPEAK, &MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodPpeak)
	ON_BN_CLICKED(IDC_BUTTON_FREQDEMOD_NPEAK, &MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNpeak)
	ON_BN_CLICKED(IDC_BUTTON_FREQDEMOD_SAMPLE, &MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodSample)
	ON_BN_CLICKED(IDC_BUTTON_FREQDEMOD_NOMAL, &MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNomal)
END_MESSAGE_MAP()


// MSOBtFreqDemodChildDlg 消息处理程序


BOOL MSOBtFreqDemodChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(1508,340,135,347);
	m_newFont.CreatePointFont(130, _T("宋体")); 

	m_buttonFreqDemod_PPeak.SubclassDlgItem(IDC_BUTTON_FREQDEMOD_PPEAK,this);
	m_buttonFreqDemod_PPeak.SetFlat(TRUE);
	m_buttonFreqDemod_PPeak.DrawBorder(FALSE);
	m_buttonFreqDemod_PPeak.SetWindowPos(NULL,25,52,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQDEMOD_PPEAK)->SetFont(&m_newFont);//ID
	m_buttonFreqDemod_PPeak.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFreqDemod_NPeak.SubclassDlgItem(IDC_BUTTON_FREQDEMOD_NPEAK,this);
	m_buttonFreqDemod_NPeak.SetFlat(TRUE);
	m_buttonFreqDemod_NPeak.DrawBorder(FALSE);
	m_buttonFreqDemod_NPeak.SetWindowPos(NULL,25,124,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQDEMOD_NPEAK)->SetFont(&m_newFont);//ID
	m_buttonFreqDemod_NPeak.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFreqDemod_Sample.SubclassDlgItem(IDC_BUTTON_FREQDEMOD_SAMPLE,this);
	m_buttonFreqDemod_Sample.SetFlat(TRUE);
	m_buttonFreqDemod_Sample.DrawBorder(FALSE);
	m_buttonFreqDemod_Sample.SetWindowPos(NULL,25,196,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQDEMOD_SAMPLE)->SetFont(&m_newFont);//ID
	m_buttonFreqDemod_Sample.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonFeqDemod_Nomal.SubclassDlgItem(IDC_BUTTON_FREQDEMOD_NOMAL,this);
	m_buttonFeqDemod_Nomal.SetFlat(TRUE);
	m_buttonFeqDemod_Nomal.DrawBorder(FALSE);
	m_buttonFeqDemod_Nomal.SetWindowPos(NULL,25,268,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_FREQDEMOD_NOMAL)->SetFont(&m_newFont);//ID
	m_buttonFeqDemod_Nomal.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOBtFreqDemodChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_FREQDEMODCHILDDLGBK);  

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


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodPpeak()
{
	// TODO: 在此添加控件通知处理程序代码
	freqflag = FREQPOSITIVE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNpeak()
{
	// TODO: 在此添加控件通知处理程序代码
	freqflag = FREQNEGATIVE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodSample()
{
	// TODO: 在此添加控件通知处理程序代码
	freqflag = FREQSAMPLE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNomal()
{
	// TODO: 在此添加控件通知处理程序代码
	freqflag = FREQNOMAL;
}
