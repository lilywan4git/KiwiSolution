
// KiwiSdiExecView.h : CKiwiSdiExecView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CKiwiSdiExecView : public CFormView
{
protected: // �������л�����
	CKiwiSdiExecView();
	DECLARE_DYNCREATE(CKiwiSdiExecView)

public:
	enum{ IDD = IDD_KIWISDIEXEC_FORM };

// ����
public:
	CKiwiSdiExecDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CKiwiSdiExecView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // KiwiSdiExecView.cpp �еĵ��԰汾
inline CKiwiSdiExecDoc* CKiwiSdiExecView::GetDocument() const
   { return reinterpret_cast<CKiwiSdiExecDoc*>(m_pDocument); }
#endif

