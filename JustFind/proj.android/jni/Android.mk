LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := JustFind_shared

LOCAL_MODULE_FILENAME := libJustFind

#FILE_LIST := JustFind/main.cpp
#FILE_LIST += $(wildcard $(LOCAL_PATH)../../Classes/*.cpp)
#FILE_LIST += $(wildcard $(LOCAL_PATH)../../Classes/RectangleBinPack/*.cpp)
#FILE_LIST += $(wildcard $(LOCAL_PATH)../../Classes/fygui/*.cpp)
#LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_SRC_FILES := JustFind/main.cpp \
                   ../../Classes/AppDelegate.cpp 

				   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../../scripting/javascript/bindings\
					$(LOCAL_PATH)/../../Classes/RectangleBinPack	\
					$(LOCAL_PATH)/../../Classes/fygui	\
					 $(LOCAL_PATH)/../../../cocos2dx/include
			

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

LOCAL_WHOLE_STATIC_LIBRARIES += spidermonkey_static
LOCAL_WHOLE_STATIC_LIBRARIES += scriptingcore-spidermonkey
LOCAL_WHOLE_STATIC_LIBRARIES += justfindex_static
LOCAL_WHOLE_STATIC_LIBRARIES += jsbinding-extension

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_DEBUG=2 -DCOCOS2D_JAVASCRIPT

include $(BUILD_SHARED_LIBRARY)
$(call import-module,extensions)
$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,JustFind/justfindex)
$(call import-module,scripting/javascript/spidermonkey-android)
$(call import-module,scripting/javascript/bindings)
$(call import-module,JustFind/jsbindingex)

