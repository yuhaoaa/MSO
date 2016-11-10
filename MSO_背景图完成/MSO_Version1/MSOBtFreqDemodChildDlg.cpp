// MSOBtFreqDemodChildDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtFreqDemodChildDlg.h"
#include "afxdialogex.h"
#include "global.h"

// MSOBtFreqDemodChildDlg �Ի���

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


// MSOBtFreqDemodChildDlg ��Ϣ�������


BOOL MSOBtFreqDemodChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MoveWindow(1508,340,135,347);
	m_newFont.CreatePointFont(130, _T("����")); 

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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtFreqDemodChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_FREQDEMODCHILDDLGBK);  

	//ѡ��DC  
	//CClientDC cdc(this);   
	CDC comdc;  
	comdc.CreateCompatibleDC(&dc);  
	comdc.SelectObject(&bitmap);  

	//����BITMAP  
	BITMAP bit;  
	bitmap.GetBitmap(&bit);  

	//�ͻ�����  
	CRect rect;  
	GetClientRect(rect);  

	//�ÿͻ�����DC���������ɵ�BITMAP������ӦΪ���ڴ�С  
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&comdc,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY); 
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodPpeak()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freqflag = FREQPOSITIVE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNpeak()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freqflag = FREQNEGATIVE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodSample()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freqflag = FREQSAMPLE;
}


void MSOBtFreqDemodChildDlg::OnBnClickedButtonFreqdemodNomal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freqflag = FREQNOMAL;
}
