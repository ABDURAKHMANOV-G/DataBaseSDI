#pragma once
#include "afxcview.h"

// Просмотр CMyTreeView
//class CAutoDBLabDoc;
//class CMFCApplication1View;

class CMainFrame;

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	HTREEITEM m_hDB, m_hTable1, m_hTable2, m_hTable3;
	void FillTree();

	CMainFrame* m_pFrm;

	//CAutoDBLabDoc* m_pDoc;
	//CMFCApplication1View* m_pView;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


