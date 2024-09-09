// ConstantPickDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantPickDlg.h"


// CConstantPickDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantPickDlg, CDialog)

CConstantPickDlg::CConstantPickDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_PICK, pParent)
	, m_constant1(0)
	, m_constant2(0)
{

}

CConstantPickDlg::~CConstantPickDlg()
{
}

void CConstantPickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDV_MinMaxDouble(pDX, m_constant1, -360, 360);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
	DDV_MinMaxDouble(pDX, m_constant2, -360, 360);
}


BEGIN_MESSAGE_MAP(CConstantPickDlg, CDialog)
END_MESSAGE_MAP()


// CConstantPickDlg 메시지 처리기
