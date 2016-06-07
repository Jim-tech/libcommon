CFLAGS := -g -I../ezxml

LDFLAGS := -L../ezxml -lezxml

all: ezxmltest

ezxmltest: ezxmltest.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) -rf *.o


