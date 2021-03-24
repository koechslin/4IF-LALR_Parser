CC = g++
CFLAGS = -g -ansi -pedantic -Wall -std=c++11

MAIN = parser
SRCS = *.cpp
OBJS = $(SRCS:.cpp=.o)

$(MAIN) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $^

help: $(MAIN)
	@./$(MAIN) -h

.PHONY : clean

clean :
	@rm -f $(MAIN) *.o core