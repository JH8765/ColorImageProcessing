// ConstantDogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantDogDlg.h"


// CConstantDogDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantDogDlg, CDialog)

CConstantDogDlg::CConstantDogDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_DOG, pParent)
	, m_constant1(0)
	, m_constant2(0)
	, m_constant3(0)
{

}

CConstantDogDlg::~CConstantDogDlg()
{
}

void CConstantDogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
	DDX_Text(pDX, IDC_EDIT_CONSTANT3, m_constant3);
	DDV_MinMaxDouble(pDX, m_constant1, 1, DBL_MAX);
	DDV_MinMaxDouble(pDX, m_constant2, 0.000001, DBL_MAX);
	DDV_MinMaxDouble(pDX, m_constant3, 0.000001, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantDogDlg, CDialog)
END_MESSAGE_MAP()


// CConstantDogDlg 메시지 처리기
