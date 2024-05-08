
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