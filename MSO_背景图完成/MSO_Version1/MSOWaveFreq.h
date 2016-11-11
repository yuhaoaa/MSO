#pragma once
#include "visa.h"

// MSOWaveFreq

class MSOWaveFreq : public CWnd
{
	DECLARE_DYNAMIC(MSOWaveFreq)

public:
	MSOWaveFreq();
	virtual ~MSOWaveFreq();
	void InitiaDrawTools();
	void InitialBackGround();
	void OpenDevice();
    unsigned char * WriteReadData(CString str ,INT len, BOOL WriteOrRead);
	double DataProcess(unsigned char* dataBuf);
	void ChooseFreqDemod();
    unsigned char *ReadFreqData();
	double ReadCenterFreqData();
	double ReadStartFreqData();
	double ReadStopFreqData();
	void DrawWave(unsigned char *data);
	int ValueToSp(double value);
public:
	CRect m_rcCanvas;                                                          //绘图区的矩形面积
	CBrush m_brushBack;                                                       //背景画刷
	CBrush *m_oldBrush;
	CDC m_dcGrid;	                                                           //表格边框设备环境DC
	CBitmap m_bitmapGrid ;                                                  //表格边框设备环境缓冲位图
	CBitmap *m_pOldBitmapGrid;
	unsigned char *RecBuf ;                                                  //ReadData函数返回的数组
	unsigned char *allData;                                                   //DrawWave中用来画图的数组
	//unsigned char *CenterFreqBuf;
	//用来画线的设备环境
	CDC m_dcLine;  	                                                           //画线设备DC
	CBitmap m_bitmapLine;                                                      //画线设备环境缓冲位图
	CBitmap *m_pOldBitmapLine;

	CPen *m_oldPen;
	CPen m_penBorederBlue;
	CPen m_pendarkYellow;                                                           //绘制作图区域的边线画笔
	CPen m_penBlack;
	CPen m_penBlack1;
	CPen m_FreqWavePenCH1;

	int     m_nHTrigXPos;                                                      //水平方向触发位置的x坐标
	COLORREF m_crGridColor;                                          //表格指示线颜色:深黄色
	COLORREF m_crLineColor;                                           //通道曲线颜色:黄色
	COLORREF m_crLine1Color;                                         //1通道曲线颜色:黄色
	COLORREF m_crLine2Color;   

	ViStatus status, status1, status2;
	ViSession defaultRM;
	ViSession instr;
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnPaint();
};


