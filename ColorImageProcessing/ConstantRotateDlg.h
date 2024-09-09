#pragma once
#include "afxdialogex.h"


// CConstantRotateDlg 대화 상자

class CConstantRotateDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantRotateDlg)

public:
	CConstantRotateDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantRotateDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_ROTATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
