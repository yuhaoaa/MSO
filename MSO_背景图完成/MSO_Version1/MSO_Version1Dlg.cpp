
// MSO_Version1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MSO_Version1.h"
#include "MSO_Version1Dlg.h"
#include "afxdialogex.h"
#include "global.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMSO_Version1Dlg 对话框




CMSO_Version1Dlg::CMSO_Version1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMSO_Version1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSO_Version1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMSO_Version1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMSO_Version1Dlg::OnBnClickedButton1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMSO_Version1Dlg 消息处理程序

BOOL CMSO_Version1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// 初始化绘图工具
	InitialDrawTool();
	//初始化背景窗口
	CWnd::SetWindowPos(NULL,0,0,1366,768,SWP_NOZORDER);
	//ShowWindow(SW_MAXIMIZE);
	CRect rect;
	GetClientRect(rect);
	m_rect.left = rect.left+80;
	m_rect.right = rect.right-36;
	m_rect.top = rect.top+17;
	m_rect.bottom = rect.bottom-100;
	m_waveCanves.Create(_T(""),_T(""),WS_VISIBLE | WS_CHILD,m_rect,this,0,NULL);
	m_waveCanves.InitiaDrawTools();
	m_waveCanves.InitialBackGround();

	m_rectSmall.left = rect.left+80;
	m_rectSmall.right = rect.right-36;
	m_rectSmall.top = rect.top+17;
	m_rectSmall.bottom = rect.top+318;
	m_waveCanvesSmall.Create(_T(""),_T(""),WS_CHILD,m_rectSmall,this,0,NULL);
	m_waveCanvesSmall.InitiaDrawTools();
	m_waveCanvesSmall.InitialBackGround();

	//初始化频域窗口
	m_rectFreq.left = rect.left+80;
	m_rectFreq.right =rect.right-36;
	m_rectFreq.top = rect.top+367;
	m_rectFreq.bottom = rect.bottom-101;
	m_waveFreqCanves.Create(_T(""),_T(""), WS_CHILD,m_rectFreq,this,0,NULL);
	m_waveFreqCanves.InitiaDrawTools();
	m_waveFreqCanves.InitialBackGround();
	//m_waveFreqCanves.DrawWave();
	Freqdown=FALSE;

	//初始化主菜单栏
	mainMenuDlg.Create(IDD_MSOMAINMENUDLG,this);
	mainMenuDlg.SetWindowPos(&wndTop, 280,849,1071,55, SWP_SHOWWINDOW);//SWP_HIDEWINDOW
	freqMainMenuDlg.Create(IDD_MSOFREQMAINMENUDLG,this);
	freqMainMenuDlg.SetWindowPos(&wndTop, 280,849,1071,55, SWP_HIDEWINDOW);

	//初始化时间显示窗口
	m_timeRect.left =rect.right-148;
	m_timeRect.right=rect.right-20;
	m_timeRect.top =  rect.bottom-40;
	m_timeRect.bottom= rect.bottom-3;
	//初始化中心频率窗口
	m_CenterFreqRect.left = rect.left + 440;
	m_CenterFreqRect.right = rect.left + 640;
	m_CenterFreqRect.top = rect.top + 670;
	m_CenterFreqRect.bottom = rect.top + 690;
	//初始化RBW窗口
	m_RBWRect.left = rect.left + 700;
	m_RBWRect.right = rect.left + 915;
	m_RBWRect.top = rect.top + 670;
	m_RBWRect.bottom = rect.top + 707;

	InitializeCriticalSection(&m_criticalSection);//用于保护对硬件的操作
	m_hEventRunnig = CreateEvent(NULL, TRUE, FALSE, NULL);      //控制采数线程的挂起和恢复
	m_hEventDrawing = CreateEvent(NULL,TRUE,FALSE,NULL);
	AfxBeginThread(AquisitionThread,this,0,0,NULL);
	AfxBeginThread(DrawThread, this);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMSO_Version1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMSO_Version1Dlg::OnPaint()
{
	CPaintDC dc(this);
	CRect   rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(57,73,148));   //设置为绿色背景

	DrawTimeRect(&dc);
	SetTimer(1,1000,NULL);
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	   //m_waveFreqCanves.DrawWave(g_nData);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMSO_Version1Dlg::OnQueryDragIcon() 
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMSO_Version1Dlg::InitialDrawTool()
{
	m_penWhite.CreatePen(PS_SOLID,1,RGB(255,255,255));
	m_brushBlack.CreateSolidBrush(RGB(0,0,0));
}

