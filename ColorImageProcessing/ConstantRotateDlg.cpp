// ConstantRotateDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantRotateDlg.h"


// CConstantRotate 대화 상자

IMPLEMENT_DYNAMIC(CConstantRotateDlg, CDialog)

CConstantRotateDlg::CConstantRotateDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_ROTATE, pParent)
	, m_constant(0)
{

}

CConstantRotateDlg::~CConstantRotateDlg()
{
}

void CConstantRotateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
}


BEGIN_MESSAGE_MAP(CConstantRotateDlg, CDialog)
END_MESSAGE_MAP()


// CConstantRotateDlg 메시지 처리기
