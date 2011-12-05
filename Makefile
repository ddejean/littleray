#########################
# Littleray build suite #
#########################

DIRS=. ./Antialiaser ./Materials ./Objects ./Lights
FILES=$(wildcard $(addsuffix /*.cpp, $(DIRS)))
OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(notdir $(FILES))))
INCLUDES=$(addprefix -I, $(DIRS))
DEPS=$(patsubst %.o,%.d,$(OBJS))

CC=g++
CFLAGS=-Wall -Wextra -Werror
OPT_CFLAGS=-O2
LDFLAGS=-lm -lSDL -Lbuild/lib -lxml

QUIET_CC=@echo -e "\tCC\t $@"; $(CC)
QUIET_MKDIR=@echo -e "\tMKDIR\t $@"; mkdir

vpath %.cpp $(DIRS)

all: opt tests

tests: opt
	@make -C tests/

# Optimized build configuration
opt: CFLAGS+=$(OPT_CFLAGS)
opt: xml build/littleray

# Coverage build
coverage: CFLAGS+=-fprofile-arcs -ftest-coverage
coverage: LDFLAGS+=-lgcov
coverage: xml build/littleray
	lcov --directory build/ --zerocounter
	build/littleray scene.xml
	lcov --base-directory "`pwd`/" --directory build/ --capture --output-file build/draft.info
	lcov -r build/draft.info "*.h" -r build/draft.info "*usr*include*" -r build/draft.info "xml/*" --output-file build/littleray.info
	genhtml build/littleray.info --output-directory build/coverage/

# Build libraries
xml: build build/lib
	make -C xml/
	@echo -e "\tCP\t xml/build/libxml.a build/lib/"; cp xml/build/libxml.a build/lib/

# Build directories
build:
	@echo "Creating build directory."
	$(QUIET_MKDIR) $@

build/lib: build
	$(QUIET_MKDIR) -p $@

build/%.d: %.cpp build
	@$(CC) -MM $< $(INCLUDES) > $@

# Include dependancy file for .h modifications
-include $(DEPS)

build/%.o: %.cpp
	$(QUIET_CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

build/littleray: $(OBJS)
	$(QUIET_CC) -o build/littleray $(OBJS) $(LDFLAGS)

clean:
	@echo "Cleaning build directory."
	@rm -rf build/
	@make -C xml/ clean
	@make -C tests/ clean
	

.PHONY: clean coverage
