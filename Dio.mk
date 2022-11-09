INCDIRS  += -I ${DIO_PATH}/src \
	    -I ${DIO_PATH}/api	\
	    -I ${DIO_PATH}/cfg \
	    -I ${DIO_PATH}/src/bsp/

LDFLAGS  += -g
CFLAGS   += -Werror ${INCDIRS} -g
ASFLAGS  += ${INCDIRS} -g

$(info compiling Dio source files)


DIO_OBJS := \
	${DIO_PATH}/src/Dio.o \
	${DIO_PATH}/src/bsp/rp2040/bsp_dio.o \
	${DIO_PATH}/cfg/Dio_cfg.o

