#include "FYDragDropDispatcher.h"
#include "support/data_support/ccCArray.h"
#include "FYDragDropHandler.h"
#include <algorithm>
USING_NS_CC;

FYDragDropDispatcher* s_fyDragDropDispatcher = NULL;
/**
 * Used for sort
 */
static int less(const CCObject* p1, const CCObject* p2)
{
    return ((FYDragDropHandler*)p1)->getPriority() < ((FYDragDropHandler*)p2)->getPriority();
}

FYDragDropDispatcher::FYDragDropDispatcher(void)
{
	m_bDispatchEvents = true;
	m_pHandlers = CCArray::createWithCapacity(8);
	m_pHandlers->retain();
	m_pHandlersToAdd = CCArray::createWithCapacity(8);
	m_pHandlersToAdd->retain();
	m_pHandlersToRemove = ccCArrayNew(8);

	m_bToRemove = false;
	m_bToAdd = false;
	m_bToQuit = false;
	m_bLocked = false;
}


FYDragDropDispatcher::~FYDragDropDispatcher(void)
{
	CC_SAFE_RELEASE(m_pHandlers);
	CC_SAFE_RELEASE(m_pHandlersToAdd);

	ccCArrayFree(m_pHandlersToRemove);
	m_pHandlersToRemove = NULL;   
}

FYDragDropDispatcher* FYDragDropDispatcher::sharedInstance()
{
	if (s_fyDragDropDispatcher == NULL)
	{
		do 
		{
			s_fyDragDropDispatcher = new FYDragDropDispatcher();
			CC_BREAK_IF(!s_fyDragDropDispatcher);
		} while (0);
	}
	return s_fyDragDropDispatcher;
}

bool FYDragDropDispatcher::isDispatchEvents(void)
{
	return m_bDispatchEvents;
}

void FYDragDropDispatcher::setDispatchEvents(bool bDispatchEvents)
{
	m_bDispatchEvents = bDispatchEvents;
}


//
// handlers management
//
void FYDragDropDispatcher::forceAddHandler(FYDragDropHandler *pHandler, CCArray *pArray)
{
    unsigned int u = 0;

    CCObject* pObj = NULL;
    CCARRAY_FOREACH(pArray, pObj)
    {
         FYDragDropHandler *h = (FYDragDropHandler *)pObj;
         if (h)
         {
             if (h->getPriority() < pHandler->getPriority())
             {
                 ++u;
             }
 
             if (h->getDelegate() == pHandler->getDelegate())
             {
                 CCAssert(0, "");
                 return;
             }
         }
     }

    pArray->insertObject(pHandler, u);
}

void FYDragDropDispatcher::addDelegate(FYDragDropDelegate *pDelegate, int nPriority)
{    
    FYDragDropHandler *pHandler = FYDragDropHandler::handlerWithDelegate(pDelegate, nPriority);
    if (! m_bLocked)
    {
        forceAddHandler(pHandler, m_pHandlers);
    }
    else
    {
        /* If pHandler is contained in m_pHandlersToRemove, if so remove it from m_pHandlersToRemove and return.
         * Refer issue #752(cocos2d-x)
         */
        if (ccCArrayContainsValue(m_pHandlersToRemove, pDelegate))
        {
            ccCArrayRemoveValue(m_pHandlersToRemove, pDelegate);
            return;
        }

        m_pHandlersToAdd->addObject(pHandler);
        m_bToAdd = true;
    }
}

void FYDragDropDispatcher::forceRemoveDelegate(FYDragDropDelegate *pDelegate)
{
    FYDragDropHandler *pHandler;
  
    // remove handler from m_pHandlers
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(m_pHandlers, pObj)
    {
        pHandler = (FYDragDropHandler*)pObj;
        if (pHandler && pHandler->getDelegate() == pDelegate)
        {
            m_pHandlers->removeObject(pHandler);
            break;
        }
    }  
}

void FYDragDropDispatcher::removeDelegate(FYDragDropDelegate *pDelegate)
{
    if (pDelegate == NULL)
    {
        return;
    }

    if (! m_bLocked)
    {
        forceRemoveDelegate(pDelegate);
    }
    else
    {
        FYDragDropHandler *pHandler = findHandler(m_pHandlersToAdd, pDelegate);
        if (pHandler)
        {
            m_pHandlersToAdd->removeObject(pHandler);
            return;
        }

        ccCArrayAppendValue(m_pHandlersToRemove, pDelegate);
        m_bToRemove = true;
    }
}

void FYDragDropDispatcher::forceRemoveAllDelegates(void)
{
     m_pHandlers->removeAllObjects();
}

