###########################
# Littleray build suite   #
# xml library build chain #
###########################

DIRS=.
FILES=$(wildcard $(addsuffix /*.cpp, $(DIRS)))
OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(notdir $(FILES))))
INCLUDES=$(addprefix -I, $(DIRS))
DEPS=$(patsubst %.o,%.d,$(OBJS))

CC=g++
AR=ar
CFLAGS=-Wall -Wextra -Werror
OPT_CFLAGS=-O2

QUIET_CC=@echo -e "\tCC\t $@"; $(CC)
QUIET_AR=@echo -e "\tAR\t $@"; $(AR)

vpath %.cpp $(DIRS)

all: build/libxml.a

build:
	@echo "Creating build directory."
	@mkdir build

build/%.d: %.cpp build
	@$(CC) -MM $< $(INCLUDES) > $@

# Include dependancy file for .h modifications
-include $(DEPS)

build/%.o: %.cpp
	$(QUIET_CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

build/libxml.a: $(OBJS)
	$(QUIET_AR) -cvq $@ $^

clean:
	@echo "Cleaning build directory."
	@rm -rf build/

