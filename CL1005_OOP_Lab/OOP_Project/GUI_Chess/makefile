CFLAGS := -Wall -Wextra -std=c++17 -Wno-type-limits -Wno-sign-compare
CXX := g++
CMD := $(CXX) $(CFLAGS)

BUILD_DIR := bin
SRC_DIR := .
OBJ_DIR := obj

SRC_DIRS := $(SRC_DIR) board game utils ui/console
SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_FILES := $(wildcard tests/*.cpp)

ifeq ($(OS),Windows_NT) # ON WINDOWS

chess: $(OBJ_FILES)
	IF NOT EXIST $(BUILD_DIR) MKDIR $(BUILD_DIR) 
	$(CMD) $(OBJ_FILES) $(LIBS) -lws2_32 -o $(BUILD_DIR)/chess.exe

clean:
	IF EXIST $(BUILD_DIR) RMDIR /S /Q $(BUILD_DIR)
	IF EXIST $(OBJ_DIR) RMDIR /S /Q $(OBJ_DIR)

endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp

ifeq ($(OS),Windows_NT) 
	IF NOT EXIST $(OBJ_DIR) MKDIR $(OBJ_DIR)
endif

	$(CMD) -c $(CFLAGS) $< -o $@

format:
	clang-format -i $(SRC_FILES) $(wildcard */*.hpp)

all: chess

.PHONY: format all clean
