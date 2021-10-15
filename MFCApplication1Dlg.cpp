
// MFCApplication1Dlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "iostream"
#include "string"
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


// Cuadro de diálogo de CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, pantalla0(0)
	, pantalla(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PANTALLA1_STATIC, pantalla0);
	DDX_Text(pDX, IDC_PANTALLA_EDIT1, pantalla);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B1_BUTTON, &CMFCApplication1Dlg::OnBnClickedB1Button)
	ON_BN_CLICKED(IDC_0_BUTTON, &CMFCApplication1Dlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CMFCApplication1Dlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CMFCApplication1Dlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CMFCApplication1Dlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CMFCApplication1Dlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CMFCApplication1Dlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CMFCApplication1Dlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CMFCApplication1Dlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CMFCApplication1Dlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_SUM_BUTTON, &CMFCApplication1Dlg::OnBnClickedSumButton)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_MUL_BUTTON, &CMFCApplication1Dlg::OnBnClickedMulButton)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CMFCApplication1Dlg::OnBnClickedDivButton)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

long op1, op2, contador = 0;
int sumop1, sumop2, resultadosum;
int mulop1, mulop2, resultadomul;
int divop1, divop2, resultadodiv;
int CodOp;


void CMFCApplication1Dlg::OnBnClickedB1Button()
{
	// Aqui va todo lo del boton 1
	UpdateData(TRUE);
		if (contador== 0) 
		{
			pantalla = "1";
			pantalla0 = 1;
		}

		else 
		{
			op2 = pantalla0 * 10;
			op1 = op2+1;
			pantalla0 = op1;

			CString cadena;
			cadena.Format(L"%d", op1);
			pantalla = cadena;

		}
	contador++;
	UpdateData(FALSE);

}


void CMFCApplication1Dlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (contador == 0) {
		pantalla = "0";
		pantalla0 = 0;
	}
	else
	{
		op2 = pantalla0 * 10;
		op1 = op2;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;


	}
	
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked2Button()
{
	// Aqui va todo lo del boton 2

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "2";
		pantalla0 = 2;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 2;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked3Button()
{
	// Aqui va todo lo del boton 3

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "3";
		pantalla0 = 3;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 3;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked4Button()
{
	// Aqui va todo lo del boton 2

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "4";
		pantalla0 = 4;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 4;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked5Button()
{
	// Aqui va todo lo del boton 2

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "5";
		pantalla0 = 5;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 5;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked6Button()
{
	// Aqui va todo lo del boton 2

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "6";
		pantalla0 = 6;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 6;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked7Button()
{
	// Aqui va todo lo del boton 7

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "7";
		pantalla0 = 7;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 7;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked8Button()
{
	// Aqui va todo lo del boton 8

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "8";
		pantalla0 = 8;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 8;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClicked9Button()
{
	// Aqui va todo lo del boton 9

	UpdateData(TRUE);
	if (contador == 0)
	{
		pantalla = "9";
		pantalla0 = 9;
	}

	else
	{
		op2 = pantalla0 * 10;
		op1 = op2 + 9;
		pantalla0 = op1;

		CString cadena;
		cadena.Format(L"%d", op1);
		pantalla = cadena;

	}
	contador++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedSumButton()
{

	CodOp = 1;
	sumop1 = op1;
	sumop2 = op2;
	resultadosum = pantalla0;
	contador = 0;

	CString cadena;
	cadena.Format(L"%d +", resultadosum);
	pantalla = cadena;
	UpdateData(FALSE);

}




void CMFCApplication1Dlg::OnBnClickedMulButton()
{
	CodOp = 3;
	mulop1 = op1;
	mulop2 = op2;
	resultadomul = pantalla0;
	contador = 0;

	CString cadena;
	cadena.Format(L"%d *", resultadosum);
	pantalla = cadena;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedDivButton()
{
	
	CodOp = 4;
	divop1 = op1;
	divop2 = op2;
	resultadodiv = pantalla0;
	contador = 0;

	CString cadena;
	cadena.Format(L"%d +¿/", resultadosum);
	pantalla = cadena;
	UpdateData(FALSE);
}
