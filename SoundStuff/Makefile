
CXXFLAGS = -std=c++11

SRCDIR=src
LIBDIR=lib/fft

OBJS=$(SRCDIR)/main.o $(SRCDIR)/morsetext.o $(SRCDIR)/SoundSample.o $(LIBDIR)/fft.o $(LIBDIR)/complex.o
HEADERS=morsetext.h SoundSample.h type.h $(LIBDIR)/fft.h $(LIBDIR)/complex.h

$(SRCDIR)/%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ &<

SoundStuff: $(OBJS)
	$(CXX) -o $@ $^
	
clean:
	rm $(OBJS) SoundStuff