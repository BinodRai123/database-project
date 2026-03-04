# Variables
CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET  = mydb
SRC     = main.c
PREFIX  = /usr/local

# Default target
all: $(TARGET)

# Compile the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Execute the program
run: $(TARGET)
	./$(TARGET)

# Install the binary to the system
install: $(TARGET)
	install -D -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

# Remove the binary from the system
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all run install uninstall clean