
#include "binpack_specifics.hpp"


JSBool jsval_to_rect(JSContext *cx, jsval v, Rect* ret)
{
	JSObject *tmp;
	jsval jsx, jsy, jswidth, jsheight;
	double x, y, width, height;
	JSBool ok = JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "width", &jswidth) &&
		JS_GetProperty(cx, tmp, "height", &jsheight) &&
		JS_ValueToNumber(cx, jsx, &x) &&
		JS_ValueToNumber(cx, jsy, &y) &&
		JS_ValueToNumber(cx, jswidth, &width) &&
		JS_ValueToNumber(cx, jsheight, &height);

	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = x;
	ret->y = y;
	ret->width = width;
	ret->height = height;
	return JS_TRUE;
}

JSBool jsval_to_rectsize(JSContext *cx, jsval v, RectSize* ret)
{
	JSObject *tmp;
	jsval jsw, jsh;
	double w, h;
	JSBool ok = JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "width", &jsw) &&
		JS_GetProperty(cx, tmp, "height", &jsh) &&
		JS_ValueToNumber(cx, jsw, &w) &&
		JS_ValueToNumber(cx, jsh, &h);

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
	JSBool ok = JS_DefineProperty(cx, tmp, "x", DOUBLE_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", DOUBLE_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "width", DOUBLE_TO_JSVAL(v.width), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "height", DOUBLE_TO_JSVAL(v.height), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

jsval rectsize_to_jsval(JSContext* cx, RectSize& v)
{
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "width", DOUBLE_TO_JSVAL(v.width), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "height", DOUBLE_TO_JSVAL(v.height), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
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
		jsval arrElement = rect_to_jsval(cx, iter);
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
		jsval arrElement = rectsize_to_jsval(cx, iter);
		if(!JS_SetElement(cx, jsretArr, i, &arrElement)) {
			break;
		}
	}
	return OBJECT_TO_JSVAL(jsretArr);
}


