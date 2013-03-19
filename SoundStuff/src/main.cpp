
#include <iostream>
#include "types.h"
#include "SoundSample.h"

using namespace std;
using namespace soundstuff;

int main() {
	sample_t sample;
	SoundSample samples(48000);

	while (true) {
		for (int i = 0; i < SoundSample::sampleLength; ++i) {
			cin >> sample;
			samples.append(sample);
		}
		try {
			if (samples.foundSignal(1000)) {
				cout << "Signal" << endl;
			}
		} catch (char * problem) {
			cerr << "Problem with "  << problem << endl;
			exit(1);
		}
	}

	return 0;
}
