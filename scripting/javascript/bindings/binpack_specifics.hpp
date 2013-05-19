#ifndef __jsb_binpack_specifics_h__
#define __jsb_binpack_specifics_h__

#include "binpack.h"
#include "js_bindings_config.h"
#include "js_bindings_core.h"
#include "jsapi.h"
#include "jsfriendapi.h"
#include "spidermonkey_specifics.h"

JSBool jsval_to_rect(JSContext *cx, jsval v, Rect* ret);
JSBool jsval_to_rectsize(JSContext *cx, jsval v, RectSize* ret);
JSBool jsval_to_rect_vector(JSContext* cx, jsval v, std::vector<Rect>& ret);
JSBool jsval_to_rectsize_vector(JSContext* cx, jsval v, std::vector<RectSize>& ret);

jsval rect_to_jsval(JSContext* cx, Rect& v);
jsval rectsize_to_jsval(JSContext* cx, RectSize& v);
jsval rect_vector_to_jsval(JSContext* cx, const std::vector<Rect>& arr);
jsval rectsize_vector_to_jsval(JSContext* cx, const std::vector<RectSize>& arr);

#endif

