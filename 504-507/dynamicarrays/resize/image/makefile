#Below CXX for M1 Mac when g++ installed via Homebrew
#Otherwise things get weird

CXX = g++-13

CXXFLAGS = -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors -g

TARGET = resize

SRCS = functions.cpp image.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

