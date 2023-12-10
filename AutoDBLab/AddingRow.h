#pragma once
#include "afxdialogex.h"
#include <mysql.h>
#include "string"

using namespace std;
// Диалоговое окно AddingRow


class AddingRow : public CDialogEx
{
	DECLARE_DYNAMIC(AddingRow)

public:
	AddingRow(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddingRow();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	MYSQL* connect;
	CString m_Name;
	CString m_CarModel;
	CString id_CL_Change;
	bool isChangeC;
	string CStoStr(CString value);
	afx_msg void OnBnClickedApply();
	afx_msg void OnBnClickedCancel();
	CString m_Id;
};
