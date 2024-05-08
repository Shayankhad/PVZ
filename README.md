in this program we have 2 folders:
1) the src folder that contains cpp and hpp files
2) th buid folder that our make file puts the .o (object) files in it.
3) and there is a Makefile:
-----------------------------
CXX = g++ -g -std=c++11

SRCDIR = src
BUILDDIR = build

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

EXE = program.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PHONY: all clean

clean:
	rm -f $(OBJS) $(EXE)

-----------------------------

this make file make each cpp and hpp files in src(source) file to build file as a .o file and doesnt matter if we add or change cpp or hpp filles 
it still does it works.

