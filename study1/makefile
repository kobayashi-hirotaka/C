prog = 
TARGET = study1.exe
BIN = bin
OBJ = obj
BINDIR = ./$(BIN)
OBJDIR = ./$(OBJ)
SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
CC = gcc
CFLAGS = -Wall -O2 -finput-charset=CP932 -fexec-charset=CP932

$(BINDIR)/$(TARGET): $(OBJECTS)
	if not exist $(BIN) mkdir $(BIN)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c
	if not exist $(OBJ) mkdir $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	cmd.exe /C del $(OBJECTS) $(BINDIR)/$(TARGET)

run:
	$(BINDIR)/$(TARGET) ${prog}
