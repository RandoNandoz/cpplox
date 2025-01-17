SOURCE_DIR = ./src
TEST_DIR = ./test
BIN_DIR = ./bin
OBJ_DIR = ./obj

CXXFLAGS = -O0 -g3 -fsanitize=address,undefined -std=c++20
TEST_CXXFLAGS = $(CXXFLAGS) -Itest/doctest -Isrc/

TEST_FILES := $(shell find ./test -type f ! -path "./test/doctest/*")
TEST_EXECS := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/test/%)

SRC_FILES := $(shell find ./src/ -type f ! -name "main.cpp")
SRC_OBJS := $(SRC_FILES:$(SOURCE_DIR)/%.cpp=$(OBJ_DIR)%)

$(OBJ_DIR)/%: $(SOURCE_DIR)/%.cpp | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(TEST_CXXFLAGS) $< -o $@

objs: $(info $(SRC_OBJS))

$(BIN_DIR)/test/%: $(TEST_DIR)/%.cpp | $(BIN_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(TEST_CXXFLAGS) $< -o $@ $(SRC_OBJS)




main:
	$(CXX) $(CXXFLAGS) $(SOURCE_DIR)/main.cpp -o $(BIN_DIR)/cpplox

tests: $(TEST_EXECS)

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all
all: main tests
.DEFAULT_GOAL := all