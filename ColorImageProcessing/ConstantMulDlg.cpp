// ConstantMulDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantMulDlg.h"


// CConstantMulDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantMulDlg, CDialog)

CConstantMulDlg::CConstantMulDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_MUL, pParent)
	, m_constant(0)
{

}

CConstantMulDlg::~CConstantMulDlg()
{
}

void CConstantMulDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
}


BEGIN_MESSAGE_MAP(CConstantMulDlg, CDialog)
END_MESSAGE_MAP()


// CConstantMulDlg 메시지 처리기
