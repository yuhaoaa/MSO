#pragma once


// MSOBtMoreChooseDlg �Ի���

class MSOBtMoreChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreChooseDlg)

public:
	MSOBtMoreChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtMoreChooseDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTMORECHOOSEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
private:
	CButtonST m_buttonMore_Choose_Close;
	CButtonST m_buttonMore_Choose_Screen;
	CButtonST m_buttonMore_Choose_Cursor;
	CFont m_newFont;
};
