// DlgNewForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KiwiSdiExec.h"
#include "DlgNewForm.h"
#include "afxdialogex.h"

#include "SQLiteHelper.h"
#include "MainFrm.h"

// CDlgNewForm �Ի���

IMPLEMENT_DYNAMIC(CDlgNewForm, CDialogEx)

CDlgNewForm::CDlgNewForm(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewForm::IDD, pParent)
{

}

CDlgNewForm::~CDlgNewForm()
{
}

void CDlgNewForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FORM_TYPE, m_listFormType);
}


BEGIN_MESSAGE_MAP(CDlgNewForm, CDialogEx)
END_MESSAGE_MAP()


// CDlgNewForm ��Ϣ��������


BOOL CDlgNewForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	m_listFormType.DeleteAllItems();

	m_listFormType.InsertColumn(0, _T("���"), LVCFMT_LEFT, 50);
	m_listFormType.InsertColumn(1, _T("������������"), LVCFMT_LEFT, 250);
	m_listFormType.InsertColumn(2, _T("˵��"), LVCFMT_LEFT, 100);


	CSQLiteHelper *help = new CSQLiteHelper();
	help->openDB("kiwi.db3");

	char *sql1 = "select type_serial, type_name, type_description from form_type";
	int row, col;
	char *eee = "i";
	char **result = &eee;
	char **re = help->rawQuery(sql1, &row, &col, result); //row �ǲ�������м�¼,col��ÿ����¼���ٸ��ֶ�

	int iItem = 0;
	char *type_serial, *type_name, *type_description;
	for (int r = 1; r <= row; r++) {
		type_serial = re[r*col + 0]; type_name = re[r*col + 1]; type_description = re[r*col + 2];
		m_listFormType.InsertItem(iItem, CA2W(type_serial, CP_UTF8));
		m_listFormType.SetItem(iItem, 1, LVIF_TEXT, CA2W(type_name, CP_UTF8), 0, NULL, NULL, NULL);
		m_listFormType.SetItem(iItem, 2, LVIF_TEXT, CA2W(type_description, CP_UTF8), 0, NULL, NULL, NULL);

		iItem++;
	}

	help->closeDB();
	delete help;

	m_listFormType.ModifyExtendedStyle(0, LVS_EX_FULLROWSELECT | LVS_EX_FULLROWSELECT);
	m_listFormType.ModifyExtendedStyle(LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);

	//UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgNewForm::OnOK()
{
	// TODO:  �ڴ�����ר�ô����/����û���
	UpdateData();

	int row = m_listFormType.GetNextItem(-1, LVIS_SELECTED);

	CMainFrame* pWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	::PostMessage(pWnd->m_hWnd, WM_CREATE_PERSONAL_FORM, 0l, LPARAM(new CString(m_listFormType.GetItemText(row, 0))));

	CDialogEx::OnOK();
}