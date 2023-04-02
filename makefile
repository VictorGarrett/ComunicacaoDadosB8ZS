
# Name of the project
PROJECT_NAME=comdados.exe

# .cpp Files
CPP_SOURCE=$(wildcard ./source/*.cpp) $(wildcard ./source/core/*.cpp) $(wildcard ./source/render/*.cpp)

# .h Files
H_SOURCE=$(wildcard ./include/*.h) $(wildcard ./source/core/*.h)  $(wildcard ./source/render/*.h)

# Object Files
OBJ=$(patsubst %source/%.cpp,%objects/%.o,$(wildcard source/*.cpp)) $(patsubst %source/%.cpp,%objects/%.o,$(wildcard source/render/*.cpp))  $(patsubst %source/%.cpp,%objects/%.o,$(wildcard source/core/*.cpp))


# Compiler
CC=g++

# Flags for Compiler
CC_FLAGS=-c -I ./include/ -I ./include/core/ -I ./include/render/


# Linker Flags
LINKER_FLAGS=-Wall -Lsfml-bin/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


# Compilation and linking
all: folders ./bin/$(PROJECT_NAME)

./bin/$(PROJECT_NAME):	$(OBJ)
				@ echo 'Bulding binary using G++ linker: $@'
				$(CC) -o $@ $^ $(LINKER_FLAGS)
				@ echo 'Finished buiding binary: $@'
				@ echo ' '

./objects/%.o: ./source/%.cpp ./include/%.h ./include/core/%.h ./include/render/%.h
				@ echo 'Building target using G++ compiler: $<'
				$(CC) -o $@ $< $(CC_FLAGS)
				@ echo ' '



./objects/main.o: ./source/main.cpp $(H_SOURCE)
		    @ echo 'Building target using G++ compiler: $<'
		    $(CC) -o $@ $< $(CC_FLAGS)
		    @ echo ' '

folders:
			@mkdir -p objects bin

clean:
		    @ rd /S /Q objects
			@ del .\bin\$(PROJECT_NAME)