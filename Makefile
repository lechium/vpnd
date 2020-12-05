target = appletv
include $(THEOS)/makefiles/common.mk

TOOL_NAME = vpnd

vpnd_FILES = main.m VPNDaemonListener.m
vpnd_FRAMEWORKS = Foundation, NetworkExtension
vpnd_LDFLAGS = -F.
vpnd_CFLAGS += -I. -F. -fobjc-arc
vpnd_CODESIGN_FLAGS=-Sentitlements_tvos.plist

include $(THEOS_MAKE_PATH)/tool.mk
