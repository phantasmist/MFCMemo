#pragma once


// CDlg_Font 대화 상자

class CDlg_Font : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Font)

public:
	CDlg_Font(int fontSize = 110, CString fontName = _T("Consolas"), CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_Font();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FONT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox ComboFont;
	CComboBox ComboSize;
	CString ChosenFont, ChosenSize;
	BOOL okay = FALSE;
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
