#pragma once
#include "afxdialogex.h"


// Диалоговое окно AddRow

class AddRow : public CDialogEx
{
	DECLARE_DYNAMIC(AddRow)

public:
	AddRow(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddRow();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
