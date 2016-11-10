#pragma once


// MSOBtMoreMethodDlg 对话框

class MSOBtMoreMethodDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreMethodDlg)

public:
	MSOBtMoreMethodDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtMoreMethodDlg();

// 对话框数据
	enum { IDD = IDD_MSOBTMOREMETHODDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
