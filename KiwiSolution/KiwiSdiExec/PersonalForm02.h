#pragma once



// CPersonalForm02 窗体视图

class CPersonalForm02 : public CFormView
{
	DECLARE_DYNCREATE(CPersonalForm02)

protected:
	CPersonalForm02();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


