// MFCMemoDlg.h: 헤더 파일

#pragma once


// CMFCMemoDlg 대화 상자
class CMFCMemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCMemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedThatbutton();
	CEdit CMemo1;
	CEdit CMemo2;
	CButton CRadio1;
	CButton CRadio2;
	afx_msg void OnMenuExit();
	afx_msg void OnMenuLower();
	afx_msg void OnMenuUpper();
	afx_msg void OnMenuHex();
	afx_msg void OnMenuOpenf();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnBnClickedBtnCalltest();
	afx_msg void OnMenuSaveAs();
};
