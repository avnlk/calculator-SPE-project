CXX = g++
CXXFLAGS = -std=c++17 -Wall
GTEST_DIR = lib/googletest/googletest
GTEST_INC = -I$(GTEST_DIR)/include
GTEST_LIB = $(GTEST_DIR)/libgtest.a
LDFLAGS = -pthread

all: calculator

calculator: main.o calculator.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $<

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $<

test: test_runner
	./test_runner

test_runner: tests/test_calculator.o calculator.o gtest_main.o $(GTEST_LIB)
	$(CXX) $(CXXFLAGS) $(GTEST_INC) $^ -o $@ $(LDFLAGS)

tests/test_calculator.o: tests/test_calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) $(GTEST_INC) -c $< -o $@

gtest_main.o: $(GTEST_DIR)/src/gtest_main.cc
	$(CXX) $(CXXFLAGS) $(GTEST_INC) -c $< -o $@

$(GTEST_LIB):
	$(CXX) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv $(GTEST_LIB) gtest-all.o
	rm gtest-all.o

clean:
	rm -f calculator test_runner *.o gtest_main.o
