CC = arm-none-linux-gnueabi-gcc

CFLAGS := -g -I../../crc32

LDFLAGS := -L../../crc32 -lcrc32

all: crc32test

crc32test: crc32test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) -rf *.o


