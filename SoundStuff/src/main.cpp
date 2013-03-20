
#include <iostream>
#include "types.h"
#include "SoundSample.h"
#include "morsetext.h"
using namespace std;
using namespace soundstuff;

const int SAMPLE_RATE = 48000;
const double SIGNAL_UNIT_LENGTH = 0.2;

int main() {
	sample_t sample;
	SoundSample samples(SAMPLE_RATE);

	vector<bool> signals;

	while (true) {
		for (int i = 0; i < SoundSample::sampleLength; ++i) {
			cin >> sample;
			samples.append(sample);
		}
		try {
			bool isSignal = samples.foundSignal(440);
			/*if (isSignal) {
				cout << "Signal" << endl;
			}*/

			signals.push_back(isSignal);
			MorseText morse(SAMPLE_RATE / SoundSample::sampleLength * SIGNAL_UNIT_LENGTH, signals);
//			cout << morse.toString() << endl << string(40, '-') << endl;
			cout << "\r" << morse.toString();

		} catch (exception& e) {
			cerr << "Problem with " << e.what() << endl;
			exit(1);
		}
	}

	return 0;
}
