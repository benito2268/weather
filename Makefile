#a simple makefile for compiling the game
CC = g++
CCFLAGS_D = -Wall -g -O0
CCFLAGS_S = -Wall -Wpedantic -g -O3 -ffast-math -msse2 -mfpmath=sse
INCLUDE = -I"include/"
LDFLAGS = -Llib -lglfw3 -lopengl32 -lgdi32 -llibstdc++
BIN = bin
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRCFILES:.cpp=.o)
TARGET = weather.exe

all: $(TARGET)

.PHONY: clean

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) bin/glad.o $(LDFLAGS)
	mv *.o bin/

%.o : %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS_D) $(INCLUDE)

r:
	./weather.exe

clean:
	rm $(OBJFILES) $(TARGET)
