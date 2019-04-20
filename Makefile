CXX = g++

outdir = ./bin

mainobj = dlist.o test.o

exeobj = test

CXXFLAGS = -I./include

VPATH = .:./include:./util:./test

$(exeobj): $(mainobj)
	$(CXX) -o $(outdir)/$(exeobj) $(CXXFLAGS) $(mainobj)
	rm -f *.o

$(mainobj): %.o:%.cpp
	$(CXX) -m64 -Wall -g $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(outdir)/$(exeobj)
