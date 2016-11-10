
// MSO_Version1Dlg.h : 头文件
//

#pragma once
#include "resource.h"
#include "MSOWave.h"
#include "MSOWaveFreq.h"
#include "MSOMainMenuDlg.h"
#include "MSOFreqMainMenuDlg.h"

// CMSO_Version1Dlg 对话框
class CMSO_Version1Dlg : public CDialogEx
{
// 构造
public:
	CMSO_Version1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MSO_VERSION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
public:
	MSOWave m_waveCanves,m_waveCanvesSmall;
	MSOWaveFreq m_waveFreqCanves;
	MSOMainMenuDlg mainMenuDlg;
	MSOFreqMainMenuDlg freqMainMenuDlg;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void InitialDrawTool();   //初始化绘图工具
	void DrawTimeRect(CDC *m_dc);  //画时间窗口
	static UINT AquisitionThread(LPVOID param);
	static UINT DrawThread(LPVOID param);
private:
	CRect m_rect;            //背景Rect
	CRect m_rectSmall;  
	CRect m_rectFreq;
	CRect m_timeRect;    //时间Rect

	CPen m_penWhite;
	CPen *pOldPen;
	CBrush m_brushBlack;
	CBrush *pOldBrush;

	BOOL Freqdown;
public:
	HANDLE m_hEventRunnig;                //运行的线程句柄
    HANDLE m_hEventDrawing;               //绘图的线程句柄		
	CRITICAL_SECTION m_criticalSection;   //用于保护对硬件的操作
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDestroy();
};
