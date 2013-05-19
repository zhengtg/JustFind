#include "jsb_binpack_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "binpack.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *jsb_DisjointRectCollection_class;
JSObject *jsb_DisjointRectCollection_prototype;

JSBool js_binpack_DisjointRectCollection_Disjoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	DisjointRectCollection* cobj = (DisjointRectCollection *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		Rect arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (Rect)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->Disjoint(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_binpack_DisjointRectCollection_Add(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	DisjointRectCollection* cobj = (DisjointRectCollection *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		Rect arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (Rect)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->Add(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_binpack_DisjointRectCollection_Clear(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	DisjointRectCollection* cobj = (DisjointRectCollection *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->Clear();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_DisjointRectCollection_Disjoint2(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		Rect arg0;
		Rect arg1;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (Rect)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg1 = (Rect)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = DisjointRectCollection::Disjoint2(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_binpack_DisjointRectCollection_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (DisjointRectCollection)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        DisjointRectCollection *nobj = static_cast<DisjointRectCollection *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_DisjointRectCollection_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    DisjointRectCollection *nobj = new DisjointRectCollection();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_DisjointRectCollection(JSContext *cx, JSObject *global) {
	jsb_DisjointRectCollection_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_DisjointRectCollection_class->name = "DisjointRectCollection";
	jsb_DisjointRectCollection_class->addProperty = JS_PropertyStub;
	jsb_DisjointRectCollection_class->delProperty = JS_PropertyStub;
	jsb_DisjointRectCollection_class->getProperty = JS_PropertyStub;
	jsb_DisjointRectCollection_class->setProperty = JS_StrictPropertyStub;
	jsb_DisjointRectCollection_class->enumerate = JS_EnumerateStub;
	jsb_DisjointRectCollection_class->resolve = JS_ResolveStub;
	jsb_DisjointRectCollection_class->convert = JS_ConvertStub;
	jsb_DisjointRectCollection_class->finalize = js_binpack_DisjointRectCollection_finalize;
	jsb_DisjointRectCollection_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Disjoint", js_binpack_DisjointRectCollection_Disjoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Add", js_binpack_DisjointRectCollection_Add, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Clear", js_binpack_DisjointRectCollection_Clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_DisjointRectCollection_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("Disjoint2", js_binpack_DisjointRectCollection_Disjoint2, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_DisjointRectCollection_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_DisjointRectCollection_class,
		dummy_constructor<DisjointRectCollection>, 0, // no constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "DisjointRectCollection", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<DisjointRectCollection> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_DisjointRectCollection_class;
		p->proto = jsb_DisjointRectCollection_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_GuillotineBinPack_class;
JSObject *jsb_GuillotineBinPack_prototype;

JSBool js_binpack_GuillotineBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	GuillotineBinPack* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	do {
		if (argc == 4) {
			std::vector<RectSize, std::allocator<RectSize> > arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR vector;
			if (!ok) { ok = JS_TRUE; break; }
			JSBool arg1;
			ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			GuillotineBinPack::FreeRectChoiceHeuristic arg2;
			ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
			if (!ok) { ok = JS_TRUE; break; }
			GuillotineBinPack::GuillotineSplitHeuristic arg3;
			ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->Insert(arg0, arg1, arg2, arg3);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 5) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			JSBool arg2;
			ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			GuillotineBinPack::FreeRectChoiceHeuristic arg3;
			ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
			if (!ok) { ok = JS_TRUE; break; }
			GuillotineBinPack::GuillotineSplitHeuristic arg4;
			ok &= jsval_to_int32(cx, argv[4], (int32_t *)&arg4);
			if (!ok) { ok = JS_TRUE; break; }
			Rect ret = cobj->Insert(arg0, arg1, arg2, arg3, arg4);
			jsval jsret; do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Rect>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_GetUsedRectangles(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	GuillotineBinPack* cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		std::vector<Rect, std::allocator<Rect> > ret = cobj->GetUsedRectangles();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR vector;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_MergeFreeList(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	GuillotineBinPack* cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->MergeFreeList();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	GuillotineBinPack* cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->Occupancy();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_GetFreeRectangles(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	GuillotineBinPack* cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		std::vector<Rect, std::allocator<Rect> > ret = cobj->GetFreeRectangles();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR vector;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	GuillotineBinPack* cobj = (GuillotineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->Init(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_binpack_GuillotineBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	GuillotineBinPack* cobj = NULL;
	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new GuillotineBinPack(arg0, arg1);
			TypeTest<GuillotineBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new GuillotineBinPack();
			TypeTest<GuillotineBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_binpack_GuillotineBinPack_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GuillotineBinPack)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        GuillotineBinPack *nobj = static_cast<GuillotineBinPack *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_GuillotineBinPack_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    GuillotineBinPack *nobj = new GuillotineBinPack();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_GuillotineBinPack(JSContext *cx, JSObject *global) {
	jsb_GuillotineBinPack_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_GuillotineBinPack_class->name = "GuillotineBinPack";
	jsb_GuillotineBinPack_class->addProperty = JS_PropertyStub;
	jsb_GuillotineBinPack_class->delProperty = JS_PropertyStub;
	jsb_GuillotineBinPack_class->getProperty = JS_PropertyStub;
	jsb_GuillotineBinPack_class->setProperty = JS_StrictPropertyStub;
	jsb_GuillotineBinPack_class->enumerate = JS_EnumerateStub;
	jsb_GuillotineBinPack_class->resolve = JS_ResolveStub;
	jsb_GuillotineBinPack_class->convert = JS_ConvertStub;
	jsb_GuillotineBinPack_class->finalize = js_binpack_GuillotineBinPack_finalize;
	jsb_GuillotineBinPack_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Insert", js_binpack_GuillotineBinPack_Insert, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("GetUsedRectangles", js_binpack_GuillotineBinPack_GetUsedRectangles, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("MergeFreeList", js_binpack_GuillotineBinPack_MergeFreeList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Occupancy", js_binpack_GuillotineBinPack_Occupancy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("GetFreeRectangles", js_binpack_GuillotineBinPack_GetFreeRectangles, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Init", js_binpack_GuillotineBinPack_Init, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_GuillotineBinPack_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_GuillotineBinPack_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_GuillotineBinPack_class,
		js_binpack_GuillotineBinPack_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "GuillotineBinPack", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<GuillotineBinPack> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_GuillotineBinPack_class;
		p->proto = jsb_GuillotineBinPack_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_MaxRectsBinPack_class;
JSObject *jsb_MaxRectsBinPack_prototype;

JSBool js_binpack_MaxRectsBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	MaxRectsBinPack* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (MaxRectsBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	do {
		if (argc == 3) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			MaxRectsBinPack::FreeRectChoiceHeuristic arg2;
			ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
			if (!ok) { ok = JS_TRUE; break; }
			Rect ret = cobj->Insert(arg0, arg1, arg2);
			jsval jsret; do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Rect>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 3) {
			std::vector<RectSize, std::allocator<RectSize> > arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR vector;
			if (!ok) { ok = JS_TRUE; break; }
			std::vector<Rect, std::allocator<Rect> > arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR vector;
			if (!ok) { ok = JS_TRUE; break; }
			MaxRectsBinPack::FreeRectChoiceHeuristic arg2;
			ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->Insert(arg0, arg1, arg2);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_binpack_MaxRectsBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	MaxRectsBinPack* cobj = (MaxRectsBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->Init(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_binpack_MaxRectsBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	MaxRectsBinPack* cobj = (MaxRectsBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->Occupancy();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_MaxRectsBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	MaxRectsBinPack* cobj = NULL;
	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new MaxRectsBinPack(arg0, arg1);
			TypeTest<MaxRectsBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new MaxRectsBinPack();
			TypeTest<MaxRectsBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_binpack_MaxRectsBinPack_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (MaxRectsBinPack)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        MaxRectsBinPack *nobj = static_cast<MaxRectsBinPack *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_MaxRectsBinPack_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    MaxRectsBinPack *nobj = new MaxRectsBinPack();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_MaxRectsBinPack(JSContext *cx, JSObject *global) {
	jsb_MaxRectsBinPack_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_MaxRectsBinPack_class->name = "MaxRectsBinPack";
	jsb_MaxRectsBinPack_class->addProperty = JS_PropertyStub;
	jsb_MaxRectsBinPack_class->delProperty = JS_PropertyStub;
	jsb_MaxRectsBinPack_class->getProperty = JS_PropertyStub;
	jsb_MaxRectsBinPack_class->setProperty = JS_StrictPropertyStub;
	jsb_MaxRectsBinPack_class->enumerate = JS_EnumerateStub;
	jsb_MaxRectsBinPack_class->resolve = JS_ResolveStub;
	jsb_MaxRectsBinPack_class->convert = JS_ConvertStub;
	jsb_MaxRectsBinPack_class->finalize = js_binpack_MaxRectsBinPack_finalize;
	jsb_MaxRectsBinPack_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Insert", js_binpack_MaxRectsBinPack_Insert, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Init", js_binpack_MaxRectsBinPack_Init, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Occupancy", js_binpack_MaxRectsBinPack_Occupancy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_MaxRectsBinPack_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_MaxRectsBinPack_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_MaxRectsBinPack_class,
		js_binpack_MaxRectsBinPack_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "MaxRectsBinPack", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<MaxRectsBinPack> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_MaxRectsBinPack_class;
		p->proto = jsb_MaxRectsBinPack_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_ShelfBinPack_class;
JSObject *jsb_ShelfBinPack_prototype;

JSBool js_binpack_ShelfBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfBinPack* cobj = (ShelfBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 3) {
		int arg0;
		int arg1;
		ShelfBinPack::ShelfChoiceHeuristic arg2;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Rect ret = cobj->Insert(arg0, arg1, arg2);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Rect>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_binpack_ShelfBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfBinPack* cobj = (ShelfBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 3) {
		int arg0;
		int arg1;
		JSBool arg2;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->Init(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_binpack_ShelfBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfBinPack* cobj = (ShelfBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->Occupancy();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_ShelfBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	ShelfBinPack* cobj = NULL;
	do {
		if (argc == 3) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			JSBool arg2;
			ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new ShelfBinPack(arg0, arg1, arg2);
			TypeTest<ShelfBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new ShelfBinPack();
			TypeTest<ShelfBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_binpack_ShelfBinPack_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ShelfBinPack)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        ShelfBinPack *nobj = static_cast<ShelfBinPack *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_ShelfBinPack_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    ShelfBinPack *nobj = new ShelfBinPack();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_ShelfBinPack(JSContext *cx, JSObject *global) {
	jsb_ShelfBinPack_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_ShelfBinPack_class->name = "ShelfBinPack";
	jsb_ShelfBinPack_class->addProperty = JS_PropertyStub;
	jsb_ShelfBinPack_class->delProperty = JS_PropertyStub;
	jsb_ShelfBinPack_class->getProperty = JS_PropertyStub;
	jsb_ShelfBinPack_class->setProperty = JS_StrictPropertyStub;
	jsb_ShelfBinPack_class->enumerate = JS_EnumerateStub;
	jsb_ShelfBinPack_class->resolve = JS_ResolveStub;
	jsb_ShelfBinPack_class->convert = JS_ConvertStub;
	jsb_ShelfBinPack_class->finalize = js_binpack_ShelfBinPack_finalize;
	jsb_ShelfBinPack_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Insert", js_binpack_ShelfBinPack_Insert, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Init", js_binpack_ShelfBinPack_Init, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Occupancy", js_binpack_ShelfBinPack_Occupancy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_ShelfBinPack_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_ShelfBinPack_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_ShelfBinPack_class,
		js_binpack_ShelfBinPack_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "ShelfBinPack", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<ShelfBinPack> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_ShelfBinPack_class;
		p->proto = jsb_ShelfBinPack_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_ShelfNextFitBinPack_class;
JSObject *jsb_ShelfNextFitBinPack_prototype;

JSBool js_binpack_ShelfNextFitBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfNextFitBinPack* cobj = (ShelfNextFitBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Node ret = cobj->Insert(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Node>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_binpack_ShelfNextFitBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfNextFitBinPack* cobj = (ShelfNextFitBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->Init(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_binpack_ShelfNextFitBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	ShelfNextFitBinPack* cobj = (ShelfNextFitBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->Occupancy();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_binpack_ShelfNextFitBinPack_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ShelfNextFitBinPack)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        ShelfNextFitBinPack *nobj = static_cast<ShelfNextFitBinPack *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_ShelfNextFitBinPack_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    ShelfNextFitBinPack *nobj = new ShelfNextFitBinPack();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_ShelfNextFitBinPack(JSContext *cx, JSObject *global) {
	jsb_ShelfNextFitBinPack_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_ShelfNextFitBinPack_class->name = "ShelfNextFitBinPack";
	jsb_ShelfNextFitBinPack_class->addProperty = JS_PropertyStub;
	jsb_ShelfNextFitBinPack_class->delProperty = JS_PropertyStub;
	jsb_ShelfNextFitBinPack_class->getProperty = JS_PropertyStub;
	jsb_ShelfNextFitBinPack_class->setProperty = JS_StrictPropertyStub;
	jsb_ShelfNextFitBinPack_class->enumerate = JS_EnumerateStub;
	jsb_ShelfNextFitBinPack_class->resolve = JS_ResolveStub;
	jsb_ShelfNextFitBinPack_class->convert = JS_ConvertStub;
	jsb_ShelfNextFitBinPack_class->finalize = js_binpack_ShelfNextFitBinPack_finalize;
	jsb_ShelfNextFitBinPack_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Insert", js_binpack_ShelfNextFitBinPack_Insert, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Init", js_binpack_ShelfNextFitBinPack_Init, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Occupancy", js_binpack_ShelfNextFitBinPack_Occupancy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_ShelfNextFitBinPack_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_ShelfNextFitBinPack_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_ShelfNextFitBinPack_class,
		dummy_constructor<ShelfNextFitBinPack>, 0, // no constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "ShelfNextFitBinPack", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<ShelfNextFitBinPack> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_ShelfNextFitBinPack_class;
		p->proto = jsb_ShelfNextFitBinPack_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_SkylineBinPack_class;
JSObject *jsb_SkylineBinPack_prototype;

JSBool js_binpack_SkylineBinPack_Insert(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	SkylineBinPack* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (SkylineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	do {
		if (argc == 3) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			SkylineBinPack::LevelChoiceHeuristic arg2;
			ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
			if (!ok) { ok = JS_TRUE; break; }
			Rect ret = cobj->Insert(arg0, arg1, arg2);
			jsval jsret; do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Rect>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 3) {
			std::vector<RectSize, std::allocator<RectSize> > arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR vector;
			if (!ok) { ok = JS_TRUE; break; }
			std::vector<Rect, std::allocator<Rect> > arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR vector;
			if (!ok) { ok = JS_TRUE; break; }
			SkylineBinPack::LevelChoiceHeuristic arg2;
			ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->Insert(arg0, arg1, arg2);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_binpack_SkylineBinPack_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SkylineBinPack* cobj = (SkylineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 3) {
		int arg0;
		int arg1;
		JSBool arg2;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->Init(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_binpack_SkylineBinPack_Occupancy(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SkylineBinPack* cobj = (SkylineBinPack *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->Occupancy();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_binpack_SkylineBinPack_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	SkylineBinPack* cobj = NULL;
	do {
		if (argc == 3) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			JSBool arg2;
			ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new SkylineBinPack(arg0, arg1, arg2);
			TypeTest<SkylineBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new SkylineBinPack();
			TypeTest<SkylineBinPack> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_binpack_SkylineBinPack_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (SkylineBinPack)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);

        SkylineBinPack *nobj = static_cast<SkylineBinPack *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
}

static JSBool js_binpack_SkylineBinPack_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    SkylineBinPack *nobj = new SkylineBinPack();
    js_proxy_t* p;
    JS_NEW_PROXY(p, nobj, obj);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_binpack_SkylineBinPack(JSContext *cx, JSObject *global) {
	jsb_SkylineBinPack_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_SkylineBinPack_class->name = "SkylineBinPack";
	jsb_SkylineBinPack_class->addProperty = JS_PropertyStub;
	jsb_SkylineBinPack_class->delProperty = JS_PropertyStub;
	jsb_SkylineBinPack_class->getProperty = JS_PropertyStub;
	jsb_SkylineBinPack_class->setProperty = JS_StrictPropertyStub;
	jsb_SkylineBinPack_class->enumerate = JS_EnumerateStub;
	jsb_SkylineBinPack_class->resolve = JS_ResolveStub;
	jsb_SkylineBinPack_class->convert = JS_ConvertStub;
	jsb_SkylineBinPack_class->finalize = js_binpack_SkylineBinPack_finalize;
	jsb_SkylineBinPack_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("Insert", js_binpack_SkylineBinPack_Insert, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Init", js_binpack_SkylineBinPack_Init, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("Occupancy", js_binpack_SkylineBinPack_Occupancy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_binpack_SkylineBinPack_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_SkylineBinPack_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_SkylineBinPack_class,
		js_binpack_SkylineBinPack_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "SkylineBinPack", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<SkylineBinPack> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_SkylineBinPack_class;
		p->proto = jsb_SkylineBinPack_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_binpack(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "binpack", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "binpack", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_binpack_SkylineBinPack(cx, obj);
	js_register_binpack_ShelfNextFitBinPack(cx, obj);
	js_register_binpack_GuillotineBinPack(cx, obj);
	js_register_binpack_ShelfBinPack(cx, obj);
	js_register_binpack_DisjointRectCollection(cx, obj);
	js_register_binpack_MaxRectsBinPack(cx, obj);
}

