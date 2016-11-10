#pragma once
#include "MSOBtFreqDemodChildDlg.h"

// MSOFreqMainMenuDlg 对话框

class MSOFreqMainMenuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOFreqMainMenuDlg)

public:
	MSOFreqMainMenuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOFreqMainMenuDlg();

// 对话框数据
	enum { IDD = IDD_MSOFREQMAINMENUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	MSOBtFreqDemodChildDlg m_freqDemodCHildDlg;
private:
	CFont m_newFont;
	CButtonST m_buttonFreqLightTrack;
	CButtonST m_buttonFreqDemod;
	BOOL FreqDemod;
public:
	afx_msg void OnBnClickedButtonFreqdemod();
};
