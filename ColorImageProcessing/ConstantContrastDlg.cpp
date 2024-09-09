// ConstantContrastDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantContrastDlg.h"


// CConstantContrastDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantContrastDlg, CDialogEx)

CConstantContrastDlg::CConstantContrastDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONSTANT_CONTRAST, pParent)
	, m_constant(0)
{

}

CConstantContrastDlg::~CConstantContrastDlg()
{
}

void CConstantContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
}


BEGIN_MESSAGE_MAP(CConstantContrastDlg, CDialogEx)
END_MESSAGE_MAP()


// CConstantContrastDlg 메시지 처리기
