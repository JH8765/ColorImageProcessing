#pragma once
#include "afxdialogex.h"


// CConstantDogDlg 대화 상자

class CConstantDogDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantDogDlg)

public:
	CConstantDogDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantDogDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_DOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant1;
	double m_constant2;
	double m_constant3;
};
