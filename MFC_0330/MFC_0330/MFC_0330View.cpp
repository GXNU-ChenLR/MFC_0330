
// MFC_0330View.cpp : CMFC_0330View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_0330.h"
#endif

#include "MFC_0330Doc.h"
#include "MFC_0330View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0330View

IMPLEMENT_DYNCREATE(CMFC_0330View, CView)

BEGIN_MESSAGE_MAP(CMFC_0330View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC_0330View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC_0330View ����/����

CMFC_0330View::CMFC_0330View()
{
	// TODO: �ڴ˴���ӹ������
}

CMFC_0330View::~CMFC_0330View()
{
}

BOOL CMFC_0330View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0330View ����

void CMFC_0330View::OnDraw(CDC* pDC)
{
	CMFC_0330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0330View ���

#ifdef _DEBUG
void CMFC_0330View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0330View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0330Doc* CMFC_0330View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0330Doc)));
	return (CMFC_0330Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0330View ��Ϣ�������


void CMFC_0330View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CMFC_0330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString file = cfd.GetPathName();
		CImage img;
		img.Load(file);
		img.Draw(this->GetDC()->m_hDC,0, 0, img.GetWidth(), img.GetHeight());
		dc.TextOutW(100, 100, file);
	}
}
