CXX = g++
CXXFLAGS = -g
INCS = -I./
OBJS = Addition.o Multiply.o

exampleApplication: ExampleApp.cpp $(OBSJS)
	$(CXX) $(CXXFLAGS) -o exampleApplication ExampleApp.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm *.o exampleApplication gmon.out
