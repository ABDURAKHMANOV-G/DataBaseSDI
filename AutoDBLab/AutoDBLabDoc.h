
// AutoDBLabDoc.h: интерфейс класса CAutoDBLabDoc 
//


#pragma once

class CMyTreeView;
class CMFCApplication1View;

class CAutoDBLabDoc : public CDocument
{
protected: // создать только из сериализации
	CAutoDBLabDoc() noexcept;
	DECLARE_DYNCREATE(CAutoDBLabDoc)

// Атрибуты
public:
	CMyTreeView* m_pTreeView;
	CMFCApplication1View* m_pView;
	

	bool m_bTable1, m_bTable2, m_bTable3;

	// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CAutoDBLabDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
