// Light_dial.cpp : implementation file
//

#include "stdafx.h"
#include "CG2016112422κΰ07.h"
#include "Light_dial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Light_dial dialog


Light_dial::Light_dial(CWnd* pParent /*=NULL*/)
	: CDialog(Light_dial::IDD, pParent)
{
	//{{AFX_DATA_INIT(Light_dial)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Light_dial::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Light_dial)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Light_dial, CDialog)
	//{{AFX_MSG_MAP(Light_dial)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Light_dial message handlers


void Light_dial::OnButton1() 
{
	// TODO: Add your control notification handler code here
	style=1;
}


void Light_dial::OnButton2() 
{
	// TODO: Add your control notification handler code here
	style=2;
}
void Light_dial::OnButton3() 
{
	// TODO: Add your control notification handler code here
	style=3;
}

void Light_dial::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
	CString str1;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str1);
	pox = atof(str1);
	GetDlgItem(IDC_EDIT4)->GetWindowText(str1);
	poy =atof(str1);
	GetDlgItem(IDC_EDIT6)->GetWindowText(str1);
	poz = atof(str1);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str1);
	dix = atof(str1);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str1);
	diy = atof(str1);
	GetDlgItem(IDC_EDIT7)->GetWindowText(str1);
	diz = atof(str1);
}