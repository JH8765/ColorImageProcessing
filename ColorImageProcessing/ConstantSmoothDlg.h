#pragma once
#include "afxdialogex.h"


// CConstantSmoothDlg 대화 상자

class CConstantSmoothDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantSmoothDlg)

public:
	CConstantSmoothDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantSmoothDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_SMOOTH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant1;
	double m_constant2;
};
