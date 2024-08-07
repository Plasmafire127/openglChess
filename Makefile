CC = gcc
CXX = g++

COMPILE_FLAGS = -Wall -ggdb -11
LINK_FLAGS = -lglfw3 -lopengl32 -lglu32 -lgdi32

glfw = /Users/jake/Desktop/opengl/glfw-3.4
glfw_inc = $(glfw)/include
glfw_lib = $(glfw)/lib64

glad = /Users/jake/Desktop/opengl/glad
glad_inc = $(glad)/include

INCLUDES = -I$(glfw_inc) -I$(glad_inc)
LIBRARIES = -L$(glfw_lib)

cpp_files = main.cpp
objects = $(cpp_files:.cpp=.o)
headers =

all: main.exe

main.exe: $(objects) glad.o
	$(CXX) $(LIBRARIES) -o main.exe $(objects) glad.o $(LINK_FLAGS)

$(objects): %.o: %.cpp $(headers) makefile
	$(CXX) $(COMPILE_FLAGS) $(INCLUDES) -c -o $@ $<

glad.o: glad.c
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c -o glad.o glad.c