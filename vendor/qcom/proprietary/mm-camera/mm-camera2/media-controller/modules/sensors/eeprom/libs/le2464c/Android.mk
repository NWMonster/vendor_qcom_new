LE2464C_MASTER_EEPROM_LIBS_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_PATH := $(LE2464C_MASTER_EEPROM_LIBS_PATH)
LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/$(CHROMATIX_VERSION)

LOCAL_SRC_FILES        := le2464c_eeprom.c
LOCAL_MODULE           := libmmcamera_le2464c_eeprom
LOCAL_SHARED_LIBRARIES := libcutils libmmcamera2_sensor_modules libmmcamera_eeprom_util

LOCAL_MODULE_OWNER       := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif

include $(BUILD_SHARED_LIBRARY)
