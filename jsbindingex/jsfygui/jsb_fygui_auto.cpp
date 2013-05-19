#include "jsb_fygui_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "FYGUI.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *jsb_FYPropCell_class;
JSObject *jsb_FYPropCell_prototype;

JSBool js_fygui_FYPropCell_getOrgPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		CCPoint ret = cobj->getOrgPosition();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getCellVisibleRect(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCRect ret = cobj->getCellVisibleRect();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR const CCRect;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_onEnter(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->onEnter();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setSelected(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setCellPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setCellPosition(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setTouchDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		CCTouchDelegate* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouchDelegate*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTouchDelegate(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setPropId(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		long long arg0;
		ok &= jsval_to_long_long(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setPropId(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_fyDragDropCancelled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		CCTouch* arg0;
		CCNode* arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouch*;
		#pragma warning NO CONVERSION TO NATIVE FOR CCNode*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->fyDragDropCancelled(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setOneTouchedDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		FYOneTouchedDelegate* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (FYOneTouchedDelegate*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setOneTouchedDelegate(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getTouchDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		CCTouchDelegate* ret = cobj->getTouchDelegate();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR CCTouchDelegate*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setDoubleTouchsTimeElapse(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDoubleTouchsTimeElapse(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_isHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isHighlighted();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getPropIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getPropIndex();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getDoubleTouchsTimeElapse(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getDoubleTouchsTimeElapse();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_fyDragDropMoved(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		CCTouch* arg0;
		CCNode* arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouch*;
		#pragma warning NO CONVERSION TO NATIVE FOR CCNode*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->fyDragDropMoved(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getCellPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCellPosition();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getTouchedPriority(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getTouchedPriority();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_isSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isSelected();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getOrgParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		CCNode* ret = cobj->getOrgParent();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR CCNode*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_cleanup(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->cleanup();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_fyDragDropEnded(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		CCTouch* arg0;
		CCNode* arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouch*;
		#pragma warning NO CONVERSION TO NATIVE FOR CCNode*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->fyDragDropEnded(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getDoubleTouchsDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		FYDoubleTouchsDelegate* ret = cobj->getDoubleTouchsDelegate();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<FYDoubleTouchsDelegate>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setShakeRange(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setShakeRange(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setEnableDragDrop(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setEnableDragDrop(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setDragCheckTime(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDragCheckTime(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_fyDragDropBegan(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		CCTouch* arg0;
		CCNode* arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouch*;
		#pragma warning NO CONVERSION TO NATIVE FOR CCNode*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->fyDragDropBegan(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_isEnableDragDrop(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isEnableDragDrop();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_dragToTopLayer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		FYPropCell* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (FYPropCell*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->dragToTopLayer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_dropToLayer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		FYPropCell* arg0;
		CCNode* arg1;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (FYPropCell*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		#pragma warning NO CONVERSION TO NATIVE FOR CCNode*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->dropToLayer(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getPropId(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		long long ret = cobj->getPropId();
		jsval jsret;
		jsret = long_long_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setTouchedPriority(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTouchedPriority(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getDragCheckTime(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getDragCheckTime();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setDoubleTouchsDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		FYDoubleTouchsDelegate* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (FYDoubleTouchsDelegate*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDoubleTouchsDelegate(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setEnableDoubleTouchs(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setEnableDoubleTouchs(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_onExit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->onExit();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_isTouchInside(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		CCTouch* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCTouch*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->isTouchInside(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_isEnableDoubleTouchs(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isEnableDoubleTouchs();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getOneTouchedDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		FYOneTouchedDelegate* ret = cobj->getOneTouchedDelegate();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<FYOneTouchedDelegate>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setPropIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setPropIndex(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_getShakeRange(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getShakeRange();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_setHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	FYPropCell* cobj = (FYPropCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setHighlighted(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_fygui_FYPropCell_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		FYPropCell* ret = FYPropCell::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<FYPropCell>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_fygui_FYPropCell_createWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		CCSpriteBatchNode* arg0;
		cocos2d::CCRect arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR CCSpriteBatchNode*;
		#pragma warning NO CONVERSION TO NATIVE FOR const CCRect;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		FYPropCell* ret = FYPropCell::createWithBatchNode(arg0, arg1);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<FYPropCell>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_fygui_FYPropCell_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		FYPropCell* cobj = new FYPropCell();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<FYPropCell> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "FYPropCell");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



extern JSObject *jsb_CCSprite_prototype;

void js_fygui_FYPropCell_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (FYPropCell)", obj);
}

static JSBool js_fygui_FYPropCell_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    FYPropCell *nobj = new FYPropCell();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "FYPropCell");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_fygui_FYPropCell(JSContext *cx, JSObject *global) {
	jsb_FYPropCell_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_FYPropCell_class->name = "FYPropCell";
	jsb_FYPropCell_class->addProperty = JS_PropertyStub;
	jsb_FYPropCell_class->delProperty = JS_PropertyStub;
	jsb_FYPropCell_class->getProperty = JS_PropertyStub;
	jsb_FYPropCell_class->setProperty = JS_StrictPropertyStub;
	jsb_FYPropCell_class->enumerate = JS_EnumerateStub;
	jsb_FYPropCell_class->resolve = JS_ResolveStub;
	jsb_FYPropCell_class->convert = JS_ConvertStub;
	jsb_FYPropCell_class->finalize = js_fygui_FYPropCell_finalize;
	jsb_FYPropCell_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getOrgPosition", js_fygui_FYPropCell_getOrgPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCellVisibleRect", js_fygui_FYPropCell_getCellVisibleRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("onEnter", js_fygui_FYPropCell_onEnter, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSelected", js_fygui_FYPropCell_setSelected, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCellPosition", js_fygui_FYPropCell_setCellPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchDelegate", js_fygui_FYPropCell_setTouchDelegate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPropId", js_fygui_FYPropCell_setPropId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("fyDragDropCancelled", js_fygui_FYPropCell_fyDragDropCancelled, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOneTouchedDelegate", js_fygui_FYPropCell_setOneTouchedDelegate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchDelegate", js_fygui_FYPropCell_getTouchDelegate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDoubleTouchsTimeElapse", js_fygui_FYPropCell_setDoubleTouchsTimeElapse, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isHighlighted", js_fygui_FYPropCell_isHighlighted, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPropIndex", js_fygui_FYPropCell_getPropIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDoubleTouchsTimeElapse", js_fygui_FYPropCell_getDoubleTouchsTimeElapse, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("fyDragDropMoved", js_fygui_FYPropCell_fyDragDropMoved, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCellPosition", js_fygui_FYPropCell_getCellPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchedPriority", js_fygui_FYPropCell_getTouchedPriority, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isSelected", js_fygui_FYPropCell_isSelected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getOrgParent", js_fygui_FYPropCell_getOrgParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("cleanup", js_fygui_FYPropCell_cleanup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("fyDragDropEnded", js_fygui_FYPropCell_fyDragDropEnded, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDoubleTouchsDelegate", js_fygui_FYPropCell_getDoubleTouchsDelegate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setShakeRange", js_fygui_FYPropCell_setShakeRange, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnableDragDrop", js_fygui_FYPropCell_setEnableDragDrop, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDragCheckTime", js_fygui_FYPropCell_setDragCheckTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("fyDragDropBegan", js_fygui_FYPropCell_fyDragDropBegan, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isEnableDragDrop", js_fygui_FYPropCell_isEnableDragDrop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("dragToTopLayer", js_fygui_FYPropCell_dragToTopLayer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("dropToLayer", js_fygui_FYPropCell_dropToLayer, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPropId", js_fygui_FYPropCell_getPropId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchedPriority", js_fygui_FYPropCell_setTouchedPriority, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDragCheckTime", js_fygui_FYPropCell_getDragCheckTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDoubleTouchsDelegate", js_fygui_FYPropCell_setDoubleTouchsDelegate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnableDoubleTouchs", js_fygui_FYPropCell_setEnableDoubleTouchs, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("onExit", js_fygui_FYPropCell_onExit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchInside", js_fygui_FYPropCell_isTouchInside, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isEnableDoubleTouchs", js_fygui_FYPropCell_isEnableDoubleTouchs, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getOneTouchedDelegate", js_fygui_FYPropCell_getOneTouchedDelegate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPropIndex", js_fygui_FYPropCell_setPropIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getShakeRange", js_fygui_FYPropCell_getShakeRange, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHighlighted", js_fygui_FYPropCell_setHighlighted, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_fygui_FYPropCell_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_fygui_FYPropCell_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createWithBatchNode", js_fygui_FYPropCell_createWithBatchNode, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_FYPropCell_prototype = JS_InitClass(
		cx, global,
		jsb_CCSprite_prototype,
		jsb_FYPropCell_class,
		js_fygui_FYPropCell_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "FYPropCell", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<FYPropCell> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_FYPropCell_class;
		p->proto = jsb_FYPropCell_prototype;
		p->parentProto = jsb_CCSprite_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_fygui(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "fygui", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "fygui", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_fygui_FYPropCell(cx, obj);
}

