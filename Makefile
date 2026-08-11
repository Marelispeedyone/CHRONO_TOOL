CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
TARGET = programm.exe
SOURCES = main.cpp src/core/Duration.cpp

UNIT_TEST_SRC = tests/unit/test_duration.cpp

UNIT_TEST_DEPS = src/core/Duration.cpp

test-unit:
	$(CXX) $(CXXFLAGS) -o tests/unit/test_duration.exe $(UNIT_TEST_SRC) $(UNIT_TEST_DEPS)
	./tests/unit/test_duration.exe

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all run

.PHONY: all clean run