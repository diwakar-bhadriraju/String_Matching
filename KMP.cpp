#include <iostream>
#include <cstring>

using namespace std;

void computeLPS(char* pattern, int* lps, int m) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pattern, char* text) {
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computeLPS(pattern, lps, m);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }

        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
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
    KMPSearch(pattern, text);
    return 0;
}
