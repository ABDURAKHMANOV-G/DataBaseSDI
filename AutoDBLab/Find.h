#pragma once
#include "afxdialogex.h"
#include <mysql.h>
#include "string"

using namespace std;

// Диалоговое окно Find

class Find : public CDialogEx
{
	DECLARE_DYNAMIC(Find)

public:
	Find(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Find();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_TableName;
	CString m_ColumnName;
	MYSQL* connect;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	string CStoStr(CString value);
	CString m_ColumnValue;


	string id, Name, Car;


	bool isOpen = false;
	afx_msg void OnBnClickedOpen();
};
