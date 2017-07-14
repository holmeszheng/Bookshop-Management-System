// RefundManage.cpp : implementation file
//

#include "stdafx.h"
#include "BookManage.h"
#include "RefundManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefundManage dialog
extern _ConnectionPtr m_pCon;  
extern _RecordsetPtr m_pRs; 
extern _CommandPtr m_pCom;

extern int PID;

CRefundManage::CRefundManage(CWnd* pParent /*=NULL*/)
	: CDialog(CRefundManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRefundManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRefundManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRefundManage)
	DDX_Control(pDX, IDC_REFUND_TAB, m_RefundTab);
	//}}AFX_DATA_MAP
}

//��������...
CRefundManage p_refund;

BEGIN_MESSAGE_MAP(CRefundManage, CDialog)
	//{{AFX_MSG_MAP(CRefundManage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_REFUND_TAB, OnSelchangeRefundTab)
	ON_COMMAND(ID_EXIT, OnExitRefund)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefundManage message handlers
BOOL CRefundManage::OnInitDialog()
{
	CDialog::OnInitDialog();
	refunddlg1 = new CRefundDlg1();
	refunddlg2 = new CRefundDlg2();
	refunddlg1->Create(IDD_REFUND_DIALOG1,&m_RefundTab);
	refunddlg2->Create(IDD_REFUND_DIALOG2,&m_RefundTab);

	m_RefundTab.InsertItem(0,"REFUND BUSINESS",0);
	m_RefundTab.InsertItem(1,"REFUND RECORD",1);	
	m_RefundTab.SetMinTabWidth(60);
	m_RefundTab.SetCurSel(PID);
	DoTab(PID);
	return TRUE;
}

void CRefundManage::SetDlgState(CWnd *pWnd, BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);
		pWnd->CenterWindow();
	}
	else
		pWnd->ShowWindow(SW_HIDE);
}

void CRefundManage::DoTab(int nPid)
{
	if(nPid > 1) nPid = 1;
	if(nPid < 0) nPid =	0;
	
	BOOL iPid[2];
	iPid[0]=iPid[1]=FALSE;
	iPid[nPid]=TRUE;

	SetDlgState(refunddlg1,iPid[0]);
	SetDlgState(refunddlg2,iPid[1]);
}

void CRefundManage::OnSelchangeRefundTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int select = m_RefundTab.GetCurSel();
	if(select >= 0)
		DoTab(select);
	*pResult = 0;
}

void CRefundManage::OnExitRefund() 
{
	// TODO: Add your command handler code here
	EndDialog(0);
}
