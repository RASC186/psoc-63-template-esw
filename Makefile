PRJ_NAME = app

# BUILD DIRECTORIES

BLD_DIR = build
BIN_DIR = $(BLD_DIR)/bin
OBJ_DIR = $(BLD_DIR)/obj

# PROJECT DIRECTORIES

PRJ_SRC_DIRS  = app
PRJ_SRC_DIRS += app/src

PRJ_INC_DIRS  = app/include 

# LIBRARIES DIRECTORIES

LIB_SRC_DIRS += bsp/TARGET_CY8CPROTO-063-BLE
LIB_SRC_DIRS += bsp/TARGET_CY8CPROTO-063-BLE/bluetooth
LIB_SRC_DIRS += libs/mtb-hal-cat1/source
LIB_SRC_DIRS += libs/mtb-hal-cat1/COMPONENT_CAT1A/source/pin_packages
LIB_SRC_DIRS += libs/mtb-hal-cat1/COMPONENT_CAT1A/source/triggers
LIB_SRC_DIRS += libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/source
LIB_SRC_DIRS += libs/mtb-pdl-cat1/drivers/source

LIB_INC_DIRS  = bsp/TARGET_CY8CPROTO-063-BLE
LIB_INC_DIRS += bsp/TARGET_CY8CPROTO-063-BLE/bluetooth
LIB_INC_DIRS += libs/cmsis/Core/Include
LIB_INC_DIRS += libs/core-lib/include
LIB_INC_DIRS += libs/mtb-hal-cat1/include
LIB_INC_DIRS += libs/mtb-hal-cat1/include_pvt
LIB_INC_DIRS += libs/mtb-hal-cat1/COMPONENT_CAT1A/include/pin_packages
LIB_INC_DIRS += libs/mtb-hal-cat1/COMPONENT_CAT1A/include/triggers
LIB_INC_DIRS += libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include
LIB_INC_DIRS += libs/mtb-pdl-cat1/devices/COMPONENT_CAT1A/include/ip
LIB_INC_DIRS += libs/mtb-pdl-cat1/drivers/include

# FILEPATHS

PRJ_SRC_FILES = $(foreach D,$(PRJ_SRC_DIRS),$(wildcard $(D)/*.c))
PRJ_INC_FILES = $(foreach D,$(PRJ_INC_DIRS),$(wildcard $(D)/*.h))

LIB_SRC_FILES = $(foreach D,$(LIB_SRC_DIRS),$(wildcard $(D)/*.c))
LIB_INC_FILES = $(foreach D,$(LIB_INC_DIRS),$(wildcard $(D)/*.h))

LINKER_SCRIPT = app/psoc63_ls.ld

# COMPILER OPTIONS

CC        = arm-none-eabi-gcc
PLATFORM  = -mcpu=cortex-m0plus -mthumb
CFLAGS    = -c -std=gnu11 -Wall -O0
LDFLAGS   = -nostdlib -T $(LINKER_SCRIPT)
SOURCES   = $(PRJ_SRC_FILES) 
SOURCES  += $(LIB_SRC_FILES)
INCLUDES  = $(foreach D, $(PRJ_INC_DIRS), -I$(shell pwd)/$(D)) 
INCLUDES += $(foreach D, $(LIB_INC_DIRS), -I$(shell pwd)/$(D))
OBJECTS   = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY:
build: $(OBJECTS)
	if [ ! -d $(BIN_DIR) ] ; then mkdir -p $(BIN_DIR) ; fi
	$(CC) $(LDFLAGS) $^ -o $(BIN_DIR)/$(PRJ_NAME)

.PHONY:
clean:
	rm -rf $(BLD_DIR) 

$(OBJ_DIR)/%.o:%.c
	if [ ! -d $(@D) ] ; then mkdir -p $(@D) ; fi
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $< -o $@
