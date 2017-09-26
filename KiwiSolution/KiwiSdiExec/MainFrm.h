
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "PaneOrgnization.h"
#include "PaneShortcut.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	CXTPDockingPaneManager& GetDockingPaneManager() { return m_paneManager; }
	CMap<UINT, UINT, CWnd*, CWnd*> m_mapPanes;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CXTPDockingPaneManager m_paneManager;

	CPaneOrgnization m_wndPaneOrgnization;
	CPaneShortcut m_wndPaneShortcut;

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

	CView* CreatePersonalForm(CRuntimeClass* pNewViewClass, int nID);
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	afx_msg LRESULT OnCreatePersonalForm(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowPersonalSummary(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateOrgnization(WPARAM wParam, LPARAM lParam);
};
