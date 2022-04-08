# makfile configuration
COMMON_OBJECTS	= switches.o p2_c_handler.o p2_asm_handler.o led.o
CPU             = msp430g2553	
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: button_demo.elf

#additional rules for files
button_demo.elf: ${COMMON_OBJECTS} button_demo.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: button_demo.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
