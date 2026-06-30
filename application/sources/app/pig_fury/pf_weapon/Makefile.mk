CFLAGS		+= -I./sources/app/pig_fury/pf_weapon
CPPFLAGS	+= -I./sources/app/pig_fury/pf_weapon

VPATH += sources/app/pig_fury/pf_weapon
PF_WEAPON_DIR := sources/app/pig_fury/pf_weapon
# CPP source files
SOURCES_CPP +=	$(PF_WEAPON_DIR)/pf_axe.cpp \
