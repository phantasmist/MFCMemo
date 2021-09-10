#pragma once


// DlgNew 대화 상자

class DlgNew : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNew)

public:
	DlgNew(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgNew();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_NEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	int result = -1;

	afx_msg void OnBnClickedYesSave();
	afx_msg void OnBnClickedNoSave();
	afx_msg void OnBnClickedUndo();
};
