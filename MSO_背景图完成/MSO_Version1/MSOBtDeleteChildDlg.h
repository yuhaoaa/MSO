#pragma once


// MSOBtDeleteChildDlg �Ի���

class MSOBtDeleteChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtDeleteChildDlg)

public:
	MSOBtDeleteChildDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtDeleteChildDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTDELETECHILDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
