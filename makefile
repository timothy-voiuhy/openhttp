# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SOURCES = core.c datatypes.c dict.c dns_resolve.c http.c httpthreads.c logging.c request.c set.c server.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = openhttp

# Default rule
all: $(TARGET)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the target executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)
