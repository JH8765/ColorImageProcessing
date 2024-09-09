// RadioLaplDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "RadioLaplDlg.h"


// CRadioLaplDlg 대화 상자

IMPLEMENT_DYNAMIC(CRadioLaplDlg, CDialog)

CRadioLaplDlg::CRadioLaplDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RADIO_LAPL, pParent)
	, m_radio1(0)
{

}

CRadioLaplDlg::~CRadioLaplDlg()
{
}

void CRadioLaplDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}


BEGIN_MESSAGE_MAP(CRadioLaplDlg, CDialog)
END_MESSAGE_MAP()


// CRadioLaplDlg 메시지 처리기
