#pragma once


// CDlgNewFolder �Ի���

class CDlgNewFolder : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewFolder)

public:
	CDlgNewFolder(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgNewFolder();

// �Ի�������
	enum { IDD = IDD_DIALOG_NEW_FOLDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strFolderName;
	virtual void OnOK();
};
