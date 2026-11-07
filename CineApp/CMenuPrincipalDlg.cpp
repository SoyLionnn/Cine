// CMenuPrincipalDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "CineApp.h"
#include "afxdialogex.h"
#include "CMenuPrincipalDlg.h"


// Cuadro de diálogo de CMenuPrincipalDlg

IMPLEMENT_DYNAMIC(CMenuPrincipalDlg, CDialogEx)

CMenuPrincipalDlg::CMenuPrincipalDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MENU_PRINCIPAL, pParent)
{

}

CMenuPrincipalDlg::~CMenuPrincipalDlg()
{
}

void CMenuPrincipalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMenuPrincipalDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CMenuPrincipalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMenuPrincipalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_STATIC_Admin, &CMenuPrincipalDlg::OnBnClickedStaticAdmin)
END_MESSAGE_MAP()


// Controladores de mensajes de CMenuPrincipalDlg

void CMenuPrincipalDlg::OnBnClickedButton3()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}

void CMenuPrincipalDlg::OnBnClickedButton1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}

void CMenuPrincipalDlg::OnBnClickedStaticAdmin()
{
	
}
BOOL CMenuPrincipalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 1. Mostrar información en el texto superior (Opcional, requiere un Static Text con ID IDC_TXT_INFO)
	// CString info;
	// info.Format(_T("Sesión activa | Rol: %s"), m_rolUsuario);
	// SetDlgItemText(IDC_TXT_INFO, info); 

	// 2. Control de acceso según el rol
	if (m_rolUsuario == _T("Vendedor"))
	{
		// Oculta el contenedor del panel administrador (asegúrate de que este sea el ID de tu Group Box)
		GetDlgItem(IDC_STATIC_Admin)->ShowWindow(SW_HIDE);

		// Oculta los botones que estén dentro de ese panel
		// GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE); 
	}

	return TRUE;
}