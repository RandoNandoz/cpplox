SOURCE_DIR = ./src
TEST_DIR = ./test
BIN_DIR = ./bin
OBJ_DIR = ./obj
DOCTEST_DIR = ./lib/doctest
MAGIC_ENUM_DIR = ./lib/magic_enum

CXXFLAGS = -std=c++20 -Wall -Werror -Wno-unused-variable -Wno-unused-private-field -O0 -g -fsanitize=address,undefined -isystem$(MAGIC_ENUM_DIR)
TEST_CXXFLAGS = $(CXXFLAGS) -isystem$(DOCTEST_DIR) -I$(SOURCE_DIR)

LOX_FILES := $(shell find $(SOURCE_DIR)/lox -type f -name "*.cpp")
LOX_OBJS := $(LOX_FILES:$(SOURCE_DIR)/lox/%.cpp=$(OBJ_DIR)/lox/%.o)

TEST_FILES := $(shell find ./test -type f -name "*.cpp")
TEST_EXECS := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/test/%)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(BIN_DIR)/test/%: $(TEST_DIR)/%.cpp | $(BIN_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(TEST_CXXFLAGS) $< $(LOX_OBJS) -o $@ $(SRC_OBJS)


main: $(LOX_OBJS)
	$(CXX) $(CXXFLAGS) $(SOURCE_DIR)/main.cpp $(LOX_OBJS) -o $(BIN_DIR)/cpplox

tests: $(LOX_OBJS) $(TEST_EXECS) $(TEST_TARGET_DATA)

clean:
	rm -rf bin/*
	rm -rf obj/*

.PHONY: all
all: main tests
.DEFAULT_GOAL := tests