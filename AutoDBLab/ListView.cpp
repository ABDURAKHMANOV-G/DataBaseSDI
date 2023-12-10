// CListView.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "ListView.h"


// CListView

IMPLEMENT_DYNCREATE(CListView, CListView)

CListView::CListView()
{

}

CListView::~CListView()
{
}

BEGIN_MESSAGE_MAP(CListView, CListView)
END_MESSAGE_MAP()


// Диагностика CListView

#ifdef _DEBUG
void CListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CListView
