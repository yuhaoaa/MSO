// MSOBtHistogramDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtHistogramDlg.h"
#include "afxdialogex.h"


// MSOBtHistogramDlg �Ի���

IMPLEMENT_DYNAMIC(MSOBtHistogramDlg, CDialogEx)

MSOBtHistogramDlg::MSOBtHistogramDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtHistogramDlg::IDD, pParent)
{

}

MSOBtHistogramDlg::~MSOBtHistogramDlg()
{
}

void MSOBtHistogramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtHistogramDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_HISTOGRAM_HIST, &MSOBtHistogramDlg::OnBnClickedButtonHistogramHist)
	ON_BN_CLICKED(IDC_BUTTON_HISTOGRAM_PAGE1, &MSOBtHistogramDlg::OnBnClickedButtonHistogramPage1)
	ON_BN_CLICKED(IDC_BUTTON_HISTOGRAM_SHOW, &MSOBtHistogramDlg::OnBnClickedButtonHistogramShow)
	ON_BN_CLICKED(IDC_BUTTON_HISTOGRAM_PAGE2, &MSOBtHistogramDlg::OnBnClickedButtonHistogramPage2)
END_MESSAGE_MAP()


// MSOBtHistogramDlg ��Ϣ�������


BOOL MSOBtHistogramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1508,340,135,420);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_buttonHistogram_Hist.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_HIST,this); 
	OnInitButton(&m_buttonHistogram_Hist);
	m_buttonHistogram_Hist.SetWindowPos(NULL,7,40,127,71,SWP_NOZORDER);
	m_buttonHistogram_Hist.SetBitmaps(IDB_BITMAP_HISTOGRAM_HIST1,RGB(0,0,0));
	Histogram_hist = 1;

	m_buttonHistogram_Source.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_SOURCE,this); 
	OnInitButton(&m_buttonHistogram_Source);
	m_buttonHistogram_Source.SetWindowPos(NULL,7,115,127,71,SWP_NOZORDER);
	m_buttonHistogram_Source.SetBitmaps(IDB_BITMAP_HISTOGRAM_SOURCE,RGB(0,0,0));

	m_buttonHistogram_StandardLimit.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_STANDARDLIMIT,this); 
	OnInitButton(&m_buttonHistogram_StandardLimit);
	m_buttonHistogram_StandardLimit.SetWindowPos(NULL,7,190,127,71,SWP_NOZORDER);
	m_buttonHistogram_StandardLimit.SetBitmaps(IDB_BITMAP_HISTOGRAM_STANDRADLIMIT,RGB(0,0,0));

	m_buttonHistogram_VerticalLimit.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_VERTICALLIMIT,this); 
	OnInitButton(&m_buttonHistogram_VerticalLimit);
	m_buttonHistogram_VerticalLimit.SetWindowPos(NULL,7,265,127,71,SWP_NOZORDER);
	m_buttonHistogram_VerticalLimit.SetBitmaps(IDB_BITMAP_HISTOGRAM_VERTICALLIMIT,RGB(0,0,0));

	m_buttonHistogram_Page1.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_PAGE1,this); 
	OnInitButton(&m_buttonHistogram_Page1);
	m_buttonHistogram_Page1.SetWindowPos(NULL,7,340,127,71,SWP_NOZORDER);
	m_buttonHistogram_Page1.SetBitmaps(IDB_BITMAP_HISTOGRAM_PAGE1,RGB(0,0,0));

	//�ڶ�ҳ�Ĳ˵���
	m_buttonHistogram_Show.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_SHOW,this); 
	OnInitButton(&m_buttonHistogram_Show);
	m_buttonHistogram_Show.SetWindowPos(NULL,7,40,127,71,SWP_HIDEWINDOW);
	m_buttonHistogram_Show.SetBitmaps(IDB_BITMAP_HISTOGRAM_SHOW1,RGB(0,0,0));
	histogramShow = TRUE;

	m_buttonHistogram_Reset.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_RESET,this); 
	OnInitButton(&m_buttonHistogram_Reset);
	m_buttonHistogram_Reset.SetWindowPos(NULL,7,115,127,71,SWP_HIDEWINDOW);
	m_buttonHistogram_Reset.SetBitmaps(IDB_BITMAP_HISTOGRAM_RESET,RGB(0,0,0));

	m_buttonHistogram_Page2.SubclassDlgItem(IDC_BUTTON_HISTOGRAM_PAGE2,this); 
	OnInitButton(&m_buttonHistogram_Page2);
	m_buttonHistogram_Page2.SetWindowPos(NULL,7,340,127,71,SWP_HIDEWINDOW);
	m_buttonHistogram_Page2.SetBitmaps(IDB_BITMAP_HISTOGRAM_PAGE2,RGB(0,0,0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtHistogramDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_HISTOGRAMHISDLGBK);  

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

void  MSOBtHistogramDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}

void MSOBtHistogramDlg::OnBnClickedButtonHistogramHist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (Histogram_hist>=3)
	{
		Histogram_hist=0;
	}
	while(Histogram_hist<=2)
	{
		if(Histogram_hist==0)
      	{
		      m_buttonHistogram_Hist.SetBitmaps(IDB_BITMAP_HISTOGRAM_HIST1,RGB(0,0,0));
			  break;
	     }
	    else if (Histogram_hist==1)
	    {
		      m_buttonHistogram_Hist.SetBitmaps(IDB_BITMAP_HISTOGRAM_HIST2,RGB(0,0,0));
			  break;
	    }
	     else if (Histogram_hist==2)
	    {
		     m_buttonHistogram_Hist.SetBitmaps(IDB_BITMAP_HISTOGRAM_HIST3,RGB(0,0,0));
			 break;
	    }
	}
	m_buttonHistogram_Hist.Invalidate(TRUE);
	Histogram_hist++;
}


void MSOBtHistogramDlg::OnBnClickedButtonHistogramPage1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_HIST)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_SOURCE)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_STANDARDLIMIT)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_VERTICALLIMIT)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_PAGE1)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_SHOW)->ShowWindow(TRUE);
    (CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_RESET)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_PAGE2)->ShowWindow(TRUE);
}


void MSOBtHistogramDlg::OnBnClickedButtonHistogramShow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	histogramShow = !histogramShow;
	if (!histogramShow)
	{
		m_buttonHistogram_Show.SetBitmaps(IDB_BITMAP_HISTOGRAM_SHOW2,RGB(0,0,0));
	}
	else
	{
		m_buttonHistogram_Show.SetBitmaps(IDB_BITMAP_HISTOGRAM_SHOW1,RGB(0,0,0));
	}
	m_buttonHistogram_Show.Invalidate(TRUE);
}


void MSOBtHistogramDlg::OnBnClickedButtonHistogramPage2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_HIST)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_SOURCE)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_STANDARDLIMIT)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_VERTICALLIMIT)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_PAGE1)->ShowWindow(TRUE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_SHOW)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_RESET)->ShowWindow(FALSE);
	(CButton *)GetDlgItem(IDC_BUTTON_HISTOGRAM_PAGE2)->ShowWindow(FALSE);
}
