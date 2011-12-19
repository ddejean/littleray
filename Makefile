#########################
# Littleray build suite #
#########################

### Makefile general parameters
SHELL=/bin/bash

### Parameters for a Makefile a little bit generic
LIB_NAMES=Antialiasers Objects Lights Materials Xml Maths Displays
LIB_DIRS=$(addprefix ./, $(LIB_NAMES))
LIBS=$(addprefix build/lib, $(addsuffix .a, $(LIB_NAMES)))

INCLUDES_DIRS=.
INCLUDES=$(addprefix -I, $(INCLUDES_DIRS))

### Tools
CC=g++
AR=ar
MKDIR=mkdir
CXXTESTGEN=tests/tools/cxxtestgen.pl

QCC=@echo -e "\tCC\t " $@; $(CC)
QMKDIR=@echo -e "\tMKDIR\t " $@; $(MKDIR)
QAR=@echo -e "\tAR\t " $@; $(AR)
QCXXTESTGEN=@echo -e "\tTESTGEN\t " $@; $(CXXTESTGEN)

### Options
CFLAGS=-Wall -Wextra -Werror
OPTFLAGS=-Ofast
LDFLAGS=-lSDL -Lbuild/ $(addprefix -l, $(LIB_NAMES))
ARFLAGS=-cq


### Main targets
all: CFLAGS+=$(OPTFLAGS)
all: littleray test

coverage: CFLAGS+=-fprofile-arcs -ftest-coverage
coverage: LDFLAGS+=-lgcov
coverage: littleray test build/coverage
	lcov --directory build/ --zerocounter
	build/littleray scene.xml
	build/tests/runtests
	lcov --base-directory "`pwd`/" --directory build/ --capture --output-file build/draft.info
	lcov -r build/draft.info "*.h" \
		 -r build/draft.info "*usr*include*" \
		 -r build/draft.info "Xml/*" \
		 -r build/draft.info "tests/cxxtest/*" \
		 --output-file build/littleray.info
	genhtml build/littleray.info --output-directory build/coverage/

profiling: CFLAGS+=-pg
profiling: LDFLAGS+=-pg
profiling: littleray build/profiling
	build/littleray scene.xml
	mv gmon.out build/profiling
	cd build/profiling; gprof ../littleray > profile.txt
	
#######################################
##### Dependency files management #####
#######################################

DEPS_WILDCARD=*.cpp  $(addsuffix /*.cpp, $(LIB_NAMES))
DEPS_CPP=$(wildcard $(DEPS_WILDCARD))
DEPS=$(addprefix build/, $(patsubst %.cpp, %.d, $(DEPS_CPP)))

build/%.d: %.cpp build
	@$(CC) -MM $< $(INCLUDES) > $@

build/Antialiasers/%.d: Antialiasers/%.cpp build/Antialiasers
	@$(CC) -MM $< $(INCLUDES) > $@

build/Objects/%.d: Objects/%.cpp build/Objects
	@$(CC) -MM $< $(INCLUDES) > $@

build/Lights/%.d: Lights/%.cpp build/Lights
	@$(CC) -MM $< $(INCLUDES) > $@

build/Materials/%.d: Materials/%.cpp build/Materials
	@$(CC) -MM $< $(INCLUDES) > $@

build/Xml/%.d: Xml/%.cpp build/Xml
	@$(CC) -MM $< $(INCLUDES) > $@

build/Maths/%.d: Maths/%.cpp build/Maths
	@$(CC) -MM $< $(INCLUDES) > $@
	
build/Displays/%.d: Displays/%.cpp build/Displays
	@$(CC) -MM $< $(INCLUDES) > $@

build/tests/%.d: tests/%.cpp build/tests
	@$(CC) -MM $< $(INCLUDES) > $@

-include $(DEPS)


###########################
##### Littleray build #####
###########################

FILES=$(wildcard *.cpp)
OBJS=$(addprefix build/, $(patsubst %.cpp, %.o, $(FILES)))

littleray: build/littleray

build/littleray: $(OBJS) $(LIBS)
	$(QCC) -o build/littleray $(OBJS) $(LDFLAGS)

build/%.o: %.cpp
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)


#################################
##### Test chain management #####
#################################

test: INCLUDES+=-Itests/
test: build/tests/runtests
	@echo "Running tests suites ..."
	@build/tests/runtests

TEST_DIRS=tests
TEST_FILES=tests/runtests.cpp $(filter-out tests/runtests.cpp, $(wildcard $(addsuffix /*.cpp, $(TEST_DIRS))))
TEST_OBJS=$(addprefix build/, $(patsubst %.cpp, %.o, $(TEST_FILES)))

build/tests/runtests: build/tests $(TEST_OBJS) $(LIBS)
	$(QCC) -o $@ $(TEST_OBJS) $(LDFLAGS)

build/tests/%.o: tests/%.cpp
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

tests/runtests.cpp: 
	$(QCXXTESTGEN) -o $@ --error-printer tests/*.h

############################
##### Archive creation #####
############################

ANTIALIASERS_FILES=$(wildcard Antialiasers/*.cpp)
ANTIALIASERS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(ANTIALIASERS_FILES)))
build/libAntialiasers.a: $(ANTIALIASERS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

OBJECTS_FILES=$(wildcard Objects/*.cpp)
OBJECTS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(OBJECTS_FILES)))
build/libObjects.a: $(OBJECTS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

MATERIALS_FILES=$(wildcard Materials/*.cpp)
MATERIALS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(MATERIALS_FILES)))
build/libMaterials.a: $(MATERIALS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

XML_FILES=$(wildcard Xml/*.cpp)
XML_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(XML_FILES)))
build/libXml.a: $(XML_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

LIGHTS_FILES=$(wildcard Lights/*.cpp)
LIGHTS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(LIGHTS_FILES)))
build/libLights.a: $(LIGHTS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

MATHS_FILES=$(wildcard Maths/*.cpp)
MATHS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(MATHS_FILES)))
build/libMaths.a: $(MATHS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

DISPLAYS_FILES=$(wildcard Displays/*.cpp)
DISPLAYS_OBJS=$(patsubst %.cpp, %.o, $(addprefix build/, $(DISPLAYS_FILES)))
build/libDisplays.a: $(DISPLAYS_OBJS)
	$(QAR) $(ARFLAGS) $@ $^

###################################
##### Libraries objects build #####
###################################

build/Antialiasers/%.o: Antialiasers/%.cpp build/Antialiasers 
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)
	
build/Objects/%.o: Objects/%.cpp build/Objects
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)
	
build/Materials/%.o: Materials/%.cpp build/Materials
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)
	
build/Xml/%.o: Xml/%.cpp build/Xml
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

build/Lights/%.o: Lights/%.cpp build/Lights
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

build/Maths/%.o: Maths/%.cpp build/Maths
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)
	
build/Displays/%.o: Displays/%.cpp build/Displays
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)


########################################
##### Build directories management #####
########################################

BUILD_DIRS=build build/coverage build/profiling \
		   $(addprefix build/, $(TEST_DIRS)) \
		   $(addprefix build/, $(LIB_NAMES))

$(BUILD_DIRS):
	$(QMKDIR) -p $@


#########################
##### Clean targets #####
#########################

clean:
	@echo "Removing generated files."
	@echo -e "\tRM\t build/"
	@rm -rf build/
	@echo -e "\tRM\t tests/runtests.cpp"
	@rm -f tests/runtests.cpp

.PHONY: clean 

