# Makefile for building the project.
# Expects variables:
# MODE         "debug" or "release".
# NAME         Name of the output executable.
# SOURCE_DIR   Directory where source files and headers are located.

# Choose C++ standard and compiler.
CXX := g++
CPP := true
ifeq ($(CPP),true)
    CXXFLAGS := -std=c++11
else
    CXXFLAGS := -std=c++11
endif

# Common flags.
CXXFLAGS += -Wall -Wextra -Werror

# Mode configuration.
ifeq ($(MODE),debug)
    CXXFLAGS += -O0 -DDEBUG -g
    BUILD_DIR := build/debug
else
    CXXFLAGS += -O3 -flto
    BUILD_DIR := build/release
endif

# Files.
HEADERS := $(wildcard $(SOURCE_DIR)/*.h)
SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

# Targets ---------------------------------------------------------------------

# Link the executable.
$(BUILD_DIR)/$(NAME): $(OBJECTS)
	@ echo "Linking $@"
	@ mkdir -p $(BUILD_DIR)
	@ $(CXX) $(CXXFLAGS) $^ -o $@

# Compile object files.
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(HEADERS)
	@ echo "Compiling $<"
	@ mkdir -p $(BUILD_DIR)
	@ $(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	@ echo "Cleaning up..."
	@ rm -rf $(BUILD_DIR)

.PHONY: all
all: $(BUILD_DIR)/$(NAME)

