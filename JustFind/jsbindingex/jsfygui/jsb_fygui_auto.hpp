#ifndef __fygui_h__
#define __fygui_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_FYPropCell_class;
extern JSObject *jsb_FYPropCell_prototype;

JSBool js_fygui_FYPropCell_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_fygui_FYPropCell_finalize(JSContext *cx, JSObject *obj);
void js_register_fygui_FYPropCell(JSContext *cx, JSObject *global);
void register_all_fygui(JSContext* cx, JSObject* obj);
JSBool js_fygui_FYPropCell_getOrgPosition(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getCellVisibleRect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_onEnter(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_registerScriptDoubleTouchedHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setSelected(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setCellPosition(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setTouchDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setPropId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setOneTouchedDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getTouchDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setDoubleTouchsTimeElapse(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_isHighlighted(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getPropIndex(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getDoubleTouchsTimeElapse(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_registerSavePositionHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getCellPosition(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getTouchedPriority(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_isSelected(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getOrgParent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_cleanup(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getDoubleTouchsDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setShakeRange(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setEnableDragDrop(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setDragCheckTime(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_unregisterScriptOneTouchedHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_registerScriptOneTouchedHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_isEnableDragDrop(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_dragToTopLayer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_dropToLayer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getPropId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setTouchedPriority(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getDragCheckTime(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setDoubleTouchsDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setEnableDoubleTouchs(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_onExit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_isTouchInside(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_isEnableDoubleTouchs(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_unregisterScriptDoubleTouchedHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getOneTouchedDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setPropIndex(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_registerScriptDragDropHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_getShakeRange(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_unregisterScriptDragDropHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_setHighlighted(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_createWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_fygui_FYPropCell_FYPropCell(JSContext *cx, uint32_t argc, jsval *vp);
#endif

