SRC_FILES = CLI/*.cpp CLI/Input_Manipulation/*.cpp CLI/Command_Execution/*.cpp
all: slide

slide: $(SRC_FILES)
	g++ $^ -o $@  
