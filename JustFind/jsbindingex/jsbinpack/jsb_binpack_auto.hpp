#ifndef __binpack_h__
#define __binpack_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_DisjointRectCollection_class;
extern JSObject *jsb_DisjointRectCollection_prototype;

JSBool js_binpack_DisjointRectCollection_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_DisjointRectCollection_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_DisjointRectCollection(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_DisjointRectCollection_Disjoint(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_DisjointRectCollection_Add(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_DisjointRectCollection_Clear(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_DisjointRectCollection_Disjoint2(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GuillotineBinPack_class;
extern JSObject *jsb_GuillotineBinPack_prototype;

JSBool js_binpack_GuillotineBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_GuillotineBinPack_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_GuillotineBinPack(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_GuillotineBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_GetUsedRectangles(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_MergeFreeList(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_GetFreeRectangles(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_GuillotineBinPack_GuillotineBinPack(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_MaxRectsBinPack_class;
extern JSObject *jsb_MaxRectsBinPack_prototype;

JSBool js_binpack_MaxRectsBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_MaxRectsBinPack_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_MaxRectsBinPack(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_MaxRectsBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_MaxRectsBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_MaxRectsBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_MaxRectsBinPack_MaxRectsBinPack(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_ShelfBinPack_class;
extern JSObject *jsb_ShelfBinPack_prototype;

JSBool js_binpack_ShelfBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_ShelfBinPack_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_ShelfBinPack(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_ShelfBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_ShelfBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_ShelfBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_ShelfBinPack_ShelfBinPack(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_ShelfNextFitBinPack_class;
extern JSObject *jsb_ShelfNextFitBinPack_prototype;

JSBool js_binpack_ShelfNextFitBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_ShelfNextFitBinPack_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_ShelfNextFitBinPack(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_ShelfNextFitBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_ShelfNextFitBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_ShelfNextFitBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_SkylineBinPack_class;
extern JSObject *jsb_SkylineBinPack_prototype;

JSBool js_binpack_SkylineBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_binpack_SkylineBinPack_finalize(JSContext *cx, JSObject *obj);
void js_register_binpack_SkylineBinPack(JSContext *cx, JSObject *global);
void register_all_binpack(JSContext* cx, JSObject* obj);
JSBool js_binpack_SkylineBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_SkylineBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_SkylineBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_binpack_SkylineBinPack_SkylineBinPack(JSContext *cx, uint32_t argc, jsval *vp);
#endif

