// ConstantHsiDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantHsiDlg.h"


// CConstantHsiDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantHsiDlg, CDialog)

CConstantHsiDlg::CConstantHsiDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_HSI, pParent)
	, m_constant1(0)
	, m_constant2(0)
	, m_constant3(0)
{

}

CConstantHsiDlg::~CConstantHsiDlg()
{
}

void CConstantHsiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDV_MinMaxDouble(pDX, m_constant1, -360, 360);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
	DDV_MinMaxDouble(pDX, m_constant2, -1, 1);
	DDX_Text(pDX, IDC_EDIT_CONSTANT3, m_constant3);
	DDV_MinMaxDouble(pDX, m_constant3, -255, 255);
}


BEGIN_MESSAGE_MAP(CConstantHsiDlg, CDialog)
END_MESSAGE_MAP()


// CConstantHsiDlg 메시지 처리기
