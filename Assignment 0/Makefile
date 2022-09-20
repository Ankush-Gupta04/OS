test:test.o
	gcc -no-pie test.o
test.o:test.asm
	yasm -f elf64 test.asm
clean:
	rm -rf *.o *a.out
