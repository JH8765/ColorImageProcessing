#pragma once
#include "afxdialogex.h"


// CRadioThreeDlg 대화 상자

class CRadioThreeDlg : public CDialog
{
	DECLARE_DYNAMIC(CRadioThreeDlg)

public:
	CRadioThreeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRadioThreeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RADIO_THREE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_radio1;
};
