#########################
# Littleray build suite #
#########################

LIB_NAMES=Antialiasers Objects Lights Materials Xml Maths
LIB_DIRS=$(addprefix ./, $(LIB_NAMES))

INCLUDES_DIRS=.
INCLUDES=$(addprefix -I, $(INCLUDES_DIRS))


### Tools
CC=g++
AR=ar
MKDIR=mkdir

QCC=@echo -e "\tCC\t " $@; $(CC)
QMKDIR=@echo -e "\tMKDIR\t " $@; $(MKDIR)
QAR=@echo -e "\tAR\t " $@; $(AR)

### Options
CFLAGS=-Wall -Wextra -Werror
OPTFLAGS=-O2
LDFLAGS=-lSDL -Lbuild/ $(addprefix -l, $(LIB_NAMES))
ARFLAGS=-cq


# Main targets
all: littleray


#######################################
##### Dependency files management #####
#######################################

DEPS_WILDCARD=*.cpp  $(addsuffix /*.cpp, $(LIB_NAMES))
DEPS_CPP=$(wildcard $(DEPS_WILDCARD))
DEPS=$(addprefix build/, $(patsubst %.cpp, %.d, $(DEPS_CPP)))

build/%.d: %.cpp build
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Antialiasers/%.d: Antialiasers/%.cpp build/Antialiasers
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Objects/%.d: Objects/%.cpp build/Objects
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Lights/%.d: Lights/%.cpp build/Lights
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Materials/%.d: Materials/%.cpp build/Materials
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Xml/%.d: Xml/%.cpp build/Xml
	@$(QCC) -MM $< $(INCLUDES) > $@

build/Maths/%.d: Maths/%.cpp build/Maths
	@$(QCC) -MM $< $(INCLUDES) > $@

-include $(DEPS)


###########################
##### Littleray build #####
###########################

FILES=$(wildcard *.cpp)
OBJS=$(addprefix build/, $(patsubst %.cpp, %.o, $(FILES)))
LIBS=$(addprefix build/lib, $(addsuffix .a, $(LIB_NAMES)))

littleray: $(OBJS) $(LIBS)
	$(QCC) -o build/littleray $(OBJS) $(LDFLAGS)

build/%.o: %.cpp
	$(QCC) -c $< -o $@ $(CFLAGS) $(INCLUDES)


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


########################################
##### Build directories management #####
########################################

BUILD_DIRS=build $(addprefix build/, $(LIB_NAMES))

$(BUILD_DIRS):
	$(QMKDIR) -p $@


#########################
##### Clean targets #####
#########################

clean:
	@echo "Removing build directory."
	@echo -e "\tRM\t build/"
	@rm -rf build/

.PHONY: clean 

