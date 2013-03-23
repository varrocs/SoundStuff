

BINDIR=bin
SRCDIR=src
LIBDIR=lib

CXXFLAGS = -std=c++11 -O3  -I$(LIBDIR)
LDFLAGS=

OBJS=$(SRCDIR)/main.o $(SRCDIR)/morsetext.o $(SRCDIR)/SoundSample.o $(LIBDIR)/fft/fft.o $(LIBDIR)/fft/complex.o
HEADERS=morsetext.h SoundSample.h type.h $(LIBDIR)/fft/fft.h $(LIBDIR)/fft/complex.h

$(SRCDIR)/%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ &<

$(BINDIR)/SoundStuff: $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^
	
clean:
	rm $(OBJS) $(BINDIR)/SoundStuff
