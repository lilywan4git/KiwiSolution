
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "PaneOrgnization.h"
#include "PaneShortcut.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:
	CXTPDockingPaneManager& GetDockingPaneManager() { return m_paneManager; }
	CMap<UINT, UINT, CWnd*, CWnd*> m_mapPanes;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
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

	bool m_bFullscreen;
	CRect m_rcMainFrame;

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

	CView* CreatePersonalForm(CRuntimeClass* pNewViewClass, int nID);
// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	afx_msg LRESULT OnCreatePersonalForm(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowPersonalSummary(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateOrgnization(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnToolFullscreen();
	afx_msg void OnUpdateToolFullscreen(CCmdUI *pCmdUI);
};

