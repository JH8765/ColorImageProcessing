// ConstantTwoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantTwoDlg.h"


// CConstantTwoDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantTwoDlg, CDialog)

CConstantTwoDlg::CConstantTwoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_TWO, pParent)
	, m_constant1(0)
	, m_constant2(0)
{

}

CConstantTwoDlg::~CConstantTwoDlg()
{
}

void CConstantTwoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDX_Text(pDX, IDC_EDIT_CONSTANT2, m_constant2);
}


BEGIN_MESSAGE_MAP(CConstantTwoDlg, CDialog)
END_MESSAGE_MAP()


// CConstantTwoDlg 메시지 처리기
