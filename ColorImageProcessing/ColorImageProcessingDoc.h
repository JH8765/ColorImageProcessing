
// ColorImageProcessingDoc.h: CColorImageProcessingDoc 클래스의 인터페이스
//


#pragma once


class CColorImageProcessingDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CColorImageProcessingDoc() noexcept;
	DECLARE_DYNCREATE(CColorImageProcessingDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CColorImageProcessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	unsigned char** m_inImageR = NULL;
	unsigned char** m_inImageG = NULL;
	unsigned char** m_inImageB = NULL;
	unsigned char** m_outImageR = NULL;
	unsigned char** m_outImageG = NULL;
	unsigned char** m_outImageB = NULL;

	int m_inH = 0;
	int m_inW = 0;
	int m_outH = 0;
	int m_outW = 0;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	unsigned char** OnMalloc2D(int h, int w);
	void OnFree2D(unsigned char** memory, int h);
	virtual void OnCloseDocument();
	void OnFreeOutImage();
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void OnEqualImage();
	void OnAddImage();
	void OnMulImage();
	void OnGrayScale();
	void OnAndImage();
	void OnOrImage();
	void OnXorImage();
	void OnNotImage();
	void OnMonoMiddleImage();
	void OnMonoMeanImage();
	void OnMonoMedianImage();
	void OnSorting(unsigned char* arr, int l, int r);
	void OnMergeSort(unsigned char* arr, unsigned char* tmp, int l, int r);
	void OnMerge(unsigned char* arr, unsigned char* tmp, int l, int m, int r);
	void OnGammaImage();
	void OnContrastImage();
	void OnPostImage();
	void OnZoominImage1();
	void OnZoominImage2();
	void OnZoominImage3();
	void OnZoomoutImage1();
	void OnZoomoutImage2();
	void OnZoomoutImage3();
	void OnRotateImage1();
	void OnRotateImage2();
	void OnRotateImage3();
	void OnMoveImage();
	void OnMirrorImage1();
	void OnMirrorImage2();
	void OnHistoStrechImage();
	double* RGB2HSI(int R, int G, int B);
	unsigned char* HSI2RGB(double H, double S, double I);
	double** OnMallocDouble2D(int h, int w, double initVal);
	void OnFreeDouble2D(double** memory, int h);
	void OnHistoEndinImage();
	void OnHistoEqualImage();
	void OnEmbossRgb();
	void OnEmbossHsi();
	void OnConvRGB(double** mask, int size);
	void OnBlurImage();
	void OnSharpHigh();
	void OnSharpLow();
	void OnSmoothingImage();
	void OnSmoothingCustom();
	void OnEdgeShift();
	void OnEdgeHomo();
	void OnEdgeSub();
	void OnEdgeRobert();
	void OnEdgePrewitt();
	void OnEdgeSobel();
	void OnEdgeLapl();
	void OnEdgeLog();
	void OnEdgeDog();
	void OnChageRgb();
	void OnChangeHsi();
	void OnPickColor();
	void InImg2OutImg();
	unsigned char** m_oriImageR = NULL;
	unsigned char** m_oriImageG = NULL;
	unsigned char** m_oriImageB = NULL;
	int m_oriH = 0;
	int m_oriW = 0;
};
