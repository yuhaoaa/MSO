#pragma once


// MSOBtMoreLevelDlg �Ի���

class MSOBtMoreLevelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreLevelDlg)

public:
	MSOBtMoreLevelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtMoreLevelDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTMORELEVELDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void OnInitButton(CButtonST *button);
private:
	CButtonST m_buttonMore_Level_SetLevel;
	BOOL more_Level_SetLevel;
	CButtonST m_buttonMore_Level_HighRefLevel;
	CButtonST m_buttonMore_Level_MedRefLevel;
	CButtonST m_buttonMore_Level_LowRefLevel;
	CButtonST m_buttonMore_Level_SetDefaultLevel;
public:
	afx_msg void OnBnClickedButtonMoreLevelSetlevel();
};
