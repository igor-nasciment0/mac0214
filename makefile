CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic

.PHONY: all clean FORCE

all:
	@echo "Usage: make path/to/file[.cpp]"
	@echo "Example: make semana1/concert-tickets"
	@echo "         make semana1/concert-tickets.cpp"

BUILD_GOALS := $(filter-out all clean FORCE,$(MAKECMDGOALS))

define COMPILE_RULE
$(1): FORCE
	$(CXX) $(CXXFLAGS) $(patsubst %.cpp,%,$(1)).cpp -o $(basename $(notdir $(1)))
endef

$(foreach goal,$(BUILD_GOALS),$(eval $(call COMPILE_RULE,$(goal))))

clean:
	rm -f $(basename $(notdir $(wildcard */*.cpp)))