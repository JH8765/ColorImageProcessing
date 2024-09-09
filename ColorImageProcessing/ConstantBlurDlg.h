#pragma once
#include "afxdialogex.h"


// CConstantBlurDlg 대화 상자

class CConstantBlurDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantBlurDlg)

public:
	CConstantBlurDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantBlurDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_BLUR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
