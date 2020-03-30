
// MFC_0330View.cpp : CMFC_0330View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC_0330View 构造/析构

CMFC_0330View::CMFC_0330View()
{
	// TODO: 在此处添加构造代码
}

CMFC_0330View::~CMFC_0330View()
{
}

BOOL CMFC_0330View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0330View 绘制

void CMFC_0330View::OnDraw(CDC* pDC)
{
	CMFC_0330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0330View 诊断

#ifdef _DEBUG
void CMFC_0330View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0330View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0330Doc* CMFC_0330View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0330Doc)));
	return (CMFC_0330Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0330View 消息处理程序


void CMFC_0330View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
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
