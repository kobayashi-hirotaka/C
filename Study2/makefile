prog = 
TARGET = ./bin/study2.exe
OBJDIR = ./obj
DEPDIR = ./dep
SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
DEPENDS = $(addprefix $(DEPDIR)/, $(SOURCES:.c=.d))
CC = gcc
CFLAGS = -Wall -O2 -finput-charset=CP932 -fexec-charset=CP932
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(DEPENDS):

include $(wildcard $(DEPENDS))

run:
	$(TARGET) ${prog}
