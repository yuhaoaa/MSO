#pragma once
#include "MSOBtMoreStatisticsDlg.h"
#include "MSOBtMoreChooseDlg.h"
#include "MSOBtMoreLevelDlg.h"
#include "MSOBtMoreMethodDlg.h"

// MSOBtMoreChildDlg 对话框

class MSOBtMoreChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreChildDlg)

public:
	MSOBtMoreChildDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtMoreChildDlg();
	MSOBtMoreStatisticsDlg m_MoreStatisticsDlg;
	MSOBtMoreChooseDlg m_MoreChooseDlg;
	MSOBtMoreLevelDlg m_MoreLevelDlg;
	MSOBtMoreMethodDlg m_MoreMethodDlg;

// 对话框数据
	enum { IDD = IDD_MSOBTMORECHILDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void OnInitButton(CButtonST *button);
	afx_msg void OnPaint();
private:
	CButtonST m_buttonMore_statistics;
	BOOL more_Statistics;
	CButtonST m_buttonMore_choose;
	BOOL more_Choose;
	CButtonST  m_buttonMore_level;
	BOOL more_Level;
	CButtonST  m_buttonMore_method;
	BOOL more_Method;
public:
	afx_msg void OnBnClickedButtonStatistics();
	afx_msg void OnBnClickedButtonChoose();
	afx_msg void OnBnClickedButtonLevel();
	afx_msg void OnBnClickedButtonMethod();
};
