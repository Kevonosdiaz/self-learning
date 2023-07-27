#include <iostream>
using namespace std;

/*
 * Perform a series of swaps using two pointers 

*/
string reverse() {
    char text[] = "hello";
    char* pStart = text;

    int len = sizeof(text) - 1; // Remember the null terminator
    char* pEnd = text + len - 1; // This will point to the 'o' in "hello" now

    while(pStart < pEnd) {
        char save = *pStart; // A temp variable
        *pStart = *pEnd; // Set the element in the left half to be the one in the right half
        *pEnd = save;

        pStart++;
        pEnd--;
    }

    cout << text << endl;
    return text;
}

int main() {
    // We can use typical array syntax, but also ptr incrementing, and while loop with ptr comparison
    string texts[] = {"one","two","three"};
    string *pTexts = texts; // The array name is the start

    for (int i=0; i < sizeof(texts)/sizeof(string); i++) {
        cout << pTexts[i] << " " << flush;
    }
    cout << endl;

    for (int i=0; i < (sizeof(texts)/sizeof(string))-1; i++, pTexts++) {
        cout << *(pTexts + i)  << " " << flush;
        // pTexts++ Points to next element
    }
    cout << endl;

    string *pElement = texts;
    string *pLast = &texts[2];

    // We could use a while loop to keep incrementing pElement until it reachs pLast


    reverse();
    return 0;
}