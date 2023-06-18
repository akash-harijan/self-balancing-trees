CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		red_black_tree.o

LIBS =

TARGET =	red_black_tree

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
