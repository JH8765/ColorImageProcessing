// RadioThreeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "RadioThreeDlg.h"


// CRadioThreeDlg 대화 상자

IMPLEMENT_DYNAMIC(CRadioThreeDlg, CDialog)

CRadioThreeDlg::CRadioThreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RADIO_THREE, pParent)
	, m_radio1(0)
{

}

CRadioThreeDlg::~CRadioThreeDlg()
{
}

void CRadioThreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}


BEGIN_MESSAGE_MAP(CRadioThreeDlg, CDialog)
END_MESSAGE_MAP()


// CRadioThreeDlg 메시지 처리기
