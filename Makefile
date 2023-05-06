PROGRAM_NAME = MarchingTets
CMAKE_EXECUTOR = CMakeCompile.sh
BUILD_DIR = ./build
BIN_DIR = ./bin

all:
	make clean
	make cmake

run:
	./$(BIN_DIR)/$(PROGRAM_NAME)

cmake:
	./$(CMAKE_EXECUTOR)

clean:
	-rm -r $(BIN_DIR)/* 2>/dev/null
	-rm -rf $(BUILD_DIR) 2>/dev/null

