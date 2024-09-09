
// ColorImageProcessingDoc.cpp: CColorImageProcessingDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ColorImageProcessing.h"
#endif

#include "ColorImageProcessingDoc.h"

#include <propkey.h>
#include "ConstantDlg.h"
#include "ConstantTwoDlg.h"
#include "RadioThreeDlg.h"
#include "ConstantThreeDlg.h"
#include "ConstantMulDlg.h"
#include "ConstantGammaDlg.h"
#include "ConstantContrastDlg.h"
#include "ConstantPostDlg.h"
#include "ConstantZoom1Dlg.h"
#include "ConstantZoom2Dlg.h"
#include "ConstantRotateDlg.h"
#include "ConstantEndinDlg.h"
#include "ConstantBlurDlg.h"
#include "ConstantShighDlg.h"
#include "ConstantSlowDlg.h"
#include "ConstantSmoothDlg.h"
#include "RadioLaplDlg.h"
#include "RadioLogDlg.h"
#include "RadioDogDlg.h"
#include "ConstantDogDlg.h"
#include "ConstantHsiDlg.h"
#include "ConstantPickDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CColorImageProcessingDoc

IMPLEMENT_DYNCREATE(CColorImageProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorImageProcessingDoc, CDocument)
END_MESSAGE_MAP()


// CColorImageProcessingDoc 생성/소멸

CColorImageProcessingDoc::CColorImageProcessingDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CColorImageProcessingDoc::~CColorImageProcessingDoc()
{
}

BOOL CColorImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	OnFree2D(m_oriImageR, m_oriH);
	OnFree2D(m_oriImageG, m_oriH);
	OnFree2D(m_oriImageB, m_oriH);
	m_oriImageR = m_oriImageG = m_oriImageB = NULL;
	m_oriH = m_oriW = 0;

	OnFree2D(m_inImageR, m_inH);
	OnFree2D(m_inImageG, m_inH);
	OnFree2D(m_inImageB, m_inH);
	m_inImageR = m_inImageG = m_inImageB = NULL;
	m_inH = m_inW = 0;


	OnFree2D(m_outImageR, m_outH);
	OnFree2D(m_outImageG, m_outH);
	OnFree2D(m_outImageB, m_outH);
	m_outImageR = m_outImageG = m_outImageB = NULL;
	m_outH = m_outW = 0;
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CColorImageProcessingDoc serialization

void CColorImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CColorImageProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CColorImageProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CColorImageProcessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CColorImageProcessingDoc 진단

#ifdef _DEBUG
void CColorImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CColorImageProcessingDoc 명령


BOOL CColorImageProcessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (m_oriImageR != NULL) {
		OnFree2D(m_oriImageR, m_oriH);
		OnFree2D(m_oriImageG, m_oriH);
		OnFree2D(m_oriImageB, m_oriH);
		m_oriImageR = m_oriImageG = m_oriImageB = NULL;
		m_oriH = m_oriW = 0;

		OnFree2D(m_inImageR, m_inH);
		OnFree2D(m_inImageG, m_inH);
		OnFree2D(m_inImageB, m_inH);
		m_inImageR = m_inImageG = m_inImageB = NULL;
		m_inH = m_inW = 0;

		OnFree2D(m_outImageR, m_outH);
		OnFree2D(m_outImageG, m_outH);
		OnFree2D(m_outImageB, m_outH);
		m_outImageR = m_outImageG = m_outImageB = NULL;
		m_outH = m_outW = 0;
	}

	CImage image;
	image.Load(lpszPathName);
	// (중요!) 입력 영상 크기 알아내기
	m_inH = image.GetHeight();
	m_inW = image.GetWidth();
	// 메모리 할당
	m_inImageR = OnMalloc2D(m_inH, m_inW);
	m_inImageG = OnMalloc2D(m_inH, m_inW);
	m_inImageB = OnMalloc2D(m_inH, m_inW);
	// CImage의 객체값 --> 메모리
	COLORREF px;
	for (int i=0; i<m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			px = image.GetPixel(j, i);
			m_inImageR[i][j] = GetRValue(px);
			m_inImageG[i][j] = GetGValue(px);
			m_inImageB[i][j] = GetBValue(px);
		}
	m_oriH = m_inH;
	m_oriW = m_inW;
	// 메모리 할당
	m_oriImageR = OnMalloc2D(m_inH, m_inW);
	m_oriImageG = OnMalloc2D(m_inH, m_inW);
	m_oriImageB = OnMalloc2D(m_inH, m_inW);
	// CImage의 객체값 --> 메모리
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			px = image.GetPixel(j, i);
			m_oriImageR[i][j] = m_inImageR[i][j];
			m_oriImageG[i][j] = m_inImageG[i][j];
			m_oriImageB[i][j] = m_inImageB[i][j];
		}

	OnEqualImage();
	return TRUE;
}


unsigned char** CColorImageProcessingDoc::OnMalloc2D(int h, int w)
{
	// TODO: 여기에 구현 코드 추가.
	unsigned char** memory;
	memory = new unsigned char* [h];
	for (int i = 0; i < h; i++)
		memory[i] = new unsigned char[w];
	return memory;
}


void CColorImageProcessingDoc::OnFree2D(unsigned char** memory, int h)
{
	// TODO: 여기에 구현 코드 추가.
	if (memory == NULL)
		return;
	for (int i = 0; i < h; i++)
		delete memory[i];
	delete[] memory;
}


double** CColorImageProcessingDoc::OnMallocDouble2D(int h, int w, double initVal=0)
{
	// TODO: 여기에 구현 코드 추가.
	double** memory;
	memory = new double* [h];
	for (int i = 0; i < h; i++)
		memory[i] = new double[w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			memory[i][j] = initVal;
	return memory;
}


void CColorImageProcessingDoc::OnFreeDouble2D(double** memory, int h)
{
	// TODO: 여기에 구현 코드 추가.
	if (memory == NULL)
		return;
	for (int i = 0; i < h; i++)
		delete memory[i];
	delete[] memory;
}


void CColorImageProcessingDoc::OnCloseDocument()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	OnFree2D(m_oriImageR, m_oriH);
	OnFree2D(m_oriImageG, m_oriH);
	OnFree2D(m_oriImageB, m_oriH);

	OnFree2D(m_inImageR, m_inH);
	OnFree2D(m_inImageG, m_inH);
	OnFree2D(m_inImageB, m_inH);

	OnFree2D(m_outImageR, m_outH);
	OnFree2D(m_outImageG, m_outH);
	OnFree2D(m_outImageB, m_outH);

	CDocument::OnCloseDocument();
}


void CColorImageProcessingDoc::OnFreeOutImage()
{
	// TODO: 여기에 구현 코드 추가.
	if (m_outImageR != NULL) {
		OnFree2D(m_outImageR, m_outH);
		OnFree2D(m_outImageG, m_outH);
		OnFree2D(m_outImageB, m_outH);
		m_outImageR = m_outImageG = m_outImageB = NULL;
		m_outH = m_outW = 0;
	}
}


BOOL CColorImageProcessingDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDocument::OnSaveDocument(lpszPathName);
	if (m_outImageR == NULL)
		return FALSE;
	CImage image;
	image.Create(m_outW, m_outH, 32);
	unsigned char R, G, B;
	COLORREF px;
	for (int i=0; i<m_outW; i++)
		for (int j = 0; j < m_outH; j++) {
			R = m_outImageR[j][i];
			G = m_outImageG[j][i];
			B = m_outImageB[j][i];
			px = RGB(R, G, B);
			image.SetPixel(i, j, px);
		}
	image.Save(lpszPathName, Gdiplus::ImageFormatPNG);
	MessageBox(NULL, L"저장", L"성공", NULL);
	return TRUE;
}


double* CColorImageProcessingDoc::RGB2HSI(int R, int G, int B)
{
	// TODO: 여기에 구현 코드 추가.
	double H, S, I;
	double* HSI = new double[3];
	double min_value, angle;
	I = (R + G + B) / 3.0; // 밝기
	if ((R == G) && (G == B)) { // 그레이
		S = 0.0;
		H = 0.0;
	}
	else {

		min_value = min(min(R, G), B); //최소값 추출
		angle = (R - 0.5 * G - 0.5 * B) / (double)sqrt((R - G) * (R - G) + (R - B) * (G - B));

		H = (double)acos(angle) * 57.29577951;
		S = 1.0f - (3.0 / (R + G + B)) * min_value;
	}
	if (B > G) H = 360. - H;

	HSI[0] = H;
	HSI[1] = S;
	HSI[2] = I;

	return HSI;
}



unsigned char* CColorImageProcessingDoc::HSI2RGB(double H, double S, double I)
{
	// TODO: 여기에 구현 코드 추가.
	double R, G, B;
	unsigned char* RGB = new unsigned char[3];
	double angle1, angle2, scale;

	if (I == 0.0) { // Black
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 0;
		return RGB;
	}

	if (H <= 0.0) H += 360.0f;

	scale = 3.0 * I;

	if (H <= 120.0)
	{
		angle1 = H * 0.017453293;
		angle2 = (60.0 - H) * 0.017453293;
		B = (1.0 - S) / 3.0f;
		R = (double)(1.0 + (S * cos(angle1) / cos(angle2))) / 3.0;
		G = 1.0 - R - B;
		B *= scale;
		R *= scale;
		G *= scale;
	}


	else if ((H > 120.0) && (H <= 240.0)) {
		H -= 120.0;
		angle1 = H * 0.017453293;

		angle2 = (60.0 - H) * 0.017453293;
		R = (1.0 - S) / 3.0;
		G = (double)(1.0f + (S * cos(angle1) / cos(angle2))) / 3.0;
		B = (double)(1.0 + S*(1.0f - cos(angle1) / cos(angle2))) / 3.0;
		R *= scale;
		G *= scale;
		B *= scale;
	}
	else {
		H -= 240.0;
		angle1 = H * 0.017453293;
		angle2 = (60.0 - H) * 0.017453293;
		G = (1.0f - S) / 3.0;
		B = (double)(1.0 + (S * cos(angle1) / cos(angle2))) / 3.0;
		R = 1.0 - G - B;

		R *= scale;
		G *= scale;
		B *= scale;
	}

	RGB[0] = (unsigned char)R;
	RGB[1] = (unsigned char)G;
	RGB[2] = (unsigned char)B;
	return RGB;
}


