
// KiwiSdiExecDoc.cpp : CKiwiSdiExecDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "KiwiSdiExec.h"
#endif

#include "KiwiSdiExecDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKiwiSdiExecDoc

IMPLEMENT_DYNCREATE(CKiwiSdiExecDoc, CDocument)

BEGIN_MESSAGE_MAP(CKiwiSdiExecDoc, CDocument)
END_MESSAGE_MAP()


// CKiwiSdiExecDoc ����/����

CKiwiSdiExecDoc::CKiwiSdiExecDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CKiwiSdiExecDoc::~CKiwiSdiExecDoc()
{
}

BOOL CKiwiSdiExecDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CKiwiSdiExecDoc ���л�

void CKiwiSdiExecDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CKiwiSdiExecDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CKiwiSdiExecDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CKiwiSdiExecDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CKiwiSdiExecDoc ���

#ifdef _DEBUG
void CKiwiSdiExecDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKiwiSdiExecDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKiwiSdiExecDoc ����
