// AddingRow_Spares.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "afxdialogex.h"
#include "AddingRow_Spares.h"

// Диалоговое окно AddingRow_Spares

IMPLEMENT_DYNAMIC(AddingRow_Spares, CDialogEx)

AddingRow_Spares::AddingRow_Spares(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_Id_Spares(_T(""))
	, m_Price(_T(""))
	, m_CarModel_Spares(_T(""))
{

}

AddingRow_Spares::~AddingRow_Spares()
{
}

void AddingRow_Spares::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Price);
	DDX_Text(pDX, IDC_EDIT3, m_CarModel_Spares);
	DDX_Text(pDX, IDC_EDIT1, m_Id_Spares);
}


BEGIN_MESSAGE_MAP(AddingRow_Spares, CDialogEx)
	ON_BN_CLICKED(IDAPPLY, &AddingRow_Spares::OnBnClickedApply)
	ON_BN_CLICKED(IDCANCEL, &AddingRow_Spares::OnBnClickedCancel)
END_MESSAGE_MAP()


// Обработчики сообщений AddingRow_Spares
string AddingRow_Spares::CStoStr(CString value)
{
	CT2CA CS_value(value);
	string str_value(CS_value);
	return str_value;
}

void AddingRow_Spares::OnBnClickedApply()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);

	if (isChangeS) {
		string sql = "UPDATE `mylabdb`.`spares` SET `spare_id` = '" + CStoStr(m_Id_Spares) + "', `price` = '" + CStoStr(m_Price) +"', `car_model` = '" + CStoStr(m_CarModel_Spares) + "' WHERE (`spare_id` = '" + CStoStr(id_SP_Change) +"');";
		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка изменения данных!");
		} 
	}
	else
	{
		string sql = "INSERT INTO `mylabdb`.`spares` (`spare_id`, `price`, `car_model`) VALUES ('" + CStoStr(m_Id_Spares) + "', '" + CStoStr(m_Price) + "', '" + CStoStr(m_CarModel_Spares) + "')";

		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка заполнения данных!");
		}
	}
	
	

	CDialogEx::OnOK();
}


void AddingRow_Spares::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}
