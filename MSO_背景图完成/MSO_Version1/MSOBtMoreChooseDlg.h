#pragma once


// MSOBtMoreChooseDlg 对话框

class MSOBtMoreChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtMoreChooseDlg)

public:
	MSOBtMoreChooseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtMoreChooseDlg();

// 对话框数据
	enum { IDD = IDD_MSOBTMORECHOOSEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
