# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: May 4, 2019
# https://github.com/WestleyR/clean-screen
# version-1.0.0
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

# where to install
PREFIX = /usr/local/bin

# your c compiler
CC = gcc

DEP_FLAG = -I deps
CFLAGS = -Wall

SF = -static

TARGET = clean-screen
SRC = src/clean-screen.c

.PHONY:
all: $(TARGET)

.PHONY:
static: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SF) -o $(TARGET) $(SRC)

.PHONY:
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC)

.PHONY:
clean:
	rm -f $(TARGET)

.PHONY:
install: $(TARGET)
	cp -f $(TARGET) $(PREFIX)

.PHONY:
uninstall: $(PREFIX)/$(TARGET)
	rm -f $(PREFIX)/$(TARGET)

#
# End Makefile
#
