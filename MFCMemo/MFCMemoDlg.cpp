
// MFCMemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCMemo.h"
#include "MFCMemoDlg.h"
#include "CDlg_Font.h"
#include "DlgNew.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma once

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
	//afx_msg void OnMenuSave();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



//CAboutDlg라는 점 기억
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_BN_CLICKED(THATBUTTON, &CAboutDlg::OnBnClickedThatbutton)
	//ON_COMMAND(ID_Menu_OpenF, &CAboutDlg::OnMenuOpenf)
	//ON_COMMAND(ID_MENU_SAVE, &CAboutDlg::OnMenuSave)
END_MESSAGE_MAP()


// CMFCMemoDlg 대화 상자



CMFCMemoDlg::CMFCMemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// 멤버 변수 선언 파트
void CMFCMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_MEMO1, CMemo1);
	DDX_Control(pDX, IDC_TB_MEMO2, CMemo2);
}

//여기가 CMFCMemoDlg: 본판 다이얼로그임
BEGIN_MESSAGE_MAP(CMFCMemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(THATBUTTON, &CMFCMemoDlg::OnBnClickedThatbutton)
	ON_COMMAND(ID_Menu_Exit, &CMFCMemoDlg::OnMenuExit)
	ON_COMMAND(ID_Menu_Lower, &CMFCMemoDlg::OnMenuLower)
	ON_COMMAND(ID_Menu_Upper, &CMFCMemoDlg::OnMenuUpper)
	ON_COMMAND(ID_Menu_Hex, &CMFCMemoDlg::OnMenuHex)
	ON_COMMAND(ID_Menu_OpenF, &CMFCMemoDlg::OnMenuOpenf)
	ON_WM_SIZE()
	ON_WM_ACTIVATE()
	//ON_BN_CLICKED(IDC_BTN_CALLTEST, &CMFCMemoDlg::OnBnClickedBtnCalltest)
	ON_COMMAND(ID_MENU_SAVE_AS, &CMFCMemoDlg::OnMenuSaveAs)
	ON_COMMAND(ID_MENU_SAVE, &CMFCMemoDlg::OnMenuSave)
	ON_COMMAND(ID_MENU_NEW_WINDOW, &CMFCMemoDlg::OnMenuNewWindow)
	ON_COMMAND(ID_MENU_FONT, &CMFCMemoDlg::OnMenuFont)
END_MESSAGE_MAP()


// CMFCMemoDlg 메시지 처리기
// 생성시 호출: 컴포넌트/내부변수 초기화

BOOL CMFCMemoDlg::OnInitDialog() //이름 주목
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
	//OnSize(0, 500, 300); //여기선 창 사이즈 초기화 하면 안됨

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

//System Message(Event) 처리기
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

//여러 string 관련 잡설 + 과거 버튼 구현 요소들
/*
void CMFCMemoDlg::OnBnClickedThatbutton()
{
	int static Count = 0;
	
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
*/


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

//16진법 보기
//이거 왜 첫글자 변환하고 엔터 치는지 확인해야 됨
void CMFCMemoDlg::OnMenuHex()
{
	CString out, tmp, in;
	CMemo1.GetWindowTextA(in);

	for (int i = 0; i < in.GetLength(); i++) // while( str[i] != 0 ) 과 같은 의미
	{
		//CString class 이용
		tmp.Format("%02X ", (unsigned char)in[i]); //이걸 표시해줘야 한글이 안깨짐
		out += tmp; //연산자 오버라이딩
		if (i % 16 == 15) out += "\r\n"; //첫글자에서 엔터치는거 방지하기
	}
	CMemo2.SetWindowTextA(out); //A: ASCII ANSI 관련 있음

}



// 파일 열기 (Open File)
void CMFCMemoDlg::OnMenuOpenf()
{
	OPENFILENAME ofn;
	char fName[512];
	HWND hwnd =m_hWnd; 
	//HANDLE hd;
	FILE* fp;

	ZeroMemory(&ofn, sizeof(ofn)); //메모리 클리어
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = fName;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(fName);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
		fp = fopen(fName, "r+b"); // b가 있어야 \r이 읽어짐
		CString cstr; 
		char* buf = fName;

		//현재파일명과, 파일이 열렸는지 여부 체크
		fileOpened = TRUE;
		strcpy(currFileName, fName);


		while (fgets(buf, 512, fp) != NULL) //정상적으로 읽었다면
		{
			cstr += buf;
		}
		CMemo1.SetWindowTextA(cstr);
		CMemo2.SetWindowTextA(cstr);
		//fclose(fp); //이거 관련해서 강사님에게 질문
	}
  
	
}

