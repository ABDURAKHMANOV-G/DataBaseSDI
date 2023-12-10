
// MainFrm.h: интерфейс класса CMainFrame
//

#pragma once

#include <mysql.h>
#include "AddingRow.h"
#include "AddingRow_Orders.h"
#include "AddingRow_Spares.h"
#include "Find.h"
#include "string"

using namespace std;


class CMFCApplication1View;
class CMyTreeView;


class CMainFrame : public CFrameWnd
{
	
protected: // создать только из сериализации
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// Атрибуты
public:
	CSplitterWnd      m_wndSplitter;
	MYSQL* conn;
	CMFCApplication1View* m_pView;
	CMyTreeView* m_pTreeView;
	AddingRow m_dlgAddRow;
	AddingRow_Orders m_dlgOrders;
	AddingRow_Spares m_dlgSpares;
	Find m_dlgFind;

	int m = 5;

	string CStoStr(CString value);
	bool m_bClients = false, m_bOrders = false, m_bSpares = false;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	

// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

		virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnAddrow();
	afx_msg void OnDelRow();
	afx_msg void OnChagerow();
	afx_msg void OnFind();
};


