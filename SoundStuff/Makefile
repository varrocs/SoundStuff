
CXXFLAGS = -std=c++11 -O3

BINDIR=bin
SRCDIR=src
LIBDIR=lib/fft

OBJS=$(SRCDIR)/main.o $(SRCDIR)/morsetext.o $(SRCDIR)/SoundSample.o $(LIBDIR)/fft.o $(LIBDIR)/complex.o
HEADERS=morsetext.h SoundSample.h type.h $(LIBDIR)/fft.h $(LIBDIR)/complex.h

$(SRCDIR)/%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ &<

$(BINDIR)/SoundStuff: $(OBJS)
	$(CXX) -o $@ $^
	
clean:
	rm $(OBJS) $(BINDIR)/SoundStuff
