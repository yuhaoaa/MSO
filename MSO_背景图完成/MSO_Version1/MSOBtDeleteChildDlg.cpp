// MSOBtDeleteChildDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOBtDeleteChildDlg.h"
#include "afxdialogex.h"


// MSOBtDeleteChildDlg �Ի���

IMPLEMENT_DYNAMIC(MSOBtDeleteChildDlg, CDialogEx)

MSOBtDeleteChildDlg::MSOBtDeleteChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MSOBtDeleteChildDlg::IDD, pParent)
{

}

MSOBtDeleteChildDlg::~MSOBtDeleteChildDlg()
{
}

void MSOBtDeleteChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MSOBtDeleteChildDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MSOBtDeleteChildDlg ��Ϣ�������


BOOL MSOBtDeleteChildDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1508,340,135,420);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_button_Delete_DeleteAll.SubclassDlgItem(IDC_BUTTON_DELETE_DELETEALL,this); 
	OnInitButton(&m_button_Delete_DeleteAll);
	m_button_Delete_DeleteAll.SetWindowPos(NULL,7,40,127,71,SWP_NOZORDER);
	m_button_Delete_DeleteAll.SetBitmaps(IDB_BITMAP_DELETE_DELETEALL,RGB(0,0,0));

	m_button_Delete_Choose.SubclassDlgItem(IDC_BUTTON_DELETE_CHOOSE,this); 
	OnInitButton(&m_button_Delete_Choose);
	m_button_Delete_Choose.SetWindowPos(NULL,7,115,127,71,SWP_NOZORDER);
	m_button_Delete_Choose.SetBitmaps(IDB_BITMAP_DELETE_CHOOSE,RGB(0,0,0));

	m_button_Delete_Ok.SubclassDlgItem(IDC_BUTTON_DELETE_OK,this); 
	OnInitButton(&m_button_Delete_Ok);
	m_button_Delete_Ok.SetWindowPos(NULL,7,340,127,71,SWP_NOZORDER);
	m_button_Delete_Ok.SetBitmaps(IDB_BITMAP_DELETE_OK,RGB(0,0,0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MSOBtDeleteChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CBitmap bitmap;  
	bitmap.LoadBitmap(IDB_BITMAP_DELETECHILDDLGBK);  

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

void  MSOBtDeleteChildDlg::OnInitButton(CButtonST *button)
{
	button->DrawTransparent(TRUE);
	button->SetFlat(TRUE);
	button->DrawBorder(FALSE);
}