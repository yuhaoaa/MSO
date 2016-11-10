#pragma once


// MSOBtFreqDemodChildDlg �Ի���

class MSOBtFreqDemodChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtFreqDemodChildDlg)

public:
	MSOBtFreqDemodChildDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtFreqDemodChildDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTFREQDEMODCHILDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CButtonST m_buttonFreqDemod_PPeak;
	CButtonST m_buttonFreqDemod_NPeak;
	CButtonST m_buttonFreqDemod_Sample;
	CButtonST m_buttonFeqDemod_Nomal;
	CFont m_newFont;
public:
	afx_msg void OnBnClickedButtonFreqdemodPpeak();
	afx_msg void OnBnClickedButtonFreqdemodNpeak();
	afx_msg void OnBnClickedButtonFreqdemodSample();
	afx_msg void OnBnClickedButtonFreqdemodNomal();
};
