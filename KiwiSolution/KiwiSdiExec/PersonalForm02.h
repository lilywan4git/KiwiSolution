#pragma once



// CPersonalForm02 ������ͼ

class CPersonalForm02 : public CFormView
{
	DECLARE_DYNCREATE(CPersonalForm02)

protected:
	CPersonalForm02();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPersonalForm02();

public:
	enum { IDD = IDD_PERSONAL_FORM02 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


