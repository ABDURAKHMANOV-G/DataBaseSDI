// AddingRow.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "afxdialogex.h"
#include "AddingRow.h"



// Диалоговое окно AddingRow

IMPLEMENT_DYNAMIC(AddingRow, CDialogEx)

AddingRow::AddingRow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_Id(_T(""))
	, m_Name(_T(""))
	, m_CarModel(_T(""))
{

}

AddingRow::~AddingRow()
{
}

void AddingRow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_CarModel);
	DDX_Text(pDX, IDC_EDIT1, m_Id);
}


BEGIN_MESSAGE_MAP(AddingRow, CDialogEx)
	ON_BN_CLICKED(IDAPPLY, &AddingRow::OnBnClickedApply)
	ON_BN_CLICKED(IDCANCEL, &AddingRow::OnBnClickedCancel)
END_MESSAGE_MAP()


// Обработчики сообщений AddingRow


string AddingRow::CStoStr(CString value)
{
	CT2CA CS_value(value);
	string str_value(CS_value);
	return str_value;
}

void AddingRow::OnBnClickedApply()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);
	
	if (isChangeC) {
		string sql = "UPDATE `mylabdb`.`clients` SET `client_id` = '" + CStoStr(m_Id) + "', `username` = '" + CStoStr(m_Name) + "', `car_model` = '" + CStoStr(m_CarModel) + "' WHERE (`client_id` = '" + CStoStr(id_CL_Change) + "');";
		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка изменения данных!");
		}
	}
	else 
	{
		string sql = "INSERT INTO `mylabdb`.`clients` (`client_id`, `username`, `car_model`) VALUES ('" + CStoStr(m_Id) + "','" + CStoStr(m_Name) + "', '" + CStoStr(m_CarModel) + "')";

		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка заполнения данных!");
		}
	}

	CDialogEx::OnOK();

}


void AddingRow::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}
