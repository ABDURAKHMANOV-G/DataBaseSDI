// MyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "MyTreeView.h"
#include "afxcview.h"
#include "AutoDBLabDoc.h"
#include "AutoListView.h"
#include "MFCApplication1.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}


void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hDB = tree.InsertItem(L"DB", -1, -1, NULL, TVI_FIRST);
	
	m_hTable1 = tree.InsertItem(L"Clients", -1, -1, m_hDB, TVI_FIRST);
	m_hTable2 = tree.InsertItem(L"Orders", -1, -1, m_hDB, TVI_FIRST);
	m_hTable3 = tree.InsertItem(L"Spares", -1, -1, m_hDB, TVI_FIRST);

}
#endif
#endif //_DEBUG
	

// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_TRACKSELECT;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeView::OnLButtonDown(nFlags, point);
	CTreeCtrl& tree = GetTreeCtrl();


	CRect rc;
	tree.GetItemRect(m_hDB, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hDB);

	tree.GetItemRect(m_hTable1, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hTable1);
		m_pFrm->m_pView->FillList("clients");
	}

	tree.GetItemRect(m_hTable2, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hTable2);
		m_pFrm->m_pView->FillList("orders");
	}

	tree.GetItemRect(m_hTable3, &rc, false);
	if (rc.PtInRect(point)){
		tree.SelectItem(m_hTable3);
		m_pFrm->m_pView->FillList("spares");
	}


	if (tree.GetSelectedItem() == m_hTable1)
	{
		m_pFrm->m_bClients = true;
	}
	else {
		m_pFrm->m_bClients = false;
	}
		

	if (tree.GetSelectedItem() == m_hTable2)
	{
		m_pFrm->m_bOrders = true;
	}
	else {
		m_pFrm->m_bOrders = false;
	}

	if (tree.GetSelectedItem() == m_hTable3)
	{
		m_pFrm->m_bSpares = true;
	}
	else {
		m_pFrm->m_bSpares = false;
	}

}
