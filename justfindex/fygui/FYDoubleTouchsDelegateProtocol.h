/************************************************************************/
/* 双击代理协议                                                         */
/************************************************************************/

#pragma once
#include "cocos2d.h"

class FYDoubleTouchsDelegate
{
public:
	FYDoubleTouchsDelegate() {};
	virtual ~FYDoubleTouchsDelegate()
	{
	};

	// 双击事件委托协议
	// @param pTarget 表示被双击的对象
	// @param pTouch 双击位置
	// bool 未使用
	virtual bool fyDidDoubleTouched(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pTarget); return false;};
};

class FYOneTouchedDelegate
{
public:
	FYOneTouchedDelegate() {};
	virtual ~FYOneTouchedDelegate()
	{
	};

	// 单击事件委托协议
	// @param pTarget 表示被单击的对象
	// @param pTouch 单击位置
	// bool 未使用
	virtual bool fyDidOneTouched(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pTarget) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pTarget); return false;};
};
