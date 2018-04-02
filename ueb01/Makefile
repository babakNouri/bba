CC = g++
CPPFLAGS = -g -W -Wall -Werror -Wextra --std=c++11
SRCS = $(shell find . -type f -name '*.cpp')
HEDS = $(shell find . -type f -name '*.hpp')
OBJS = $(SRCS:%.cpp=%.o)
PROG = bba

OPENCV = `pkg-config opencv --cflags --libs`
LIBS += $(OPENCV)

all: doxygen.log $(PROG)

.PHONY: clean all doc

$(PROG): .depend $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS) $(LIBS)

clean: 
	rm -f $(PROG)
	rm -f $(OBJS)
	rm -f .depend
	rm -f doxygen.log

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

# Compute header file dependencies 
.depend : $(SRCS)
	$(CC) $(CPPFLAGS) -MM $^ > .depend

doc: doxygen.log
	

# check for undocumented Functions
# or generate Documentation
doxygen.log : Doxyfile $(SRCS)
	! doxygen 2>&1 | tee doxygen.log | grep "is not documented"

# Respect header file dependencies
include .depend
