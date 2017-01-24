CC = g++
CFLAGS = -O2 -Wall -I . -std=c++11 -L"/usr/local/lib"#加上库文件的路径
LIB1 = -lpthread
LIB2 = -lgtest #这是静态库的链接

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o $(LIB1) $(LIB2)

main.o: main.cc
	$(CC) $(CFLAGS) -o main.o -c main.cc
clean:
	rm -f *.o main *~