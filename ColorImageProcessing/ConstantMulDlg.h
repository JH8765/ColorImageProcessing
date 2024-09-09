#pragma once
#include "afxdialogex.h"


// CConstantMulDlg 대화 상자

class CConstantMulDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantMulDlg)

public:
	CConstantMulDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantMulDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_MUL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