void CColorImageProcessingDoc::OnEqualImage()
{
	// TODO: 여기에 구현 코드 추가.
	//if (m_inImageR != NULL) {
	//	OnFree2D(m_inImageR, m_inH);
	//	OnFree2D(m_inImageG, m_inH);
	//	OnFree2D(m_inImageB, m_inH);
	//	m_inImageR = m_inImageG = m_inImageB = NULL;
	//	m_inH = m_inW = 0;
	//}
	//m_inH = m_oriH;
	//m_inW = m_oriW;
	//// 메모리 할당
	//m_inImageR = OnMalloc2D(m_inH, m_inW);
	//m_inImageG = OnMalloc2D(m_inH, m_inW);
	//m_inImageB = OnMalloc2D(m_inH, m_inW);

	//// ** 진짜 영상처리  알고리즘 ** //
	//for (int i = 0; i < m_oriH; i++) {
	//	for (int j = 0; j < m_oriW; j++) {
	//		m_inImageR[i][j] = m_oriImageR[i][j];
	//		m_inImageG[i][j] = m_oriImageG[i][j];
	//		m_inImageB[i][j] = m_oriImageB[i][j];
	//	}
	//}

	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_oriH;
	m_outW = m_oriW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	for (int i = 0; i < m_outH; i++) {
		for (int j = 0; j < m_outW; j++) {
			m_outImageR[i][j] = m_oriImageR[i][j];
			m_outImageG[i][j] = m_oriImageG[i][j];
			m_outImageB[i][j] = m_oriImageB[i][j];
		}
	}
}


void CColorImageProcessingDoc::OnAddImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int value = (int)dlg.m_constant;
		if (value > 255 || value < -255) {
			MessageBox(NULL, L"-255~255 사이값 입력", L"경고", NULL);
			return;
		}
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				if (m_inImageR[i][j] + value > 255)
					m_outImageR[i][j] = 255;
				else if (m_inImageR[i][j] + value < 0)
					m_outImageR[i][j] = 0;
				else
					m_outImageR[i][j] = m_inImageR[i][j] + value;

				if (m_inImageG[i][j] + value > 255)
					m_outImageG[i][j] = 255;
				else if (m_inImageG[i][j] + value < 0)
					m_outImageG[i][j] = 0;
				else
					m_outImageG[i][j] = m_inImageG[i][j] + value;

				if (m_inImageB[i][j] + value > 255)
					m_outImageB[i][j] = 255;
				else if (m_inImageB[i][j] + value < 0)
					m_outImageB[i][j] = 0;
				else
					m_outImageB[i][j] = m_inImageB[i][j] + value;

			}
		}
	}
}


void CColorImageProcessingDoc::OnMulImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantMulDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double value = dlg.m_constant;
		
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				if (m_inImageR[i][j] * value > 255)
					m_outImageR[i][j] = 255;
				else if (m_inImageR[i][j] * value < 0)
					m_outImageR[i][j] = 0;
				else
					m_outImageR[i][j] = m_inImageR[i][j] * value;

				if (m_inImageG[i][j] * value > 255)
					m_outImageG[i][j] = 255;
				else if (m_inImageG[i][j] * value < 0)
					m_outImageG[i][j] = 0;
				else
					m_outImageG[i][j] = m_inImageG[i][j] * value;

				if (m_inImageB[i][j] * value > 255)
					m_outImageB[i][j] = 255;
				else if (m_inImageB[i][j] * value < 0)
					m_outImageB[i][j] = 0;
				else
					m_outImageB[i][j] = m_inImageB[i][j] * value;

			}
		}
	}
}


void CColorImageProcessingDoc::OnGrayScale()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정 --> 알고리즘에 따름...
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);
	// ** 진짜 영상처리 알고리즘 **
	double avg;
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			avg = (m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3.0;
			m_outImageR[i][j] = m_outImageG[i][j] = m_outImageB[i][j] = (unsigned char)avg;
		}
	}
}


void CColorImageProcessingDoc::OnAndImage()
{
	// TODO: 여기에 구현 코드 추가.
	CString m_filedir;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK) {
		m_filedir = fileDlg.GetPathName();
		LPCTSTR lpszPathName = m_filedir;
		CImage image;
		image.Load(lpszPathName);
		// (중요!) 입력 영상 크기 알아내기
		int m_tmpH = image.GetHeight();
		int m_tmpW = image.GetWidth();
		if ((m_inH != m_tmpH) || (m_inW != m_tmpW)) {
			MessageBox(NULL, L"같은 크기의 이미지만 가능", L"경고", NULL);
			return;
		}
		// 임시 메모리 할당
		unsigned char** m_tmpImageR, **m_tmpImageG, **m_tmpImageB;
		m_tmpImageR = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageG = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageB = OnMalloc2D(m_tmpH, m_tmpW);

		// CImage의 객체값 --> 메모리
		COLORREF px;
		for (int i = 0; i < m_inH; i++)
			for (int j = 0; j < m_inW; j++) {
				px = image.GetPixel(j, i);
				m_tmpImageR[i][j] = GetRValue(px);
				m_tmpImageG[i][j] = GetGValue(px);
				m_tmpImageB[i][j] = GetBValue(px);
			}

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정 --> 알고리즘에 따름...
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리 알고리즘 **
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				m_outImageR[i][j] = m_inImageR[i][j] & m_tmpImageR[i][j];
				m_outImageG[i][j] = m_inImageG[i][j] & m_tmpImageG[i][j];
				m_outImageB[i][j] = m_inImageB[i][j] & m_tmpImageB[i][j];
			}
		}
		OnFree2D(m_tmpImageR, m_tmpH);
		OnFree2D(m_tmpImageG, m_tmpH);
		OnFree2D(m_tmpImageB, m_tmpH);
	}
}


void CColorImageProcessingDoc::OnOrImage()
{
	// TODO: 여기에 구현 코드 추가.
	CString m_filedir;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK) {
		m_filedir = fileDlg.GetPathName();
		LPCTSTR lpszPathName = m_filedir;
		CImage image;
		image.Load(lpszPathName);
		// (중요!) 입력 영상 크기 알아내기
		int m_tmpH = image.GetHeight();
		int m_tmpW = image.GetWidth();
		if ((m_inH != m_tmpH) || (m_inW != m_tmpW)) {
			MessageBox(NULL, L"같은 크기의 이미지만 가능", L"경고", NULL);
			return;
		}
		// 임시 메모리 할당
		unsigned char** m_tmpImageR, ** m_tmpImageG, ** m_tmpImageB;
		m_tmpImageR = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageG = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageB = OnMalloc2D(m_tmpH, m_tmpW);

		// CImage의 객체값 --> 메모리
		COLORREF px;
		for (int i = 0; i < m_inH; i++)
			for (int j = 0; j < m_inW; j++) {
				px = image.GetPixel(j, i);
				m_tmpImageR[i][j] = GetRValue(px);
				m_tmpImageG[i][j] = GetGValue(px);
				m_tmpImageB[i][j] = GetBValue(px);
			}

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정 --> 알고리즘에 따름...
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리 알고리즘 **
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				m_outImageR[i][j] = m_inImageR[i][j] | m_tmpImageR[i][j];
				m_outImageG[i][j] = m_inImageG[i][j] | m_tmpImageG[i][j];
				m_outImageB[i][j] = m_inImageB[i][j] | m_tmpImageB[i][j];
			}
		}
		OnFree2D(m_tmpImageR, m_tmpH);
		OnFree2D(m_tmpImageG, m_tmpH);
		OnFree2D(m_tmpImageB, m_tmpH);
	}
}


void CColorImageProcessingDoc::OnXorImage()
{
	// TODO: 여기에 구현 코드 추가.
	CString m_filedir;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK) {
		m_filedir = fileDlg.GetPathName();
		LPCTSTR lpszPathName = m_filedir;
		CImage image;
		image.Load(lpszPathName);
		// (중요!) 입력 영상 크기 알아내기
		int m_tmpH = image.GetHeight();
		int m_tmpW = image.GetWidth();
		if ((m_inH != m_tmpH) || (m_inW != m_tmpW)) {
			MessageBox(NULL, L"같은 크기의 이미지만 가능", L"경고", NULL);
			return;
		}
		// 임시 메모리 할당
		unsigned char** m_tmpImageR, ** m_tmpImageG, ** m_tmpImageB;
		m_tmpImageR = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageG = OnMalloc2D(m_tmpH, m_tmpW);
		m_tmpImageB = OnMalloc2D(m_tmpH, m_tmpW);

		// CImage의 객체값 --> 메모리
		COLORREF px;
		for (int i = 0; i < m_inH; i++)
			for (int j = 0; j < m_inW; j++) {
				px = image.GetPixel(j, i);
				m_tmpImageR[i][j] = GetRValue(px);
				m_tmpImageG[i][j] = GetGValue(px);
				m_tmpImageB[i][j] = GetBValue(px);
			}

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정 --> 알고리즘에 따름...
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리 알고리즘 **
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				m_outImageR[i][j] = m_inImageR[i][j] ^ m_tmpImageR[i][j];
				m_outImageG[i][j] = m_inImageG[i][j] ^ m_tmpImageG[i][j];
				m_outImageB[i][j] = m_inImageB[i][j] ^ m_tmpImageB[i][j];
			}
		}
		OnFree2D(m_tmpImageR, m_tmpH);
		OnFree2D(m_tmpImageG, m_tmpH);
		OnFree2D(m_tmpImageB, m_tmpH);
	}
}


void CColorImageProcessingDoc::OnNotImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			m_outImageR[i][j] = ~m_inImageR[i][j];
			m_outImageG[i][j] = ~m_inImageG[i][j];
			m_outImageB[i][j] = ~m_inImageB[i][j];
		}
	}
}


void CColorImageProcessingDoc::OnMonoMiddleImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	double avg;
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			avg = (m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3.0;
			if (avg > 127)
				avg = 255.0;
			else 
				avg = 0.0;
			m_outImageR[i][j] = m_outImageG[i][j] = m_outImageB[i][j] = (unsigned char)avg;
		}
	}
}


void CColorImageProcessingDoc::OnMonoMeanImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	double mean = 0;
	for (int i = 0; i < m_inH; i++) 
		for (int j = 0; j < m_inW; j++) 
			mean += (m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3.0;
	mean = mean / (m_inH * m_inW);
	double avg;
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			avg = (m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3.0;
			if (avg > mean)
				avg = 255.0;
			else
				avg = 0.0;
			m_outImageR[i][j] = m_outImageG[i][j] = m_outImageB[i][j] = (unsigned char)avg;
		}
	}
}


void CColorImageProcessingDoc::OnMonoMedianImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	unsigned char* arr = new unsigned char [m_inH*m_inW];
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++)
			arr[i*m_inW + j] = ((m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3);
	OnSorting(arr, 0, m_inH * m_inW);
	unsigned char median = arr[m_inH * m_inW / 2];
	unsigned char avg;
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			avg = (unsigned char)((m_inImageR[i][j] + m_inImageG[i][j] + m_inImageB[i][j]) / 3);
			if (avg > median)
				avg = 255.0;
			else
				avg = 0.0;
			m_outImageR[i][j] = m_outImageG[i][j] = m_outImageB[i][j] = avg;
		}
	}
	delete[] arr;
}



