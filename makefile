
ifeq ($(shell echo "check_os"),"check_os")
WINDOWS := yes
else
WINDOWS := no
endif



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
ifeq ($(WINDOWS), yes)
	@ if not exist "objects" mkdir objects	
else
	@mkdir -p objects bin
endif

clean:
ifeq ($(WINDOWS), yes)
	@ rd /S /Q objects
	@ del .\bin\$(PROJECT_NAME)
else
endif
		    