SRC_FILES = main.cpp Application.cpp CLI/*.cpp CLI/Parsing/*.cpp CLI/Command_Execution/*.cpp Document/*.cpp Editor/*.cpp Visualization/*.cpp Visualization/Shapes/*.cpp
all: slide

slide: $(SRC_FILES)
	g++ $^ -o $@  