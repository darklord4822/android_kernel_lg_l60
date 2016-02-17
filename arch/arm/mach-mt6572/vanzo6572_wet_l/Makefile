
include $(srctree)/drivers/misc/mediatek/Makefile.custom

# Module project related part

ifeq ($(CONFIG_MTK_EPL88051_AUTO),y)
obj-y   +=  alsps/epl88051_auto/
endif

ifeq ($(CONFIG_MTK_CM36671_AUTO),y)
obj-y   +=  alsps/cm36671_auto/
endif

ifeq ($(CONFIG_MTK_BMA250E),y)
obj-y   +=  accelerometer/bma250e/
endif

ifeq ($(CONFIG_MTK_MT5193),y)
obj-y	+=  matv/mt5193/
endif

ifneq ($(CONFIG_ARCH_MTK_PROJECT),)
ARCH_MTK_PROJECT := $(shell echo $(CONFIG_ARCH_MTK_PROJECT))
obj-y	+= core/
obj-y	+= dct/dct/
endif

#obj-y	+=  hdmi/
obj-y	+=  camera/camera/
obj-y	+=  vibrator/
obj-y	+=  leds/
obj-y	+=  keypad/
obj-y	+=  sound/
obj-y	+=  accdet/
