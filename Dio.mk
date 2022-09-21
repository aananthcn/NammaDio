INCDIRS  += -I ${DIO_PATH}/src \
	    -I ${DIO_PATH}/api	\
	    -I ${DIO_PATH}/cfg \
	    -I ${DIO_PATH}/src/board/

LDFLAGS  += -g
CFLAGS   += -Werror ${INCDIRS} -g
ASFLAGS  += ${INCDIRS} -g

$(info compiling Dio source files)


DIO_OBJS := \
	${DIO_PATH}/src/Dio.o \
	${DIO_PATH}/src/board/rp2040/brd_dio.o \
	${DIO_PATH}/cfg/Dio_cfg.o

