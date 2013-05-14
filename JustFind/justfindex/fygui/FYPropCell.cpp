#include "FYPropCell.h"
#include "FYDragDropDispatcher.h"
#include "CCLuaEngine.h"
#include "CCScriptSupport.h"

USING_NS_CC;
FYPropCell::FYPropCell(void):
_pTouchDelegate(NULL),
_bDraging(false),
_bDragReady(false),
_shakeRange(10),
_touchedTime(0),
_DragCheckTime(DRAG_BEGIN_MILLISECOND),
_doubleTouchsTimeElapse(DOUBLE_CLICK_MILLISECOND),
m_bEnableDragDrop(true),
m_bEnableDoubleTouchs(true)
{
	_touchedPoint = CCPointZero;
	_orgPosition = CCPointZero;
	_cellRect = CCRectZero;
	m_dragDrapScripHandle = 0;
	m_doubleTouchedHandle = 0;
	m_oneTouchedHandle = 0;
	m_touchedPriority = -1;
	m_dragDropPriority = 0;
    m_saveCellPositionHandle = 0;
	_pTouchEnd = NULL;
	_propId = -1;
    _cellPos = -1;
    _propIndex = -1;
}


FYPropCell::~FYPropCell(void)
{
}

void FYPropCell::onEnter()
{
	CCSprite::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, m_touchedPriority, true);//优先级比普通高一级
	if (m_dragDrapScripHandle!=0)
	{
		FYDragDropDispatcher::sharedInstance()->addDelegate(this,m_dragDropPriority);//添加拖拽处理事件，0普通优先级
	}
}

void FYPropCell::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	FYDragDropDispatcher::sharedInstance()->removeDelegate(this);//删除拖拽处理事件，0普通优先级
	CCSprite::onExit();
}

void FYPropCell::cleanup(void)
{
	unregisterScriptDragDropHandler();
	unregisterScriptDoubleTouchedHandler();
	CCSprite::cleanup();
}

bool FYPropCell::isTouchInside(cocos2d::CCTouch * touch)
{
	CCPoint touchLocation = touch->getLocation(); 
	touchLocation = this->getParent()->convertToNodeSpace(touchLocation);
	CCRect bBox=this->boundingBox();
	return bBox.containsPoint(touchLocation);
}

FYPropCell* FYPropCell::createWithBatchNode(cocos2d::CCSpriteBatchNode *batchNode, const cocos2d::CCRect& rect)
{
	FYPropCell *pobSprite = new FYPropCell();
	if (pobSprite && pobSprite->initWithTexture(batchNode->getTexture(), rect))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}

void FYPropCell::setSelected(bool bSelected)
{
	m_bSelected = bSelected;
}

bool FYPropCell::isSelected()
{
	return m_bSelected;
}

void FYPropCell::setHighlighted(bool bHighlighted)
{
	m_bHighlighted = bHighlighted;
}

bool FYPropCell::isHighlighted()
{
	return m_bHighlighted;
}
CCRect& FYPropCell::getCellVisibleRect(void)
{
	CCSize size = getContentSize();
	CCSize sizeVisible = CCSizeMake(size.width*getScaleX(),size.height*getScaleY());
	float newWidth = sizeVisible.width*cos(getRotationY()) + sizeVisible.height*sin(getRotationX());
	float newHeight = sizeVisible.width*sin(getRotationY()) + sizeVisible.height*cos(getRotationX());
	_cellRect = CCRectMake(getPositionX(),getPositionY(),newWidth,newHeight);
	return _cellRect
}

void FYPropCell::setTouchedPriority(int touchedPriority)
{
	m_touchedPriority = touchedPriority;
	if (m_bIsRunning)
	{
		CCDirector::sharedDirector()->getTouchDispatcher()->setPriority(m_touchedPriority,this);
	}
}

