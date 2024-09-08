SRC_FILES = main.cpp slide.cpp parser.cpp
TARGET = slide

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	g++ $(SRC_FILES) -o $(TARGET)

clean:
	rm -f $(TARGET)
