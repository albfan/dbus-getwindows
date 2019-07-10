
CFLAGS_DBUS = $(shell pkg-config --cflags --libs dbus-1)
CFLAGS_DBUS_GLIB = $(shell pkg-config --cflags --libs dbus-glib-1)
CFLAGS_GIO  = $(shell pkg-config --cflags --libs gio-2.0)

CFLAGS = -g -Wall -Werror


all: dbus-getwindows

dbus-getwindows: dbus-getwindows.c
	gcc $< -o $@ $(CFLAGS) $(CFLAGS_GIO) $(CFLAGS_DBUS_GLIB)

clean:
	rm -f dbus-getwindows


.PHONY: all clean
