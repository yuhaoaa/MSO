#pragma once


// MSOBtDeleteChildDlg 对话框

class MSOBtDeleteChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtDeleteChildDlg)

public:
	MSOBtDeleteChildDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MSOBtDeleteChildDlg();

// 对话框数据
	enum { IDD = IDD_MSOBTDELETECHILDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void OnInitButton(CButtonST *button);
private:
	CButtonST m_button_Delete_DeleteAll;
	CButtonST m_button_Delete_Choose;
	CButtonST m_button_Delete_Ok;
};
