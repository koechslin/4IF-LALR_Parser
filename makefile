CC = g++
CFLAGS = -g -ansi -pedantic -Wall -std=c++11

MAIN = parser
SRCS = *.cpp
OBJS = $(SRCS:.cpp=.o)

$(MAIN) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $^

.PHONY : launch

launch : $(MAIN)
	@./$(MAIN)

.PHONY : clean

clean :
	rm -f $(MAIN) *.o core