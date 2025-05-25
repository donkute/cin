// GO-BACK-N ARQ Simulation
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void transmission(int &currentFrame, int windowSize, int totalFrames, int &transmissionCount) {
    while (currentFrame <= totalFrames) {
        int acknowledgedFrames = 0;

        // Send frames in the current window
        for (int k = currentFrame; k < currentFrame + windowSize && k <= totalFrames; k++) {
            cout << "Sending Frame " << k << "..." << endl;
            transmissionCount++;
        }

        // Receive acknowledgments
        for (int k = currentFrame; k < currentFrame + windowSize && k <= totalFrames; k++) {
            if (rand() % 2 == 0) {
                cout << "Acknowledgment for Frame " << k << endl;
                acknowledgedFrames++;
            } else {
                cout << "Timeout!! Frame " << k << " not acknowledged." << endl;
                cout << "Retransmitting window starting from Frame " << k << "..." << endl;
                break;  // Stop and retransmit from the unacknowledged frame
            }
        }

        // Slide the window forward by the number of successfully acknowledged frames
        currentFrame += acknowledgedFrames;
        cout << "---------------------------\n";
    }
}

int main() {
    int totalFrames, windowSize, totalTransmissions = 0;
    srand(time(0));

    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    int currentFrame = 1;  // Start from frame 1 for user clarity
    transmission(currentFrame, windowSize, totalFrames, totalTransmissions);

    cout << "Total frames sent (including retransmissions): " << totalTransmissions << endl;
    return 0;
}
