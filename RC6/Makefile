# Configurations
PROJECT	=	run test_rc6
CXX =	g++
FLAGS	=	-g
WFLAGS	=	-Wall -Wextra
OPTIMIZATION =	-O2
OBJ	=	RC6.o
HEADER	=	RC6.hpp
SRC	=	RC6.cpp
DRIVER	=	RC6_main.cpp

# Build
all:		$(PROJECT)

run:	$(OBJ) $(DRIVER)
		$(CXX) $(FLAGS) $^ -o $@

test_rc6: test_rc6.o RC6.o
		$(CXX) $(FLAGS) -o $@ $^

warning-enbl:	$(OBJ) $(DRIVER)
		$(CXX) $(FLAGS) $(WFLAGS) $^ -o $@

optimizations:	$(OBJ) $(DRIVER)
		$(CXX) $(FLAGS) $(OPTIMIZATION) $^ -o $@

# Build object files
%.o:		%.c
		$(CXX) $(FLAGS) -c $^

# Clean up
clean:
		rm -f *.o *~ *.a $(PROJECT) warning-enbl optimizations

# tar relevent files
tar:		clean
		cd ..; \
		tar -cvf RC6_enc.tar RC6

rm_tar:
		cd ..; \
		rm RC6_enc.tar