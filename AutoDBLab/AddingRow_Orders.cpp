// AddingRow_Orders.cpp: файл реализации
//

#include "pch.h"
#include "AutoDBLab.h"
#include "afxdialogex.h"
#include "AddingRow_Orders.h"


// Диалоговое окно AddingRow_Orders

IMPLEMENT_DYNAMIC(AddingRow_Orders, CDialogEx)

AddingRow_Orders::AddingRow_Orders(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_Summa(_T(""))
	, m_Duration(_T(""))
	, m_Id_Orders(_T(""))
{

}

AddingRow_Orders::~AddingRow_Orders()
{
}

void AddingRow_Orders::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Summa);
	DDX_Text(pDX, IDC_EDIT3, m_Duration);
	DDX_Text(pDX, IDC_EDIT1, m_Id_Orders);
}


BEGIN_MESSAGE_MAP(AddingRow_Orders, CDialogEx)
	ON_BN_CLICKED(IDAPPLY, &AddingRow_Orders::OnBnClickedApply)
	ON_BN_CLICKED(IDCANCEL, &AddingRow_Orders::OnBnClickedCancel)
END_MESSAGE_MAP()


// Обработчики сообщений AddingRow_Orders

string AddingRow_Orders::CStoStr(CString value)
{
	CT2CA CS_value(value);
	string str_value(CS_value);
	return str_value;
}

void AddingRow_Orders::OnBnClickedApply()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);

	if (isChangeO) {
		string sql = "UPDATE `mylabdb`.`orders` SET `order_id` = '" + CStoStr(m_Id_Orders) + "', `summa` = '" + CStoStr(m_Summa) + "', `duration` = '" + CStoStr(m_Duration) + "' WHERE (`order_id` = '" + CStoStr(id_OR_Change) + "');";
		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка изменения данных!");
		}
	}
	//`order_id`,'" + CStoStr(m_Id_Orders) + "', 
	else {
		string sql = "INSERT INTO `mylabdb`.`orders` (`order_id`,`summa`, `duration`) VALUES ('" + CStoStr(m_Id_Orders) + "', '" + CStoStr(m_Summa) + "', '" + CStoStr(m_Duration) + "')";

		if (mysql_query(connect, sql.c_str())) {
			MessageBox(L"Ошибка заполнения данных!");
		}
	}
	
	

	CDialogEx::OnOK();
}


void AddingRow_Orders::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}
