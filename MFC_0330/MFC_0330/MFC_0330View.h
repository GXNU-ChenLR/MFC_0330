
// MFC_0330View.h : CMFC_0330View 类的接口
//

#pragma once


class CMFC_0330View : public CView
{
protected: // 仅从序列化创建
	CMFC_0330View();
	DECLARE_DYNCREATE(CMFC_0330View)

// 特性
public:
	CMFC_0330Doc* GetDocument() const;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC_0330View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC_0330View.cpp 中的调试版本
inline CMFC_0330Doc* CMFC_0330View::GetDocument() const
   { return reinterpret_cast<CMFC_0330Doc*>(m_pDocument); }
#endif

