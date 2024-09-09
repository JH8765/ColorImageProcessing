// ConstantSmoothDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantSmoothDlg.h"


// CConstantSmoothDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantSmoothDlg, CDialog)

CConstantSmoothDlg::CConstantSmoothDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_SMOOTH, pParent)
	, m_constant1(0)
	, m_constant2(0)
{

}

CConstantSmoothDlg::~CConstantSmoothDlg()
{
}

void CConstantSmoothDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
}


BEGIN_MESSAGE_MAP(CConstantSmoothDlg, CDialog)
END_MESSAGE_MAP()


// CConstantSmoothDlg 메시지 처리기