void CColorImageProcessingDoc::OnSorting(unsigned char* arr, int l, int r)
{
	// TODO: 여기에 구현 코드 추가.
	unsigned char* tmp = new unsigned char[r - l];
	OnMergeSort(arr, tmp, l, r);
	delete[] tmp;
}


void CColorImageProcessingDoc::OnMergeSort(unsigned char* arr, unsigned char* tmp, int l, int r)
{
	// TODO: 여기에 구현 코드 추가.
	if (r - l < 2)
		return;
	else {
		OnMergeSort(arr, tmp, l, (l + r) / 2);
		OnMergeSort(arr, tmp, (l + r) / 2, r);
		OnMerge(arr, tmp, l, (l + r) / 2, r);
	}
}


void CColorImageProcessingDoc::OnMerge(unsigned char* arr, unsigned char* tmp, int l, int m, int r)
{
	// TODO: 여기에 구현 코드 추가.
	int i = l, j = m, k = 0;
	while (i < m && j < r) {
		if (arr[i] > arr[j]) {
			tmp[k] = arr[j];
			k++;
			j++;
		}
		else {
			tmp[k] = arr[i];
			i++;
			k++;
		}
	}
	if (i == m) {
		while (j < r) {
			tmp[k] = arr[j];
			j++;
			k++;
		}
	}
	else if (j == r) {
		while (i < m) {
			tmp[k] = arr[i];
			i++;
			k++;
		}
	}
	for (int q = 0; q < k; q++) {
		arr[l] = tmp[q];
		l++;
	}
}


void CColorImageProcessingDoc::OnGammaImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantGammaDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double value = dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				m_outImageR[i][j] = (unsigned char)(pow((double)m_inImageR[i][j] / 255.0, 1 / value) * 255.0);
				m_outImageG[i][j] = (unsigned char)(pow((double)m_inImageG[i][j] / 255.0, 1 / value) * 255.0);
				m_outImageB[i][j] = (unsigned char)(pow((double)m_inImageB[i][j] / 255.0, 1 / value) * 255.0);
			}
		}
	}
}


void CColorImageProcessingDoc::OnContrastImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantContrastDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double value = dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		double R, G, B;
		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				R = (double)(m_inImageR[i][j] - 127) * value + 127.0;
				G = (double)(m_inImageG[i][j] - 127) * value + 127.0;
				B = (double)(m_inImageB[i][j] - 127) * value + 127.0;

				if (R > 255.0) R = 255.0;
				else if (R < 0.0) R = 0.0;
				m_outImageR[i][j] = R;
				if (G > 255.0) G = 255.0;
				else if (G < 0.0) G = 0.0;
				m_outImageG[i][j] = G;
				if (B > 255.0) B = 255.0;
				else if (B < 0.0) B = 0.0;
				m_outImageB[i][j] = B;

			}
		}
	}
}


void CColorImageProcessingDoc::OnPostImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantPostDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int value = (int)dlg.m_constant;
		if (value < 2) {
			MessageBox(NULL, L"2이상 입력", L"경고", NULL);
			return;
		}
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		int interval = 255 / value;
		unsigned char pxValue = 255 / (value - 1);

		for (int k = 0; k < value; k++)
			for (int i = 0; i < m_inH; i++)
				for (int j = 0; j < m_inW; j++) {
					if (m_inImageR[i][j] < interval * (k + 1) && m_inImageR[i][j] >= interval * k)
						m_outImageR[i][j] = pxValue * k;
					if (m_inImageG[i][j] < interval * (k + 1) && m_inImageG[i][j] >= interval * k)
						m_outImageG[i][j] = pxValue * k;
					if (m_inImageB[i][j] < interval * (k + 1) && m_inImageB[i][j] >= interval * k)
						m_outImageB[i][j] = pxValue * k;
				}

	}
}


void CColorImageProcessingDoc::OnZoominImage1()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom1Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH * scale);
		m_outW = (int)(m_inW * scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++)
			for (int j = 0; j < m_inW; j++) {
				m_outImageR[(int)(i * scale)][(int)(j * scale)] = m_inImageR[i][j];
				m_outImageG[(int)(i * scale)][(int)(j * scale)] = m_inImageG[i][j];
				m_outImageB[(int)(i * scale)][(int)(j * scale)] = m_inImageB[i][j];
			}
	}
}


void CColorImageProcessingDoc::OnZoominImage2()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom1Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH * scale);
		m_outW = (int)(m_inW * scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				m_outImageR[i][j] = m_inImageR[(int)(i / scale)][(int)(j / scale)];
				m_outImageG[i][j] = m_inImageG[(int)(i / scale)][(int)(j / scale)];
				m_outImageB[i][j] = m_inImageB[(int)(i / scale)][(int)(j / scale)];
			}
		}
	}
}


void CColorImageProcessingDoc::OnZoominImage3()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom1Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH * scale);
		m_outW = (int)(m_inW * scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		double x1, x2, y1, y2, val1, val2, val3, val4, val_p, val_q, val_r;
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				x1 = j / scale;
				x2 = j / scale + 1;
				y1 = i / scale;
				y2 = i / scale + 1;
				if (x2 < m_inW && y2 < m_inH) {
					val1 = m_inImageR[(int)y1][(int)x1];
					val2 = m_inImageR[(int)y1][(int)x2];
					val3 = m_inImageR[(int)y2][(int)x1];
					val4 = m_inImageR[(int)y2][(int)x2];
					val_p = (val2 - val1) * (x1 - (int)x1) + val1;
					val_q = (val4 - val3) * (x2 - (int)x2) + val3;
					val_r = (val_q - val_p) * (y1 - (int)y1) + val_p;
					m_outImageR[i][j] = (unsigned char)val_r;

					val1 = m_inImageG[(int)y1][(int)x1];
					val2 = m_inImageG[(int)y1][(int)x2];
					val3 = m_inImageG[(int)y2][(int)x1];
					val4 = m_inImageG[(int)y2][(int)x2];
					val_p = (val2 - val1) * (x1 - (int)x1) + val1;
					val_q = (val4 - val3) * (x2 - (int)x2) + val3;
					val_r = (val_q - val_p) * (y1 - (int)y1) + val_p;
					m_outImageG[i][j] = (unsigned char)val_r;

					val1 = m_inImageB[(int)y1][(int)x1];
					val2 = m_inImageB[(int)y1][(int)x2];
					val3 = m_inImageB[(int)y2][(int)x1];
					val4 = m_inImageB[(int)y2][(int)x2];
					val_p = (val2 - val1) * (x1 - (int)x1) + val1;
					val_q = (val4 - val3) * (x2 - (int)x2) + val3;
					val_r = (val_q - val_p) * (y1 - (int)y1) + val_p;
					m_outImageB[i][j] = (unsigned char)val_r;
				}
			}
		}
	}
}


void CColorImageProcessingDoc::OnZoomoutImage1()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom2Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH / scale);
		m_outW = (int)(m_inW / scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				m_outImageR[i][j] = m_inImageR[(int)(i * scale)][(int)(j * scale)];
				m_outImageG[i][j] = m_inImageG[(int)(i * scale)][(int)(j * scale)];
				m_outImageB[i][j] = m_inImageB[(int)(i * scale)][(int)(j * scale)];
			}
		}
	}
}


void CColorImageProcessingDoc::OnZoomoutImage2()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom2Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH / scale);
		m_outW = (int)(m_inW / scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				int meanR = 0, meanG = 0, meanB = 0;
				int count = 0;
				for (int m = (int)(i * scale); m < (int)((i + 1) * scale); m++)
					for (int n = (int)(j * scale); n < (int)((j + 1) * scale); n++) {
						meanR += m_inImageR[m][n];
						meanG += m_inImageG[m][n];
						meanB += m_inImageB[m][n];
						count++;
					}
				m_outImageR[i][j] = (unsigned char)(meanR / count);
				m_outImageG[i][j] = (unsigned char)(meanG / count);
				m_outImageB[i][j] = (unsigned char)(meanB / count);
			}
		}
	}
}


void CColorImageProcessingDoc::OnZoomoutImage3()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantZoom2Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		double scale = dlg.m_constant;

		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)(m_inH / scale);
		m_outW = (int)(m_inW / scale);
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		unsigned char* tmpR = new unsigned char[scale * scale];
		unsigned char* tmpG = new unsigned char[scale * scale];
		unsigned char* tmpB = new unsigned char[scale * scale];
		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				int count = 0;
				for (int m = (int)(i * scale); m < (int)((i + 1) * scale); m++)
					for (int n = (int)(j * scale); n < (int)((j + 1) * scale); n++) {
						tmpR[count] = m_inImageR[m][n];
						tmpG[count] = m_inImageG[m][n];
						tmpB[count] = m_inImageB[m][n];
						count++;
					}
				OnSorting(tmpR, 0, count);
				OnSorting(tmpG, 0, count);
				OnSorting(tmpB, 0, count);
				m_outImageR[i][j] = tmpR[count / 2];
				m_outImageG[i][j] = tmpG[count / 2];
				m_outImageB[i][j] = tmpB[count / 2];
			}
		}
		delete[] tmpR;
		delete[] tmpG;
		delete[] tmpB;
	}
}


void CColorImageProcessingDoc::OnRotateImage1()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantRotateDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double deg = dlg.m_constant;
		double rad = deg * 3.141592 / 180.0;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리  알고리즘 ** //
		double cx = (double)m_inW / 2;
		double cy = (double)m_inH / 2;
		int xd, yd, xs, ys;
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				xd = j;
				yd = i;
				xs = int(cos(rad) * ((double)xd - cx) + sin(rad) * ((double)yd - cy) + (double)cx);
				ys = int(sin(-rad) * ((double)xd - cx) + cos(rad) * ((double)yd - cy) + (double)cy);
				if (0 <= xs && xs < m_inW && 0 <= ys && ys < m_inH) {
					m_outImageR[yd][xd] = m_inImageR[ys][xs];
					m_outImageG[yd][xd] = m_inImageG[ys][xs];
					m_outImageB[yd][xd] = m_inImageB[ys][xs];

				}
			}
		}
	}
}


