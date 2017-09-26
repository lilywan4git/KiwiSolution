// DlgNewFolder.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KiwiSdiExec.h"
#include "DlgNewFolder.h"
#include "afxdialogex.h"

#include "MainFrm.h"

#include "SQLiteHelper.h"

// CDlgNewFolder �Ի���


IMPLEMENT_DYNAMIC(CDlgNewFolder, CDialogEx)

CDlgNewFolder::CDlgNewFolder(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewFolder::IDD, pParent)
	, m_strFolderName(_T(""))
{

}

CDlgNewFolder::~CDlgNewFolder()
{
}

void CDlgNewFolder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strFolderName);
}


BEGIN_MESSAGE_MAP(CDlgNewFolder, CDialogEx)
END_MESSAGE_MAP()


// CDlgNewFolder ��Ϣ�������


void CDlgNewFolder::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData();

	m_strFolderName.Trim();
	if (m_strFolderName.GetLength() > 1) {
		CSQLiteHelper *help = new CSQLiteHelper();
		help->openDB("kiwi.db3");
		char value[500];
		//USES_CONVERSION;
		//sprintf_s(value, 500, "insert into orgnization_folder(folder_id, folder_name) values (null, '%s')", G2U(W2A(m_strFolderName.GetBuffer())));
		sprintf_s(value, 500, "insert into orgnization_folder(folder_id, folder_name) values (null, '%s')", CW2A(m_strFolderName.GetBuffer(), CP_UTF8));
		help->execSQL(value);
		help->closeDB();
		delete help;

		//������֯�ṹ
		CMainFrame* pWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		::PostMessage(pWnd->m_hWnd, WM_UPDATE_ORGNIZATION, 0l, 0l);
	}

	CDialogEx::OnOK();
}
