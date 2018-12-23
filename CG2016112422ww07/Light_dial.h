#if !defined(AFX_LIGHT_DIAL_H__160DFAD3_E371_401F_AF5B_C2858E1B7237__INCLUDED_)
#define AFX_LIGHT_DIAL_H__160DFAD3_E371_401F_AF5B_C2858E1B7237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Light_dial.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Light_dial dialog

class Light_dial : public CDialog
{
// Construction
public:
	Light_dial(CWnd* pParent = NULL);   // standard constructor
	int style;
	float pox,poy,poz,dix,diy,diz;
// Dialog Data
	//{{AFX_DATA(Light_dial)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Light_dial)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Light_dial)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHT_DIAL_H__160DFAD3_E371_401F_AF5B_C2858E1B7237__INCLUDED_)
