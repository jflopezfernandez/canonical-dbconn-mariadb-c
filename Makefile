
vpath %.c src

CC       := gcc
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic
CPPFLAGS := -I include $(shell mariadb_config --include)
LDFLAGS  := $(shell mariadb_config --libs)
LIBS     := $(shell mariadb_config --libs_sys)

RM       := rm -f

OBJS     := $(patsubst %.c,%.o,$(notdir $(wildcard src/*c)))

TARGET   := connect

all: $(TARGET)
	@echo $(OBJS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
