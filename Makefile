# Define the compiler and its flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 $(pkg-config --cflags gtk4)
CXEFKAGS = $(pkg-config --libs gtk4)

# $(pkg-config --cflags gtk4) -o hello-world-gtk hello-world-gtk.c $(pkg-config --libs gtk4)

# Define the directories for the source code, object files, and executable
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Define the sources and objects
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

EXENAME = MarchingTets

# Define the target executable
TARGET = $(BINDIR)/$(EXENAME)

# Define the dependencies for each object file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(CXEFKAGS)

# Define the target rule
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Define a clean rule to remove all object files and the executable
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

run:
	./$(TARGET)

