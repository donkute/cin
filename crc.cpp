#include <iostream>
using namespace std;

char data[100], divisor[30], codeword[130];
int datalen, divlen;

// Perform XOR operation between two char arrays
void xorOperation(char* temp, char* div) {
    for (int i = 1; i < divlen; i++) {
        temp[i - 1] = (temp[i] == div[i]) ? '0' : '1';
    }
}

// Perform modulo-2 division
void computeCRC(char* input, char* div, char* remainder) {
    char temp[130];

    // Copy first divlen bits
    for (int i = 0; i < divlen; i++)
        temp[i] = input[i];

    int idx = divlen;
    while (idx <= datalen + divlen - 1) {
        if (temp[0] == '1')
            xorOperation(temp, div);
        else {
            for (int i = 1; i < divlen; i++)
                temp[i - 1] = temp[i];
        }
        temp[divlen - 1] = input[idx++];
    }

    // Copy remainder
    for (int i = 0; i < divlen - 1; i++)
        remainder[i] = temp[i];
}

int main() {
    cout << "Enter number of data bits: ";
    cin >> datalen;

    cout << "Enter data bits: ";
    for (int i = 0; i < datalen; i++)
        cin >> data[i];

    cout << "Enter number of divisor bits: ";
    cin >> divlen;

    cout << "Enter divisor bits: ";
    for (int i = 0; i < divlen; i++)
        cin >> divisor[i];

    // Append zeros to data
    for (int i = 0; i < datalen; i++)
        codeword[i] = data[i];
    for (int i = 0; i < divlen - 1; i++)
        codeword[datalen + i] = '0';

    char remainder[30];
    computeCRC(codeword, divisor, remainder);

    // Create final codeword = data + remainder
    for (int i = 0; i < datalen; i++)
        codeword[i] = data[i];
    for (int i = 0; i < divlen - 1; i++)
        codeword[datalen + i] = remainder[i];

    cout << "Transmitted Code Word: ";
    for (int i = 0; i < datalen + divlen - 1; i++)
        cout << codeword[i];
    cout << endl;

    // Receiver side
    cout << "Enter received code word: ";
    for (int i = 0; i < datalen + divlen - 1; i++)
        cin >> codeword[i];

    computeCRC(codeword, divisor, remainder);

    bool error = false;
    for (int i = 0; i < divlen - 1; i++) {
        if (remainder[i] == '1') {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error detected in received code word." << endl;
    else
        cout << "No error detected. Transmission successful!" << endl;

    return 0;
}
