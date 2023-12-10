
// MFCApplication1View.cpp: реализация класса CMFCApplication1View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "AutoDBLab.h"
#include "MainFrm.h"
#endif

#include "AutoDbLabDoc.h"
#include "MFCApplication1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CListView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CListView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: добавьте код создания

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CAutoDBLabDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: добавьте здесь код отрисовки для собственных данных
}


void CMFCApplication1View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ListView можно заполнить элементами посредством непосредственного обращения
	//  к элементам управления этого списка через вызов GetListCtr().
}


// Печать CMFCApplication1View

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CListView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

void CMFCApplication1View::FillList(string table)
{
	

	m_list.DeleteAllItems();
	for (int i = m_list.GetHeaderCtrl()->GetItemCount(), k = 0; k < i; k++) {
		m_list.DeleteColumn(0);
	}

	string sql = "SELECT * FROM information_schema.columns where table_schema = 'mylabdb' and table_name = '" + table + "';"; 
	mysql_query(connect, sql.c_str()); 


	int result = mysql_query(connect, sql.c_str());

	if (res = mysql_store_result(connect))
	{
		for (int i = 0; row = mysql_fetch_row(res); i++)
		{
			m_list.InsertColumn(i, (CString)row[3], LVCFMT_LEFT, 100, -1);

		}
	}

	sql = "SELECT * FROM mylabdb." + table;
	mysql_query(connect, sql.c_str());

	if (res = mysql_store_result(connect))
	{
		int field_cnt = mysql_field_count(connect);
		for (int i = 0; row = mysql_fetch_row(res); i++)
		{
			m_list.InsertItem(i, L"Item");
			for (int k = 0; k < field_cnt; k++)
			{
				m_list.SetItemText(i, k, (CString)row[k]);
			}
		}
	}

}

CAutoDBLabDoc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoDBLabDoc)));
	return (CAutoDBLabDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApplication1View


int CMFCApplication1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= WS_CHILD | WS_VISIBLE | WS_TABSTOP | CS_DBLCLKS | LVS_REPORT;
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	//CMainFrame* m_pFrm = (CMainFrame*)GetDocument();

	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MAINFRAME);

	CMenu* SubMenu = MainMenu.GetSubMenu(4);

	ClientToScreen(&point);


	SubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CListView::OnRButtonDown(nFlags, point);
}
