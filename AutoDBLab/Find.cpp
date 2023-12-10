// Find.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "afxdialogex.h"
#include "Find.h"


// Диалоговое окно Find

IMPLEMENT_DYNAMIC(Find, CDialogEx)

Find::Find(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_TableName(_T(""))
	, m_ColumnName(_T(""))
	, m_ColumnValue(_T(""))
{

}

Find::~Find()
{
}

void Find::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TableName);
	DDX_Text(pDX, IDC_EDIT4, m_ColumnName);
	DDX_Text(pDX, IDC_EDIT2, m_ColumnValue);
}


BEGIN_MESSAGE_MAP(Find, CDialogEx)
	ON_BN_CLICKED(IDOK, &Find::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Find::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_OPEN, &Find::OnBnClickedOpen)
END_MESSAGE_MAP()


// Обработчики сообщений Find



void Find::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);

	CDialogEx::OnOK();
}


void Find::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}

string Find::CStoStr(CString value)
{
	CT2CA CS_value(value);
	string str_value(CS_value);
	return str_value;
}


void Find::OnBnClickedOpen()
{
	// TODO: добавьте свой код обработчика уведомлений
}
