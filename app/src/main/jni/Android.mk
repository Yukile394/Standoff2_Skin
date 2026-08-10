LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := nativehook
LOCAL_SRC_FILES := nativehook.c

include $(BUILD_SHARED_LIBRARY)
