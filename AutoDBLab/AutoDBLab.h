
// AutoDBLab.h: основной файл заголовка для приложения AutoDBLab
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CAutoDBLabApp:
// Сведения о реализации этого класса: AutoDBLab.cpp
//

class CAutoDBLabApp : public CWinApp
{
public:
	CAutoDBLabApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAutoDBLabApp theApp;
