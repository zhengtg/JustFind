#pragma once
#include "FYDragDropDelegateProtocol.h"
#include "cocos2d.h"

class FYDragDropHandler;
struct cocos2d::_ccCArray;

enum FYDragDropType{
	FYDRAGDROPBEGAN,
	FYDRAGDROPMOVED,
	FYDRAGDROPENDED,
	FYDRAGDROPCANCELLED
};

class FYDragDropDispatcher : public cocos2d::CCObject
{
public:
	FYDragDropDispatcher(void);
	~FYDragDropDispatcher(void);

	 /** Whether or not the events are going to be dispatched. Default: true */
    bool isDispatchEvents(void);
    void setDispatchEvents(bool bDispatchEvents);

    /** Adds a drag drop delegate to the dispatcher's list.
     IMPORTANT: The delegate will be retained.
     */
    void addDelegate(FYDragDropDelegate *pDelegate, int nPriority);

    /** Removes a drag drop delegate.
     The delegate will be released
     */
    void removeDelegate(FYDragDropDelegate *pDelegate);

    /** Removes all drag drop delegates, releasing all the delegates */
    void removeAllDelegates(void);

    /** Changes the priority of a previously added delegate. The lower the number,
    the higher the priority */
    void setPriority(int nPriority, FYDragDropDelegate *pDelegate);

	//分发dragdrop事件	
    virtual bool dispatchDragDropBegan(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget); //暂时未使用
	virtual bool dispatchDragDropMoved(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget); //暂时未使用
	virtual bool dispatchDragDropEnded(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);
	virtual bool dispatchDragDropCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);

	static FYDragDropDispatcher* sharedInstance();
public:
	FYDragDropHandler* findHandler(FYDragDropDelegate *pDelegate);	//查找处理事件
protected:
	void forceRemoveDelegate(FYDragDropDelegate *pDelegate);
	void forceAddHandler(FYDragDropHandler *pHandler, cocos2d::CCArray* pArray);
	void forceRemoveAllDelegates(void);
	void rearrangeHandlers(cocos2d::CCArray* pArray);
	FYDragDropHandler* findHandler(cocos2d::CCArray* pArray, FYDragDropDelegate *pDelegate);

	bool dispatchDragDrop(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget,FYDragDropType type);
private:
	cocos2d::CCArray* m_pHandlers;

	bool m_bLocked;
	bool m_bToAdd;
	bool m_bToRemove;
	cocos2d::CCArray* m_pHandlersToAdd;
	struct cocos2d::_ccCArray *m_pHandlersToRemove;
	bool m_bToQuit;
	bool m_bDispatchEvents;

};

