#include <iostream>
using namespace std;

// Function to encode 4-bit data into 7-bit Hamming code
void encodeHammingCode(int data[]) {
    // Calculate parity bits using XOR (based on Hamming 7,4 logic)
    data[0] = data[2] ^ data[4] ^ data[6];  // Parity bit at position 1 (P1)
    data[1] = data[2] ^ data[5] ^ data[6];  // Parity bit at position 2 (P2)
    data[3] = data[4] ^ data[5] ^ data[6];  // Parity bit at position 4 (P4)
}

// Function to detect and correct single-bit error
void detectAndCorrectError(int receivedData[]) {
    int c1, c2, c3, errorPos;

    // Recalculate parity check bits using received data
    c1 = receivedData[0] ^ receivedData[2] ^ receivedData[4] ^ receivedData[6]; // P1
    c2 = receivedData[1] ^ receivedData[2] ^ receivedData[5] ^ receivedData[6]; // P2
    c3 = receivedData[3] ^ receivedData[4] ^ receivedData[5] ^ receivedData[6]; // P4

    // Combine to get error position (binary to decimal)
    errorPos = c3 * 4 + c2 * 2 + c1;

    if (errorPos == 0) {
        cout << "No error detected.\n";
    } else {
        cout << "Error detected at position: " << errorPos << endl;

        // Flip the bit at the error position (0-based index)
        receivedData[errorPos - 1] ^= 1;

        cout << "Corrected data: ";
        for (int i = 0; i < 7; i++)
            cout << receivedData[i] << " ";
        cout << endl;
    }
}

int main() {
    int data[7] = {0};         // Hamming code positions: 1-based mapping
    int receivedData[7] = {0}; // To hold potentially corrupted data

    cout << "Enter 4 data bits (in order):\n";

    // Input 4 data bits: positions 3 (index 2), 5 (4), 6 (5), 7 (6)
    cout << "Bit for position 3 (d3): "; cin >> data[2];
    cout << "Bit for position 5 (d5): "; cin >> data[4];
    cout << "Bit for position 6 (d6): "; cin >> data[5];
    cout << "Bit for position 7 (d7): "; cin >> data[6];

    // Encode with Hamming Code
    encodeHammingCode(data);

    // Display encoded Hamming code
    cout << "\nEncoded 7-bit Hamming code:\n";
    for (int i = 0; i < 7; i++)
        cout << data[i] << " ";
    cout << endl;

    // Input received data (possibly with errors)
    cout << "\nEnter received 7-bit data (with possible error):\n";
    for (int i = 0; i < 7; i++)
        cin >> receivedData[i];

    // Detect and correct single-bit error
    detectAndCorrectError(receivedData);

    return 0;
}