void  FYPropCell::registerScriptDragDropHandler(int nHandler, int nPriority )
{	
	m_dragDropPriority = nPriority;
	m_dragDrapScripHandle = nHandler;
}
/** Unregister script drag drop events handler */
void  FYPropCell::unregisterScriptDragDropHandler(void)
{
	m_dragDrapScripHandle = 0;
}

/** Register script double touch events handler */
void  FYPropCell::registerScriptDoubleTouchedHandler(int nHandler, int nPriority)
{
	CC_UNUSED_PARAM(nPriority);
	m_doubleTouchedHandle = nHandler;
}

/** Unregister script double touch events handler */
void  FYPropCell::unregisterScriptDoubleTouchedHandler(void)
{
	m_doubleTouchedHandle = 0;
}

void FYPropCell::registerScriptOneTouchedHandler(int nHandler, int nPriority)
{
	CC_UNUSED_PARAM(nPriority);
	m_oneTouchedHandle = nHandler;
}

/** Unregister script drag drop events handler */
void FYPropCell::unregisterScriptOneTouchedHandler(void)
{
	m_oneTouchedHandle = 0;
}

int FYPropCell::excuteScriptDragDropHandler(int nEventType, CCNode *pDragTarget)
{
	if (m_dragDrapScripHandle)
	{
		CCLuaEngine * engine = static_cast<CCLuaEngine *>(CCScriptEngineManager::sharedManager()->getScriptEngine());
		engine->pushInt(nEventType);
		engine->pushCCObject(this, "FYPropCell");
		engine->pushCCObject(pDragTarget, "FYPropCell");		
		return engine->executeFunctionByHandler(m_dragDrapScripHandle, 3);
	}
	return 0;
}

int FYPropCell::excuteScriptDoubleTouchedHandler()
{
	if (m_doubleTouchedHandle)
	{
		CCLuaEngine * engine = static_cast<CCLuaEngine *>(CCScriptEngineManager::sharedManager()->getScriptEngine());
		engine->pushCCObject(this, "FYPropCell");
		return engine->executeFunctionByHandler(m_doubleTouchedHandle, 1);
	}	

	return 0;
}

int FYPropCell::excuteScriptOneTouchedHandler()
{
	if (m_oneTouchedHandle)
	{
		CCLuaEngine * engine = static_cast<CCLuaEngine *>(CCScriptEngineManager::sharedManager()->getScriptEngine());
		engine->pushCCObject(this, "FYPropCell");
		return engine->executeFunctionByHandler(m_oneTouchedHandle, 1);
	}	

	return 0;
}

void FYPropCell::scheduleOneTouched(float time)
{
	if (kScriptTypeNone != m_eScriptType)
	{
		excuteScriptOneTouchedHandler();
	}
	else if (_pOneTouchedDelegate)
	{
		_pOneTouchedDelegate->fyDidOneTouched(_pTouchEnd,this);
		CC_SAFE_RELEASE_NULL(_pTouchEnd);
	}	
}

bool FYPropCell::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (this->isVisible() && isTouchInside(pTouch))
	{
		_touchedTime = millisecondNow();
		_touchedPoint = pTouch->getLocation();
		_bDraging = false;
		_orgPosition = getPosition();
		_bDragReady = true;
		//CCPoint point = this->getParent()->convertToNodeSpace(_touchedPoint);//CCDirector::sharedDirector()->convertToGL(_touchedPoint);
		if (_pTouchDelegate)
		{
			 _pTouchDelegate->ccTouchBegan(pTouch,pEvent);
		}
		return true;		
	}

	return false;
}

