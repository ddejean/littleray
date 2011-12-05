###########################
# Littleray build suite   #
# xml library build chain #
###########################

DIRS=. .. ../Antialiasers ../Objects ../Materials ../Lights ../xml
EXCLUDES= ../raytracer.cpp ../Scene.cpp ../SceneFactory.cpp ../Display.cpp ../Factories/SceneFactory.cpp
FILES=$(filter-out $(EXCLUDES), $(wildcard $(addsuffix /*.cpp, $(DIRS))))
OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(notdir $(FILES))))
INCLUDES=$(addprefix -I, $(DIRS))
DEPS=$(patsubst %.o,%.d,$(OBJS))

CC=g++
AR=ar
CFLAGS=-Wall -Wextra -Werror

OPT_CFLAGS=-O2

QUIET_CC=@echo -e "\tCC\t $@"; $(CC)

vpath %.cpp $(DIRS)

all: test

build:
	@echo "Creating build directory."
	@mkdir build

build/%.d: %.cpp build
	@$(CC) -MM $< $(INCLUDES) > $@

# Include dependancy file for .h modifications
-include $(DEPS)

tests.cpp:
	tools/cxxtestgen.pl -o tests.cpp --error-printer *.h

build/%.o: %.cpp
	$(QUIET_CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

build/tests: build/tests.o $(OBJS)
	$(QUIET_CC) -o $@ $^ $(LDFLAGS)

test: build/tests
	@echo "Littleray tests suite :"
	@build/tests

clean:
	@echo "Cleaning build directory."
	@rm -rf build/
	@rm -f tests.cpp

