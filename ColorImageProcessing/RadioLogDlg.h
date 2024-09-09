#pragma once
#include "afxdialogex.h"


// CRadioLogDlg 대화 상자

class CRadioLogDlg : public CDialog
{
	DECLARE_DYNAMIC(CRadioLogDlg)

public:
	CRadioLogDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRadioLogDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RADIO_LOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_radio1;
};
