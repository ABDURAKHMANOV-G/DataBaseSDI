#pragma once
#include "afxdialogex.h"
#include <mysql.h>
#include "string"


using namespace std;

// Диалоговое окно AddingRow_Spares


class AddingRow_Spares : public CDialogEx
{
	DECLARE_DYNAMIC(AddingRow_Spares)

public:
	AddingRow_Spares(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddingRow_Spares();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedApply();
	afx_msg void OnBnClickedCancel();
	CString m_Price;
	CString m_CarModel_Spares;
	MYSQL* connect;
	bool isChangeS;
	CString id_SP_Change;
	string CStoStr(CString value);
	CString m_Id_Spares;
};
