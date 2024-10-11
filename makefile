SRC_FILES = CLI/*.cpp
all: slide

slide: $(SRC_FILES)
	g++ $^ -o $@  
