
// CineAppDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "CineApp.h"
#include "CineAppDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <sstream>
#include "CMenuPrincipalDlg.h" // Asegúrate de incluir la cabecera de tu menú
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CCineAppDlg



CCineAppDlg::CCineAppDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CINEAPP_DIALOG, pParent)
	, m_usuario(_T(""))
	, m_contrasena(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCineAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USUARIO, m_usuario);
	DDX_Text(pDX, IDC_EDIT_CLAVE, m_contrasena);
}

BEGIN_MESSAGE_MAP(CCineAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INGRESAR, &CCineAppDlg::OnBnClickedBtnIngresar)
	ON_EN_CHANGE(IDC_EDIT_USUARIO, &CCineAppDlg::OnEnChangeEditUsuario)
END_MESSAGE_MAP()


// Controladores de mensajes de CCineAppDlg

BOOL CCineAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCineAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCineAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCineAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CCineAppDlg::OnBnClickedBtnIngresar()
{
	UpdateData(TRUE);

	// Convertir CString de MFC a std::string estándar
	CStringA usrA(m_usuario);
	CStringA pwdA(m_contrasena);
	std::string strUsuario = usrA.GetString();
	std::string strClave = pwdA.GetString();

	std::ifstream archivo("usuarios.txt");
	bool autenticado = false;
	std::string rolAsignado = "";

	if (archivo.is_open())
	{
		std::string linea;
		while (std::getline(archivo, linea))
		{
			std::stringstream ss(linea);
			std::string userFile, passFile, rolFile;

			// Separar la línea por comas
			std::getline(ss, userFile, ',');
			std::getline(ss, passFile, ',');
			std::getline(ss, rolFile, ',');
			
			if (userFile == strUsuario && passFile == strClave)
			{
				autenticado = true;
				rolAsignado = rolFile;
				break; // Detener la búsqueda si se encuentra
			}
		}
		archivo.close();
	}
	else
	{
		AfxMessageBox(_T("Error: No se pudo abrir el archivo usuarios.txt"));
		return;
	}

	if (autenticado)
	{
		// Ocultar login y pasar a la siguiente página
		ShowWindow(SW_HIDE);

		CMenuPrincipalDlg dlgMenu;
		dlgMenu.m_rolUsuario = CString(rolAsignado.c_str());
		dlgMenu.DoModal();

		// Cerrar el programa completamente al salir del menú
		EndDialog(IDOK);
	}
	else
	{
		AfxMessageBox(_T("Usuario o contraseña incorrectos.")); // Cumple validación requerida[cite: 3]
	}
}

void CCineAppDlg::OnEnChangeEditUsuario()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialogEx::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.


	// TODO:  Agregue aquí el controlador de notificación de controles
}
void CCineAppDlg::OnOK()
{
	// En lugar de cerrar, simula un clic en "Ingresar"
	OnBnClickedBtnIngresar();
}