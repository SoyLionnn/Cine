
// CineAppDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CCineAppDlg
class CCineAppDlg : public CDialogEx
{
// Construcción
public:
	CCineAppDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CINEAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV
	virtual void OnOK();

// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_usuario;
	CString m_contrasena;
	afx_msg void OnBnClickedBtnIngresar();
	afx_msg void OnEnChangeEditUsuario();
};
