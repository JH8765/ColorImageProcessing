#pragma once
#include "afxdialogex.h"


// CCONSTANT 대화 상자

class CCONSTANT : public CDialog
{
	DECLARE_DYNAMIC(CCONSTANT)

public:
	CCONSTANT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCONSTANT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
