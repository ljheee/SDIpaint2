
// SDIpaint2View.cpp : CSDIpaint2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SDIpaint2.h"
#endif

#include "SDIpaint2Doc.h"
#include "SDIpaint2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIpaint2View

IMPLEMENT_DYNCREATE(CSDIpaint2View, CView)

BEGIN_MESSAGE_MAP(CSDIpaint2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CSDIpaint2View ����/����

CSDIpaint2View::CSDIpaint2View()
{
	// TODO:  �ڴ˴���ӹ������

}

CSDIpaint2View::~CSDIpaint2View()
{
}

BOOL CSDIpaint2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSDIpaint2View ����
void CSDIpaint2View::OnDraw(CDC* pDC)
{
	CSDIpaint2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);//��������ӳ��ģʽ
	pDC->SetWindowExt(1000,1000);//���ô��ڷ�Χ

	//�����ӿڷ�Χ
	pDC->SetViewportExt(rectClient.right,-rectClient.bottom);
	pDC->SetViewportOrg(rectClient.right / 2, rectClient.bottom/2);

	pDC->Ellipse(CRect(-500,-500,500,500));//������Բ


}


// CSDIpaint2View ��ӡ

BOOL CSDIpaint2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSDIpaint2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSDIpaint2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CSDIpaint2View ���

#ifdef _DEBUG
void CSDIpaint2View::AssertValid() const
{
	CView::AssertValid();
}

void CSDIpaint2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIpaint2Doc* CSDIpaint2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIpaint2Doc)));
	return (CSDIpaint2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSDIpaint2View ��Ϣ�������
CPoint org;//��갴�µ�

//left��갴��
void CSDIpaint2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	org = point;
	CView::OnLButtonDown(nFlags, point);
}

//left���̧��
void CSDIpaint2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDC* pDC = GetDC();
	pDC->MoveTo(org);
	pDC->LineTo(point);
	CView::OnLButtonUp(nFlags, point);


	ReleaseDC(pDC);
}
