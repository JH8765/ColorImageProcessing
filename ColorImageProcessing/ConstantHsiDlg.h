#pragma once
#include "afxdialogex.h"


// CConstantHsiDlg 대화 상자

class CConstantHsiDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantHsiDlg)

public:
	CConstantHsiDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantHsiDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_HSI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant1;
	double m_constant2;
	double m_constant3;
};
