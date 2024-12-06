# Compiler and flags
CXX = g++
CXXFLAGS = -Itypes -std=c++17

# Output directories
BIN_DIR = bin

# Source files and their corresponding binaries
DAY_1_PART_1_SRC = day_1/day_1_part_1.cpp
DAY_1_PART_1_BIN = $(BIN_DIR)/day_1_part_1

DAY_1_PART_2_SRC = day_1/day_1_part_2.cpp
DAY_1_PART_2_BIN = $(BIN_DIR)/day_1_part_2

DAY_2_SRC = day_2/day_2.cpp
DAY_2_BIN = $(BIN_DIR)/day_2

DAY_3_SRC = day_3/day_3.cpp
DAY_3_BIN = $(BIN_DIR)/day_3

# Default target
all: day_1 day_2 day_3

# Compile and run day_1
day_1: $(DAY_1_PART_1_BIN) $(DAY_1_PART_2_BIN)
	$(DAY_1_PART_1_BIN)
	$(DAY_1_PART_2_BIN)

$(DAY_1_PART_1_BIN): $(DAY_1_PART_1_SRC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(DAY_1_PART_2_BIN): $(DAY_1_PART_2_SRC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Compile and run day_2
day_2: $(DAY_2_BIN)
	$(DAY_2_BIN)

$(DAY_2_BIN): $(DAY_2_SRC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Compile and run day_3
day_3: $(DAY_3_BIN)
	$(DAY_3_BIN)

$(DAY_3_BIN): $(DAY_3_SRC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Compile and run day_1_part_1
day_1_part_1: $(DAY_1_PART_1_BIN)
	$(DAY_1_PART_1_BIN)

# Compile and run day_1_part_2
day_1_part_2: $(DAY_1_PART_2_BIN)
	$(DAY_1_PART_2_BIN)

# Clean build files
clean:
	rm -rf $(BIN_DIR)

