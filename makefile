# Compiler and flags
CXX = g++
CXXFLAGS = -I src -std=c++20

# Source files
SRCS = $(wildcard src/*.cpp)

# Output binary
TARGET = build/MiniShell

# Default rule
all: $(TARGET)

# Link object files into the final binary
$(TARGET): $(SRCS)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
