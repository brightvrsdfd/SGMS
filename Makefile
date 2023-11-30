CC = g++
CFLAGS = -std=c++11

all: filesystem_test

filesystem_test: filesystem_test.o filesystem.o course.o assignment.o
	$(CC) $(CFLAGS) -o filesystem_test filesystem_test.o filesystem.o course.o assignment.o

filesystem_test.o: filesystem_test.cpp filesystem.h course.h assignment.h
	$(CC) $(CFLAGS) -c filesystem_test.cpp

filesystem.o: filesystem.cpp filesystem.h course.h assignment.h
	$(CC) $(CFLAGS) -c filesystem.cpp

course.o: course.cpp course.h
	$(CC) $(CFLAGS) -c course.cpp

assignment.o: assignment.cpp assignment.h
	$(CC) $(CFLAGS) -c assignment.cpp

clean:
	rm -f *.o filesystem_test
