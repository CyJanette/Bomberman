CC := g++
CFLAGS := -Wall -I/mingw64/include/SDL2 -D_REENTRANT
LDFLAGS := -L/mingw64/lib -lmingw32 -lSDL2main -lSDL2

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := bomberman

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
