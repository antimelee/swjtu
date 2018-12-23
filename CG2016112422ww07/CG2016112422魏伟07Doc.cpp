// CG2016112422κΰ07Doc.cpp : implementation of the CCG201611242207Doc class
//

#include "stdafx.h"
#include "CG2016112422κΰ07.h"

#include "CG2016112422κΰ07Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207Doc

IMPLEMENT_DYNCREATE(CCG201611242207Doc, CDocument)

BEGIN_MESSAGE_MAP(CCG201611242207Doc, CDocument)
	//{{AFX_MSG_MAP(CCG201611242207Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207Doc construction/destruction

CCG201611242207Doc::CCG201611242207Doc()
{
	// TODO: add one-time construction code here

}

CCG201611242207Doc::~CCG201611242207Doc()
{
}

BOOL CCG201611242207Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCG201611242207Doc serialization

void CCG201611242207Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207Doc diagnostics

#ifdef _DEBUG
void CCG201611242207Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCG201611242207Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207Doc commands
