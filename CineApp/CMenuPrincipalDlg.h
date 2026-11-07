#pragma once
#include "afxdialogex.h"


// Cuadro de diálogo de CMenuPrincipalDlg

class CMenuPrincipalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuPrincipalDlg)

public:
	CMenuPrincipalDlg(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~CMenuPrincipalDlg();
	CString m_rolUsuario; // <-- Agrega esta línea aquí





// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU_PRINCIPAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Soporte DDX/DDV
	virtual BOOL OnInitDialog(); // <-- AGREGA ESTA LÍNEA AQUÍ
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedStaticAdmin();
};
