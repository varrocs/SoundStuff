/*
 * SoundSample.cpp
 *
 *  Created on: 2013.03.19.
 *      Author: varrocs
 */

#include <algorithm>
#include <iostream>

#include "SoundSample.h"
#include "../lib/fft/complex.h"
#include "../lib/fft/fft.h"

using namespace std;
using namespace soundstuff;

//#define TRACE

// Has to be the power of 2 because of fft
const int SoundSample::sampleLength = 1024;

complex toComplex(sample_t s) {
	return s;
}

SoundSample::SoundSample(int rate) : rate(rate){
	sampleFreq = rate / sampleLength;	// 48000 / 1024 = 46,875Hz. Normal A sound: 9,190600522 freqs away
}

void SoundSample::append(sample_t sample) {
	samples.push_back(sample);
}

bool SoundSample::foundSignal(int frequency) {
	// Transform to complex*
	vector<complex> complexVector;
	complexVector.resize(samples.size()); // To fit the result of the transformation
	transform(samples.begin(), samples.end(), complexVector.begin(), toComplex);
	samples.clear();
	complex* temp = &complexVector[0];
	bool ok = CFFT::Forward(temp, complexVector.size());
	if (!ok) {
		throw "fft";
	}

	// Find the strongest freq
	int counter = 0;
	int strongest = 0;
	double strongestValue = 0.0;
	for (auto c : complexVector) {
		if (counter == 0) {
			++counter;
			continue;	// Noise reduction
		}
		if (strongestValue < c.norm()) {
			strongestValue = c.norm();
			strongest = counter;
		}
		++counter;
	}

	int freqToFind = frequency / sampleFreq;
#ifdef TRACE
	cout << "Target postion " << freqToFind << endl;
	cout << "Strongest value: " << strongestValue << " @ " << strongest << endl;
#endif

	return strongest == freqToFind || strongest == sampleLength - freqToFind;

	return true;
}
