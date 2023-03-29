# Name of the project
PROJECT_NAME=comdados.exe

# .cpp Files
CPP_SOURCE=$(wildcard ./source/*.cpp)

# .h Files
H_SOURCE=$(wildcard ./include/*.h)

# Object Files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(CPP_SOURCE)))

# Compiler
CC=g++

# Flags for Compiler
CC_FLAGS=-c -I ./include/


# Linker Flags
LINKER_FLAGS=-Wall -Lsfml-bin/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


# Compilation and linking
all: folders ./bin/$(PROJECT_NAME)

./bin/$(PROJECT_NAME):	$(OBJ)
				@ echo 'Bulding binary using G++ linker: $@'
				$(CC) -o $@ $^ $(LINKER_FLAGS)
				@ echo 'Finished buiding binary: $@'
				@ echo ' '

./objects/%.o: ./source/%.cpp ./include/%.h
				@ echo 'Building target using G++ compiler: $<'
				$(CC) -o $@ $< $(CC_FLAGS)
				@ echo ' '

./objects/main.o: ./source/main.cpp $(H_SOURCE)
		    @ echo 'Building target using G++ compiler: $<'
		    $(CC) -o $@ $< $(CC_FLAGS)
		    @ echo ' '

folders:
			@ if not exist "objects" mkdir objects
			@ if not exist "bin" mkdir bin

clean:
		    @ rd /S /Q objects
			@ del .\bin\$(PROJECT_NAME)