void CColorImageProcessingDoc::OnRotateImage2()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantRotateDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double deg = dlg.m_constant;
		double rad = deg * 3.141592 / 180.0;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)((double)m_inW * sin(rad) + (double)m_inH * cos(rad)); // H = W*sin(rad) + H*cos(rad)
		m_outW = (int)((double)m_inW * cos(rad) + (double)m_inH * sin(rad)); // W = W*cos(rad) + H*sin(rad)
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리  알고리즘 ** //
		double cx = (double)m_outW / 2;
		double cy = (double)m_outH / 2;
		double csx = (double)m_inH / 2;
		double csy = (double)m_inW / 2;
		int xd, yd, xs, ys;
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				xd = j;
				yd = i;
				xs = int(cos(rad) * ((double)xd - cx) + sin(rad) * ((double)yd - cy) + (double)csy);
				ys = int(sin(-rad) * ((double)xd - cx) + cos(rad) * ((double)yd - cy) + (double)csx);
				if (0 <= xs && xs < m_inW && 0 <= ys && ys < m_inH) {
					m_outImageR[yd][xd] = m_inImageR[ys][xs];
					m_outImageG[yd][xd] = m_inImageG[ys][xs];
					m_outImageB[yd][xd] = m_inImageB[ys][xs];

				}
			}
		}
	}
}


void CColorImageProcessingDoc::OnRotateImage3()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantRotateDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double deg = dlg.m_constant;
		double rad = deg * 3.141592 / 180.0;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = (int)((double)m_inW * sin(rad) + (double)m_inH * cos(rad)); // H = W*sin(rad) + H*cos(rad)
		m_outW = (int)((double)m_inW * cos(rad) + (double)m_inH * sin(rad)); // W = W*cos(rad) + H*sin(rad)
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리  알고리즘 ** //
		double cx = (double)m_outW / 2;
		double cy = (double)m_outH / 2;
		double csx = (double)m_inH / 2;
		double csy = (double)m_inW / 2;
		double xd, yd, xs, ys, val1, val2, val3, val4, val_p, val_q, val_r;
		for (int i = 0; i < m_outH; i++) {
			for (int j = 0; j < m_outW; j++) {
				xd = j;
				yd = i;
				xs = cos(rad) * ((double)xd - cx) + sin(rad) * ((double)yd - cy) + (double)csy;
				ys = sin(-rad) * ((double)xd - cx) + cos(rad) * ((double)yd - cy) + (double)csx;
				if (0 <= xs && xs < m_inW - 1 && 0 <= ys && ys < m_inH - 1) {
					val1 = m_inImageR[(int)ys][(int)xs];
					val2 = m_inImageR[(int)ys][(int)xs + 1];
					val3 = m_inImageR[(int)ys + 1][(int)xs];
					val4 = m_inImageR[(int)ys + 1][(int)xs + 1];
					val_p = (val2 - val1) * (xs - (int)xs) + val1;
					val_q = (val4 - val3) * (xs - (int)xs) + val3;
					val_r = (val_q - val_p) * (ys - (int)ys) + val_p;
					m_outImageR[i][j] = (unsigned char)val_r;

					val1 = m_inImageG[(int)ys][(int)xs];
					val2 = m_inImageG[(int)ys][(int)xs + 1];
					val3 = m_inImageG[(int)ys + 1][(int)xs];
					val4 = m_inImageG[(int)ys + 1][(int)xs + 1];
					val_p = (val2 - val1) * (xs - (int)xs) + val1;
					val_q = (val4 - val3) * (xs - (int)xs) + val3;
					val_r = (val_q - val_p) * (ys - (int)ys) + val_p;
					m_outImageG[i][j] = (unsigned char)val_r;

					val1 = m_inImageB[(int)ys][(int)xs];
					val2 = m_inImageB[(int)ys][(int)xs + 1];
					val3 = m_inImageB[(int)ys + 1][(int)xs];
					val4 = m_inImageB[(int)ys + 1][(int)xs + 1];
					val_p = (val2 - val1) * (xs - (int)xs) + val1;
					val_q = (val4 - val3) * (xs - (int)xs) + val3;
					val_r = (val_q - val_p) * (ys - (int)ys) + val_p;
					m_outImageB[i][j] = (unsigned char)val_r;

				}
			}
		}
	}
}


void CColorImageProcessingDoc::OnMoveImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantTwoDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int x = (int)dlg.m_constant1;
		int y = (int)dlg.m_constant2;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				if (i + y > 0 && i + y < m_inH && j + x>0 && j + x < m_inW) {
					m_outImageR[i + y][j + x] = m_inImageR[i][j];
					m_outImageG[i + y][j + x] = m_inImageG[i][j];
					m_outImageB[i + y][j + x] = m_inImageB[i][j];
				}
			}
		}
	}
}


void CColorImageProcessingDoc::OnMirrorImage1()
{
	// TODO: 여기에 구현 코드 추가.

	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			m_outImageR[m_inH - i - 1][j] = m_inImageR[i][j];
			m_outImageG[m_inH - i - 1][j] = m_inImageG[i][j];
			m_outImageB[m_inH - i - 1][j] = m_inImageB[i][j];
		}
	}
}


void CColorImageProcessingDoc::OnMirrorImage2()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			m_outImageR[i][m_inW - j - 1] = m_inImageR[i][j];
			m_outImageG[i][m_inW - j - 1] = m_inImageG[i][j];
			m_outImageB[i][m_inW - j - 1] = m_inImageB[i][j];
		}
	}
}


void CColorImageProcessingDoc::OnHistoStrechImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	int high[3] = { m_inImageR[0][0],m_inImageG[0][0] ,m_inImageB[0][0] };
	int low[3] = { m_inImageR[0][0],m_inImageG[0][0] ,m_inImageB[0][0] };
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			if (m_inImageR[i][j] < low[0])
				low[0] = m_inImageR[i][j];
			if (m_inImageR[i][j] > high[0])
				high[0] = m_inImageR[i][j];

			if (m_inImageG[i][j] < low[1])
				low[1] = m_inImageG[i][j];
			if (m_inImageG[i][j] > high[1])
				high[1] = m_inImageG[i][j];

			if (m_inImageB[i][j] < low[2])
				low[2] = m_inImageB[i][j];
			if (m_inImageB[i][j] > high[2])
				high[2] = m_inImageB[i][j];
		}
	}
	int value[3] = { 0 };
	int old[3] = { 0 };
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			old[0] = m_inImageR[i][j];
			old[1] = m_inImageG[i][j];
			old[2] = m_inImageB[i][j];
			value[0] = (int)((old[0] - low[0]) / (double)(high[0] - low[0]) * 255.0);
			value[1] = (int)((old[1] - low[1]) / (double)(high[1] - low[1]) * 255.0);
			value[2] = (int)((old[2] - low[2]) / (double)(high[2] - low[2]) * 255.0);
			for (int k = 0; k < 3; k++) {
				if (value[k] > 255)
					value[k] = 255;
				else if (value[k] < 0)
					value[k] = 0;
			}
			m_outImageR[i][j] = (unsigned char)value[0];
			m_outImageG[i][j] = (unsigned char)value[1];
			m_outImageB[i][j] = (unsigned char)value[2];
		}
	}

}


void CColorImageProcessingDoc::OnHistoEndinImage()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantEndinDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int valueE = (int)dlg.m_constant;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		int high[3] = { m_inImageR[0][0],m_inImageG[0][0] ,m_inImageB[0][0] };
		int low[3] = { m_inImageR[0][0],m_inImageG[0][0] ,m_inImageB[0][0] };
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				if (m_inImageR[i][j] < low[0])
					low[0] = m_inImageR[i][j];
				if (m_inImageR[i][j] > high[0])
					high[0] = m_inImageR[i][j];

				if (m_inImageG[i][j] < low[1])
					low[1] = m_inImageG[i][j];
				if (m_inImageG[i][j] > high[1])
					high[1] = m_inImageG[i][j];

				if (m_inImageB[i][j] < low[2])
					low[2] = m_inImageB[i][j];
				if (m_inImageB[i][j] > high[2])
					high[2] = m_inImageB[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {
			high[i] -= valueE;
			low[i] += valueE;
		}

		int value[3] = { 0 };
		int old[3] = { 0 };
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				old[0] = m_inImageR[i][j];
				old[1] = m_inImageG[i][j];
				old[2] = m_inImageB[i][j];
				value[0] = (int)((old[0] - low[0]) / (double)(high[0] - low[0]) * 255.0);
				value[1] = (int)((old[1] - low[1]) / (double)(high[1] - low[1]) * 255.0);
				value[2] = (int)((old[2] - low[2]) / (double)(high[2] - low[2]) * 255.0);
				for (int k = 0; k < 3; k++) {
					if (value[k] > 255)
						value[k] = 255;
					else if (value[k] < 0)
						value[k] = 0;
				}
				m_outImageR[i][j] = (unsigned char)value[0];
				m_outImageG[i][j] = (unsigned char)value[1];
				m_outImageB[i][j] = (unsigned char)value[2];
			}
		}
	}
}


void CColorImageProcessingDoc::OnHistoEqualImage()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	// 1단계 : 빈도수 세기(=히스토그램) histo[256]
	int histo[3][256] = { 0, };
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			histo[0][m_inImageR[i][j]]++;
			histo[1][m_inImageG[i][j]]++;
			histo[2][m_inImageB[i][j]]++;
		}


	// 2단계 : 누적 히스토그램 생성
	int sumHisto[3][256] = { 0, };
	for (int i = 0; i < 3; i++)
		sumHisto[i][0] = histo[i][0];
	for (int i = 1; i < 256; i++) {
		sumHisto[0][i] = sumHisto[0][i - 1] + histo[0][i];
		sumHisto[1][i] = sumHisto[1][i - 1] + histo[1][i];
		sumHisto[2][i] = sumHisto[2][i - 1] + histo[2][i];
	}

	// 3단계 :정규화된 히스토그램 생성 normalHisto = sumHisto[i] * (1.0/(inH*inW)) * 255.0;
	double normalHisto[3][256] = { 1.0, };
	for (int i = 0; i < 256; i++) {
		normalHisto[0][i] = sumHisto[0][i] * (1.0 / (m_inH * m_inW)) * 255.0;
		normalHisto[1][i] = sumHisto[1][i] * (1.0 / (m_inH * m_inW)) * 255.0;
		normalHisto[2][i] = sumHisto[2][i] * (1.0 / (m_inH * m_inW)) * 255.0;
	}

	// 4단계 : inImage를 정규화된 값으로 치환
	// 입력 배열 --> 출력 배열
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			m_outImageR[i][j] = (unsigned char)normalHisto[0][m_inImageR[i][j]];
			m_outImageG[i][j] = (unsigned char)normalHisto[1][m_inImageG[i][j]];
			m_outImageB[i][j] = (unsigned char)normalHisto[2][m_inImageB[i][j]];
		}
	}
}


