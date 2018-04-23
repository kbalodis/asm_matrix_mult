md2: md2.o md2_main.o
	arm-linux-gnueabi-gcc -o md2 md2.o md2_main.o

md2_main.o: md2_main.c
	arm-linux-gnueabi-gcc -g -mcpu=xscale -O0 -Wall -o md2_main.o -c md2_main.c

md2.o: md2.s
	arm-linux-gnueabi-as -g -mcpu=xscale -alh=md2.lis -L -o md2.o md2.s

clean:
	rm md2 *.o *.lis
