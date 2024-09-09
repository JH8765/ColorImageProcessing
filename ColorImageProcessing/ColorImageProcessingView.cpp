
// ColorImageProcessingView.cpp: CColorImageProcessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ColorImageProcessing.h"
#endif

#include "ColorImageProcessingDoc.h"
#include "ColorImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorImageProcessingView

IMPLEMENT_DYNCREATE(CColorImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CColorImageProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_EQUAL_IMAGE, &CColorImageProcessingView::OnEqualImage)
	ON_COMMAND(IDM_ADD_IMAGE, &CColorImageProcessingView::OnAddImage)
	ON_COMMAND(IDM_MUL_IMAGE, &CColorImageProcessingView::OnMulImage)
	ON_COMMAND(IDM_GRAY_SCALE, &CColorImageProcessingView::OnGrayScale)
	ON_COMMAND(IDM_AND_IMAGE, &CColorImageProcessingView::OnAndImage)
	ON_COMMAND(IDM_OR_IMAGE, &CColorImageProcessingView::OnOrImage)
	ON_COMMAND(IDM_XOR_IMAGE, &CColorImageProcessingView::OnXorImage)
	ON_COMMAND(IDM_NOT_IMAGE, &CColorImageProcessingView::OnNotImage)
	ON_COMMAND(IDM_MONO_MIDDLE_IMAGE, &CColorImageProcessingView::OnMonoMiddleImage)
	ON_COMMAND(IDM_MONO_MEAN_IMAGE, &CColorImageProcessingView::OnMonoMeanImage)
	ON_COMMAND(IDM_MONO_MEDIAN_IMAGE, &CColorImageProcessingView::OnMonoMedianImage)
	ON_COMMAND(IDM_GAMMA_IMAGE, &CColorImageProcessingView::OnGammaImage)
	ON_COMMAND(IDM_CONTRAST_IMAGE, &CColorImageProcessingView::OnContrastImage)
	ON_COMMAND(IDM_POST_IMAGE, &CColorImageProcessingView::OnPostImage)
	ON_COMMAND(IDM_ZOOMIN_IMAGE1, &CColorImageProcessingView::OnZoominImage1)
	ON_COMMAND(IDM_ZOOMIN_IMAGE2, &CColorImageProcessingView::OnZoominImage2)
	ON_COMMAND(IDM_ZOOMIN_IMAGE3, &CColorImageProcessingView::OnZoominImage3)
	ON_COMMAND(IDM_ZOOMOUT_IMAGE1, &CColorImageProcessingView::OnZoomoutImage1)
	ON_COMMAND(IDM_ZOOMOUT_IMAGE2, &CColorImageProcessingView::OnZoomoutImage2)
	ON_COMMAND(IDM_ZOOMOUT_IMAGE3, &CColorImageProcessingView::OnZoomoutImage3)
	ON_COMMAND(IDM_ROTATE_IMAGE1, &CColorImageProcessingView::OnRotateImage1)
	ON_COMMAND(IDM_ROTATE_IMAGE2, &CColorImageProcessingView::OnRotateImage2)
	ON_COMMAND(IDM_ROTATE_IMAGE3, &CColorImageProcessingView::OnRotateImage3)
	ON_COMMAND(IDM_MOVE_IMAGE, &CColorImageProcessingView::OnMoveImage)
	ON_COMMAND(IDM_MIRROR_IMAGE1, &CColorImageProcessingView::OnMirrorImage1)
	ON_COMMAND(IDM_MIRROR_IMAGE2, &CColorImageProcessingView::OnMirrorImage2)
	ON_COMMAND(IDM_HISTO_STRECH_IMAGE, &CColorImageProcessingView::OnHistoStrechImage)
	ON_COMMAND(IDM_HISTO_ENDIN_IMAGE, &CColorImageProcessingView::OnHistoEndinImage)
	ON_COMMAND(IDM_HISTO_EQUAL_IMAGE, &CColorImageProcessingView::OnHistoEqualImage)
	ON_COMMAND(IDM_EMBOSS_RGB, &CColorImageProcessingView::OnEmbossRgb)
	ON_COMMAND(IDM_EMBOSS_HSI, &CColorImageProcessingView::OnEmbossHsi)
	ON_COMMAND(IDM_BLUR_IMAGE, &CColorImageProcessingView::OnBlurImage)
	ON_COMMAND(IDM_SHARP_HIGH, &CColorImageProcessingView::OnSharpHigh)
	ON_COMMAND(IDM_SHARP_LOW, &CColorImageProcessingView::OnSharpLow)
	ON_COMMAND(IDM_SMOOTHING_IMAGE, &CColorImageProcessingView::OnSmoothingImage)
	ON_COMMAND(IDM_SMOOTHING_CUSTOM, &CColorImageProcessingView::OnSmoothingCustom)
	ON_COMMAND(IDM_EDGE_SHIFT, &CColorImageProcessingView::OnEdgeShift)
	ON_COMMAND(IDM_EDGE_HOMO, &CColorImageProcessingView::OnEdgeHomo)
	ON_COMMAND(IDM_EDGE_SUB, &CColorImageProcessingView::OnEdgeSub)
	ON_COMMAND(IDM_EDGE_ROBERT, &CColorImageProcessingView::OnEdgeRobert)
	ON_COMMAND(IDM_EDGE_PREWITT, &CColorImageProcessingView::OnEdgePrewitt)
	ON_COMMAND(IDM_EDGE_SOBEL, &CColorImageProcessingView::OnEdgeSobel)
	ON_COMMAND(IDM_EDGE_LAPL, &CColorImageProcessingView::OnEdgeLapl)
	ON_COMMAND(IDM_EDGE_LOG, &CColorImageProcessingView::OnEdgeLog)
	ON_COMMAND(IDM_EDGE_DOG, &CColorImageProcessingView::OnEdgeDog)
	ON_COMMAND(IDM_CHAGE_RGB, &CColorImageProcessingView::OnChageRgb)
	ON_COMMAND(IDM_CHANGE_HSI, &CColorImageProcessingView::OnChangeHsi)
	ON_COMMAND(IDM_PICK_COLOR, &CColorImageProcessingView::OnPickColor)
