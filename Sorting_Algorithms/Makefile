CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS =

SRC = /Users/riddhinarkar/Documents/GitHub/data-structures-and-algorithms/Sorting_Algorithms/
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
