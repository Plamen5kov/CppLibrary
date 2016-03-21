CC    = g++
FLAGS        = -std=c++11 -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
CFLAGS       = -Wall -fPIC -fexceptions -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = libJniTest.so
SOURCES = $(shell echo com_gradle_test_JniTest.cpp)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)	
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)

