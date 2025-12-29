CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude
SRC = main.cpp src/*.cpp
TARGET = a.out

all:
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

main:
	@$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	@rm -f $(TARGET)