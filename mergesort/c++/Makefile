targets	:= main 
objs	:= main.o mergesort.o

CC		:= g++
CFLAGS	:= -Wall
CFLAGS 	+= -std=c++11
CFLAGS	+= -g
#PANDOC	:= pandoc

#Quiet mode: pass V=1 as argument to make
ifneq ($(V),1)
Q = @
endif 

all: $(targets)

#Substitute all object files for the equivalent dependency files
deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

#compiling the main executable
main: $(objs)
	@echo "CC $@"
	$(Q)$(CC) $(CFLAGS) -o $@ $^

#compiling all object files from source
%.o: %.cpp
	@echo "CC $@"
	$(Q)$(CC) $(CFLAGS) -c -o $@ $< $(DEPFLAGS)

#Compiling markdown to html (if used)
# %.html: %.md
# 	@echo "MD $@"
# 	$(Q)$(PANDOC) -o $$@ $<

clean:
	@echo "clean"
	$(Q)rm -f $(targets) $(objs) $(deps)