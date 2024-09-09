
// ColorImageProcessingView.h: CColorImageProcessingView 클래스의 인터페이스
//

#pragma once


class CColorImageProcessingView : public CView
{
protected: // serialization에서만 만들어집니다.
	CColorImageProcessingView() noexcept;
	DECLARE_DYNCREATE(CColorImageProcessingView)

// 특성입니다.
public:
	CColorImageProcessingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CColorImageProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEqualImage();
	afx_msg void OnAddImage();
	afx_msg void OnMulImage();
	afx_msg void OnGrayScale();
	afx_msg void OnAndImage();
	afx_msg void OnOrImage();
	afx_msg void OnXorImage();
	afx_msg void OnNotImage();
	afx_msg void OnMonoMiddleImage();
	afx_msg void OnMonoMeanImage();
	afx_msg void OnMonoMedianImage();
	afx_msg void OnGammaImage();
	afx_msg void OnContrastImage();
	afx_msg void OnPostImage();
	afx_msg void OnZoominImage1();
	afx_msg void OnZoominImage2();
	afx_msg void OnZoominImage3();
	afx_msg void OnZoomoutImage1();
	afx_msg void OnZoomoutImage2();
	afx_msg void OnZoomoutImage3();
	afx_msg void OnRotateImage1();
	afx_msg void OnRotateImage2();
	afx_msg void OnRotateImage3();
	afx_msg void OnMoveImage();
	afx_msg void OnMirrorImage1();
	afx_msg void OnMirrorImage2();
	afx_msg void OnHistoStrechImage();
	afx_msg void OnHistoEndinImage();
	afx_msg void OnHistoEqualImage();
	afx_msg void OnEmbossRgb();
	afx_msg void OnEmbossHsi();
	afx_msg void OnBlurImage();
	afx_msg void OnSharpHigh();
	afx_msg void OnSharpLow();
	afx_msg void OnSmoothingImage();
	afx_msg void OnSmoothingCustom();
	afx_msg void OnEdgeShift();
	afx_msg void OnEdgeHomo();
	afx_msg void OnEdgeSub();
	afx_msg void OnEdgeRobert();
	afx_msg void OnEdgePrewitt();
	afx_msg void OnEdgeSobel();
	afx_msg void OnEdgeLapl();
	afx_msg void OnEdgeLog();
	afx_msg void OnEdgeDog();
	afx_msg void OnChageRgb();
	afx_msg void OnChangeHsi();
	afx_msg void OnPickColor();
};

#ifndef _DEBUG  // ColorImageProcessingView.cpp의 디버그 버전
inline CColorImageProcessingDoc* CColorImageProcessingView::GetDocument() const
   { return reinterpret_cast<CColorImageProcessingDoc*>(m_pDocument); }
#endif

