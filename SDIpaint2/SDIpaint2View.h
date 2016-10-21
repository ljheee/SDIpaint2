
// SDIpaint2View.h : CSDIpaint2View 类的接口
//

#pragma once


class CSDIpaint2View : public CView
{
protected: // 仅从序列化创建
	CSDIpaint2View();
	DECLARE_DYNCREATE(CSDIpaint2View)

// 特性
public:
	CSDIpaint2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSDIpaint2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SDIpaint2View.cpp 中的调试版本
inline CSDIpaint2Doc* CSDIpaint2View::GetDocument() const
   { return reinterpret_cast<CSDIpaint2Doc*>(m_pDocument); }
#endif

