/************************************************************************/
/* 拖拽代理协议                                                         */
/************************************************************************/

#pragma once
#include "cocos2d.h"

class FYDragDropDelegate
{
public:
	FYDragDropDelegate() {};
	virtual ~FYDragDropDelegate()
	{
	};

	virtual bool fyDragDropBegan(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pDragTarget); return false;};
	virtual bool fyDragDropMoved(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pDragTarget);return false;};
	virtual bool fyDragDropEnded(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pDragTarget);return false;};
	virtual bool fyDragDropCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pDragTarget);return false;};
};
