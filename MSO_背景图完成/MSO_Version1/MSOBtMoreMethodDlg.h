#pragma once


// MSOBtMoreMethodDlg �Ի���

class MSOBtMoreMethodDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreMethodDlg)

public:
	MSOBtMoreMethodDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtMoreMethodDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTMOREMETHODDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CButtonST m_buttonMore_Method_AutoChoose;
	CButtonST m_buttonMore_Method_Histogram;
	CButtonST m_buttonMore_Method_Mintomax;
	CFont m_newFont;
};
