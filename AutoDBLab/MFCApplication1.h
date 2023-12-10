
// MFCApplication1View.h: интерфейс класса CMFCApplication1View
//

#pragma once
#include "afxcview.h"
#include "AutoDbLabDoc.h"
#include "string"
#include <mysql.h>

#include "AddingRow.h"
#include "AddingRow_Orders.h"
#include "AddingRow_Spares.h"

using namespace std;

class CmainFrame;
class CAutoLabDBDoc;

class CMFCApplication1View : public CListView
{
protected: // создать только из сериализации
	CMFCApplication1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1View)

		// Атрибуты
public:
	CAutoDBLabDoc* GetDocument() const;
	MYSQL* connect;
	MYSQL_RES* res;
	MYSQL_ROW row;


	AddingRow m_dlgAddRow;
	AddingRow_Orders m_dlgOrders;
	AddingRow_Spares m_dlgSpares;

	CListCtrl& m_list = GetListCtrl(); 
	// Операции
public:

	// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Реализация
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

	void FillList(string table);
#endif

protected:

	// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
{
	return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument);
}
#endif

