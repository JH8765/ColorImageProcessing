#pragma once
#include "afxdialogex.h"


// CConstantShighDlg 대화 상자

class CConstantShighDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantShighDlg)

public:
	CConstantShighDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantShighDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_SHIGH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
