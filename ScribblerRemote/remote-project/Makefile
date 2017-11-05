remote : remote.c commands.c
	gcc -Wall -std=c11 -I/home/walker/MyroC/include -L/home/walker/MyroC/lib -lm -lMyroC -lbluetooth -ljpeg -leSpeakPackage remote.c commands.c -o remote

.PHONY : clean
clean :
	rm -rf remote *.o *.core