void CColorImageProcessingDoc::OnEmbossRgb()
{
	// TODO: 여기에 구현 코드 추가.
	const int MSIZE = 3;
	double** mask = OnMallocDouble2D(MSIZE, MSIZE, 0);
	mask[0][0] = -1.0; mask[2][2] = 1.0;
	OnConvRGB(mask, MSIZE);
	// 임시 출력 영상 --> 출력 영상.
	for (int i = 0; i < m_outH; i++)
		for (int j = 0; j < m_outW; j++) {
			if (m_outImageR[i][j] + 127 > 255)
				m_outImageR[i][j] = 255;
			else
				m_outImageR[i][j] += 127;

			if (m_outImageG[i][j] + 127 > 255)
				m_outImageG[i][j] = 255;
			else
				m_outImageG[i][j] += 127;

			if (m_outImageB[i][j] + 127 > 255)
				m_outImageB[i][j] = 255;
			else
				m_outImageB[i][j] += 127;
		}
	OnFreeDouble2D(mask, MSIZE);
}


void CColorImageProcessingDoc::OnEmbossHsi()
{
	// TODO: 여기에 구현 코드 추가.
// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //
	const int MSIZE = 3;
	double mask[MSIZE][MSIZE] = {
		{ -1.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 1.0} };

	// 임시 메모리 할당
	double** tmpInImageR, ** tmpInImageG, ** tmpInImageB, ** tmpOutImageR, ** tmpOutImageG, ** tmpOutImageB;
	double** tmpInImageH, ** tmpInImageS, ** tmpInImageI;
	tmpInImageR = OnMallocDouble2D(m_inH + 2, m_inW + 2);
	tmpInImageG = OnMallocDouble2D(m_inH + 2, m_inW + 2);
	tmpInImageB = OnMallocDouble2D(m_inH + 2, m_inW + 2);

	tmpInImageH = OnMallocDouble2D(m_inH + 2, m_inW + 2);
	tmpInImageS = OnMallocDouble2D(m_inH + 2, m_inW + 2);
	tmpInImageI = OnMallocDouble2D(m_inH + 2, m_inW + 2);

	tmpOutImageR = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageG = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageB = OnMallocDouble2D(m_outH, m_outW);
	for (int i = 0; i < m_inH + 2; i++) {
		for (int j = 0; j < m_inW + 2; j++) {
			tmpInImageR[i][j] = tmpInImageG[i][j] = tmpInImageB[i][j] = 127.0;
		}
	}
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			tmpInImageR[i + 1][j + 1] = m_inImageR[i][j];
			tmpInImageG[i + 1][j + 1] = m_inImageG[i][j];
			tmpInImageB[i + 1][j + 1] = m_inImageB[i][j];
		}
	}

	// RGB 모델 --> HSI 모델 //
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			double* hsi;
			unsigned char R, G, B;
			R = tmpInImageR[i][j]; G = tmpInImageG[i][j]; B = tmpInImageB[i][j];
			hsi = RGB2HSI(R, G, B);

			double H, S, I;
			H = hsi[0]; S = hsi[1], I = hsi[2];
			tmpInImageH[i][j] = H; tmpInImageS[i][j] = S; tmpInImageI[i][j] = I;
		}
	}




	// *** 회선연산 : 마스크로 긁어가며 계산하기.

	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			double S_VALUE = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S_VALUE += tmpInImageI[i + m][j + n] * mask[m][n];
			tmpInImageI[i][j] = S_VALUE;
		}
	}
	// 후처리 (마스크의 합계에 따라 127을 더할지 결정)
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			tmpInImageI[i][j] += 127.0;
		}
	}

	///// HSI --> RGB ////
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			unsigned char* rgb;
			double H, S, I;
			H = tmpInImageH[i][j]; S = tmpInImageS[i][j]; I = tmpInImageI[i][j];

			rgb = HSI2RGB(H, S, I);
			tmpOutImageR[i][j] = rgb[0];
			tmpOutImageG[i][j] = rgb[1];
			tmpOutImageB[i][j] = rgb[2];
		}
	}


	// 임시 출력 이미지 --> 출력 이미지
	for (int i = 0; i < m_outH; i++) {
		for (int j = 0; j < m_outW; j++) {
			if (tmpOutImageR[i][j] < 0.0)
				m_outImageR[i][j] = 0;
			else if (tmpOutImageR[i][j] > 255.0)
				m_outImageR[i][j] = 255;
			else
				m_outImageR[i][j] = (unsigned char)tmpOutImageR[i][j];

			if (tmpOutImageG[i][j] < 0.0)
				m_outImageG[i][j] = 0;
			else if (tmpOutImageG[i][j] > 255.0)
				m_outImageG[i][j] = 255;
			else
				m_outImageG[i][j] = (unsigned char)tmpOutImageG[i][j];

			if (tmpOutImageB[i][j] < 0.0)
				m_outImageB[i][j] = 0;
			else if (tmpOutImageB[i][j] > 255.0)
				m_outImageB[i][j] = 255;
			else
				m_outImageB[i][j] = (unsigned char)tmpOutImageB[i][j];
		}
	}

	// 임시 메모리 해제
	OnFreeDouble2D(tmpInImageR, m_inH+2);
	OnFreeDouble2D(tmpInImageG, m_inH +2);
	OnFreeDouble2D(tmpInImageB, m_inH +2);
	OnFreeDouble2D(tmpInImageH, m_inH + 2);
	OnFreeDouble2D(tmpInImageS, m_inH + 2);
	OnFreeDouble2D(tmpInImageI, m_inH + 2);
	OnFreeDouble2D(tmpOutImageR, m_outH);
	OnFreeDouble2D(tmpOutImageG, m_outH);
	OnFreeDouble2D(tmpOutImageB, m_outH);
}


void CColorImageProcessingDoc::OnConvRGB(double** mask, int size)
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	int m_tmpInH = m_inH + size - 1;
	int m_tmpInW = m_inW + size - 1;
	int m_tmpOutH = m_outH;
	int m_tmpOutW = m_outW;

	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //

	// 임시 메모리 할당
	double** tmpInImageR, ** tmpInImageG, ** tmpInImageB, ** tmpOutImageR, ** tmpOutImageG, ** tmpOutImageB;
	tmpInImageR = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageG = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageB = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpOutImageR = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageG = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageB = OnMallocDouble2D(m_outH, m_outW);


	//padding
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < (int)(size / 2); j++) {
			tmpInImageR[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageR[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageR[i][m_inW - 1];

			tmpInImageG[i + (int)(size / 2)][j] = m_inImageG[i][0];
			tmpInImageG[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageG[i][m_inW - 1];

			tmpInImageB[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageB[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageB[i][m_inW - 1];
		}
	}
	for (int i = 0; i < (int)(size / 2); i++) {
		for (int j = 0; j < m_tmpInW; j++) {
			tmpInImageR[i][j] = tmpInImageR[(int)(size / 2)][j];
			tmpInImageR[i + (int)(size / 2) + m_inH][j] = tmpInImageR[(int)(size / 2) + m_inH - 1][j];

			tmpInImageG[i][j] = tmpInImageG[(int)(size / 2)][j];
			tmpInImageG[i + (int)(size / 2) + m_inH][j] = tmpInImageG[(int)(size / 2) + m_inH - 1][j];

			tmpInImageB[i][j] = tmpInImageB[(int)(size / 2)][j];
			tmpInImageB[i + (int)(size / 2) + m_inH][j] = tmpInImageB[(int)(size / 2) + m_inH - 1][j];
		}
	}

	//입력 이미지 --> 임시 입력 이미지
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			tmpInImageR[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageR[i][j];
			tmpInImageG[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageG[i][j];
			tmpInImageB[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageB[i][j];
		}

	// *** 회선 연산 *** //

	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			// 마스크와 한점을 중심으로한 size x size을 곱하기
			double S[3] = { 0 };
			for (int m = 0; m < size; m++)
				for (int n = 0; n < size; n++) {
					S[0] += tmpInImageR[i + m][j + n] * mask[m][n];
					S[1] += tmpInImageG[i + m][j + n] * mask[m][n];
					S[2] += tmpInImageB[i + m][j + n] * mask[m][n];
				}
			
			tmpOutImageR[i][j] = S[0];
			tmpOutImageG[i][j] = S[1];
			tmpOutImageB[i][j] = S[2];
		}
	}
	// 임시 출력 영상 --> 출력 영상.
	for (int i = 0; i < m_outH; i++)
		for (int j = 0; j < m_outW; j++) {
			if (tmpOutImageR[i][j] < 0.0)
				m_outImageR[i][j] = 0;
			else if (tmpOutImageR[i][j] > 255.0)
				m_outImageR[i][j] = 255;
			else
				m_outImageR[i][j] = (unsigned char)tmpOutImageR[i][j];

			if (tmpOutImageG[i][j] < 0.0)
				m_outImageG[i][j] = 0;
			else if (tmpOutImageG[i][j] > 255.0)
				m_outImageG[i][j] = 255;
			else
				m_outImageG[i][j] = (unsigned char)tmpOutImageG[i][j];

			if (tmpOutImageB[i][j] < 0.0)
				m_outImageB[i][j] = 0;
			else if (tmpOutImageB[i][j] > 255.0)
				m_outImageB[i][j] = 255;
			else
				m_outImageB[i][j] = (unsigned char)tmpOutImageB[i][j];
		}

	// 임시 메모리 해제
	OnFreeDouble2D(tmpInImageR, m_tmpInH);
	OnFreeDouble2D(tmpInImageG, m_tmpInH);
	OnFreeDouble2D(tmpInImageB, m_tmpInH);
	OnFreeDouble2D(tmpOutImageR, m_outH);
	OnFreeDouble2D(tmpOutImageG, m_outH);
	OnFreeDouble2D(tmpOutImageB, m_outH);
}


void CColorImageProcessingDoc::OnBlurImage()
{
	CConstantBlurDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int size = (int)dlg.m_constant;
		if (size % 2 == 0) {
			MessageBox(NULL, L"마스크 크기는 홀수만 가능", L"경고", NULL);
			return;
		}
		double** mask = OnMallocDouble2D(size, size, 0);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				mask[i][j] = 1.0 / (size * size);
			}
		}
		OnConvRGB(mask, size);
		OnFreeDouble2D(mask, size);
	}
}


void CColorImageProcessingDoc::OnSharpHigh()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantShighDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double value = dlg.m_constant;
		double val_filter = -1.0 * value / 9.0;
		int size = 3;
		double** mask = OnMallocDouble2D(size, size, 0);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				mask[i][j] = val_filter;
			}
		}
		mask[1][1] = 1 - val_filter * 8.0;
		OnConvRGB(mask, size);
		OnFreeDouble2D(mask, size);
	}
}