//绘制时间窗口
void  CMSO_Version1Dlg::DrawTimeRect(CDC *m_dc)
{
	
	pOldPen = m_dc->SelectObject(&m_penWhite);
	pOldBrush = m_dc->SelectObject(&m_brushBlack);
	m_dc->RoundRect(m_timeRect,CPoint(10,10));  //绘制带边框的矩形

	CTime beginTime;
	beginTime = CTime::GetCurrentTime();
	CString Tstr, Tstr1, Tstr2;
	Tstr1.Format(_T("%d年 %d月 %d日"), 
		beginTime.GetYear(), beginTime.GetMonth(),  beginTime.GetDay());
	Tstr2.Format(_T("%d:%02d:%02d"), 
		beginTime.GetHour(),  beginTime.GetMinute(),  beginTime.GetSecond());
	Tstr = _T(" ") + Tstr1+ _T("\r\n") + _T(" ") + Tstr2;

	m_dc->SetBkMode(TRANSPARENT);  //设置背景透明
	m_dc->SetTextColor(RGB(255,255,255));  //设置颜色
	m_dc->DrawText(Tstr,  m_timeRect,   DT_NOCLIP| DT_LEFT);
}
//画频谱的中心频率显示框
void CMSO_Version1Dlg::DrawCenterFreqRect(CDC *m_dc)
{
	pOldPen = m_dc->SelectObject(&m_penWhite);
	pOldBrush = m_dc->SelectObject(&m_brushBlack);
	m_dc->RoundRect(m_CenterFreqRect,CPoint(10,10));  //绘制带边框的矩形

	//读取频谱仪中心频谱显示
	m_dc->SetBkMode(TRANSPARENT);  //设置背景透明
	m_dc->SetTextColor(RGB(255,170,0));  //设置颜色
	double m_centerFreqdata = m_waveFreqCanves.ReadCenterFreqData();
	CString str1,str;
	if (m_centerFreqdata>=100000000) 
	{
		m_centerFreqdata = m_centerFreqdata/1000000000;
		str1.Format(_T("%.9f"), m_centerFreqdata);
		str = _T("  Center :   ")+str1+_T("GHz");
	}
	else if(m_centerFreqdata>=1000000)
	{
		m_centerFreqdata = m_centerFreqdata/1000000;
		str1.Format(_T("%.6f"), m_centerFreqdata);
		str = _T("  Center :   ")+str1+_T("MHz");
	}
	else if (m_centerFreqdata>=1000)
	{
		m_centerFreqdata = m_centerFreqdata/1000;
		str1.Format(_T("%.3f"), m_centerFreqdata);
		str = _T("  Center :   ")+str1+_T("KHz");
	}
	m_dc->DrawText(str,  m_CenterFreqRect,   DT_NOCLIP| DT_LEFT);
}

//画频谱的RBW显示框
void CMSO_Version1Dlg::DrawRBWRect(CDC *m_dc)
{
	pOldPen = m_dc->SelectObject(&m_penWhite);
	pOldBrush = m_dc->SelectObject(&m_brushBlack);
	m_dc->RoundRect(m_RBWRect,CPoint(10,10));  //绘制带边框的矩形
	double m_stopFreqdata = m_waveFreqCanves.ReadStopFreqData();
	double m_startFreqdata = m_waveFreqCanves.ReadStartFreqData();
	double m_spandata = m_stopFreqdata - m_startFreqdata;
	m_dc->SetBkMode(TRANSPARENT);  //设置背景透明
	m_dc->SetTextColor(RGB(255,170,0));  //设置颜色
	CString str,str1;
	if (m_spandata >=100000000) 
	{
		m_spandata  = m_spandata /1000000000;
		str1.Format(_T("%.9f"), m_spandata );
		str = _T("  Span :   ")+str1+_T("GHz\r\n")+_T("  RBW :   3.000000 MHz");
	}
	else if(m_spandata >=1000000)
	{
		m_spandata  = m_spandata /1000000;
		str1.Format(_T("%.6f"), m_spandata );
		str = _T(" Span :   ")+str1+_T("MHz");
	}
	else if (m_spandata >=1000)
	{
		m_spandata  = m_spandata /1000;
		str1.Format(_T("%.3f"), m_spandata );
		str = _T("  Span :   ")+str1+_T("KHz");
	}
	m_dc->DrawText(str,  m_RBWRect,   DT_NOCLIP| DT_LEFT);
}


