# makfile configuration
COMMON_OBJECTS		= draw_shapes.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: shape_demo.elf

#additional rules for files
shape_demo.elf: ${COMMON_OBJECTS} shape_demo.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: shape_demo.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
