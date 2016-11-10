// MSOBtFreqChooseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtFreqChooseDlg.h"
#include "afxdialogex.h"


// MSOBtFreqChooseDlg �Ի���

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


// MSOBtFreqChooseDlg ��Ϣ�������


BOOL MSOBtFreqChooseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MoveWindow(1508,340,135,347);
	m_newFont.CreatePointFont(130, _T("����")); 

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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtFreqChooseDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_FREQCHOOSEDLGBK);  

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
