
#include "binpack_specifics.hpp"


JSBool jsval_to_rect(JSContext *cx, jsval v, Rect* ret)
{
	JSObject *tmp;
	jsval jsx, jsy, jswidth, jsheight;
	int x, y, width, height;
	JSBool ok = JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "width", &jswidth) &&
		JS_GetProperty(cx, tmp, "height", &jsheight) &&
		JS_ValueToInt32(cx, jsx, &x) &&
		JS_ValueToInt32(cx, jsy, &y) &&
		JS_ValueToInt32(cx, jswidth, &width) &&
		JS_ValueToInt32(cx, jsheight, &height);

	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = x;
	ret->y = y;
	ret->width = width;
	ret->height = height;
	return JS_TRUE;
}


JSBool jsval_to_node(JSContext *cx, jsval v,Node* ret)
{
	JSObject *tmp;
	jsval jsx, jsy, jswidth, jsheight,jsflipped;
	int x, y, width, height,flipped;
	JSBool ok = JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "width", &jswidth) &&
		JS_GetProperty(cx, tmp, "height", &jsheight) &&
		JS_GetProperty(cx, tmp, "flipped", &jsflipped) &&
		JS_ValueToInt32(cx, jsx, &x) &&
		JS_ValueToInt32(cx, jsy, &y) &&
		JS_ValueToInt32(cx, jswidth, &width) &&
		JS_ValueToInt32(cx, jsheight, &height) &&
		JS_ValueToInt32(cx, jsflipped, &flipped);

	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = x;
	ret->y = y;
	ret->width = width;
	ret->height = height;
	ret->flipped = flipped;
	return JS_TRUE;
}


JSBool jsval_to_rectsize(JSContext *cx, jsval v, RectSize* ret)
{
	JSObject *tmp;
	jsval jsw, jsh;
	int w, h;
	JSBool ok = JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "width", &jsw) &&
		JS_GetProperty(cx, tmp, "height", &jsh) &&
		JS_ValueToInt32(cx, jsw, &w) &&
		JS_ValueToInt32(cx, jsh, &h);

	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
	ret->width = w;
	ret->height = h;
	return JS_TRUE;
}

JSBool jsval_to_rect_vector(JSContext* cx, jsval v, std::vector<Rect>& ret)
{
	JSObject *jsobj;
	JSBool ok = JS_ValueToObject( cx, v, &jsobj );
	JSB_PRECONDITION2( ok, cx, JS_FALSE, "Error converting value to object");
	JSB_PRECONDITION2( jsobj && JS_IsArrayObject( cx, jsobj),  cx, JS_FALSE, "Object must be an array");

	uint32_t len = 0;
	JS_GetArrayLength(cx, jsobj, &len);

	for (uint32_t i=0; i < len; i++) {
		Rect rect;
		jsval elt;
		if (JS_GetElement(cx, jsobj, i, &elt)) {
			jsval_to_rect(cx,elt,&rect);
			ret.push_back(rect);		
		}
	}

	return JS_TRUE;
}

JSBool jsval_to_rectsize_vector(JSContext* cx, jsval v, std::vector<RectSize>& ret)
{
	JSObject *jsobj;
	JSBool ok = JS_ValueToObject( cx, v, &jsobj );
	JSB_PRECONDITION2( ok, cx, JS_FALSE, "Error converting value to object");
	JSB_PRECONDITION2( jsobj && JS_IsArrayObject( cx, jsobj),  cx, JS_FALSE, "Object must be an array");

	uint32_t len = 0;
	JS_GetArrayLength(cx, jsobj, &len);

	for (uint32_t i=0; i < len; i++) {
		RectSize rect;
		jsval elt;
		if (JS_GetElement(cx, jsobj, i, &elt)) {
			if (jsval_to_rectsize(cx,elt,&rect)){
				ret.push_back(rect);		
			}
		}
	}

	return JS_TRUE;
}





jsval rect_to_jsval(JSContext* cx, Rect& v)
{
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "x", INT_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", INT_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "width", INT_TO_JSVAL(v.width), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "height", INT_TO_JSVAL(v.height), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

jsval node_to_jsval(JSContext* cx, Node& v)
{
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "x", INT_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", INT_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "width", INT_TO_JSVAL(v.width), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "height", INT_TO_JSVAL(v.height), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT)&&
		JS_DefineProperty(cx, tmp, "flipped", BOOLEAN_TO_JSVAL(v.flipped), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}


jsval rectsize_to_jsval(JSContext* cx, RectSize& v)
{
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "width", INT_TO_JSVAL(v.width), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "height", INT_TO_JSVAL(v.height), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

jsval rect_vector_to_jsval(JSContext* cx, const std::vector<Rect>& arr)
{
	JSObject *jsretArr = JS_NewArrayObject(cx, 0, NULL);

	int i = 0;
	for(std::vector<Rect>::const_iterator iter = arr.begin(); iter != arr.end(); ++iter, ++i) {
		Rect rect = *iter;
		jsval arrElement = rect_to_jsval(cx, rect);
		if(!JS_SetElement(cx, jsretArr, i, &arrElement)) {
			break;
		}
	}
	return OBJECT_TO_JSVAL(jsretArr);
}

jsval rectsize_vector_to_jsval(JSContext* cx, const std::vector<RectSize>& arr)
{
	JSObject *jsretArr = JS_NewArrayObject(cx, 0, NULL);

	int i = 0;
	for(std::vector<RectSize>::const_iterator iter = arr.begin(); iter != arr.end(); ++iter, ++i) {
		RectSize rectsize = *iter;
		jsval arrElement = rectsize_to_jsval(cx, rectsize);
		if(!JS_SetElement(cx, jsretArr, i, &arrElement)) {
			break;
		}
	}
	return OBJECT_TO_JSVAL(jsretArr);
}


