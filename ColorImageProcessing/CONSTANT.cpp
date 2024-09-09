// CONSTANT.cpp: 구현 파일
//

#include "pch.h"
#include "ColorImageProcessing.h"
#include "afxdialogex.h"
#include "CONSTANT.h"


// CCONSTANT 대화 상자

IMPLEMENT_DYNAMIC(CCONSTANT, CDialog)

CCONSTANT::CCONSTANT(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONSTANT, pParent)
{

}

CCONSTANT::~CCONSTANT()
{
}

void CCONSTANT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCONSTANT, CDialog)
END_MESSAGE_MAP()


// CCONSTANT 메시지 처리기
