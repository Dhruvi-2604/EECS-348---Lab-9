

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

# Target executable name
TARGET = Lab9

# Source files
SRC = Lab9.cpp

# Default rule
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