void CColorImageProcessingDoc::OnSharpLow()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantSlowDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int size = (int)dlg.m_constant1;
		if (size % 2 == 0 || size < 0) {
			MessageBox(NULL, L"마스크 크기는 홀수만 가능", L"경고", NULL);
			return;
		}
		double valSharp = dlg.m_constant2;
		double** mask = OnMallocDouble2D(size, size, 0);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				mask[i][j] = 1.0 / (size * size);
			}
		}
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		int m_tmpInH = m_inH + size - 1;
		int m_tmpInW = m_inW + size - 1;
		int m_tmpOutH = m_outH;
		int m_tmpOutW = m_outW;

		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //

		// 임시 메모리 할당
		double** tmpInImageR, ** tmpInImageG, ** tmpInImageB, ** tmpOutImageR, ** tmpOutImageG, ** tmpOutImageB;
		tmpInImageR = OnMallocDouble2D(m_tmpInH, m_tmpInW);
		tmpInImageG = OnMallocDouble2D(m_tmpInH, m_tmpInW);
		tmpInImageB = OnMallocDouble2D(m_tmpInH, m_tmpInW);
		tmpOutImageR = OnMallocDouble2D(m_outH, m_outW);
		tmpOutImageG = OnMallocDouble2D(m_outH, m_outW);
		tmpOutImageB = OnMallocDouble2D(m_outH, m_outW);


		//padding
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < (int)(size / 2); j++) {
				tmpInImageR[i + (int)(size / 2)][j] = m_inImageR[i][0];
				tmpInImageR[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageR[i][m_inW - 1];

				tmpInImageG[i + (int)(size / 2)][j] = m_inImageG[i][0];
				tmpInImageG[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageG[i][m_inW - 1];

				tmpInImageB[i + (int)(size / 2)][j] = m_inImageR[i][0];
				tmpInImageB[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageB[i][m_inW - 1];
			}
		}
		for (int i = 0; i < (int)(size / 2); i++) {
			for (int j = 0; j < m_tmpInW; j++) {
				tmpInImageR[i][j] = tmpInImageR[(int)(size / 2)][j];
				tmpInImageR[i + (int)(size / 2) + m_inH][j] = tmpInImageR[(int)(size / 2) + m_inH - 1][j];

				tmpInImageG[i][j] = tmpInImageG[(int)(size / 2)][j];
				tmpInImageG[i + (int)(size / 2) + m_inH][j] = tmpInImageG[(int)(size / 2) + m_inH - 1][j];

				tmpInImageB[i][j] = tmpInImageB[(int)(size / 2)][j];
				tmpInImageB[i + (int)(size / 2) + m_inH][j] = tmpInImageB[(int)(size / 2) + m_inH - 1][j];
			}
		}

		//입력 이미지 --> 임시 입력 이미지
		for (int i = 0; i < m_inH; i++)
			for (int j = 0; j < m_inW; j++) {
				tmpInImageR[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageR[i][j];
				tmpInImageG[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageG[i][j];
				tmpInImageB[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageB[i][j];
			}

		// *** 회선 연산 *** //

		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				// 마스크와 한점을 중심으로한 size x size을 곱하기
				double S[3] = { 0 };
				for (int m = 0; m < size; m++)
					for (int n = 0; n < size; n++) {
						S[0] += tmpInImageR[i + m][j + n] * mask[m][n];
						S[1] += tmpInImageG[i + m][j + n] * mask[m][n];
						S[2] += tmpInImageB[i + m][j + n] * mask[m][n];
					}
				tmpOutImageR[i][j] = S[0];
				tmpOutImageG[i][j] = S[1];
				tmpOutImageB[i][j] = S[2];
			}
		}

		for (int i = 0; i < m_inH; i++) 
			for (int j = 0; j < m_inW; j++) {
				tmpOutImageR[i][j] = (double)m_inImageR[i][j] - tmpOutImageR[i][j];
				tmpOutImageG[i][j] = (double)m_inImageG[i][j] - tmpOutImageG[i][j];
				tmpOutImageB[i][j] = (double)m_inImageB[i][j] - tmpOutImageB[i][j];
			}
		

		// 임시 출력 영상 --> 출력 영상.
		double R, G, B;
		for (int i = 0; i < m_outH; i++)
			for (int j = 0; j < m_outW; j++) {
				R = m_inImageR[i][j] + valSharp * tmpOutImageR[i][j];
				G = m_inImageG[i][j] + valSharp * tmpOutImageG[i][j];
				B = m_inImageB[i][j] + valSharp * tmpOutImageB[i][j];
				if (R < 0.0)
					m_outImageR[i][j] = 0;
				else if (R > 255.0)
					m_outImageR[i][j] = 255;
				else
					m_outImageR[i][j] = (unsigned char)R;

				if (G < 0.0)
					m_outImageG[i][j] = 0;
				else if (G > 255.0)
					m_outImageG[i][j] = 255;
				else
					m_outImageG[i][j] = (unsigned char)G;

				if (B < 0.0)
					m_outImageB[i][j] = 0;
				else if (B > 255.0)
					m_outImageB[i][j] = 255;
				else
					m_outImageB[i][j] = (unsigned char)B;
			}

		// 임시 메모리 해제
		OnFreeDouble2D(tmpInImageR, m_tmpInH);
		OnFreeDouble2D(tmpInImageG, m_tmpInH);
		OnFreeDouble2D(tmpInImageB, m_tmpInH);
		OnFreeDouble2D(tmpOutImageR, m_outH);
		OnFreeDouble2D(tmpOutImageG, m_outH);
		OnFreeDouble2D(tmpOutImageB, m_outH);
		OnFreeDouble2D(mask, size);
	}
}




void CColorImageProcessingDoc::OnSmoothingImage()
{
	// TODO: 여기에 구현 코드 추가.
	const int size = 3;
	double** mask = OnMallocDouble2D(size, size, 0);
	mask[0][0] = mask[0][2] = mask[2][0] = mask[2][2] = 1.0 / 16.0;
	mask[0][1] = mask[1][0] = mask[2][1] = mask[1][2] = 1.0 / 8.0;
	mask[1][1] = 1.0 / 4.0;
	OnConvRGB(mask, size);
	OnFreeDouble2D(mask, size);
}


void CColorImageProcessingDoc::OnSmoothingCustom()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantSmoothDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int size = (int)dlg.m_constant1;
		if (size % 2 == 0 || size < 0) {
			MessageBox(NULL, L"마스크 크기는 홀수만 가능", L"경고", NULL);
			return;
		}
		double sigma = dlg.m_constant2;
		if (sigma < 0) {
			MessageBox(NULL, L"시그마는 0 이상", L"경고", NULL);
			return;
		}

		double** mask = OnMallocDouble2D(size, size, 0);
		double sum = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int dis = (i - (int)(size / 2)) * (i - (int)(size / 2)) + (j - (int)(size / 2)) * (j - (int)(size / 2));
				mask[i][j] = exp(-1.0 * (double)dis / (2.0 * sigma * sigma)) / (2.0 * 3.141592 * sigma * sigma);
				sum += mask[i][j];
			}
		}
		//필터 정규화
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				mask[i][j] = mask[i][j] / sum;

		OnConvRGB(mask, size);
		OnFreeDouble2D(mask, size);
	}
}


void CColorImageProcessingDoc::OnEdgeShift()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioThreeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[1][0] = -1; mask[1][1] = 1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][1] = -1; mask[1][1] = 1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[1][0] = mask[0][1] = -1; mask[1][1] = 2;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
	}
}


