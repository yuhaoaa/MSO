#pragma once


// MSOBtFreqChooseDlg �Ի���

class MSOBtFreqChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtFreqChooseDlg)

public:
	MSOBtFreqChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtFreqChooseDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTFREQCHOOSEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CButtonST m_buttonFreq_NO;
	CButtonST m_buttonFreq_CP;
	CButtonST m_buttonFreq_ACPR;
	CButtonST m_buttonfreq_OBW;
	CFont m_newFont;
};
