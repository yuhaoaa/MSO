
// MSO_Version1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMSO_Version1App:
// �йش����ʵ�֣������ MSO_Version1.cpp
//

class CMSO_Version1App : public CWinApp
{
public:
	CMSO_Version1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMSO_Version1App theApp;