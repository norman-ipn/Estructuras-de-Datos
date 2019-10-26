run: a.out
	./a.out
a.out: main.c
	gcc main.c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -fr a.out
