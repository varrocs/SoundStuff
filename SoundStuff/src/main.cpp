
#include <iostream>
#include "types.h"
#include "SoundSample.h"
#include "morsetext.h"
using namespace std;
using namespace soundstuff;

int main() {
	sample_t sample;
	SoundSample samples(48000);

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
			MorseText morse(signals);
			cout << morse.toString() << endl << string(20, '-') << endl;

		} catch (exception& e) {
			cerr << "Problem with " << e.what() << endl;
			exit(1);
		}
	}

	return 0;
}
