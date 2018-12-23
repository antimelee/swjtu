// CG2016112422κΰ07.h : main header file for the CG2016112422κΰ07 application
//

#if !defined(AFX_CG201611242207_H__CBBD1FED_C51D_4F33_A980_5130B9ADB918__INCLUDED_)
#define AFX_CG201611242207_H__CBBD1FED_C51D_4F33_A980_5130B9ADB918__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207App:
// See CG2016112422κΰ07.cpp for the implementation of this class
//

class CCG201611242207App : public CWinApp
{
public:
	CCG201611242207App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG201611242207App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCG201611242207App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG201611242207_H__CBBD1FED_C51D_4F33_A980_5130B9ADB918__INCLUDED_)
