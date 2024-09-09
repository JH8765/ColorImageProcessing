// RadioLogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "RadioLogDlg.h"


// CRadioLogDlg 대화 상자

IMPLEMENT_DYNAMIC(CRadioLogDlg, CDialog)

CRadioLogDlg::CRadioLogDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RADIO_LOG, pParent)
	, m_radio1(0)
{

}

CRadioLogDlg::~CRadioLogDlg()
{
}

void CRadioLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}


BEGIN_MESSAGE_MAP(CRadioLogDlg, CDialog)
END_MESSAGE_MAP()


// CRadioLogDlg 메시지 처리기
