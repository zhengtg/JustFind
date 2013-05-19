LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := jsbinding-extension

LOCAL_MODULE_FILENAME := libjsbinding-extension

LOCAL_SRC_FILES := jsbinpack/jsb_binpack_auto.cpp \
				   jsbinpack/binpack_specifics.cpp \
                   jsfygui/jsb_fygui_auto.cpp 

LOCAL_CFLAGS := -DCOCOS2D_JAVASCRIPT

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_JAVASCRIPT

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../scripting/javascript/bindings\
                    $(LOCAL_PATH)/../justfindex/RectangleBinPack\
					$(LOCAL_PATH)/../justfindex/fygui\
					$(LOCAL_PATH)/jsbinpack\
					$(LOCAL_PATH)/jsbfygui

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../scripting/javascript/bindings\
						   $(LOCAL_PATH)/../justfindex/RectangleBinPack\
						   $(LOCAL_PATH)/../justfindex/fygui\
                           $(LOCAL_PATH)/jsbinpack\
						   $(LOCAL_PATH)/jsbfygui\
						   $(LOCAL_PATH)/../

LOCAL_WHOLE_STATIC_LIBRARIES := spidermonkey_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += justfindex_static

LOCAL_LDLIBS := -landroid
LOCAL_LDLIBS += -llog

include $(BUILD_STATIC_LIBRARY)

$(call import-module,scripting/javascript/spidermonkey-android)
$(call import-module,cocos2dx)
$(call import-module,extensions)
$(call import-module,justfindex)
