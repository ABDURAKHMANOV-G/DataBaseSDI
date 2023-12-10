
// MainFrm.cpp: реализация класса CMainFrame
//

#include "pch.h"
#include "framework.h"
#include "AutoDBLab.h"
#include "MFCApplication1.h"
#include "MyTreeView.h"
#include "AutoListView.h"
#include "AutoDBLabDoc.h"
#include "mysql.h"
#include <string>


#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame




using namespace std;

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_ADDROW, &CMainFrame::OnAddrow)
	ON_COMMAND(ID_DELROW, &CMainFrame::OnDelRow)
	ON_COMMAND(ID_CHAGEROW, &CMainFrame::OnChagerow)
	ON_COMMAND(ID_FIND, &CMainFrame::OnFind)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // индикатор строки состояния
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// Создание или уничтожение CMainFrame

CMainFrame::CMainFrame() noexcept
{
	// TODO: добавьте код инициализации члена
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Не удалось создать панель инструментов\n");
		return -1;      // не удалось создать
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Не удалось создать строку состояния\n");
		return -1;      // не удалось создать
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Удалите эти три строки, если не собираетесь закреплять панель инструментов
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	


	// Получаем дескриптор соединения
	conn = mysql_init(NULL);


	// Подключаемся к серверу
	if (!mysql_real_connect(conn, "localhost", "root", "Ufcfy4733abd", "mylabdb", NULL, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		MessageBox(L"Error: can'tconnecttodatabase!");
	}

	mysql_set_character_set(conn, "cp1251");

	CMFCApplication1View* listP = (CMFCApplication1View*)m_wndSplitter.GetPane(0, 1);
	listP->connect = conn;
	m_dlgAddRow.connect = conn;
	m_dlgOrders.connect = conn;
	m_dlgSpares.connect = conn;
	m_dlgFind.connect = conn;
	m_pTreeView->FillTree();
	//listP->FillList("clients"); 


	return 0;
}

string CMainFrame::CStoStr(CString value)
{
	CT2CA CS_value(value);
	string str_value(CS_value);
	return str_value;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return TRUE;
}

// Диагностика CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// Обработчики сообщений CMainFrame



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: добавьте специализированный код или вызов базового класса

	m_wndSplitter.CreateStatic(this, 1, 2);
	
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyTreeView), CSize(200, 0), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CMFCApplication1View), CSize(0, 0), pContext);

	SetActiveView((CView*)m_wndSplitter.GetPane(0, 1));

	//CAutoDBLabDoc* pDoc = (CAutoDBLabDoc*)GetActiveDocument();

	
	m_pTreeView = (CMyTreeView*)m_wndSplitter.GetPane(0, 0);

	m_pTreeView->m_pFrm = this;
	m_pView = (CMFCApplication1View*)m_wndSplitter.GetPane(0, 1);
		

	//pDoc->m_pTreeView->m_pDoc = pDoc;

	return TRUE;
}



void CMainFrame::OnAddrow()
{
	m_dlgAddRow.isChangeC = false;
	m_dlgOrders.isChangeO = false;
	m_dlgSpares.isChangeS = false;
	UpdateData(true);
	m_dlgAddRow.m_Id = "";
	m_dlgAddRow.m_Name = ""; 
	m_dlgAddRow.m_CarModel = "";
	m_dlgOrders.m_Id_Orders = "";
	m_dlgOrders.m_Summa = "";
	m_dlgOrders.m_Duration = "";
	m_dlgSpares.m_Id_Spares = "";
	m_dlgSpares.m_Price = "";
	m_dlgSpares.m_CarModel_Spares = "";
	UpdateData(false);
	// TODO: добавьте свой код обработчика команд
	if (m_bClients) {
		m_dlgAddRow.DoModal();
		m_pView->FillList("clients");
	} 
	else if (m_bOrders) {
		m_dlgOrders.DoModal();
		m_pView->FillList("orders");
	}
	else if (m_bSpares) {
		m_dlgSpares.DoModal();
		m_pView->FillList("spares");
	}

}

