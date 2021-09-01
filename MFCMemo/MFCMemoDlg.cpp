
// MFCMemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCMemo.h"
#include "MFCMemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void THISONEISCLICKED();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

//요거 확인해야 됨..
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_BN_CLICKED(THATBUTTON, &CAboutDlg::OnBnClickedThatbutton)
END_MESSAGE_MAP()


// CMFCMemoDlg 대화 상자



CMFCMemoDlg::CMFCMemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO_DIALOG, pParent)
	//, strMemo(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_MEMO1, CMemo1);
	DDX_Control(pDX, IDC_TB_MEMO2, CMemo2);
	DDX_Control(pDX, IDC_RADIO1, CRadio1);
	DDX_Control(pDX, IDC_RADIO2, CRadio2);
}

BEGIN_MESSAGE_MAP(CMFCMemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(THATBUTTON, &CMFCMemoDlg::OnBnClickedThatbutton)
	ON_COMMAND(ID_Menu_Exit, &CMFCMemoDlg::OnMenuExit)
	ON_COMMAND(ID_Menu_Lower, &CMFCMemoDlg::OnMenuLower)
	ON_COMMAND(ID_Menu_Upper, &CMFCMemoDlg::OnMenuUpper)
END_MESSAGE_MAP()


// CMFCMemoDlg 메시지 처리기

BOOL CMFCMemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCMemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCMemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCMemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCMemoDlg::OnBnClickedThatbutton()
{
	int static Count = 0;
	/*
	char buf[1024];
	//LPCW == Wchar(Widecharacter) == 2byte(short) == word: <unicode용> vs LPSTR == char*
	CMemo1.GetWindowTextA(buf, 1024); //기본 문자열 처리를 유니코드가 아니게->ASCI로
	CMemo2.SetWindowTextA(buf);
	
	//기본 설정을 ASCII 로 맞춤
	CString cstr, s1;
	//A(ASCII==char)->1byte, W(wchar)->2byte
	CMemo1.GetWindowTextA(cstr);
	//((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == 0
	if (CRadio1.GetState()) s1 = cstr.MakeLower(); //라디오버튼1이 체크되어 있다면..
	//if (Count % 2 == 1) s1 = cstr.MakeLower(); 위의 카운터와 연동
	else s1 = cstr.MakeUpper();
	CMemo2.SetWindowTextA(s1);
	*/
	
	CString cs, cs1;
	char buf[1024]; 
	char* sp = buf;
	char* str = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; *(str + i); i++) // while( str[i] != 0 ) 과 같은 의미
	{
		//char* 이용
		sprintf(sp, "%02X ", str[i]);
		while (*sp++);

		//CString class 이용
		cs1.Format("%02X ", str[i]);
		cs += cs1; //연산자 오버라이딩
	}
	//CMemo2.SetWindowTextA(buf);
	CMemo2.SetWindowTextA(cs); //ASCII ANSI 관련 있음
	
	Count++;
}


void CMFCMemoDlg::OnMenuExit()
{
	EndDialog(0); //다이얼로그 종료
}


void CMFCMemoDlg::OnMenuLower()
{
	CString cstr;
	CMemo1.GetWindowTextA(cstr);
	CMemo2.SetWindowTextA(cstr.MakeLower());
}


void CMFCMemoDlg::OnMenuUpper()
{
	CString cstr;
	CMemo1.GetWindowTextA(cstr);
	CMemo2.SetWindowTextA(cstr.MakeUpper());
}
