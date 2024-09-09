// ConstantSlowDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantSlowDlg.h"


// CConstantSlowDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantSlowDlg, CDialog)

CConstantSlowDlg::CConstantSlowDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_SLOW, pParent)
	, m_constant1(0)
	, m_constant2(0)
{

}

CConstantSlowDlg::~CConstantSlowDlg()
{
}

void CConstantSlowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
	DDV_MinMaxDouble(pDX, m_constant1, 1, DBL_MAX);
	DDV_MinMaxDouble(pDX, m_constant2, 1, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantSlowDlg, CDialog)
END_MESSAGE_MAP()


// CConstantSlowDlg 메시지 처리기
