CC=gcc
CARGS=-g -Wall
SRC_DIR=src
BUILD_DIR=build

all:
	$(CC) $(CARGS) $(SRC_DIR)/*.c -o $(BUILD_DIR)/exec

run:
	$(BUILD_DIR)/exec

clean:
	rm $(BUILD_DIR)/*
