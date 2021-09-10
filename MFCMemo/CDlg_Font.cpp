// CDlg_Font.cpp: 구현 파일
//

#include "pch.h"
#include "MFCMemo.h"
#include "CDlg_Font.h"
#include "MFCMemoDlg.h"
#include "afxdialogex.h"


// CDlg_Font 대화 상자

IMPLEMENT_DYNAMIC(CDlg_Font, CDialogEx)

CDlg_Font::CDlg_Font(int fontSize, CString fontName, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_FONT, pParent)
{
	CString tmp;
	tmp.Format(_T("%d"), (fontSize / 10));
	this->ChosenSize = tmp;
	this->ChosenFont = fontName;
}

CDlg_Font::~CDlg_Font()
{
}

void CDlg_Font::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FONT, ComboFont);
	DDX_Control(pDX, IDC_COMBO_SIZE, ComboSize);
}


BEGIN_MESSAGE_MAP(CDlg_Font, CDialogEx)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDOK, &CDlg_Font::OnBnClickedOk)
END_MESSAGE_MAP()




void CDlg_Font::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


//여기에서 콤보박스에 들어갈 요소들을 배치함
BOOL CDlg_Font::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//EnumFontFamiliesExA;
	// 폰트를 리스트로 뽑아서 for문으로 자동공급할수도 있지만 
	// 여기선 개발의 편의를 위해 그냥 대입
	ComboFont.AddString(_T("Arial"));
	ComboFont.AddString(_T("Bahnschrift"));
	ComboFont.AddString(_T("Consolas"));
	ComboFont.AddString(_T("Dubai"));
	ComboFont.AddString(_T("Georgia"));
	ComboFont.AddString(_T("NanumGothicCoding"));
	
	// 이걸 atoi()와 for문으로 돌릴수는 있지만 미묘함
	ComboSize.AddString("08"); ComboSize.AddString("09");
	ComboSize.AddString("10"); ComboSize.AddString("11");
	ComboSize.AddString("12"); ComboSize.AddString("14");
	ComboSize.AddString("16"); ComboSize.AddString("18");
	ComboSize.AddString("20"); ComboSize.AddString("24");
	ComboSize.AddString("26"); ComboSize.AddString("30");

	//CString STH = _T("Arial"); // _T() 괄호 챙길 것

	okay = FALSE;

	ComboFont.SetWindowTextA(ChosenFont);
	ComboSize.SetWindowTextA(ChosenSize);

	//ComboBox_

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 확인 버튼 누르면 콤보박스 값 반환
void CDlg_Font::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ComboFont.GetWindowTextA(ChosenFont);
	ComboSize.GetWindowTextA(ChosenSize);
	okay = TRUE;


	CDialogEx::OnOK();
}
