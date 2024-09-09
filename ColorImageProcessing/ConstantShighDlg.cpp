// ConstantShighDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantShighDlg.h"


// CConstantShighDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantShighDlg, CDialog)

CConstantShighDlg::CConstantShighDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_SHIGH, pParent)
	, m_constant(0)
{

}

CConstantShighDlg::~CConstantShighDlg()
{
}

void CConstantShighDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
	DDV_MinMaxDouble(pDX, m_constant, 1, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantShighDlg, CDialog)
END_MESSAGE_MAP()


// CConstantShighDlg 메시지 처리기
