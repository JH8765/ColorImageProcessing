#pragma once
#include "afxdialogex.h"


// CRadioDogDlg 대화 상자

class CRadioDogDlg : public CDialog
{
	DECLARE_DYNAMIC(CRadioDogDlg)

public:
	CRadioDogDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRadioDogDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RADIO_DOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_radio1;
};
