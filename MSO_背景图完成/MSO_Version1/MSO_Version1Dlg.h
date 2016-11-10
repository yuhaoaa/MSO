
// MSO_Version1Dlg.h : ͷ�ļ�
//

#pragma once
#include "resource.h"
#include "MSOWave.h"
#include "MSOWaveFreq.h"
#include "MSOMainMenuDlg.h"
#include "MSOFreqMainMenuDlg.h"

// CMSO_Version1Dlg �Ի���
class CMSO_Version1Dlg : public CDialogEx
{
// ����
public:
	CMSO_Version1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MSO_VERSION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
public:
	MSOWave m_waveCanves,m_waveCanvesSmall;
	MSOWaveFreq m_waveFreqCanves;
	MSOMainMenuDlg mainMenuDlg;
	MSOFreqMainMenuDlg freqMainMenuDlg;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void InitialDrawTool();   //��ʼ����ͼ����
	void DrawTimeRect(CDC *m_dc);  //��ʱ�䴰��
	static UINT AquisitionThread(LPVOID param);
	static UINT DrawThread(LPVOID param);
private:
	CRect m_rect;            //����Rect
	CRect m_rectSmall;  
	CRect m_rectFreq;
	CRect m_timeRect;    //ʱ��Rect

	CPen m_penWhite;
	CPen *pOldPen;
	CBrush m_brushBlack;
	CBrush *pOldBrush;

	BOOL Freqdown;
public:
	HANDLE m_hEventRunnig;                //���е��߳̾��
    HANDLE m_hEventDrawing;               //��ͼ���߳̾��		
	CRITICAL_SECTION m_criticalSection;   //���ڱ�����Ӳ���Ĳ���
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDestroy();
};
