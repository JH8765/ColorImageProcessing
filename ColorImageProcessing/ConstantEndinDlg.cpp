// ConstantEndinDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantEndinDlg.h"


// CConstantEndinDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantEndinDlg, CDialog)

CConstantEndinDlg::CConstantEndinDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_ENDIN, pParent)
	, m_constant(0)
{

}

CConstantEndinDlg::~CConstantEndinDlg()
{
}

void CConstantEndinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
	DDV_MinMaxDouble(pDX, m_constant, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstantEndinDlg, CDialog)
END_MESSAGE_MAP()


// CConstantEndinDlg 메시지 처리기
