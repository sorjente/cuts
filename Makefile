CC = gcc
CFLAGS = -Wall -Wextra -Isrc
PREFIX ?= /usr/local/bin

BUILD_DIR = build
TST_DIR = tests


TEST_SOURCES = $(wildcard $(TST_DIR)/*.c)
TEST_OBJECTS = $(patsubst $(TST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SOURCES)) 
TEST_TARGETS = $(patsubst %.o, %, $(TEST_OBJECTS))


all: build $(TEST_TARGETS)


tests: $(TEST_TARGETS)
ifeq ($(shell uname -s), Linux)
	@for test in $(TEST_TARGETS) ; do \
		valgrind --leak-check=full --error-exitcode=1 $$test ; \
	done
else
	@for test in $(TEST_TARGETS) ; do \
		macgrind . $$test --run-before "make clean" ; \
	done
endif


$(BUILD_DIR)/%.o: $(TST_DIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@


%: %.o
	$(CC) $(CFLAGS) $< -o $@


build:
	@mkdir -p $(BUILD_DIR)


clean:
	rm -rf $(BUILD_DIR)/


.PHONY : all build clean

