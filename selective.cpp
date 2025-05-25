#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Simulate receiving a frame (90% chance of success)
bool receiveFrame() {
    return rand() % 10 < 9; // returns true 90% of the time
}

int main() {
    int totalFrames, windowSize;

    // Seed random number generator
    srand(time(0));

    // Input from user
    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    // Array to track whether each frame was acknowledged
    bool acknowledged[100] = {false};

    int base = 0;  // The starting index of the sliding window

    // Continue until all frames are acknowledged
    while (base < totalFrames) {
        cout << "\nSending window frames:\n";

        // Send frames in the current window
        for (int i = 0; i < windowSize; i++) {
            int frame = base + i;
            if (frame < totalFrames && !acknowledged[frame]) {
                cout << "Sending Frame " << frame << endl;
            }
        }

        // Check acknowledgments
        for (int i = 0; i < windowSize; i++) {
            int frame = base + i;
            if (frame < totalFrames && !acknowledged[frame]) {
                if (receiveFrame()) {
                    acknowledged[frame] = true;
                    cout << "Acknowledgment received for Frame " << frame << endl;
                } else {
                    cout << "Frame " << frame << " lost! Will resend later." << endl;
                }
            }
        }

        // Slide the window forward past acknowledged frames
        while (base < totalFrames && acknowledged[base]) {
            base++;
        }
    }

    cout << "\nAll frames sent and acknowledged successfully!" << endl;

    return 0;
}
