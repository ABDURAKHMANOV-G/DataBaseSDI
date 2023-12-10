#pragma once
#include "afxcview.h"
#include "string"
#include "MainFrm.h"
#include <mysql.h>

using namespace std;

// Просмотр CAutoListView

class CAutoListView : public CListView
{
	DECLARE_DYNCREATE(CAutoListView)

protected:
	CAutoListView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CAutoListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	void FillList(string table);
	MYSQL* connect;
	MYSQL_RES* res;
	MYSQL_ROW row;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};