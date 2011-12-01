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

QUIET_CC=@echo -e "\tCC\t $@"; $(CC)

vpath %.cpp $(DIRS)

all: build/littleray

coverage: CFLAGS+=-fprofile-arcs -ftest-coverage
coverage: LDFLAGS+=-lgcov
coverage: build/littleray
	lcov --directory build/ --zerocounter
	build/littleray scene.xml
	lcov --base-directory "`pwd`/" --directory build/ --capture --output-file build/draft.info
	lcov -r build/draft.info "*.h" -r build/draft.info "*usr*include*" -r build/draft.info "xml/*" --output-file build/littleray.info
	genhtml build/littleray.info --output-directory build/coverage/

build:
	@echo "Creating build directory."
	@mkdir build

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
	

.PHONY: clean coverage
