
// MFCApplication1Dlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Construcción
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


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
	int pantalla0;
	CString pantalla;
	afx_msg void OnBnClickedB1Button();
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedSumButton();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedMulButton();
	afx_msg void OnBnClickedDivButton();
};
