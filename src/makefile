.PHONY:clean distclean

BIN      = 	0

CC       = g++
LIBS     = -lpthread  -lboost_system -lcrypto  -lssl -lgtest -pthread
CIFLAGS  =  -I/usr/include/gtest
CXXFLAGS = -Wall -g -std=c++11 $(CIFLAGS)
CFLAGS   = $(CIFLAGS) -g

ROOTSRC  = $(wildcard *.c) $(wildcard *.cpp)
ROOTOBJ  = $(patsubst %c,%o,$(patsubst %cpp,%o,$(ROOTSRC)))

SUBDIR   = $(shell ls -d */)
SUBSRC   = $(shell find $(SUBDIR) -name '*.c') $(shell find $(SUBDIR) -name '*.cpp')
SUBOBJ   = $(patsubst %c,%o,$(patsubst %cpp,%o,$(SUBSRC)))

$(BIN):$(ROOTOBJ) $(SUBOBJ)
	$(CC) $(CXXFLAGS) $(ROOTOBJ) $(SUBOBJ) -o $(BIN) $(LIBS)
	# rm -rf $(ROOTOBJ) $(SUBOBJ)

clean:
	rm -rf $(ROOTOBJ) $(SUBOBJ)

distclean:
	rm -rf $(BIN) $(ROOTOBJ) $(SUBOBJ)
