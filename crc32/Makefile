CC = arm-none-linux-gnueabi-gcc
AR = arm-none-linux-gnueabi-ar
RM = rm -f
CFLAGS = -Wall -O2 -g
OBJS = crc32.o
LIB = libcrc32.a

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(LIB) *~
