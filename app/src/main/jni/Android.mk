LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := jssc
LOCAL_SRC_FILES := jssc.cpp
include $(BUILD_SHARED_LIBRARY)