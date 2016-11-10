#pragma once
#include "MSOBtFreqDemodChildDlg.h"

// MSOFreqMainMenuDlg �Ի���

class MSOFreqMainMenuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOFreqMainMenuDlg)

public:
	MSOFreqMainMenuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOFreqMainMenuDlg();

// �Ի�������
	enum { IDD = IDD_MSOFREQMAINMENUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
