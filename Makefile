corpus: main.o hello.o str_tool.o
	cc -o corpus main.o hello.o str_tool.o

main.o: main.c
	cc -c main.c

hello.o: hello.c
	cc -c hello.c

str_tool.o: str_tool.c
	cc -c str_tool.c
