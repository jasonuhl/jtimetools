LIBRARY_CFLAGS = -fpic -Wall -W
LIBRARY_LDLIBS = -shared -ldl
PROG_CFLAGS = -Wall -W

LIBRARY  = libtimewarp.so
PROG     = topofsec

LIBRARY_OBJS := libtimewarp.o
PROG_OBJS := topofsec.o
OBJS := $(LIBRARY_OBJS) $(PROG_OBJS)

.PHONY: all clean

all: $(LIBRARY) $(PROG)

$(LIBRARY): $(LIBRARY_OBJS)
	$(CC) $(LIBRARY_OBJS) $(LIBRARY_LDLIBS) -o $@

libtimewarp.o: libtimewarp.c
	$(CC) $(LIBRARY_CFLAGS) -c $< -o $@

$(PROG): $(PROG_OBJS)
	$(CC) $(PROG_OBJS) -o $@

topofsec.o: topofsec.c
	$(CC) $(PROG_CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(LIBRARY) $(PROG)
