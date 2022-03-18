CXX := i586-mingw32msvc-g++
WXCONFIG ?= /var/lib/jenkins/lib/wx/config/i586-mingw32msvc-msw-unicode-release-static-2.9

LDFLAGS	:= -Wl,-s

# include path
INCLUDE	:= -I../manual -I../auto 

INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild: clean build

run:
	./$(TARGET).exe

debug:
	insight-x86 $(TARGET).exe

$(TARGET).exe:	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