void CColorImageProcessingDoc::OnEdgeHomo()
{
	const int size = 3;
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	int m_tmpInH = m_inH + size - 1;
	int m_tmpInW = m_inW + size - 1;
	int m_tmpOutH = m_outH;
	int m_tmpOutW = m_outW;

	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //

	// 임시 메모리 할당
	double** tmpInImageR, ** tmpInImageG, ** tmpInImageB, ** tmpOutImageR, ** tmpOutImageG, ** tmpOutImageB;
	tmpInImageR = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageG = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageB = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpOutImageR = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageG = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageB = OnMallocDouble2D(m_outH, m_outW);


	//padding
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < (int)(size / 2); j++) {
			tmpInImageR[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageR[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageR[i][m_inW - 1];

			tmpInImageG[i + (int)(size / 2)][j] = m_inImageG[i][0];
			tmpInImageG[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageG[i][m_inW - 1];

			tmpInImageB[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageB[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageB[i][m_inW - 1];
		}
	}
	for (int i = 0; i < (int)(size / 2); i++) {
		for (int j = 0; j < m_tmpInW; j++) {
			tmpInImageR[i][j] = tmpInImageR[(int)(size / 2)][j];
			tmpInImageR[i + (int)(size / 2) + m_inH][j] = tmpInImageR[(int)(size / 2) + m_inH - 1][j];

			tmpInImageG[i][j] = tmpInImageG[(int)(size / 2)][j];
			tmpInImageG[i + (int)(size / 2) + m_inH][j] = tmpInImageG[(int)(size / 2) + m_inH - 1][j];

			tmpInImageB[i][j] = tmpInImageB[(int)(size / 2)][j];
			tmpInImageB[i + (int)(size / 2) + m_inH][j] = tmpInImageB[(int)(size / 2) + m_inH - 1][j];
		}
	}

	//입력 이미지 --> 임시 입력 이미지
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			tmpInImageR[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageR[i][j];
			tmpInImageG[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageG[i][j];
			tmpInImageB[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageB[i][j];
		}

	// *** 회선 연산 *** //
	
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			double max[3] = { 0 };
			double tmpmax[3] = { 0 };
			for (int m = 0; m < size; m++) {
				for (int n = 0; n < size; n++) {
					tmpmax[0] = fabs((double)(tmpInImageR[i + 1][j + 1] - tmpInImageR[i + m][j + n]));
					tmpmax[1] = fabs((double)(tmpInImageG[i + 1][j + 1] - tmpInImageG[i + m][j + n]));
					tmpmax[2] = fabs((double)(tmpInImageB[i + 1][j + 1] - tmpInImageB[i + m][j + n]));
					if (tmpmax[0] > max[0])
						max[0] = tmpmax[0];
					if (tmpmax[1] > max[1])
						max[1] = tmpmax[1];
					if (tmpmax[2] > max[2])
						max[2] = tmpmax[2];

				}
			}
			tmpOutImageR[i][j] = max[0];
			tmpOutImageG[i][j] = max[1];
			tmpOutImageB[i][j] = max[2];
		}
	}
	// 임시 출력 영상 --> 출력 영상.
	for (int i = 0; i < m_outH; i++)
		for (int j = 0; j < m_outW; j++) {
			if (tmpOutImageR[i][j] < 0.0)
				m_outImageR[i][j] = 0;
			else if (tmpOutImageR[i][j] > 255.0)
				m_outImageR[i][j] = 255;
			else
				m_outImageR[i][j] = (unsigned char)tmpOutImageR[i][j];

			if (tmpOutImageG[i][j] < 0.0)
				m_outImageG[i][j] = 0;
			else if (tmpOutImageG[i][j] > 255.0)
				m_outImageG[i][j] = 255;
			else
				m_outImageG[i][j] = (unsigned char)tmpOutImageG[i][j];

			if (tmpOutImageB[i][j] < 0.0)
				m_outImageB[i][j] = 0;
			else if (tmpOutImageB[i][j] > 255.0)
				m_outImageB[i][j] = 255;
			else
				m_outImageB[i][j] = (unsigned char)tmpOutImageB[i][j];
		}

	// 임시 메모리 해제
	OnFreeDouble2D(tmpInImageR, m_tmpInH);
	OnFreeDouble2D(tmpInImageG, m_tmpInH);
	OnFreeDouble2D(tmpInImageB, m_tmpInH);
	OnFreeDouble2D(tmpOutImageR, m_outH);
	OnFreeDouble2D(tmpOutImageG, m_outH);
	OnFreeDouble2D(tmpOutImageB, m_outH);
}


void CColorImageProcessingDoc::OnEdgeSub()
{
	const int size = 3;
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFreeOutImage();
	// 중요! 출력 이미지 크기 결정
	m_outH = m_inH;
	m_outW = m_inW;
	int m_tmpInH = m_inH + size - 1;
	int m_tmpInW = m_inW + size - 1;
	int m_tmpOutH = m_outH;
	int m_tmpOutW = m_outW;

	// 메모리 할당
	m_outImageR = OnMalloc2D(m_outH, m_outW);
	m_outImageG = OnMalloc2D(m_outH, m_outW);
	m_outImageB = OnMalloc2D(m_outH, m_outW);

	// ** 진짜 영상처리  알고리즘 ** //

	// 임시 메모리 할당
	double** tmpInImageR, ** tmpInImageG, ** tmpInImageB, ** tmpOutImageR, ** tmpOutImageG, ** tmpOutImageB;
	tmpInImageR = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageG = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpInImageB = OnMallocDouble2D(m_tmpInH, m_tmpInW);
	tmpOutImageR = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageG = OnMallocDouble2D(m_outH, m_outW);
	tmpOutImageB = OnMallocDouble2D(m_outH, m_outW);


	//padding
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < (int)(size / 2); j++) {
			tmpInImageR[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageR[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageR[i][m_inW - 1];

			tmpInImageG[i + (int)(size / 2)][j] = m_inImageG[i][0];
			tmpInImageG[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageG[i][m_inW - 1];

			tmpInImageB[i + (int)(size / 2)][j] = m_inImageR[i][0];
			tmpInImageB[i + (int)(size / 2)][j + m_inW + (int)(size / 2)] = m_inImageB[i][m_inW - 1];
		}
	}
	for (int i = 0; i < (int)(size / 2); i++) {
		for (int j = 0; j < m_tmpInW; j++) {
			tmpInImageR[i][j] = tmpInImageR[(int)(size / 2)][j];
			tmpInImageR[i + (int)(size / 2) + m_inH][j] = tmpInImageR[(int)(size / 2) + m_inH - 1][j];

			tmpInImageG[i][j] = tmpInImageG[(int)(size / 2)][j];
			tmpInImageG[i + (int)(size / 2) + m_inH][j] = tmpInImageG[(int)(size / 2) + m_inH - 1][j];

			tmpInImageB[i][j] = tmpInImageB[(int)(size / 2)][j];
			tmpInImageB[i + (int)(size / 2) + m_inH][j] = tmpInImageB[(int)(size / 2) + m_inH - 1][j];
		}
	}

	//입력 이미지 --> 임시 입력 이미지
	for (int i = 0; i < m_inH; i++)
		for (int j = 0; j < m_inW; j++) {
			tmpInImageR[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageR[i][j];
			tmpInImageG[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageG[i][j];
			tmpInImageB[i + (int)(size / 2)][j + (int)(size / 2)] = m_inImageB[i][j];
		}

	// *** 회선 연산 *** //

	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			double max[3] = { 0 };
			double tmpmax[3] = { 0 };
			for (int m = 0; m < 4; m++) {
				tmpmax[0] = fabs(tmpInImageR[i + 2 - m / 3][j + 2 - m % 3] - tmpInImageR[i + m / 3][j + m % 3]);
				tmpmax[1] = fabs(tmpInImageG[i + 2 - m / 3][j + 2 - m % 3] - tmpInImageG[i + m / 3][j + m % 3]);
				tmpmax[2] = fabs(tmpInImageB[i + 2 - m / 3][j + 2 - m % 3] - tmpInImageB[i + m / 3][j + m % 3]);
				if (tmpmax[0] > max[0])
					max[0] = tmpmax[0];
				if (tmpmax[1] > max[1])
					max[1] = tmpmax[1];
				if (tmpmax[2] > max[2])
					max[2] = tmpmax[2];
			}
			tmpOutImageR[i][j] = max[0];
			tmpOutImageG[i][j] = max[1];
			tmpOutImageB[i][j] = max[2];
		}
	}
	// 임시 출력 영상 --> 출력 영상.
	for (int i = 0; i < m_outH; i++)
		for (int j = 0; j < m_outW; j++) {
			if (tmpOutImageR[i][j] < 0.0)
				m_outImageR[i][j] = 0;
			else if (tmpOutImageR[i][j] > 255.0)
				m_outImageR[i][j] = 255;
			else
				m_outImageR[i][j] = (unsigned char)tmpOutImageR[i][j];

			if (tmpOutImageG[i][j] < 0.0)
				m_outImageG[i][j] = 0;
			else if (tmpOutImageG[i][j] > 255.0)
				m_outImageG[i][j] = 255;
			else
				m_outImageG[i][j] = (unsigned char)tmpOutImageG[i][j];

			if (tmpOutImageB[i][j] < 0.0)
				m_outImageB[i][j] = 0;
			else if (tmpOutImageB[i][j] > 255.0)
				m_outImageB[i][j] = 255;
			else
				m_outImageB[i][j] = (unsigned char)tmpOutImageB[i][j];
		}

	// 임시 메모리 해제
	OnFreeDouble2D(tmpInImageR, m_tmpInH);
	OnFreeDouble2D(tmpInImageG, m_tmpInH);
	OnFreeDouble2D(tmpInImageB, m_tmpInH);
	OnFreeDouble2D(tmpOutImageR, m_outH);
	OnFreeDouble2D(tmpOutImageG, m_outH);
	OnFreeDouble2D(tmpOutImageB, m_outH);
}


void CColorImageProcessingDoc::OnEdgeRobert()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioThreeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = -1; mask[1][1] = 1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][2] = -1; mask[1][1] = 1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = mask[0][2] = -1; mask[1][1] = 2;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
	}
}


void CColorImageProcessingDoc::OnEdgePrewitt()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioThreeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = mask[0][1] = mask[0][2] = -1;
			mask[2][0] = mask[2][1] = mask[2][2] = 1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = mask[1][0] = mask[2][0] = 1;
			mask[0][2] = mask[1][2] = mask[2][2] = -1;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][1] = -1.0; mask[0][2] = -2.0; mask[1][0] = 1.0;
			mask[1][2] = -1.0; mask[2][0] = 2.0; mask[2][1] = 1.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
	}
}


void CColorImageProcessingDoc::OnEdgeSobel()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioThreeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = -1.0; mask[0][1] = -2.0; mask[0][2] = -1.0;
			mask[2][0] = 1.0; mask[2][1] = 2.0; mask[2][2] = 1.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][0] = 1.0; mask[1][0] = 2.0; mask[2][0] = 1.0;
			mask[0][2] = -1.0; mask[1][2] = -2.0; mask[2][2] = -1.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][1] = -2.0; mask[0][2] = -2.0; mask[1][0] = 2.0;
			mask[1][2] = -2.0; mask[2][0] = 2.0; mask[2][1] = 2.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
	}
}


void CColorImageProcessingDoc::OnEdgeLapl()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioLaplDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][1] = mask[1][0] = mask[1][2] = mask[2][1] = -1; mask[1][1] = 4;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			for (int i = 0; i < 9; i++) mask[i / 3][i % 3] = 1; mask[1][1] = -8;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			int size = 3;
			double** mask = OnMallocDouble2D(size, size, 0);
			for (int i = 0; i < 9; i++) mask[i / 3][i % 3] = -1; mask[1][1] = 8;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
	}
}


void CColorImageProcessingDoc::OnEdgeLog()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioLogDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 5;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][2] = mask[1][1] = mask[1][3] = mask[2][0] = mask[2][4] = mask[3][1] = mask[3][3] = mask[4][2] = -1.0;
			mask[1][2] = mask[2][1] = mask[2][3] = mask[3][2] = -2.0;
			mask[2][2] = 16;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			CConstantSmoothDlg dlg;
			if (dlg.DoModal() == IDOK) {
				int size = (int)dlg.m_constant1;
				if (size % 2 == 0 || size < 0) {
					MessageBox(NULL, L"마스크 크기는 홀수만 가능", L"경고", NULL);
					return;
				}
				double sigma = dlg.m_constant2;
				if (sigma < 0) {
					MessageBox(NULL, L"시그마는 0 이상", L"경고", NULL);
					return;
				}

				double** mask = OnMallocDouble2D(size, size, 0);
				double sum = 0;
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						double dis = (double)((i - (int)(size / 2)) * (i - (int)(size / 2)) + (j - (int)(size / 2)) * (j - (int)(size / 2)));
						double valLoG = (1.0 - (dis / (2.0 * sigma * sigma))) / (3.141592 * pow(sigma, 4)) - exp(-1.0 * dis / (3.141592 * sigma * sigma));
						mask[i][j] = valLoG;
						sum += valLoG;
					}
				}
				//필터 정규화
				for (int i = 0; i < size; i++) { // 0으로 정규화
					for (int j = 0; j < size; j++) {
						mask[i][j] = mask[i][j] - sum / ((double)size * size);
					}
				}

				OnConvRGB(mask, size);
				OnFreeDouble2D(mask, size);
			}
		}
	}
}


