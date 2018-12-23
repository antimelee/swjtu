// CG2016112422κΰ07Doc.h : interface of the CCG201611242207Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG201611242207DOC_H__E15EACEC_FCDD_428D_A1D1_0DD328C8628A__INCLUDED_)
#define AFX_CG201611242207DOC_H__E15EACEC_FCDD_428D_A1D1_0DD328C8628A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCG201611242207Doc : public CDocument
{
protected: // create from serialization only
	CCG201611242207Doc();
	DECLARE_DYNCREATE(CCG201611242207Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG201611242207Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCG201611242207Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCG201611242207Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG201611242207DOC_H__E15EACEC_FCDD_428D_A1D1_0DD328C8628A__INCLUDED_)
