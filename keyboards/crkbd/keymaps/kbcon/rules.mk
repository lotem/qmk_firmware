# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes        # Audio control and System control
MOUSEKEY_ENABLE = yes        # Mouse keys
NKRO_ENABLE = yes            # Nkey Rollover

ifeq ($(strip $(STENO_ENABLE)), yes)
MOUSEKEY_ENABLE = no
endif
