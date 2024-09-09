// ConstantZoom2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantZoom2Dlg.h"


// CConstantZoom2Dlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantZoom2Dlg, CDialog)

CConstantZoom2Dlg::CConstantZoom2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT_ZOOM2, pParent)
	, m_constant(0)
{

}

CConstantZoom2Dlg::~CConstantZoom2Dlg()
{
}

void CConstantZoom2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT, m_constant);
	DDV_MinMaxDouble(pDX, m_constant, 1, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CConstantZoom2Dlg, CDialog)
END_MESSAGE_MAP()


// CConstantZoom2Dlg 메시지 처리기
