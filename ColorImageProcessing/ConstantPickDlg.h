#pragma once
#include "afxdialogex.h"


// CConstantPickDlg 대화 상자

class CConstantPickDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantPickDlg)

public:
	CConstantPickDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantPickDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_PICK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant1;
	double m_constant2;
};
