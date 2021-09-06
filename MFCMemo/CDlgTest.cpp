// CDlgTest.cpp: 구현 파일
//

#include "pch.h"
#include "MFCMemo.h"
#include "CDlgTest.h"
#include "afxdialogex.h"


// CDlgTest 대화 상자

IMPLEMENT_DYNAMIC(CDlgTest, CDialogEx)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_TEST, pParent)
{

}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CDlgTest, CDialogEx)
//	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgTest::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


