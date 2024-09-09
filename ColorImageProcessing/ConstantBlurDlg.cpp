// ConstantBlurDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantBlurDlg.h"


// CConstantBlurDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantBlurDlg, CDialog)

CConstantBlurDlg::CConstantBlurDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_BLUR, pParent)
	, m_constant(0)
{

}

CConstantBlurDlg::~CConstantBlurDlg()
{
}

void CConstantBlurDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
}


BEGIN_MESSAGE_MAP(CConstantBlurDlg, CDialog)
END_MESSAGE_MAP()


// CConstantBlurDlg 메시지 처리기
