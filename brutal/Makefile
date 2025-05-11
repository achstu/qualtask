CXXFLAGS = $(shell cat compile_flags.txt)

default: sol

%: %.cpp
	g++ $(CXXFLAGS) -O3 $< -o $@


%_fast: %.cpp
	g++ $(CXXFLAGS) -DLOCAL -O2 $< -o $@

%_debug: %.cpp
	g++ $(CXXFLAGS) -g $< -o $@
