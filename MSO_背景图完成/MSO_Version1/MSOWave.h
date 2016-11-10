#pragma once


// MSOWave

class MSOWave : public CWnd
{
	DECLARE_DYNAMIC(MSOWave)

public:
	MSOWave();
	virtual ~MSOWave();
	void InitiaDrawTools();
	void InitialBackGround();
public:
	CRect m_rcCanvas;                                                          //��ͼ���ľ������
	CBrush m_brushBack;                                                       //������ˢ
	CBrush *m_oldBrush;
	CDC m_dcGrid;	                                                           //���߿��豸����DC
	CBitmap m_bitmapGrid ;                                                  //���߿��豸��������λͼ
	CBitmap *m_pOldBitmapGrid;

	//�������ߵ��豸����
	CDC m_dcLine;  	                                                           //�����豸DC
	CBitmap m_bitmapLine;                                                      //�����豸��������λͼ
	CBitmap *m_pOldBitmapLine;

	CPen *m_oldPen;
	CPen m_penBorederBlue;
	CPen m_pendarkYellow;                                                           //������ͼ����ı��߻���
	CPen m_penBlack;
	CPen m_penBlack1;

	int     m_nHTrigXPos;                                                      //ˮƽ���򴥷�λ�õ�x����
	COLORREF m_crGridColor;                                          //���ָʾ����ɫ:���ɫ
	COLORREF m_crLineColor;                                           //ͨ��������ɫ:��ɫ
	COLORREF m_crLine1Color;                                         //1ͨ��������ɫ:��ɫ
	COLORREF m_crLine2Color;   
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};


