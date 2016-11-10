// MSOBtMoreMethodDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreMethodDlg.h"
#include "afxdialogex.h"


// MSOBtMoreMethodDlg �Ի���

IMPLEMENT_DYNAMIC(MSOBtMoreMethodDlg, CDialogEx)

MSOBtMoreMethodDlg::MSOBtMoreMethodDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtMoreMethodDlg::IDD, pParent)
{

}

MSOBtMoreMethodDlg::~MSOBtMoreMethodDlg()
{
}

void MSOBtMoreMethodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtMoreMethodDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtMoreMethodDlg ��Ϣ�������


BOOL MSOBtMoreMethodDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MoveWindow(1508,340,135,272);//style����Ϊchild��������������1366*768�ģ������������������Ļ,���ǻᱻ�ڵ�����û�ҵ�����������û��child
	m_newFont.CreatePointFont(130, _T("����")); 

	m_buttonMore_Method_Mintomax.SubclassDlgItem(IDC_BUTTON_MOREMINTOMAX,this);
	m_buttonMore_Method_Mintomax.SetFlat(TRUE);
	m_buttonMore_Method_Mintomax.DrawBorder(FALSE);
	m_buttonMore_Method_Mintomax.SetWindowPos(NULL,25,196,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREMINTOMAX)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_Mintomax.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));
	
	m_buttonMore_Method_Histogram.SubclassDlgItem(IDC_BUTTON_MOREHISTOGRAM,this);
	m_buttonMore_Method_Histogram.SetFlat(TRUE);
	m_buttonMore_Method_Histogram.DrawBorder(FALSE);
	m_buttonMore_Method_Histogram.SetWindowPos(NULL,25,124,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREHISTOGRAM)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_Histogram.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));

	m_buttonMore_Method_AutoChoose.SubclassDlgItem(IDC_BUTTON_MOREAUTOCHOOSE,this);
	//m_buttonMore_Method_AutoChoose.DrawTransparent(TRUE);
	m_buttonMore_Method_AutoChoose.SetFlat(TRUE);
	m_buttonMore_Method_AutoChoose.DrawBorder(FALSE);
	m_buttonMore_Method_AutoChoose.SetWindowPos(NULL,25,52,96,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_MOREAUTOCHOOSE)->SetFont(&m_newFont);//ID
	m_buttonMore_Method_AutoChoose.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(82,134,231));


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtMoreMethodDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MOREMETHODDLGBK);  

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
