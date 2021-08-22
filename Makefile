CC = gcc
SRC_DIR = ./src
INC_DIR = ./include
BUILD_DIR = ./build
OUT_DIR = ./bin
EXE_FILE = neuralnetwork
#OBJECTS = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))
vpath %.c $(SRC_DIR):$(SRC_DIR)/NeuralNetwork

$(BUILD_DIR)/%.o : %.c 
	$(CC) -c -I $(INC_DIR) -o $@ $^

$(OUT_DIR)/% : $(wildcard $(BUILD_DIR)/*.o)
	$(CC) -g -o $@ $^

.PHONY : run

run : 
	$(OUT_DIR)/$(EXE_FILE)
