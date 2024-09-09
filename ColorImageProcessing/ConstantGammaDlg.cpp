// ConstantGammaDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantGammaDlg.h"


// CConstantGammaDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantGammaDlg, CDialog)

CConstantGammaDlg::CConstantGammaDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_GAMMA, pParent)
	, m_constant(0)
{

}

CConstantGammaDlg::~CConstantGammaDlg()
{
}

void CConstantGammaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
}


BEGIN_MESSAGE_MAP(CConstantGammaDlg, CDialog)
END_MESSAGE_MAP()


// CConstantGammaDlg 메시지 처리기
