// DlgNew.cpp: 구현 파일
//

#include "pch.h"
#include "MFCMemo.h"
#include "DlgNew.h"
#include "afxdialogex.h"


// DlgNew 대화 상자

IMPLEMENT_DYNAMIC(DlgNew, CDialogEx)

DlgNew::DlgNew(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_NEW, pParent)
{

}

DlgNew::~DlgNew()
{
}

void DlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNew, CDialogEx)
	ON_BN_CLICKED(ID_YES_SAVE, &DlgNew::OnBnClickedYesSave)
	ON_BN_CLICKED(ID_NO_SAVE, &DlgNew::OnBnClickedNoSave)
	//ON_BN_CLICKED(IDCANCEL, &DlgNew::OnBnClickedCancel)
	//ON_BN_CLICKED(ID_NO_SAVE2, &DlgNew::OnBnClickedNoSave2)
	ON_BN_CLICKED(ID_UNDO, &DlgNew::OnBnClickedUndo)
END_MESSAGE_MAP()


// DlgNew 메시지 처리기


void DlgNew::OnBnClickedYesSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	result = 1;
	CDialogEx::OnOK();
}


void DlgNew::OnBnClickedNoSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	result = 0;
	CDialogEx::OnOK();
}

void DlgNew::OnBnClickedUndo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	result = -1;
	CDialogEx::OnOK();
}
