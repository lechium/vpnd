target = appletv
THEOS_DEVICE_IP=13tv.local
include $(THEOS)/makefiles/common.mk

INSTALL_TARGET_PROCESSES = TVSystemMenuService 

BUNDLE_NAME = VPN

VPN_FILES = NTVVPNModule.m UIView+RecursiveFind.m UIImage+Tint.m
VPN_INSTALL_PATH = /Library/TVSystemMenuModules
VPN_FRAMEWORKS = UIKit
VPN_PRIVATE_FRAMEWORKS = TVSystemMenuUI 
VPN_CFLAGS = -fobjc-arc  -F. -I.
VPN_LDFLAGS +=  -F. -I. -undefined dynamic_lookup

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/TVSystemMenuModules$(ECHO_END)
	