void FYDragDropDispatcher::removeAllDelegates(void)
{
    if (! m_bLocked)
    {
        forceRemoveAllDelegates();
    }
    else
    {
        m_bToQuit = true;
    }
}

FYDragDropHandler* FYDragDropDispatcher::findHandler(FYDragDropDelegate *pDelegate)
{
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(m_pHandlers, pObj)
    {
        FYDragDropHandler* pHandler = (FYDragDropHandler*)pObj;
        if (pHandler->getDelegate() == pDelegate)
        {
            return pHandler;
        }
    }
    return NULL;
}

FYDragDropHandler* FYDragDropDispatcher::findHandler(CCArray* pArray, FYDragDropDelegate *pDelegate)
{
    CCAssert(pArray != NULL && pDelegate != NULL, "");

    CCObject* pObj = NULL;
    CCARRAY_FOREACH(pArray, pObj)
    {
        FYDragDropHandler* pHandle = (FYDragDropHandler*)pObj;
        if (pHandle->getDelegate() == pDelegate)
        {
            return pHandle;
        }
    }

    return NULL;
}

void FYDragDropDispatcher::rearrangeHandlers(CCArray *pArray)
{
    std::sort(pArray->data->arr, pArray->data->arr + pArray->data->num, less);
}

void FYDragDropDispatcher::setPriority(int nPriority, FYDragDropDelegate *pDelegate)
{
    CCAssert(pDelegate != NULL, "");

    FYDragDropHandler *handler = NULL;

    handler = this->findHandler(pDelegate);

    CCAssert(handler != NULL, "");	
    if (handler->getPriority() != nPriority)
    {
        handler->setPriority(nPriority);
        this->rearrangeHandlers(m_pHandlers);
    }
}

bool FYDragDropDispatcher::dispatchDragDrop(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget,FYDragDropType type)
{
	m_bLocked = true;

	bool bResult = false;
	unsigned int uHandlersCount = m_pHandlers->count();
	if (uHandlersCount > 0)
	{
		FYDragDropHandler *pHandler = NULL;
		CCObject* pObj = NULL;		
		CCARRAY_FOREACH(m_pHandlers, pObj)
		{
			pHandler = (FYDragDropHandler *)(pObj);

           /* 
           相同的target不处理
		   */
			if (! pHandler ||pHandler == findHandler(dynamic_cast<FYDragDropDelegate*>(pDragTarget)))
			{
				continue;
			}		
			switch(type)
			{
			case FYDRAGDROPBEGAN:
				bResult = pHandler->getDelegate()->fyDragDropBegan(pTouch, pDragTarget);
				break;
			case FYDRAGDROPMOVED:
				bResult = pHandler->getDelegate()->fyDragDropMoved(pTouch, pDragTarget);
				break;
			case FYDRAGDROPENDED:
				bResult = pHandler->getDelegate()->fyDragDropEnded(pTouch, pDragTarget);
				break;
			case FYDRAGDROPCANCELLED:
				bResult = pHandler->getDelegate()->fyDragDropCancelled(pTouch, pDragTarget);
				break;
			default:
				break;
			}
			if (bResult)
			{
				break;
			}
			
		}
	}

	m_bLocked = false;
	if (m_bToRemove)
	{
		m_bToRemove = false;
		for (unsigned int i = 0; i < m_pHandlersToRemove->num; ++i)
		{
			forceRemoveDelegate((FYDragDropDelegate*)m_pHandlersToRemove->arr[i]);
		}
		ccCArrayRemoveAllValues(m_pHandlersToRemove);
	}

	if (m_bToAdd)
	{
		m_bToAdd = false;
		FYDragDropHandler* pHandler = NULL;
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(m_pHandlersToAdd, pObj)
		{
			pHandler = (FYDragDropHandler*)pObj;
			if (! pHandler)
			{
				break;
			}
			forceAddHandler(pHandler, m_pHandlers);			
		}

		m_pHandlersToAdd->removeAllObjects();    
	}

	if (m_bToQuit)
	{
		m_bToQuit = false;
		forceRemoveAllDelegates();
	}

	return bResult;
}

bool FYDragDropDispatcher::dispatchDragDropBegan(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	return dispatchDragDrop(pTouch,pDragTarget,FYDRAGDROPBEGAN);
}

bool FYDragDropDispatcher::dispatchDragDropMoved(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	return dispatchDragDrop(pTouch,pDragTarget,FYDRAGDROPMOVED);
}

bool FYDragDropDispatcher::dispatchDragDropEnded(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	return dispatchDragDrop(pTouch,pDragTarget,FYDRAGDROPENDED);
}

bool FYDragDropDispatcher::dispatchDragDropCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	return dispatchDragDrop(pTouch,pDragTarget,FYDRAGDROPCANCELLED);
}