/************************************************************************/
/* 道具基本单元,派生自CCSprite
 * 支持单击、拖拽事件
 * 
 ************************************************************************/

#pragma once
#include "cocos2d.h"
#include "FYDragDropDelegateProtocol.h"
#include "FYDoubleTouchsDelegateProtocol.h"

#define DRAG_BEGIN_MILLISECOND		200
#define DOUBLE_CLICK_MILLISECOND	400
#define ZODER_TOPMOST			2147483647
#define ZODOR_EMPTY_CELL		1
#define ZODOR_EMPTY_PROP		10
class FYPropCell : public cocos2d::CCSprite, 
	public cocos2d::CCTargetedTouchDelegate, 
	public FYDragDropDelegate
{
public:
	FYPropCell(void);
	~FYPropCell(void);

	static FYPropCell* createWithBatchNode(cocos2d::CCSpriteBatchNode *batchNode, const cocos2d::CCRect& rect);

	CREATE_FUNC(FYPropCell);

	virtual void onEnter();
	virtual void onExit();
	
	virtual void cleanup(void);
	/**
    * Returns a boolean value that indicates whether a touch is inside the bounds
    * of the receiver. The given touch must be relative to the world.
    * @param touch A CCTouch object that represents a touch.
    * @return YES whether a touch is inside the receiver’s rect.
    */
    virtual bool isTouchInside(cocos2d::CCTouch * touch);

	virtual void setSelected(bool bSelected);
	virtual bool isSelected();
	/** A Boolean value that determines whether the control is highlighted. */
	virtual void setHighlighted(bool bHighlighted);
	virtual bool isHighlighted();

	virtual void setTouchedPriority(int touchedPriority);
	virtual int getTouchedPriority(){return m_touchedPriority;};

	CC_SYNTHESIZE(int,_propIndex,PropIndex);//道具type和编号的集合

    CC_SYNTHESIZE(int64_t,_propId,PropId);//服务器上的唯一id

    virtual const cocos2d::CCRect& getCellVisibleRect(void); 

    int getCellPosition(){return _cellPos;};
    void setCellPosition(int var);
    
    // 设置保存位置回调函数
    // @param1 参数1为FYPropCell类型对象，本对象
    void registerSavePositionHandler(int nHandler);
	// -------------------拖拽事件-------------------

	// 对层的操作效果
	// dragToTopLayer 将指定的道具元素拖到最顶层，
	// 目的在于跨层拖拽物品时可以完整显示道具	
	void dragToTopLayer(FYPropCell* cell);

	// dropToLayer 将指定的道具元素放到指定的父node里
	// 目的在于将拖拽到toplayer上的道具移到固定的层
	void dropToLayer(FYPropCell* cell,cocos2d::CCNode *pParent);	

	// 获取拖拽前，道具的原始坐标，目的在于不处理时，还原位置
	cocos2d::CCPoint getOrgPosition(){return _orgPosition;};

	// 获取拖拽前，道具的原始父窗口，目的在于不处理时，还原道具
	cocos2d::CCNode *getOrgParent(){return _orgParent;};

	// 是否允许拖拽，默认允许
	bool isEnableDragDrop(){return m_bEnableDragDrop;};
	void setEnableDragDrop(bool bEnable){m_bEnableDragDrop = bEnable;};

	// 设置拖动检测时间范围，当触发moved事件时，若在这个事件范围内没移开_shakeRange距离，则认为产生Drag事件
	// 单位毫秒
	CC_SYNTHESIZE(int,_DragCheckTime,DragCheckTime);

	// 设置抖动范围，当触发moved事件时，若在这个范围内都认为touch没有移动
	CC_SYNTHESIZE(int,_shakeRange,ShakeRange);

	// 设置touch的代理事件，当touch后，不进行拖拽操作时，将该touch事件转发给_pTouchDelegate
	CC_SYNTHESIZE(cocos2d::CCTouchDelegate*,_pTouchDelegate,TouchDelegate);

	// -------------------双击事件-------------------

	// 是否允许双击事件，默认允许
	bool isEnableDoubleTouchs(){return m_bEnableDoubleTouchs;};
	void setEnableDoubleTouchs(bool bEnable){m_bEnableDoubleTouchs = bEnable;};

	// 设置双击事件事件间隔，当触发touchedended事件时，若在这个事件范围内都认为时双击
	// 单位毫秒
	CC_SYNTHESIZE(int,_doubleTouchsTimeElapse,DoubleTouchsTimeElapse);

	// 设置double touch的代理事件，当double touch后，将该double touch事件转发给_pDoubleTouchsDelegate
	CC_SYNTHESIZE(FYDoubleTouchsDelegate*,_pDoubleTouchsDelegate,DoubleTouchsDelegate);

	// -------------------单击事件-------------------
	// 设置one touch的代理事件，当one touch后，将该one touch事件转发给_pOneTouchsDelegate
	CC_SYNTHESIZE(FYOneTouchedDelegate*,_pOneTouchedDelegate,OneTouchedDelegate);

	// 脚本支持
	/** Register script drag drop events handler */
	// nHandler要求：
	// lua 接受该回调事件时，有2个参数
	// @param1 参数1为FYDragDropType类型枚举事件
	// @param2 参数2为FYPropCell类型对象，本对象
	// @param3 参数3为FYPropCell类型对象，被拖动的对象
	// 返回值: boolean ture表示不需要其他对象处理了，false表示自己不处理
	void registerScriptDragDropHandler(int nHandler, int nPriority = 0);
	/** Unregister script drag drop events handler */
	void unregisterScriptDragDropHandler(void);

	/** Register script double touch events handler */
	// nHandler要求：
	// lua 接受该事件时，有1个参数
	// @param FYPropCell类型对象，即被双击的对象
	void registerScriptDoubleTouchedHandler(int nHandler, int nPriority = 0);
	/** Unregister script double touch events handler */
	void unregisterScriptDoubleTouchedHandler(void);

	/** Register script one touched events handler */
	// nHandler要求：
	// lua 接受该回调事件时，有1个参数
	// @param1 参数1为FYPropCell类型对象，被单击的对象
	void registerScriptOneTouchedHandler(int nHandler, int nPriority = 0);
	/** Unregister script drag drop events handler */
	void unregisterScriptOneTouchedHandler(void);
protected:
	// CCTargetedTouchDelegate 代理事件
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) ;
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) ;
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) ;

	// FYDragDropDelegate 代理事件
	virtual bool fyDragDropBegan(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);
	virtual bool fyDragDropMoved(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);
	virtual bool fyDragDropEnded(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);
	virtual bool fyDragDropCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget);
	
	// 脚本支持
	int excuteScriptDragDropHandler(int nEventType, cocos2d::CCNode *pDragTarget);
	int excuteScriptDoubleTouchedHandler();
	int excuteScriptOneTouchedHandler();
	void scheduleOneTouched(float time);
	long millisecondNow()  
	{ 
		struct cocos2d::cc_timeval now; 
		cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL); 
		return (now.tv_sec * 1000 + now.tv_usec / 1000); 
	};

	inline bool isDoubleTouch();

protected:
	bool m_bSelected;
	bool m_bHighlighted;
	bool m_bEnableDragDrop;		// 是否允许拖拽
	bool m_bEnableDoubleTouchs;	// 是否允许双击事件
	int m_touchedPriority;				// 点击事件优先级
	int m_dragDropPriority;				// 拖拽事件优先级
	int m_dragDrapScripHandle;
	int m_doubleTouchedHandle;
	int m_oneTouchedHandle;
    int m_saveCellPositionHandle;
private:
	bool _bDraging;		//是否开始拖拽
	bool _bDragReady;	//是否满足拖拽
	long _touchedTime;	//记录touch时间
    int _cellPos;       //cell位置
	cocos2d::CCPoint _touchedPoint;//记录touchbegan时的点,GL坐标系
	cocos2d::CCPoint _orgPosition;	//记录touchbegan时的位置，本地坐标系
	cocos2d::CCNode *_orgParent;	//记录touchbegan时的原始节点
	cocos2d::CCTouch *_pTouchEnd;	//记录touchEnd后的点
	cocos2d::CCRect _cellRect;	//cell的矩形区域
};

