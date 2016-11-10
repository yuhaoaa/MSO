// MSOBtMoreStatisticsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreStatisticsDlg.h"
#include "afxdialogex.h"


// MSOBtMoreStatisticsDlg �Ի���

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


// MSOBtMoreStatisticsDlg ��Ϣ�������
BOOL MSOBtMoreStatisticsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtMoreStatisticsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORESTATISTICSDLGBK);  

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

//��ʼ��CButtonSt������Ϊ͸����ƽ�̣�����ʾ�߿�
void  MSOBtMoreStatisticsDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}


void MSOBtMoreStatisticsDlg::OnBnClickedButtonStatisticsStatistics()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
