CXXFLAGS = $(shell cat compile_flags.txt)

default: sol

%: %.cpp
	g++ $(CXXFLAGS) -DLOCAL $< -o $@


%_fast: %.cpp
	g++ $(CXXFLAGS) -O2 $< -o $@

%_debug: %.cpp
	g++ $(CXXFLAGS) -g $< -o $@
