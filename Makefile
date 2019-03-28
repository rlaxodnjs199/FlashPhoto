CC=/usr/bin/g++
INCLUDE=-I ./ext/glui/include
CFLAGS=-W -Wall -Wextra -Weffc++ -std=c++11 $(INCLUDE)
LFLAGS=-lglut -lGL -lGLU -lglui -L./ext/glui/lib
COMPILE_COMMAND= $(CC) -c $(CFLAGS) ./src/$(notdir $(@:.o=.cc)) -o $@
CC_FILES := $(wildcard ./src/*.cc)
OBJ_FILES := $(addprefix ./out/,$(notdir $(CC_FILES:.cc=.o)))
LIBS = ./ext/glui/lib/libglui.a
make-depend-cc=$(CC) -MM -MF $3 -MP -MT $2 $(INCLUDE) $1
.PHONY: all clean module
all: ./bin/BrushWork

ifneq ($(MAKECMDGOALS),clean)
-include $(OBJ_FILES:.o=.d)
endif

./bin/BrushWork: ./bin ./out $(LIBS) $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(LFLAGS)
./out/%.o: ./src/%.cc
	@$(call make-depend-cc,$<,$@,$(subst .o,.d,$@))
	$(CC) -c $(CFLAGS) $< -o $@ 	   
./bin:
	mkdir -p ./bin
./out:
	mkdir -p ./out
./ext/glui/lib/libglui.a:
	$(MAKE) -C ./ext/glui
clean:
	rm -r ./bin ./out
clean_all: clean
	$(MAKE) -C ./ext/glui clean
