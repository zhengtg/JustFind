#pragma once
#include "FYDragDropDelegateProtocol.h"
#include "cocos2d.h"

class FYDragDropHandler : public cocos2d::CCObject
{
public:
	FYDragDropHandler(void);
	virtual ~FYDragDropHandler(void);

	/** delegate */
	FYDragDropDelegate* getDelegate();
	void setDelegate(FYDragDropDelegate *pDelegate);

	/** priority */
	int getPriority(void);
	void setPriority(int nPriority);

	/** enabled selectors */
	int getEnabledSelectors(void);
	void setEnalbedSelectors(int nValue);

	/** initializes a FYDragDropHandler with a delegate and a priority */
	virtual bool initWithDelegate(FYDragDropDelegate *pDelegate, int nPriority);

public:
	/** allocates a FYDragDropHandler with a delegate and a priority */
	static FYDragDropHandler* handlerWithDelegate(FYDragDropDelegate *pDelegate, int nPriority);

protected:
	FYDragDropDelegate *m_pDelegate;
	int m_nPriority;
	int m_nEnabledSelectors;
};

