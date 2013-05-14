LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := justfindex_static

LOCAL_MODULE_FILENAME := libjustfindex

FILE_LIST := $(wildcard $(LOCAL_PATH)/fygui/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/RectangleBinPack/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/fygui \
                    $(LOCAL_PATH)/RectangleBinPack \
                    $(LOCAL_PATH)../../cocos2dx/include

LOCAL_C_INCLUDES :=$(LOCAL_PATH) \
                    $(LOCAL_PATH)/fygui \
                    $(LOCAL_PATH)/RectangleBinPack \
                    $(LOCAL_PATH)../../cocos2dx/include



LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_DEBUG=2 -DCOCOS2D_JAVASCRIPT

include $(BUILD_STATIC_LIBRARY)

$(call import-module,cocos2dx)
