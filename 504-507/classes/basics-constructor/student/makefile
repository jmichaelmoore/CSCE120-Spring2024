CXX = g++-13

CXXFLAGS = -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors -g

TARGET = student

SRCS = Student.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
