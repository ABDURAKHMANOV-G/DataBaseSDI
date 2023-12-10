
// AutoDBLabView.cpp: реализация класса CAutoDBLabView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "AutoDBLab.h"
#endif


#include "AutoDBLabDoc.h"
#include "MFCApplication1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoDBLabView

IMPLEMENT_DYNCREATE(CAutoDBLabView, CView)

BEGIN_MESSAGE_MAP(CAutoDBLabView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CAutoDBLabView

CAutoDBLabView::CAutoDBLabView() noexcept
{
	// TODO: добавьте код создания

}

CAutoDBLabView::~CAutoDBLabView()
{
}

BOOL CAutoDBLabView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CAutoDBLabView

void CAutoDBLabView::OnDraw(CDC* /*pDC*/)
{
	CAutoDBLabDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CAutoDBLabView

BOOL CAutoDBLabView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CAutoDBLabView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CAutoDBLabView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CAutoDBLabView

#ifdef _DEBUG
void CAutoDBLabView::AssertValid() const
{
	CView::AssertValid();
}

void CAutoDBLabView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAutoDBLabDoc* CAutoDBLabView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoDBLabDoc)));
	return (CAutoDBLabDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CAutoDBLabView
