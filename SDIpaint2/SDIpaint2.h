
// SDIpaint2.h : SDIpaint2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSDIpaint2App:
// �йش����ʵ�֣������ SDIpaint2.cpp
//

class CSDIpaint2App : public CWinApp
{
public:
	CSDIpaint2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIpaint2App theApp;
