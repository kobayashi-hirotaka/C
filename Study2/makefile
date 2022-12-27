prog = 
TARGET = study2.exe
BIN = bin
DEP = dep
OBJ = obj
BINDIR = ./$(BIN)
DEPDIR = ./$(DEP)
OBJDIR = ./$(OBJ)
SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
DEPENDS = $(addprefix $(DEPDIR)/, $(SOURCES:.c=.d))
CC = gcc
CFLAGS = -Wall -O2 -finput-charset=CP932 -fexec-charset=CP932
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

# DEPフォルダが無いときエラーを無視するための空ルール
$(DEPENDS):

include $(wildcard $(DEPENDS))

$(BINDIR):
	if not exist $(BIN) mkdir $(BIN)

$(DEPDIR):
	if not exist $(DEP) mkdir $(DEP)

$(OBJDIR):
	if not exist $(OBJ) mkdir $(OBJ)

run:
	$(BINDIR)/$(TARGET) ${prog}
