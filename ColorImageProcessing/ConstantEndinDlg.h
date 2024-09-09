#pragma once
#include "afxdialogex.h"


// CConstantEndinDlg 대화 상자

class CConstantEndinDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantEndinDlg)

public:
	CConstantEndinDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantEndinDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_ENDIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