void CMSO_Version1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	DrawTimeRect(pDC);
	ReleaseDC(pDC);
	CDialogEx::OnTimer(nIDEvent);
}


// void CMSO_Version1Dlg::OnClose()
// {
// 	// TODO: 在此添加消息处理程序代码和/或调用默认值
// 	CDialogEx::OnClose();
// }


void CMSO_Version1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC *pDC = GetDC();
	Freqdown=!Freqdown;
	if (Freqdown)
	{
		m_waveCanves.ShowWindow(SW_HIDE);
		mainMenuDlg.ShowWindow(SW_HIDE);
		freqMainMenuDlg.ShowWindow(SW_SHOW);
		m_waveCanvesSmall.ShowWindow(SW_SHOW);
		m_waveFreqCanves.OpenDevice();  //打开频谱仪设备
		m_waveFreqCanves.ShowWindow(SW_SHOW);
		DrawCenterFreqRect(pDC);
		DrawRBWRect(pDC);
		SetEvent(m_hEventRunnig);
	    
	}
	else
	{
		Invalidate(TRUE); //清除频谱中的Rect
		m_waveCanves.ShowWindow(SW_SHOW);
		mainMenuDlg.ShowWindow(SW_SHOW);
		freqMainMenuDlg.ShowWindow(SW_HIDE);
		m_waveFreqCanves.ShowWindow(SW_HIDE);
		m_waveCanvesSmall.ShowWindow(SW_HIDE);
	
		freqflag = FREQNOMAL;
		m_waveFreqCanves.ChooseFreqDemod();
		ResetEvent(m_hEventRunnig);
	}
}


UINT CMSO_Version1Dlg::AquisitionThread(LPVOID param)
{
	CMSO_Version1Dlg *MSOView = (CMSO_Version1Dlg*)param;
	//g_nData = new unsigned char[7515];
	//MSOView->m_waveFreqCanves.OpenDevice();
	while (1)
	{
		WaitForSingleObject(MSOView->m_hEventRunnig, INFINITE);
		//EnterCriticalSection(&MSOView->m_criticalSection); //在频谱窗口关闭时，会出错 因为关闭窗口时已经删除了m_criticalSection
		MSOView->m_waveFreqCanves.ChooseFreqDemod();
	    g_nData = MSOView->m_waveFreqCanves.ReadFreqData();
		g_nData[7515]='\0';
		SetEvent(MSOView->m_hEventDrawing);
		//LeaveCriticalSection(&MSOView->m_criticalSection);
		//Sleep(5);
	}
	return 0;
}

UINT CMSO_Version1Dlg::DrawThread(LPVOID param)
{
	CMSO_Version1Dlg *MSOView = (CMSO_Version1Dlg*)param;
	while(1)
	{
		WaitForSingleObject(MSOView->m_hEventDrawing, INFINITE);
		MSOView->m_waveFreqCanves.DrawWave(g_nData);
		ResetEvent(MSOView->m_hEventDrawing);
	}
}

void CMSO_Version1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	m_penWhite.DeleteObject();
	m_brushBlack.DeleteObject();
	CloseHandle(m_hEventDrawing);
	CloseHandle(m_hEventRunnig);
	//DeleteCriticalSection(&m_criticalSection);
	KillTimer(1);
}
