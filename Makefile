CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Cpp_Training_autoDecltype.o

LIBS =

TARGET =	Cpp_Training_autoDecltype

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
