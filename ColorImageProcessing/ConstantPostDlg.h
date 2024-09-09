#pragma once
#include "afxdialogex.h"


// CConstantPostDlg 대화 상자

class CConstantPostDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantPostDlg)

public:
	CConstantPostDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantPostDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_POST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
