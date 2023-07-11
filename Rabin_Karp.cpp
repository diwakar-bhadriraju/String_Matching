#include <iostream>
#include <cstring>

using namespace std;

#define d 256 // Number of characters in the input alphabet
#define q 101 // A prime number used for hashing

void search(char* pattern, char* text, int d, int q) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If pattern is found, print the index
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    char text[1000], pattern[1000];
    cout << "Enter the text string: ";
    cin.getline(text, 1000);
    cout << "Enter the pattern string: ";
    cin.getline(pattern, 1000);

    // Check if the pattern is longer than the text
    if (strlen(pattern) > strlen(text)) {
        cout << "Error: Pattern is longer than the text." << endl;
        return 0;
    }

    search(pattern, text, d, q);
    return 0;
}
