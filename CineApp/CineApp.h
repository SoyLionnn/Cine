
// CineApp.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CCineAppApp:
// Consulte CineApp.cpp para obtener información sobre la implementación de esta clase
//

class CCineAppApp : public CWinApp
{
public:
	CCineAppApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CCineAppApp theApp;