void CColorImageProcessingDoc::OnEdgeDog()
{
	// TODO: 여기에 구현 코드 추가.
	CRadioDogDlg dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.m_radio1 == 0) {
			int size = 7;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][2] = mask[0][3] = mask[0][4] = mask[2][0] = mask[2][6] = mask[3][0] = mask[3][6] = mask[4][0] = mask[4][6] = mask[6][2] = mask[6][3] = mask[6][4] = -1.0;
			mask[1][1] = mask[1][5] = mask[5][1] = mask[5][5] = -2.0;
			mask[1][2] = mask[1][3] = mask[1][4] = mask[2][1] = mask[2][5] = mask[3][1] = mask[3][5] = mask[4][1] = mask[4][5] = mask[5][2] = mask[5][3] = mask[5][4] = -3.0;
			mask[2][2] = mask[2][3] = mask[2][4] = mask[3][2] = mask[3][4] = mask[4][2] = mask[4][3] = mask[4][4] = 5.0;
			mask[3][3] = 16.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 1) {
			int size = 9;
			double** mask = OnMallocDouble2D(size, size, 0);
			mask[0][3] = mask[0][4] = mask[0][5] = mask[3][0] = mask[4][0] = mask[5][0] = mask[3][8] = mask[4][8] = mask[5][8] = mask[8][3] = mask[8][4] = mask[8][5] = -1.0;
			mask[1][1] = mask[1][7] = mask[7][1] = mask[7][7] = -2.0;
			mask[1][2] = mask[1][3] = mask[1][4] = mask[1][5] = mask[1][6] = mask[2][1] = mask[3][1] = mask[4][1] = mask[5][1] = mask[6][1] = -3.0;
			mask[7][2] = mask[7][3] = mask[7][4] = mask[7][5] = mask[7][6] = mask[2][7] = mask[3][7] = mask[4][7] = mask[5][7] = mask[6][7] = -3.0;
			mask[2][2] = mask[2][6] = mask[6][2] = mask[6][6] = -2.0;
			mask[2][3] = mask[2][4] = mask[2][5] = mask[3][2] = mask[4][2] = mask[5][2] = mask[3][6] = mask[4][6] = mask[5][6] = mask[6][3] = mask[6][4] = mask[6][5] = -1.0;
			mask[3][3] = mask[3][4] = mask[3][5] = mask[4][3] = mask[4][5] = mask[5][3] = mask[5][4] = mask[5][5] = 9.0;
			mask[4][4] = 19.0;
			OnConvRGB(mask, size);
			OnFreeDouble2D(mask, size);
		}
		else if (dlg.m_radio1 == 2) {
			CConstantDogDlg dlg;
			if (dlg.DoModal() == IDOK) {
				int size = (int)dlg.m_constant1;
				if (size % 2 == 0 || size < 0) {
					MessageBox(NULL, L"마스크 크기는 홀수만 가능", L"경고", NULL);
					return;
				}
				double sigma1 = dlg.m_constant2;
				if (sigma1 < 0) {
					MessageBox(NULL, L"시그마는 0 이상", L"경고", NULL);
					return;
				}
				double sigma2 = dlg.m_constant3;
				if (sigma2 < 0) {
					MessageBox(NULL, L"시그마는 0 이상", L"경고", NULL);
					return;
				}

				double sum = 0;
				double valDoG = 0;

				double** mask = OnMallocDouble2D(size, size, 0);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						double dis = (double)((i - (int)(size / 2)) * (i - (int)(size / 2)) + (j - (int)(size / 2)) * (j - (int)(size / 2)));
						double valGauss1 = exp(-1.0 * (double)dis / (2.0 * sigma1 * sigma1)) / (2.0 * 3.141592 * sigma1 * sigma1);
						double valGauss2 = exp(-1.0 * (double)dis / (2.0 * sigma2 * sigma2)) / (2.0 * 3.141592 * sigma2 * sigma2);
						valDoG = valGauss1 - valGauss2;
						sum += valDoG;
						mask[i][j] = valDoG;
					}
				}
				for (int i = 0; i < size; i++) { // 0으로 정규화
					for (int j = 0; j < size; j++) {
						mask[i][j] = mask[i][j] - sum / ((double)size * size);
					}
				}

				OnConvRGB(mask, size);
				OnFreeDouble2D(mask, size);
			}
		}
	}
}


void CColorImageProcessingDoc::OnChageRgb()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantThreeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		int R = (int)dlg.m_constant1, G = (int)dlg.m_constant2, B = (int)dlg.m_constant3;
		if (R > 255 || R < -255 || G>255 || G < -255 || B>255 || B < -255) {
			MessageBox(NULL, L"값은 -255~255 사이", L"경고", NULL);
			return;
		}
		// TODO: 여기에 구현 코드 추가.
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		// ** 진짜 영상처리  알고리즘 ** //
		int newVal[3];
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				newVal[0] = m_inImageR[i][j] + R;
				newVal[1] = m_inImageG[i][j] + G;
				newVal[2] = m_inImageB[i][j] + B;
				if (newVal[0] > 255)
					newVal[0] = 255;
				else if (newVal[0] < 0)
					newVal[0] = 0;
				if (newVal[1] > 255)
					newVal[1] = 255;
				else if (newVal[1] < 0)
					newVal[1] = 0;
				if (newVal[2] > 255)
					newVal[2] = 255;
				else if (newVal[2] < 0)
					newVal[2] = 0;
				m_outImageR[i][j] = (unsigned char)newVal[0];
				m_outImageG[i][j] = (unsigned char)newVal[1];
				m_outImageB[i][j] = (unsigned char)newVal[2];
			}
		}
	}
}


void CColorImageProcessingDoc::OnChangeHsi()
{
	// TODO: 여기에 구현 코드 추가.
		// TODO: 여기에 구현 코드 추가.
	CConstantHsiDlg dlg;
	if (dlg.DoModal() == IDOK) {
		double H = dlg.m_constant1;
		double S = dlg.m_constant2;
		double I = dlg.m_constant3;
		if (H > 360 || H < -360 || S>1 || S < -1 || I>255 || I < -255) {
			MessageBox(NULL, L"H : -360~350, S : -1~1, I : -255~255", L"경고", NULL);
			return;
		}
		// TODO: 여기에 구현 코드 추가.
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);

		double** tmpImageH, ** tmpImageS, ** tmpImageI;
		tmpImageH = OnMallocDouble2D(m_inH, m_inW);
		tmpImageS = OnMallocDouble2D(m_inH, m_inW);
		tmpImageI = OnMallocDouble2D(m_inH, m_inW);
		
		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				double valH, valS, valI;
				unsigned char R, G, B;
				R = m_inImageR[i][j];
				G = m_inImageG[i][j];
				B = m_inImageB[i][j];
				double* hsi = RGB2HSI(R, G, B);
				valH = hsi[0]; valS = hsi[1]; valI = hsi[2];

				tmpImageH[i][j] = valH + H;
				tmpImageS[i][j] = valS + S;
				tmpImageI[i][j] = valI + I;
				delete hsi;
			}
		}

		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				if (tmpImageH[i][j] > 360)
					tmpImageH[i][j] -= 360;
				else if (tmpImageH[i][j] < -360)
					tmpImageH[i][j] += 350;
				if (tmpImageS[i][j] > 1)
					tmpImageS[i][j] = 1;
				else if (tmpImageS[i][j] < 0)
					tmpImageS[i][j] = 0;
				if (tmpImageI[i][j] > 255)
					tmpImageI[i][j] = 255;
				else if (tmpImageI[i][j] < 0)
					tmpImageI[i][j] = 0;

			}
		}

		for (int i = 0; i < m_inH; i++) {
			for (int j = 0; j < m_inW; j++) {
				double valH = tmpImageH[i][j], valS = tmpImageS[i][j], valI = tmpImageI[i][j];
				unsigned char* rgb = HSI2RGB(valH, valS, valI);
				unsigned char R = rgb[0], G = rgb[1], B = rgb[2];

				m_outImageR[i][j] = R;
				m_outImageG[i][j] = G;
				m_outImageB[i][j] = B;

				delete rgb;
			}
		}
	}
}


void CColorImageProcessingDoc::OnPickColor()
{
	// TODO: 여기에 구현 코드 추가.
	CConstantPickDlg dlg;
	if (dlg.DoModal()) {
		double angle1 = dlg.m_constant1;
		double angle2 = dlg.m_constant2;
		// 기존 메모리 해제
		OnFreeOutImage();
		// 중요! 출력 이미지 크기 결정 --> 알고리즘에 따름...
		m_outH = m_inH;
		m_outW = m_inW;
		// 메모리 할당
		m_outImageR = OnMalloc2D(m_outH, m_outW);
		m_outImageG = OnMalloc2D(m_outH, m_outW);
		m_outImageB = OnMalloc2D(m_outH, m_outW);
		// ** 진짜 영상처리 알고리즘 **
		for (int i = 0; i < m_inH; i++) {
			for (int k = 0; k < m_inW; k++) {
				// HIS 모델 값
				// H(색상) : 0~360
				// S(채도) : 0.0 ~ 1.0
				// I(명도) : 0 ~ 255

				// RGB --> HSI
				double H, S, I;
				unsigned char R, G, B;
				R = m_inImageR[i][k];
				G = m_inImageG[i][k];
				B = m_inImageB[i][k];

				double* hsi = RGB2HSI(R, G, B);
				H = hsi[0];	S = hsi[1];	I = hsi[2];

				/// 색상 추출
				if (angle1 <= H && H <= angle2) {
					m_outImageR[i][k] = m_inImageR[i][k];
					m_outImageG[i][k] = m_inImageG[i][k];
					m_outImageB[i][k] = m_inImageB[i][k];
				}
				else {
					double avg = (m_inImageR[i][k] + m_inImageG[i][k] + m_inImageB[i][k]) / 3.0;
					m_outImageR[i][k] = m_outImageG[i][k] = m_outImageB[i][k] = (unsigned char)avg;
				}

			}
		}
	}
}

void CColorImageProcessingDoc::InImg2OutImg()
{
	// TODO: 여기에 구현 코드 추가.
	// 기존 메모리 해제
	OnFree2D(m_inImageR, m_inH);
	OnFree2D(m_inImageG, m_inH);
	OnFree2D(m_inImageB, m_inH);
	m_inImageR = m_inImageG = m_inImageB = NULL;
	// 입력이미지 크기 변환
	m_inH = m_outH;
	m_inW = m_outW;
	// 입력 메모리 재할당
	m_inImageR = OnMalloc2D(m_outH, m_outW);
	m_inImageG = OnMalloc2D(m_outH, m_outW);
	m_inImageB = OnMalloc2D(m_outH, m_outW);

	// ** 출력 이미지를 입력 이미지로 복사 ** //
	for (int i = 0; i < m_inH; i++) {
		for (int j = 0; j < m_inW; j++) {
			m_inImageR[i][j] = m_outImageR[i][j];
			m_inImageG[i][j] = m_outImageG[i][j];
			m_inImageB[i][j] = m_outImageB[i][j];
		}
	}
}
