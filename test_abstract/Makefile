CXX = g++
CXXFLAGS = -ggdb -Wall -pthread -std=c++17

SOURCE=test.cpp
MODULE=test_framework.cpp 
FUNCTION=insert_sort
FUNCTION_FILE=$(FUNCTION:=.cpp)
INPUT=input.txt

OBJMODULES=$(MODULE:.cpp=.o) $(FUNCTION_FILE:.cpp=.o)
	
ARG= $(FUNCTION) $(INPUT)
GOAL=$(SOURCE:.cpp=$*)

all: run 

run : $(GOAL)
	./$(GOAL) $(ARG)
$(GOAL): $(SOURCE) $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $(GOAL)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

#$(GOAL) : $(SOURCE)	$(CXX) $(CXXFLAGS) $^ -o $@

clean : 
	rm -f *.o

