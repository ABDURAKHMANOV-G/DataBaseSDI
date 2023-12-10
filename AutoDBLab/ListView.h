#pragma once
#include "afxcview.h"

// Просмотр CListView

class CListView : public CListView
{
	DECLARE_DYNCREATE(CListView)

protected:
	CListView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


