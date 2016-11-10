// MSOFreqMainMenuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOFreqMainMenuDlg.h"
#include "afxdialogex.h"
#include "global.h"

// MSOFreqMainMenuDlg 对话框

IMPLEMENT_DYNAMIC(MSOFreqMainMenuDlg, CDialogEx)

MSOFreqMainMenuDlg::MSOFreqMainMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOFreqMainMenuDlg::IDD, pParent)
{

}

MSOFreqMainMenuDlg::~MSOFreqMainMenuDlg()
{
}

void MSOFreqMainMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOFreqMainMenuDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_FREQDEMOD, &MSOFreqMainMenuDlg::OnBnClickedButtonFreqdemod)
END_MESSAGE_MAP()


// MSOFreqMainMenuDlg 消息处理程序


BOOL MSOFreqMainMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_newFont.CreatePointFont(130, _T("宋体")); 
	// TODO:  在此添加额外的初始化
	m_buttonFreqLightTrack.SubclassDlgItem(IDC_BUTTON_FREQLIGHTTRACK,this);
	m_buttonFreqLightTrack.DrawTransparent(TRUE);
	m_buttonFreqLightTrack.SetFlat(TRUE);
	m_buttonFreqLightTrack.DrawBorder(FALSE);
	m_buttonFreqLightTrack.SetWindowPos(NULL,80,1,116,55,SWP_NOZORDER);
	m_buttonFreqLightTrack.SetBitmaps(IDB_BITMAP_FREQLIGHTTRACK1,RGB(0,0,0));

	m_buttonFreqDemod.SubclassDlgItem(IDC_BUTTON_FREQDEMOD,this);
	m_buttonFreqDemod.DrawTransparent(TRUE);
	m_buttonFreqDemod.SetFlat(TRUE);
	m_buttonFreqDemod.DrawBorder(FALSE);
	m_buttonFreqDemod.SetWindowPos(NULL,656,1,117,55,SWP_NOZORDER);
	m_buttonFreqDemod.SetBitmaps(IDB_BITMAP_FREQDEMOD1,RGB(0,0,0));
	FreqDemod=TRUE;

	m_freqDemodCHildDlg.Create(IDD_MSOBTFREQDEMODCHILDDLG,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MSOFreqMainMenuDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(57,73,148));  

	dc.SelectObject(m_newFont);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255,255,255));

	dc.TextOut(512,10,_T("频谱"));
	dc.TextOut(504,30,_T("已触发"));

}


void MSOFreqMainMenuDlg::OnBnClickedButtonFreqdemod()
{
	// TODO: 在此添加控件通知处理程序代码
	FreqDemod = !FreqDemod;
	if (!FreqDemod)
	{
		m_buttonFreqDemod.SetBitmaps(IDB_BITMAP_FREQDEMOD2,RGB(0,0,0));
		m_freqDemodCHildDlg.ShowWindow(SW_SHOW);
	}
	else
	{
		m_buttonFreqDemod.SetBitmaps(IDB_BITMAP_FREQDEMOD1,RGB(0,0,0));
		m_freqDemodCHildDlg.ShowWindow(SW_HIDE);
	}
	m_buttonFreqDemod.Invalidate(TRUE);
}
