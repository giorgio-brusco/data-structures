# compiler
CXX=g++
CXXFLAGS=-g -std=c++14  -Wall -Werror
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main -pthread
BIN=$(shell basename $(CURDIR))

# Define RECURSIVE_FIND to use the recursive implementation
# To compile with the recursive find function, use: make USE_RECURSIVE_FIND=1
ifdef USE_RECURSIVE_FIND
    CXXFLAGS += -DRECURSIVE_FIND
endif

# folders
SOURCEDIR=source
BUILDDIR=build
TESTDIR=tests

SRC=$(wildcard $(SOURCEDIR)/*.cpp)
TEST_SRC=$(wildcard $(TESTDIR)/*.cpp)
OBJ=$(SRC:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)
TEST_OBJ=$(TEST_SRC:$(TESTDIR)/%.cpp=$(BUILDDIR)/%.o)

all: $(BIN)

# Build tests
test: $(TEST_OBJ) $(OBJ)
	$(CXX) -o test_runner $^ $(LDFLAGS)
	./test_runner

# Compile source files
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR)
	rm -f test_runner