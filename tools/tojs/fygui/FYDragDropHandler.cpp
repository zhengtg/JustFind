#include "FYDragDropHandler.h"

USING_NS_CC;
FYDragDropHandler::FYDragDropHandler(void)
{
}


FYDragDropHandler::~FYDragDropHandler(void)
{
	if (m_pDelegate)
	{
		dynamic_cast<CCObject*>(m_pDelegate)->release();
	}   
}

FYDragDropDelegate* FYDragDropHandler::getDelegate(void)
{
	return m_pDelegate;
}

void FYDragDropHandler::setDelegate(FYDragDropDelegate *pDelegate)
{
	if (pDelegate)
	{
		dynamic_cast<CCObject*>(pDelegate)->retain();
	}

	if (m_pDelegate)
	{
		dynamic_cast<CCObject*>(m_pDelegate)->release();
	}

	m_pDelegate = pDelegate;
}

int FYDragDropHandler::getPriority(void)
{
	return m_nPriority;
}

void FYDragDropHandler::setPriority(int nPriority)
{
	m_nPriority = nPriority;
}

int FYDragDropHandler::getEnabledSelectors(void)
{
	return m_nEnabledSelectors;
}

void FYDragDropHandler::setEnalbedSelectors(int nValue)
{
	m_nEnabledSelectors = nValue;
}

FYDragDropHandler* FYDragDropHandler::handlerWithDelegate(FYDragDropDelegate *pDelegate, int nPriority)
{
	FYDragDropHandler *pHandler = new FYDragDropHandler();

	if (pHandler)
	{
		if (pHandler->initWithDelegate(pDelegate, nPriority))
		{
			pHandler->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(pHandler);
		}
	}

	return pHandler;
}

bool FYDragDropHandler::initWithDelegate(FYDragDropDelegate *pDelegate, int nPriority)
{
	CCAssert(pDelegate != NULL, "touch delegate should not be null");

	m_pDelegate = pDelegate; 

	dynamic_cast<CCObject*>(pDelegate)->retain();

	m_nPriority = nPriority;
	m_nEnabledSelectors = 0;

	return true;
}
