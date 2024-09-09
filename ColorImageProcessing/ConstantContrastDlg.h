#pragma once
#include "afxdialogex.h"


// CConstantContrastDlg 대화 상자

class CConstantContrastDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConstantContrastDlg)

public:
	CConstantContrastDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantContrastDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_CONTRAST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