void FYPropCell::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (isEnableDragDrop())
	{
		//如果开始拖拽
		if (_bDraging)	
		{
			// 转发拖拽事件
			this->fyDragDropMoved(pTouch,this);
		}
		else if (_bDragReady) //开始拖拽判断
		{
			if ((millisecondNow() - _touchedTime) >= _DragCheckTime)	//拖拽时间校验
			{	
				//转发拖拽事件，如果不处理则停止拖拽
				_bDraging = this->fyDragDropBegan(pTouch,this);
				_bDragReady = false;//取消标志位
			}
			else
			{
				//如果移出该区域，则取消拖拽
				if (ccpDistance(_touchedPoint,pTouch->getLocation()) > _shakeRange) 
				{
					_bDragReady = false;
					_bDraging = false;
				}		
			}
		}	
		else	//直接不处理拖拽
		{
			if (_pTouchDelegate)
			{
				_pTouchDelegate->ccTouchMoved(pTouch,pEvent);
			}
		}
	}
	else
	{
		if (_pTouchDelegate)
		{
			_pTouchDelegate->ccTouchMoved(pTouch,pEvent);
		}
	}	
}

void FYPropCell::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (isEnableDragDrop() && _bDraging)
	{
		//如果没处理fyDragDropEnded，则复位
		if(!this->fyDragDropEnded(pTouch,this))
		{
			setPosition(_orgPosition);//复位
		}
		_bDraging = false;
	}
	else
	{
		// 双击事件派发
		if (isEnableDoubleTouchs() && isDoubleTouch())
		{
			CC_SAFE_RELEASE_NULL(_pTouchEnd);
			this->unschedule(schedule_selector(FYPropCell::scheduleOneTouched));
			if (kScriptTypeNone != m_eScriptType)
			{
				excuteScriptDoubleTouchedHandler();
			}
			else if (this->getDoubleTouchsDelegate())
			{
				this->getDoubleTouchsDelegate()->fyDidDoubleTouched(pTouch,this);
			}
		}
		else if (isTouchInside(pTouch))	//单击响应
		{
            CCPoint endPoint = pTouch->getLocation();            
            CC_SAFE_RELEASE_NULL(_pTouchEnd);
			pTouch->retain();
			_pTouchEnd = pTouch;
            
            if (ccpDistance(_touchedPoint,endPoint) > _shakeRange)
            {
                //判断为滚动界面，则不做单击事件处理
                CCLog("判断为滚动界面，则不做单击事件处理,_shakeRange=%d,%f",_shakeRange,ccpDistance(_touchedPoint,endPoint));
            }
            else
            {
                if (isEnableDoubleTouchs())
                {
                    this->scheduleOnce(schedule_selector(FYPropCell::scheduleOneTouched),(_doubleTouchsTimeElapse+10)/1000.0);
                }
                else
                {
                    this->scheduleOnce(schedule_selector(FYPropCell::scheduleOneTouched),0.0);
                }
            } 	
		}
	}
	

	// touchedbegin时已经注册了，所以end时，都必须传递ccTouchEnded事件
	if (_pTouchDelegate)
	{
		_pTouchDelegate->ccTouchEnded(pTouch,pEvent);
	}	
}

void FYPropCell::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (isEnableDragDrop()&&_bDraging)
	{
		//如果没处理fyDragDropCancelled，则复位
		if(!this->fyDragDropCancelled(pTouch,this))
		{
			setPosition(_orgPosition);//复位
		}
		_bDraging = false;
	}

	// touchedbegin时已经注册了，所以end时，都必须传递ccTouchCancelled事件
	if (_pTouchDelegate)
	{
		_pTouchDelegate->ccTouchCancelled(pTouch,pEvent);
	}
}

void FYPropCell::dragToTopLayer(FYPropCell* cell)
{
	if (cell->isEnableDragDrop())
	{
		cell->_orgParent = cell->getParent();
		cell->retain();
		cell->removeFromParentAndCleanup(false);
		setPosition(cell->_touchedPoint);
		CCDirector::sharedDirector()->getRunningScene()->addChild(cell,ZODER_TOPMOST);
		cell->release();
	}	
}

