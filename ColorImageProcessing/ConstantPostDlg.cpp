// ConstantPostDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantPostDlg.h"


// CConstantPostDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantPostDlg, CDialog)

CConstantPostDlg::CConstantPostDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_POST, pParent)
	, m_constant(0)
{

}

CConstantPostDlg::~CConstantPostDlg()
{
}

void CConstantPostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
	DDV_MinMaxDouble(pDX, m_constant, 2, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantPostDlg, CDialog)
END_MESSAGE_MAP()


// CConstantPostDlg 메시지 처리기
