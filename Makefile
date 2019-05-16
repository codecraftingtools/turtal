# Copyright (c) 2019 Jeffrey A. Webb

HEADERS := \
    include/turtal/clock/ID.hpp \
    include/turtal/clock/Parameters.hpp \
    include/turtal/clock/clock.hpp \
    include/turtal/clock/io.hpp \
    include/turtal/time/Difference.hpp \
    include/turtal/time/Instant.hpp \
    include/turtal/time/time.hpp \
    include/turtal/time/io.hpp \
    include/turtal/turtal.hpp

OBJS := \
    obj/test_turtal.o \
    obj/clock.o

all: bin/test_turtal

bin:
	mkdir bin

obj:
	mkdir obj

bin/test_turtal: $(OBJS) | bin
	g++ -o $@ $^

obj/test_turtal.o: test/test_turtal.cpp $(HEADERS) | obj
	g++ -c -o $@ -I include $<

obj/clock.o: src/clock.cpp $(HEADER) | obj
	g++ -c -o $@ -I include $<

clean:
	rm -rf bin obj
