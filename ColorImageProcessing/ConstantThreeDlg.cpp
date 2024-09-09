// ConstantThreeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "ConstantThreeDlg.h"


// CConstantThreeDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantThreeDlg, CDialogEx)

CConstantThreeDlg::CConstantThreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONSTANT_THREE, pParent)
	, m_constant1(0)
	, m_constant2(0)
	, m_constant3(0)
{

}

CConstantThreeDlg::~CConstantThreeDlg()
{
}

void CConstantThreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSTANT1, m_constant1);
	DDX_Text(pDX, IDC_EDIT__CONSTANT2, m_constant2);
	DDX_Text(pDX, IDC_EDIT__CONSTANT3, m_constant3);
}


BEGIN_MESSAGE_MAP(CConstantThreeDlg, CDialogEx)
END_MESSAGE_MAP()


// CConstantThreeDlg 메시지 처리기
