CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
TARGET = programm.exe
SOURCES = main.cpp src/core/Duration.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all run

.PHONY: all clean run