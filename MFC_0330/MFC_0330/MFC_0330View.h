
// MFC_0330View.h : CMFC_0330View ��Ľӿ�
//

#pragma once


class CMFC_0330View : public CView
{
protected: // �������л�����
	CMFC_0330View();
	DECLARE_DYNCREATE(CMFC_0330View)

// ����
public:
	CMFC_0330Doc* GetDocument() const;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC_0330View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC_0330View.cpp �еĵ��԰汾
inline CMFC_0330Doc* CMFC_0330View::GetDocument() const
   { return reinterpret_cast<CMFC_0330Doc*>(m_pDocument); }
#endif

