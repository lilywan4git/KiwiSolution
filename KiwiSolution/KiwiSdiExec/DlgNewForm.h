#pragma once

#include "Resource.h"
#include "afxcmn.h"

// CDlgNewForm �Ի���

class CDlgNewForm : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewForm)

public:
	CDlgNewForm(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgNewForm();

// �Ի�������
	enum { IDD = IDD_DIALOG_NEW_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CXTPListCtrl m_listFormType;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
