// ConstantZoom1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantZoom1Dlg.h"


// CConstantZoom1Dlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantZoom1Dlg, CDialog)

CConstantZoom1Dlg::CConstantZoom1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_ZOOM1, pParent)
	, m_constant(0)
{

}

CConstantZoom1Dlg::~CConstantZoom1Dlg()
{
}

void CConstantZoom1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
	DDV_MinMaxDouble(pDX, m_constant, 1, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantZoom1Dlg, CDialog)
END_MESSAGE_MAP()


// CConstantZoom1Dlg 메시지 처리기
