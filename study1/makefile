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

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BINDIR):
	mkdir $(BIN)

$(OBJDIR):
	mkdir $(OBJ)

run:
	$(BINDIR)/$(TARGET) ${prog}
