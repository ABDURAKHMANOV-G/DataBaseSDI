#pragma once
#include "afxdialogex.h"
#include <mysql.h>
#include "string"

using namespace std;

// Диалоговое окно AddingRow_Orders

class AddingRow_Orders : public CDialogEx
{
	DECLARE_DYNAMIC(AddingRow_Orders)

public:
	AddingRow_Orders(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddingRow_Orders();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedApply();
	afx_msg void OnBnClickedCancel();
	string CStoStr(CString value);
	CString m_Summa;
	MYSQL* connect;
	CString id_OR_Change;
	bool isChangeO;
	CString m_Duration;
	CString m_Id_Orders;
};
