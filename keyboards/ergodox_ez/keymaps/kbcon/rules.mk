BOOTMAGIC_ENABLE = yes # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nk

ifeq ($(strip $(STENO_ENABLE)), yes)
MOUSEKEY_ENABLE = no
endif
