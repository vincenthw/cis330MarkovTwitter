# Hey Emacs, this is a -*- makefile -*-
# The twitcurl library.. a Makefile for OpenWRT
# Makefile-fu by John Boiles
# 28 September 2009

LIBNAME = twitcurl
SRC = $(LIBNAME).cpp
STAGING_DIR = 
INCLUDE_DIR = $(STAGING_DIR)/usr/include
LINCLUDE_DIR = $(STAGING_DIR)/usr/local/include
LIBRARY_DIR = $(STAGING_DIR)/usr/lib
LLIBRARY_DIR = $(STAGING_DIR)/usr/local/lib
LDFLAGS += -Wl,-rpath-link=$(STAGING_DIR)/usr/lib
CC = g++
REMOVE = rm -f
COPY = cp


CFLAGS =$(CDEFS) $(CINCS) $(CSTANDARD)

all: install

install: $(SRC) $(LIBNAME).h
	$(CC) -Wall -fPIC -c -I$(INCLUDE_DIR) $(SRC) oauthlib.cpp urlencode.cpp base64.cpp HMAC_SHA1.cpp SHA1.cpp
	$(CC) -shared $(LDFLAGS) -o lib$(LIBNAME).so *.o -L$(LIBRARY_DIR) -lcurl
	$(COPY) lib$(LIBNAME).so /usr/lib/lib$(LIBNAME).so

clean:
	$(REMOVE) lib$(LIBNAME)*.so
	$(REMOVE) $(LIBNAME).o
	$(REMOVE) *.o
	$(REMOVE) $(LIBRARY_DIR)/lib$(LIBNAME).so*