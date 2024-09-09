#pragma once
#include "afxdialogex.h"


// CConstantZoom2Dlg 대화 상자

class CConstantZoom2Dlg : public CDialog
{
	DECLARE_DYNAMIC(CConstantZoom2Dlg)

public:
	CConstantZoom2Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstantZoom2Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTANT_ZOOM2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_constant;
};
