CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		avl_tree.o

LIBS =

TARGET =	avl_tree

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