//윈도우 사이즈 재조정 메시지
void CMFCMemoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (GetDlgItem(IDC_TB_MEMO1) != NULL)
	{	//SetWindowPos(STH, 시작점x, 시작점y, X_Width, Y_Width, STH)
		CMemo1.SetWindowPos(NULL, 5, 5, cx / 2 - 10, cy  - 10, 0);
		CMemo2.SetWindowPos(NULL, cx/2, 5, cx/2 - 10 , cy - 10, 0);
	}
}


void CMFCMemoDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	CRect r; // Client 영역 담는 구조체 클래스
	GetClientRect(&r); //현재 클라이언트의 사각형 받아오기
	OnSize(0, r.Width(), r.Height()); //사이즈 초기화
}


//다른이름으로 저장
//TODO .txt가 기본으로 붙도록 설정해야 함
void CMFCMemoDlg::OnMenuSaveAs()
{
	OPENFILENAME ofn;
	char fName[512];
	HWND hwnd = m_hWnd;
	//HANDLE hd;
	FILE* fp;

	ZeroMemory(&ofn, sizeof(ofn)); //메모리 클리어
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = fName;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(fName);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 2;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST; // | OFN_FILEMUSTEXIST;
	ofn.lpstrDefExt = ".TXT"; //기본 파일확장자


	if (GetSaveFileName(&ofn) == TRUE)
	{
		fp = fopen(fName, "w+b"); 
		CString cstr;
		CMemo2.GetWindowTextA(cstr); // cstr으로 제대로 복사가 됨

		//현재파일명과, 파일이 열렸는지 여부 체크
		fileOpened = TRUE;
		strcpy(currFileName, fName);
		//파일포인터가 멀쩡하면 파일로 출력
		if (fp != NULL)
			fputs((LPCTSTR)cstr, fp);

		CMemo1.SetWindowTextA(cstr);
		//fclose(fp);
	}
}


//그냥 저장 
// TODO: 가능하면 global 변수 제거.. static 변수를 쓰고싶지도 않다만..
void CMFCMemoDlg::OnMenuSave()
{
	// 현재 파일이 열려있다면 그 파일에 저장
	if (fileOpened == TRUE)
	{
		CString cstr;
		FILE* fp;
		fp = fopen(currFileName, "w+b");
		CMemo2.GetWindowTextA(cstr); // cstr으로 제대로 복사가 됨
		//파일포인터가 멀쩡하면 파일로 출력
		if (fp != NULL)
			fputs((LPCSTR)cstr, fp);

		CMemo1.SetWindowTextA(cstr);

	}
	//그게 아니라면 SaveAs 호출
	else
		CMFCMemoDlg::OnMenuSaveAs();
}

//New(새 항목)
void CMFCMemoDlg::OnMenuNewWindow()
{
	//저장할거냐 다이얼로그 팝업
	DlgNew _new_dlg;
	_new_dlg.DoModal();
	//취소가 아니면 실행
	if (_new_dlg.result != -1)
	{
		if (_new_dlg.result == 1)
			CMFCMemoDlg::OnMenuSave();
		//창 정리
		fileOpened = FALSE;
		CMemo1.SetWindowTextA("");
		CMemo2.SetWindowTextA("");
	}
}



//폰트 조절
//TODO: 현재 폰트를 다이얼로그 드랍다운 메뉴에 default로 표기
// 시스템 폰트 목록을 어디서 어떻게 추출할 수 있을까?  EnumFontFamilies 계열 함수로 가능함
// Bold/Italic 같은것도 설정 가능함 >> 시간 남으면 하자
void CMFCMemoDlg::OnMenuFont()
{
	//모달 다이얼로그 선언/실행
	CFont* m_pFont = new CFont();
	CDlg_Font font(fontSize, fontName, (CWnd * )nullptr);
	font.DoModal();
	//확인 버튼을 눌렀다면 모달 다이얼로그 반환값 반영
	if (font.okay == TRUE)
	{
		//폰트 포인터 선언		
		fontSize = atoi((LPCTSTR)(font.ChosenSize)) * 10;
		fontName = font.ChosenFont;
		//폰트 포인터 설정
		m_pFont->CreatePointFont(fontSize, fontName); //CreatePointFont(크기*10, 폰트명);
		//폰트 변경 반영
		CMemo1.SetFont(m_pFont);
		CMemo2.SetFont(m_pFont);
	}
	//delete m_pFont; //이거 있으면 폰트 깨짐
}
