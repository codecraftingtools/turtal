# Copyright (c) 2019 Jeffrey A. Webb

HEADERS := \
    include/turtal/Clock_ID.hpp \
    include/turtal/Clock_Parameters.hpp \
    include/turtal/clock.hpp \
    include/turtal/Time_Difference.hpp \
    include/turtal/Time_Point.hpp \
    include/turtal/turtal.hpp

OBJS := \
    obj/test_turtal.o \
    obj/Clock_Parameters.o

all: bin/test_turtal

bin:
	mkdir bin

obj:
	mkdir obj

bin/test_turtal: $(OBJS) | bin
	g++ -o $@ $^

obj/test_turtal.o: test/test_turtal.cpp $(HEADERS) | obj
	g++ -c -o $@ -I include $<

obj/Clock_Parameters.o: src/Clock_Parameters.cpp $(HEADER) | obj
	g++ -c -o $@ -I include $<

clean:
	rm -rf bin obj