void CMainFrame::OnChagerow()
{
	m_dlgAddRow.isChangeC = true;
	m_dlgOrders.isChangeO = true;
	m_dlgSpares.isChangeS = true;
	// TODO: добавьте свой код обработчика команд
	if (m_bClients) {
		m_dlgAddRow.id_CL_Change = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgAddRow.m_Id = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgAddRow.m_Name = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 1);
		m_dlgAddRow.m_CarModel = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 2);
		
		if (m_dlgAddRow.m_Id != "") {
			m_dlgAddRow.DoModal();
		}
		else
			MessageBox(L"Выберите ячейку!");
		m_pView->FillList("clients");
	}
	else if (m_bOrders) {
		m_dlgOrders.id_OR_Change = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgOrders.m_Id_Orders = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgOrders.m_Summa = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 1);
		m_dlgOrders.m_Duration = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 2);

		if (m_dlgOrders.m_Id_Orders != "") { 
			m_dlgOrders.DoModal(); 
		}
		else
			MessageBox(L"Выберите ячейку!");
		m_pView->FillList("orders");
	}
	else if (m_bSpares) {
		m_dlgSpares.id_SP_Change = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgSpares.m_Id_Spares = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0);
		m_dlgSpares.m_Price = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 1);
		m_dlgSpares.m_CarModel_Spares = m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 2);

		if (m_dlgSpares.m_Id_Spares != "") {
			m_dlgSpares.DoModal();
		}
		else
			MessageBox(L"Выберите ячейку!");
		m_pView->FillList("spares");
	}
	UINT nFlags = 0;
	CPoint point;
}


void CMainFrame::OnDelRow()
{
	// TODO: добавьте свой код обработчика команд
	if (m_bClients) {
		string sql = "DELETE FROM `mylabdb`.`clients` WHERE (`client_id` = '" + CStoStr(m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0)) + "');";
		if (MessageBox(L"Удалить строку?", L"Подтверждение", MB_YESNO == 6)) {
			if (mysql_query(conn, sql.c_str())) {
				MessageBox(L"Ошибка удаления данных!");
			}
		}
		m_pView->FillList("clients");
	}

	else if (m_bOrders) {
		string sql = "DELETE FROM `mylabdb`.`orders` WHERE (`order_id` = '" + CStoStr(m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0)) + "');";
		if (MessageBox(L"Удалить строку?", L"Подтверждение", MB_YESNO == 6)) {
			if (mysql_query(conn, sql.c_str())) {
				MessageBox(L"Ошибка удаления данных!");
			}
		}
		m_pView->FillList("orders");
	}

	else if (m_bSpares) {
		string sql = "DELETE FROM `mylabdb`.`spares` WHERE (`spare_id` = '" + CStoStr(m_pView->m_list.GetItemText(m_pView->m_list.GetSelectionMark(), 0)) + "');";
		if (MessageBox(L"Удалить строку?", L"Подтверждение", MB_YESNO == 6)) {
			if (mysql_query(conn, sql.c_str())) {
				MessageBox(L"Ошибка удаления данных!");
			}
		}
		m_pView->FillList("spares");
	}
	
}



void CMainFrame::OnFind()
{
	// TODO: добавьте свой код обработчика команд
	
	m_dlgFind.DoModal();

	string sql = "SELECT * FROM `mylabdb`.`" + CStoStr(m_dlgFind.m_TableName) + "` WHERE (`" + CStoStr(m_dlgFind.m_ColumnName) + "` = '" + CStoStr(m_dlgFind.m_ColumnValue) + "');";

	//m_dlgFind.id = "SELECT `client_id` FROM `mylabdb`.`" + CStoStr(m_dlgFind.m_TableName) + "` WHERE (`" + CStoStr(m_dlgFind.m_ColumnName) + "` = '" + CStoStr(m_dlgFind.m_ColumnValue) + "');";
	
	mysql_query(conn, sql.c_str());
	if (m_pView->res = mysql_store_result(conn)) {

		int field_count = mysql_field_count(conn);
		
		m_dlgFind.id = "";
		m_pView->row = mysql_fetch_row(m_pView->res);
		for (int i = 0; i < field_count; i++) {
			m_dlgFind.id += m_pView->row[i];
			m_dlgFind.id += " ";
		}

		MessageBoxA(NULL, m_dlgFind.id.c_str(), "Your", NULL);
		
		
	}
	else
		MessageBox(L"Некорректный или несуществующий столбец! ");
	//m_pView->FillList("spares");

}
