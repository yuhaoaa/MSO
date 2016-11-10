#pragma once


// MSOBtMoreStatisticsDlg 对话框

class MSOBtMoreStatisticsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreStatisticsDlg)

public:
	MSOBtMoreStatisticsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtMoreStatisticsDlg();

// 对话框数据
	enum { IDD = IDD_MSOBTMORESTATISTICSDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	void OnInitButton(CButtonST *button);
private:
	CButtonST m_buttonMore_statistics_statistics;
	BOOL more_Statistics_Statistics;
	CButtonST m_buttonMore_statistics_averge;
	//BOOL more_Statistics_Averge;
    CButtonST m_buttonMore_statistics_reset;
	BOOL _Statistics_Reset;
public:
	afx_msg void OnBnClickedButtonStatisticsStatistics();
};
