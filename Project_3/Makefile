# makefile configuration
COMMON_OBJECTS		= wdt_handler.o p2_interrupt_handler.o Tetris.o switches.o wdt_c_handler.o buzzer.o ../lib/libTimer.a



CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} main.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: main.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf 
