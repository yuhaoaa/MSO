#pragma once


// MSOBtHistogramDlg �Ի���

class MSOBtHistogramDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MSOBtHistogramDlg)

public:
	MSOBtHistogramDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MSOBtHistogramDlg();

// �Ի�������
	enum { IDD = IDD_MSOBTHISTOGRAMDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
    void OnInitButton(CButtonST *button);
private:
	CButtonST m_buttonHistogram_Hist;
	INT Histogram_hist;
	CButtonST m_buttonHistogram_Source;
	CButtonST m_buttonHistogram_StandardLimit;
	CButtonST m_buttonHistogram_VerticalLimit;
	CButtonST m_buttonHistogram_Page1;
	CButtonST m_buttonHistogram_Show;
	BOOL histogramShow;
	CButtonST m_buttonHistogram_Reset;
	CButtonST m_buttonHistogram_Page2;
public:
	afx_msg void OnBnClickedButtonHistogramHist();
	afx_msg void OnBnClickedButtonHistogramPage1();
	afx_msg void OnBnClickedButtonHistogramShow();
	afx_msg void OnBnClickedButtonHistogramPage2();
};
