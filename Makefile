SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

main: $(OBJS)
	g++ $(OBJS)  -o main 

$(OBJS) : $(SRCS)
	g++ -c $(SRCS) 


