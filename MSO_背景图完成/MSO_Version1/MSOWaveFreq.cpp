// MSOWaveFreq.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSOWaveFreq.h"

#include "global.h"

// MSOWaveFreq

IMPLEMENT_DYNAMIC(MSOWaveFreq, CWnd)

MSOWaveFreq::MSOWaveFreq()
{
	m_crGridColor = RGB(148,138,107);
	m_brushBack.CreateSolidBrush(RGB(0,0,0));
	m_penBorederBlue.CreatePen(PS_SOLID,1,RGB(156,207,255));
	m_pendarkYellow.CreatePen(PS_SOLID,1,m_crGridColor);
	m_penBlack.CreatePen(PS_SOLID,1,RGB(255,255,0));
	m_penBlack1.CreatePen(PS_SOLID,1,RGB(255,255,0));
	m_FreqWavePenCH1.CreatePen(PS_SOLID, 1, RGB(255,130,0));
	//OpenDevice();
}

MSOWaveFreq::~MSOWaveFreq()
{
	viClose(instr);//�ر����ض�������ͨ��
	viClose(defaultRM);//�ر���Ĭ����Դ����������ͨ��
}


BEGIN_MESSAGE_MAP(MSOWaveFreq, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// MSOWaveFreq ��Ϣ�������
void MSOWaveFreq::InitiaDrawTools( )
{
	CClientDC dc(this);

	//��������豸�����Լ�������Ӧ������
	if(m_dcGrid.GetSafeHdc()==NULL)
	{
		m_dcGrid.CreateCompatibleDC(&dc);
		m_bitmapGrid.CreateCompatibleBitmap(&dc,m_rcCanvas.Width(),m_rcCanvas.Height());
		m_pOldBitmapGrid = m_dcGrid.SelectObject(&m_bitmapGrid);
	}

	//������ͼ�豸�����Լ�������Ӧ������
	if (m_dcLine.GetSafeHdc() == NULL)
	{
		m_dcLine.CreateCompatibleDC(&dc);
		m_bitmapLine.CreateCompatibleBitmap(&dc,m_rcCanvas.Width(),m_rcCanvas.Height());
		m_pOldBitmapLine = m_dcLine.SelectObject(&m_bitmapLine);
	}
}

void MSOWaveFreq::InitialBackGround()
{
	//�м����
	GetClientRect(m_rcCanvas);
	m_oldPen=m_dcGrid.SelectObject(&m_penBorederBlue);
	m_oldBrush=m_dcGrid.SelectObject(&m_brushBack);
	m_dcGrid.Rectangle(m_rcCanvas);
	m_penBorederBlue.DeleteObject();
	m_brushBack.DeleteObject();

	m_oldPen = m_dcGrid.SelectObject(&m_pendarkYellow);

	int nYLittleGap = (int)( m_rcCanvas.Height() / 50.0);//��������ʮС��
	int nYBigGap = nYLittleGap * 5 ;//һ���������С��
	int nXLittleGap = (int)( m_rcCanvas.Width() / 50.0);//��������ʮС��
	int nXBigGap = nXLittleGap * 5; //һ���������С��

	CString Yparameter[10]={_T("0.00dBm"),_T("-10.0"),_T("-20.0"),_T("-30.0"),_T("-40.0"),_T("-50.0"),_T("-60.0"),
		_T("-70.0"),_T("-80.0"),_T("-90.0")};

		//ͻ������Ĵ��
		for(int i = nYBigGap; i <m_rcCanvas.Height() ;i += nYBigGap)  
		{
			m_dcGrid.MoveTo(m_rcCanvas.left , m_rcCanvas.top + i);
			m_dcGrid.LineTo(m_rcCanvas.left + 7, m_rcCanvas.top + i);
			m_dcGrid.MoveTo(m_rcCanvas.right - 7, m_rcCanvas.top + i);
			m_dcGrid.LineTo(m_rcCanvas.right, m_rcCanvas.top + i);
		}
		//�����Ļ���
		for(int j = nXBigGap; j <= m_rcCanvas.Width(); j += nXBigGap)
		{
			for(int x=0;x<m_rcCanvas.Height();x+=2)
			{
				m_dcGrid.SetPixel(m_rcCanvas.left + j, m_rcCanvas.top + x, m_crGridColor);
			}
		}
		//�����������
		m_dcGrid.SetBkMode(TRANSPARENT);
		m_dcGrid.SetTextColor(RGB(148,138,107));
		m_dcGrid.TextOut(15,0,Yparameter[0]);
		for (int i=1; i<10; i++)
		{
			m_dcGrid.TextOut(15,i*nYBigGap-8,Yparameter[i]);
		}
		//ͻ������Ĵ��
		for(int i = nXBigGap; i <m_rcCanvas.Width() ;i += nXBigGap)  
		{
			m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.top);
			m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.top + 7);
			m_dcGrid.MoveTo(m_rcCanvas.left + i, m_rcCanvas.bottom - 7);
			m_dcGrid.LineTo(m_rcCanvas.left + i, m_rcCanvas.bottom);
		}
		//�����Ļ���
		for(int j = nYBigGap; j < m_rcCanvas.Height(); j+=nYBigGap)
		{
			for(int y=0;y<m_rcCanvas.Width();y+=2)
			{
				m_dcGrid.SetPixel(m_rcCanvas.left +50+ y, m_rcCanvas.top + j, m_crGridColor);
			}
		}	

	m_dcGrid.SelectObject(m_oldPen);
	//�ӱ���DC����ͼ����ͼdc
	m_dcLine.BitBlt(0,0,m_rcCanvas.Width(),m_rcCanvas.Height(),&m_dcGrid,0,0,SRCCOPY);
}

