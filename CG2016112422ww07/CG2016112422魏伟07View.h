// CG2016112422魏伟07View.h : interface of the CCG201611242207View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG201611242207VIEW_H__AD618131_28BD_4CCF_8EED_2A870562D406__INCLUDED_)
#define AFX_CG201611242207VIEW_H__AD618131_28BD_4CCF_8EED_2A870562D406__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCG201611242207View : public CScrollView
{
protected: // create from serialization only
	CCG201611242207View();
	DECLARE_DYNCREATE(CCG201611242207View)

// Attributes
public:
	CCG201611242207Doc* GetDocument();
	HGLRC m_hGLRC; //OpenGL 绘制描述表
	CDC* m_pDC; //OpenGL 设备描述表
	HPALETTE m_hPalette; //OpenGL 调色板
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG201611242207View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCG201611242207View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL RenderScene(void);
	BOOL SetupPixelFormat(void);
	void SetLogicalPalette(void);
// Generated message map functions
protected:
	//{{AFX_MSG(CCG201611242207View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuitemteapot();
	afx_msg void OnMenuitemcone();
	afx_msg void OnMenuitemball();
	afx_msg void OnMenuitemtorus();
	afx_msg void OnMenuitembrass();
	afx_msg void OnMenuitembronze();
	afx_msg void OnMenuitemgold();
	afx_msg void OnMenuitemsilver();
	afx_msg void OnMenuitemjade();
	afx_msg void OnMenuitemplastic();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuitemrotatex();
	afx_msg void OnMenuitemrotatey();
	afx_msg void OnMenuitemrotatez();
	afx_msg void OnMenuitemmovex();
	afx_msg void OnMenuitemmovey();
	afx_msg void OnMenuitemmovez();
	afx_msg void OnMenuitem32791();
	afx_msg void OnMenuitem32792();
	afx_msg void OnMenuitem32793();
	afx_msg void OnMenuitem32794();
	afx_msg void OnMenuitemstop();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CG2016112422魏伟07View.cpp
inline CCG201611242207Doc* CCG201611242207View::GetDocument()
   { return (CCG201611242207Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG201611242207VIEW_H__AD618131_28BD_4CCF_8EED_2A870562D406__INCLUDED_)
