#pragma once
#include "MSOBtMoreChildDlg.h"
#include "MSOBtHistogramDlg.h"
#include "MSOBtDeleteChildDlg.h"
#include "MSOBtFreqChooseDlg.h"

// MSOMainMenuDlg 对话框

class MSOMainMenuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOMainMenuDlg)

public:
	MSOMainMenuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOMainMenuDlg();

// 对话框数据
	enum { IDD = IDD_MSOMAINMENUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	void OnInitButton(CButtonST *button);
	void ShowMoreChilddlg();
	MSOBtMoreChildDlg m_BtMoreChildDlg;
	MSOBtHistogramDlg m_BtHistogramDlg;
	MSOBtDeleteChildDlg m_BtDeleteChildDlg;
	MSOBtFreqChooseDlg m_BtFreqChooseDlg;

private:
	CButtonST m_buttonChooseDomain;
	BOOL ChooseDomain;
	CButtonST m_buttonAddMeasure;
	BOOL AddMeasure;
	CButtonST m_buttondeleteMeasure;
	BOOL DeleteMeasure;
	CButtonST m_buttonIndicator;
	CButtonST m_buttonHistogram;
	BOOL Histogram;
	CButtonST m_buttonMore;
	CButtonST m_buttonShowCursorInScr;
	CButtonST m_buttonFreqChoose;
	BOOL FreqChoose;
public:
	afx_msg void OnBnClickedChoosedomain();
	afx_msg void OnBnClickedAddmeasure();
	afx_msg void OnBnClickedDeletemeasure();
	afx_msg void OnBnClickedHistogram();
	afx_msg void OnBnClickedMore();
	afx_msg void OnBnClickedFreqchoose();
};