BOOL MSOWaveFreq::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	BOOL result ;
	//ע�ᴰ����
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//����������
	result = CWnd::CreateEx(NULL, className, NULL, dwStyle, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), (HMENU)nID) ;
	m_rcCanvas = CRect(rect);
	return  result;
}

void MSOWaveFreq::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()

	dc.BitBlt(m_rcCanvas.left,m_rcCanvas.top,m_rcCanvas.Width(),m_rcCanvas.Height(),&m_dcLine,0,0,SRCCOPY);
}

void MSOWaveFreq::OpenDevice()
{
	status = viOpenDefaultRM(&defaultRM);//����Ĭ����Դ��������ͨ����Ĭ����Դ��������visa�����ڹ���������Դ����
	//���øú�������һ�������Ϊviopen���������
	if (status != VI_SUCCESS)
	{
		defaultRM = 0;
		MessageBox(" �� ȷ �� VISA �� �� �� �� �� �� �� װ "," �� ʼ �� VISA ʧ ��",MB_ICONERROR);
		//		return;
	}
	status1 = viOpen(defaultRM, "TCPIP0::192.168.1.58::5025::SOCKET", VI_NULL, VI_NULL, &instr);//�����ض�������ͨ�������һ������Ϊ�ú�������һ���
	// ���vi��Ϊ��������
	//�����������һ������ΪviOpenDefaultRM()�������صľ��
	//viOpen(ViSession sesn,ViRsrc rsrcName,ViAccessMode accessMode,
	//ViUInt32 timeout,ViPSession vi)
	if (status1 < VI_SUCCESS)
	{
		instr = 0;
		MessageBox("��ȷ��Ӳ����������","����ʧ��!",MB_ICONERROR);
		//		return;
	}
}

