// RadioDogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "RadioDogDlg.h"


// CRadioDogDlg 대화 상자

IMPLEMENT_DYNAMIC(CRadioDogDlg, CDialog)

CRadioDogDlg::CRadioDogDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RADIO_DOG, pParent)
	, m_radio1(0)
{

}

CRadioDogDlg::~CRadioDogDlg()
{
}

void CRadioDogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}


BEGIN_MESSAGE_MAP(CRadioDogDlg, CDialog)
END_MESSAGE_MAP()


// CRadioDogDlg 메시지 처리기
