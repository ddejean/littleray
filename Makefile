#########################
# Littleray build suite #
#########################

DIRS=. ./Antialiaser ./Factories ./Materials ./Objects ./xml
FILES=$(wildcard $(addsuffix /*.cpp, $(DIRS)))
OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(notdir $(FILES))))
INCLUDES=$(addprefix -I, $(DIRS))
DEPS=$(patsubst %.o,%.d,$(OBJS))

CC=g++
CFLAGS=-O2 -Wall -Wextra -Werror
LDFLAGS=-lm -lSDL

vpath %.cpp $(DIRS)

all: raytracer

build:
	@echo "Creating build directory"
	@mkdir build

build/%.d: %.cpp build
	@$(CC) -MM $< $(INCLUDES) > $@

# Include dependancy file for .h modifications
-include $(DEPS)

build/%.o: %.cpp
	$(CC) -c $< -o $@ $(INCLUDES)

raytracer: $(OBJS)
	$(CC) -o build/raytracer $(OBJS) $(LDFLAGS)

clean:
	rm -rf build/
	

.PHONY: clean