void MSOWaveFreq::ChooseFreqDemod()
{
	ViUInt32 retCount;
	ViPChar SendBuf1 = NULL;ViPChar SendBuf2 = NULL;
	ViPChar SendBuf3 = NULL;ViPChar SendBuf4 = NULL;
	CString strCmd1  =  "SENSe:DETector:FUNCtion POSitive\n";  //����ȡ1001����
	CString strCmd2  =  " SENSe:DETector:FUNCtion NEGative\n";
	CString strCmd3  =  "SENSe:DETector:FUNCtion SAMPle\n";
	CString strCmd4  =  "SENSe:DETector:FUNCtion NORMal\n";
	SendBuf1 = strCmd1.GetBuffer(strCmd1.GetLength());
	SendBuf2 = strCmd2.GetBuffer(strCmd2.GetLength());
	SendBuf3 = strCmd3.GetBuffer(strCmd3.GetLength());
	SendBuf4 = strCmd4.GetBuffer(strCmd4.GetLength());
	strcpy(SendBuf1,strCmd1);
	strcpy(SendBuf2,strCmd2);
	strcpy(SendBuf3,strCmd3);
	strcpy(SendBuf4,strCmd4);
	switch (freqflag)
	{
	case FREQPOSITIVE:
		status2 = viWrite(instr, (unsigned char *)SendBuf1 ,strlen(SendBuf1), &retCount);
		break;
	case FREQNEGATIVE:
		status2 = viWrite(instr, (unsigned char *)SendBuf2 ,strlen(SendBuf2), &retCount);
		break;
	case FREQSAMPLE:
		status2 = viWrite(instr, (unsigned char *)SendBuf3 ,strlen(SendBuf3), &retCount);
		break;
	case FREQNOMAL:
		status2 = viWrite(instr, (unsigned char *)SendBuf4 ,strlen(SendBuf4), &retCount);
		break;
	}
}

unsigned char*  MSOWaveFreq::ReadData()
{
	ViUInt32 retCount;
	char* SendBuf = NULL;
	ViPChar SendBuf1= NULL;
	ViPChar SendBuf2= NULL;
	CString strCmd = "TRACe:DATA? TRACE1\n";        //��ȡͨ��1��������
	SendBuf = strCmd.GetBuffer(strCmd.GetLength());
	strcpy(SendBuf,strCmd);
	status2 = viWrite(instr, (unsigned char *)SendBuf, strlen(strCmd), &retCount);

	//unsigned char RecBuf[15015];    //���þ�̬�����ڷֽ�����ʱ��472��972��������ʱ�����ָ�����why��
	unsigned char *RecBuf = new unsigned char [7515];
	//unsigned char *RecBuf = new unsigned char [15015];
	status = viRead(instr, RecBuf, 7515, &retCount);//RecBufΪ�������ݴ洢����retCountΪ�������ݵĴ�С

	return RecBuf;

}

int MSOWaveFreq::ValueToSp(double value)
{
	int result;
	result = (int)((m_rcCanvas.Height())/(-10)*value) ;
	if (result > m_rcCanvas.bottom)
	{
		result = m_rcCanvas.bottom;
	}
	if (result < m_rcCanvas.top)
	{
		result = m_rcCanvas.top;
	}
	return result;
}
void MSOWaveFreq::DrawWave(unsigned char *data)
{
	CClientDC dc(this);
	m_dcLine.BitBlt(0,0,m_rcCanvas.Width(),m_rcCanvas.Height(),&m_dcGrid,0,0,SRCCOPY);                             
	
	m_dcLine.SelectObject(&m_FreqWavePenCH1);
	CPoint *pPt = new CPoint[501];

	unsigned char *allData = new unsigned  char[7515];
	memset(allData, 0 ,7515);
	char *singleData = new char[15];
	//allData = ReadData();
	//allData[7515] = '\0';
	allData = data;
	float doubData[501];
	//int multData[501];
	const char *delim = "e,";  
	singleData = strtok((char*)allData, delim);
	doubData[0] = atof(singleData);
	int len = 1;
	while (singleData)
	{
		singleData = strtok(NULL,delim);
		if (0 ==len%2 && singleData)
		{
			doubData[len/2] = atof(singleData);
		}
		len++;
	}

	len--;
	for (int i=0; i<501; i=i+1)
	{
		pPt[i].y = ValueToSp(doubData[i]);
		//pPt[i].x =m_rcCanvas.left+m_rcCanvas.Width()*i/(len/2);
		pPt[i].x =m_rcCanvas.left+i*2.49;
	}
	m_dcLine.MoveTo(pPt[0]);
	for (int i=0; i<501; i++)
	{
		//m_dcLine.LineTo(pPt[i+1].x,pPt[i+1].y);
		m_dcLine.LineTo(pPt[i+1]);
	}
	delete []pPt;
	delete []singleData;
	dc.BitBlt(m_rcCanvas.left,m_rcCanvas.top,m_rcCanvas.Width(),
		m_rcCanvas.Height(),&m_dcLine,0,0,SRCCOPY);
	Invalidate(FALSE);
}