END_MESSAGE_MAP()

// CColorImageProcessingView 생성/소멸

CColorImageProcessingView::CColorImageProcessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CColorImageProcessingView::~CColorImageProcessingView()
{
}

BOOL CColorImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CColorImageProcessingView 그리기

void CColorImageProcessingView::OnDraw(CDC* pDC)
{
	
	///////////////////
	/// ** 더블 버퍼링 **
	///////////////////
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/////////////////////
	/// 성능 개선을 위한 더블 버퍼링 
	////////////////////
	int i, k;
	unsigned char R, G, B;
	// 메모리 DC 선언
	CDC memDC;
	CBitmap* pOldBitmap, bitmap;

	// 화면 DC와 호환되는 메모리 DC 객체를 생성
	memDC.CreateCompatibleDC(pDC);

	// 마찬가지로 화면 DC와 호환되는 Bitmap 생성
	bitmap.CreateCompatibleBitmap(pDC, pDoc->m_inW, pDoc->m_inH);

	pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.PatBlt(0, 0, pDoc->m_inW, pDoc->m_inH, WHITENESS); // 흰색으로 초기화

	// 출력 영상의 크기를 자동 조절
	double MAXSIZE = 800; // 필요시 모니터 크기에 따라서 변경 가능
	int inH = pDoc->m_inH;
	int inW = pDoc->m_inW;
	double hop = 1.0; //기본

	if (inH > MAXSIZE || inW > MAXSIZE) {
		// hop을 새로 계산.
		if (inW > inH)
			hop = (inW / MAXSIZE);
		else
			hop = (inH / MAXSIZE);

		inW = (int)(inW / hop);
		inH = (int)(inH / hop);
	}


	// 메모리 DC에 그리기
	for (i = 0; i < inH; i++) {
		for (k = 0; k < inW; k++) {
			R = pDoc->m_inImageR[(int)(i * hop)][(int)(k * hop)];
			G = pDoc->m_inImageG[(int)(i * hop)][(int)(k * hop)];
			B = pDoc->m_inImageB[(int)(i * hop)][(int)(k * hop)];
			memDC.SetPixel(k, i, RGB(R, G, B));
		}
	}
	// 메모리 DC를 화면 DC에 고속 복사
	pDC->BitBlt(5, 5, pDoc->m_inW, pDoc->m_inH, &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();

	///////////////////

	// 화면 DC와 호환되는 메모리 DC 객체를 생성
	memDC.CreateCompatibleDC(pDC);

	// 마찬가지로 화면 DC와 호환되는 Bitmap 생성
	bitmap.CreateCompatibleBitmap(pDC, pDoc->m_outW, pDoc->m_outH);

	pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.PatBlt(0, 0, pDoc->m_outW, pDoc->m_outH, WHITENESS); // 흰색으로 초기화

	int outH = pDoc->m_outH;
	int outW = pDoc->m_outW;
	hop = 1.0; //기본

	if (outH > MAXSIZE || outW > MAXSIZE) {
		// hop을 새로 계산.
		if (outW > outH)
			hop = (outW / MAXSIZE);
		else
			hop = (outH / MAXSIZE);

		outW = (int)(outW / hop);
		outH = (int)(outH / hop);
	}


	// 메모리 DC에 그리기
	for (i = 0; i < outH; i++) {
		for (k = 0; k < outW; k++) {
			R = pDoc->m_outImageR[(int)(i * hop)][(int)(k * hop)];
			G = pDoc->m_outImageG[(int)(i * hop)][(int)(k * hop)];
			B = pDoc->m_outImageB[(int)(i * hop)][(int)(k * hop)];
			memDC.SetPixel(k, i, RGB(R, G, B));
		}
	}
	// 메모리 DC를 화면 DC에 고속 복사
	pDC->BitBlt(inW + 10, 5, pDoc->m_outW, pDoc->m_outH, &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();

	pDoc->InImg2OutImg();

}


// CColorImageProcessingView 인쇄

BOOL CColorImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CColorImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CColorImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CColorImageProcessingView 진단

#ifdef _DEBUG
void CColorImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CColorImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorImageProcessingDoc* CColorImageProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorImageProcessingDoc)));
	return (CColorImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CColorImageProcessingView 메시지 처리기


void CColorImageProcessingView::OnEqualImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEqualImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnAddImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAddImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMulImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMulImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnGrayScale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayScale();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnAndImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnOrImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnXorImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnXorImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnNotImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNotImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMonoMiddleImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMonoMiddleImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMonoMeanImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMonoMeanImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMonoMedianImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMonoMedianImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnGammaImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnContrastImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnContrastImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnPostImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPostImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoominImage1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoominImage1();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoominImage2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoominImage2();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoominImage3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoominImage3();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoomoutImage1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomoutImage1();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoomoutImage2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomoutImage2();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnZoomoutImage3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomoutImage3();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnRotateImage1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotateImage1();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnRotateImage2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotateImage2();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnRotateImage3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotateImage3();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMoveImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMoveImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMirrorImage1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorImage1();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnMirrorImage2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorImage2();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnHistoStrechImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStrechImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnHistoEndinImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEndinImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnHistoEqualImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqualImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEmbossRgb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossRgb();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEmbossHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossHsi();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnBlurImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnSharpHigh()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpHigh();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnSharpLow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpLow();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnSmoothingImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSmoothingImage();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnSmoothingCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSmoothingCustom();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeShift()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeShift();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeHomo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeHomo();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeSub();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeRobert()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeRobert();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgePrewitt()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgePrewitt();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeSobel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeSobel();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeLapl()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeLapl();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeLog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeLog();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnEdgeDog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeDog();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnChageRgb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnChageRgb();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnChangeHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnChangeHsi();
	Invalidate(TRUE);
}


void CColorImageProcessingView::OnPickColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPickColor();
	Invalidate(TRUE);
}
