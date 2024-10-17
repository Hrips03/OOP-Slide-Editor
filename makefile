SRC_FILES = main.cpp CLI/*.cpp CLI/Parsing/*.cpp CLI/Command_Execution/*.cpp
all: slide

slide: $(SRC_FILES)
	g++ $^ -o $@  
