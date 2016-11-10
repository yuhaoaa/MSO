#pragma once


// MSOBtFreqChooseDlg 对话框

class MSOBtFreqChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtFreqChooseDlg)

public:
	MSOBtFreqChooseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtFreqChooseDlg();

// 对话框数据
	enum { IDD = IDD_MSOBTFREQCHOOSEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
