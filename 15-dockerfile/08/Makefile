
hi: hi.o
	ld -o hi hi.o
	strip --strip-all hi

hi.o: hi.s
	as -o hi.o hi.s

clean:
	rm -f hi hi.o

docker: hi
	docker build -t tvs-ex08 .
