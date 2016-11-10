// MSOFreqMainMenuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOFreqMainMenuDlg.h"
#include "afxdialogex.h"
#include "global.h"

// MSOFreqMainMenuDlg �Ի���

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


// MSOFreqMainMenuDlg ��Ϣ�������


BOOL MSOFreqMainMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_newFont.CreatePointFont(130, _T("����")); 
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOFreqMainMenuDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(57,73,148));  

	dc.SelectObject(m_newFont);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255,255,255));

	dc.TextOut(512,10,_T("Ƶ��"));
	dc.TextOut(504,30,_T("�Ѵ���"));

}


void MSOFreqMainMenuDlg::OnBnClickedButtonFreqdemod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
