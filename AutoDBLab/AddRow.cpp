// AddRow.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "afxdialogex.h"
#include "AddRow.h"


// Диалоговое окно AddRow

IMPLEMENT_DYNAMIC(AddRow, CDialogEx)

AddRow::AddRow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

AddRow::~AddRow()
{
}

void AddRow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddRow, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений AddRow
