########################################################
# Author     : Gary M. Zoppetti
# Description: Sample Makefile for CMSC 476
########################################################

########################################################
# Variable definitions
########################################################
# C++ compiler
CXX := g++
#CXX := clang++
#CXX := mpicxx

# C++ compiler flags
# Use this first configuration for debugging
#CXXFLAGS := -Wall -Werror -std=c++26 -ggdb
# Use the following configuration for release
CXXFLAGS := -O3 -Wall -Werror -std=c++26 -fopenmp

# Linker: for C++ should be $(CXX)
LINK := $(CXX)

# Linker flags. Usually none.
LDFLAGS := 

# Library paths, prefaced with "-L". Usually none.
LDPATHS := 

# Libraries we're using, prefaced with "-l".
LDLIBS := -lblas64 -lgomp

# Executable name. Needs to be the basename of your driver
#   file. I.e., your driver must be named $(EXEC).cc
EXEC := MatrixMult

#############################################################
# Rules
#   Rules have the form
#   target : prerequisites
#   	  recipe
#############################################################

# Add additional object files if you're using more than one
#   source file.
$(EXEC) : $(EXEC).o
	$(LINK) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Add rules for each object file.
# No recipes are typically needed.
MatrixMult.o : MatrixMult.cc Matrix.hpp Blas.hpp

#############################################################

.PHONY : clean
clean :
	@$(RM) $(EXEC) a.out core
	@$(RM) *.o *.d *~
	@echo "Cleanup complete."

#############################################################