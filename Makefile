CC = g++

CFLAGS = -g -Wall -Wextra -c

TARGET = deque_test

all: $(TARGET)

$(TARGET): main.o deque.o
	$(CC) main.o deque.o -o $(TARGET)

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) main.cpp

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) deque.cpp

clean:
	$(RM) *.o *~ $(TARGET)