void FYPropCell::dropToLayer(FYPropCell* cell,cocos2d::CCNode *pParent)
{
	if (cell->isEnableDragDrop())
	{
		cell->retain();
		cell->removeFromParentAndCleanup(false);
		pParent->addChild(cell,ZODER_TOPMOST-100);
		cell->release();
	}
}

bool FYPropCell::fyDragDropBegan(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{	
	dragToTopLayer(this);
	if (kScriptTypeNone != m_eScriptType)
	{
		excuteScriptDragDropHandler(FYDRAGDROPBEGAN,pDragTarget);
	}	
	return true;
}

bool FYPropCell::fyDragDropMoved(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	CCPoint point = pTouch->getLocationInView();
	point = CCDirector::sharedDirector()->convertToGL(point);
	setPosition(point);
	//setPosition(this->getParent()->convertTouchToNodeSpace(pTouch));
	if (kScriptTypeNone != m_eScriptType)
	{
		excuteScriptDragDropHandler(FYDRAGDROPMOVED,pDragTarget);
	}
	return true;
}

bool FYPropCell::fyDragDropEnded(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	bool bRet = false;
	if (pDragTarget == this) //当前的cell触发fyDragDropEnded条件，则遍历FYDragDropDispatcher，查看是否有关注该消息
	{
		bRet = FYDragDropDispatcher::sharedInstance()->dispatchDragDropEnded(pTouch,pDragTarget);
	}
	else if (this->isVisible() && isTouchInside(pTouch) )
	{
		if (kScriptTypeNone != m_eScriptType)
		{
			// 拖到其他目标上，优先在其他目标上进行进行脚本处理,
			// 若处理了，返回ture，否则返回false
			return excuteScriptDragDropHandler(FYDRAGDROPENDED,pDragTarget)==0?false:true;
		}

		// 其他目标拖动本目标上
		FYPropCell* prop = dynamic_cast<FYPropCell*>(pDragTarget);
		if (prop)	//交换
		{
			//相同的父窗口，则对调位置
			if (prop->getOrgParent() == this->getParent())
			{
				dropToLayer(prop,prop->getOrgParent());				
			}
			else	//不同的父窗口也对调位置
			{
				CCNode* parent = this->getParent();
				dropToLayer(this,prop->getOrgParent());		
				dropToLayer(prop,parent);	
			}

			CCPoint point = prop->getOrgPosition();
			prop->setPosition(this->getPosition());
			this->setPosition(point);			
			return true;//已处理
		}
		return false;//不敢兴趣
	}
	else
	{
		return false;//不满足条件
	}

	if (!bRet) //都不敢兴趣
	{
 		dropToLayer(this,this->getOrgParent());
		// 全部都不需要该消息，则不运行拖拽脚本
		// 后续再添加
// 		if (kScriptTypeNone != m_eScriptType)
// 		{
// 			excuteScriptDragDropHandler(FYDRAGDROPENDED,this);
// 		}
	}
	return bRet;
}

bool FYPropCell::fyDragDropCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCNode *pDragTarget)
{
	return false;
}

inline bool FYPropCell::isDoubleTouch()
{
	static long lastTouchTime=0;
	long thisTouchTime=millisecondNow();
	if(abs(thisTouchTime-lastTouchTime)<_doubleTouchsTimeElapse)
	{
		lastTouchTime=0;
		return true;
	}
	else
	{
		lastTouchTime=millisecondNow();
		return false;
	}
};

void FYPropCell::registerSavePositionHandler(int nHandler)
{
    m_saveCellPositionHandle = nHandler;
}

void FYPropCell::setCellPosition(int var)
{
    _cellPos = var;
    if (m_saveCellPositionHandle != 0)
    {
        CCLuaEngine * engine = static_cast<CCLuaEngine *>(CCScriptEngineManager::sharedManager()->getScriptEngine());
		engine->pushCCObject(this, "FYPropCell");
		engine->executeFunctionByHandler(m_saveCellPositionHandle, 1);
    }
}