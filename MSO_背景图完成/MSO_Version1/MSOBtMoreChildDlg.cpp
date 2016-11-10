// MSOBtMoreChildDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtMoreChildDlg.h"
#include "afxdialogex.h"


// MSOBtMoreChildDlg �Ի���

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


// MSOBtMoreChildDlg ��Ϣ�������


BOOL MSOBtMoreChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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

    //������ť���ӶԻ���
	m_MoreMethodDlg.Create(IDD_MSOBTMOREMETHODDLG,NULL);
	m_MoreStatisticsDlg.Create(IDD_MSOBTMORESTATISTICSDLG,NULL);
	m_MoreChooseDlg.Create(IDD_MSOBTMORECHOOSEDLG,NULL);
	m_MoreLevelDlg.Create(IDD_MSOBTMORELEVELDLG,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtMoreChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_MORECHILDDLG);  

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
void  MSOBtMoreChildDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}

void MSOBtMoreChildDlg::OnBnClickedButtonStatistics()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
