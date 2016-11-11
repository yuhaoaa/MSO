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
	CRect m_rcCanvas;                                                          //��ͼ���ľ������
	CBrush m_brushBack;                                                       //������ˢ
	CBrush *m_oldBrush;
	CDC m_dcGrid;	                                                           //���߿��豸����DC
	CBitmap m_bitmapGrid ;                                                  //���߿��豸��������λͼ
	CBitmap *m_pOldBitmapGrid;
	unsigned char *RecBuf ;                                                  //ReadData�������ص�����
	unsigned char *allData;                                                   //DrawWave��������ͼ������
	//unsigned char *CenterFreqBuf;
	//�������ߵ��豸����
	CDC m_dcLine;  	                                                           //�����豸DC
	CBitmap m_bitmapLine;                                                      //�����豸��������λͼ
	CBitmap *m_pOldBitmapLine;

	CPen *m_oldPen;
	CPen m_penBorederBlue;
	CPen m_pendarkYellow;                                                           //������ͼ����ı��߻���
	CPen m_penBlack;
	CPen m_penBlack1;
	CPen m_FreqWavePenCH1;

	int     m_nHTrigXPos;                                                      //ˮƽ���򴥷�λ�õ�x����
	COLORREF m_crGridColor;                                          //���ָʾ����ɫ:���ɫ
	COLORREF m_crLineColor;                                           //ͨ��������ɫ:��ɫ
	COLORREF m_crLine1Color;                                         //1ͨ��������ɫ:��ɫ
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


