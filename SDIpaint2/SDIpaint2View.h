
// SDIpaint2View.h : CSDIpaint2View ��Ľӿ�
//

#pragma once


class CSDIpaint2View : public CView
{
protected: // �������л�����
	CSDIpaint2View();
	DECLARE_DYNCREATE(CSDIpaint2View)

// ����
public:
	CSDIpaint2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSDIpaint2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SDIpaint2View.cpp �еĵ��԰汾
inline CSDIpaint2Doc* CSDIpaint2View::GetDocument() const
   { return reinterpret_cast<CSDIpaint2Doc*>(m_pDocument); }
#endif

