# Copyright (c) 2019 Jeffrey A. Webb

all: bin/test_turtal

bin:
	mkdir bin

bin/test_turtal: test/test_turtal.cpp | bin
	g++ -o $@ -I include $<

bin/test_turtal: \
    include/turtal/Clock.hpp \
    include/turtal/Duration.hpp \
    include/turtal/Time_Point.hpp \

clean:
	rm -rf bin
