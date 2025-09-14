#include <iostream>
#include <string>

using namespace std;

int findPattern(const string& text, const string& pattern) {
    // handle empty pattern case
    if (pattern.empty()) {
        return 0;
    }
    
    //handle case where pattern is longer than text
    if (pattern.length() > text.length()) {
        return -1;
    }

    // naive pattern matching algorithm
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        int j;
        for (j = 0; j < pattern.length(); j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern.length()) {
            return i;
        }
    }
    return -1;
}

void runTest(const string& text, const string& pattern, const string& testName) {
    int result = findPattern(text, pattern);
    cout << testName << endl;
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Result: " << result << endl << endl;
}

int main() {
    // test 1: Pattern at the beginning
    runTest("Hello World", "Hello", "Test 1: Pattern at beginning");

    // test 2: Pattern at the end
    runTest("Hello World", "World", "Test 2: Pattern at end");

    // test 3: Pattern not present
    runTest("Hello World", "Python", "Test 3: Pattern not present");

    // test 4: Empty pattern
    runTest("Hello World", "", "Test 4: Empty pattern");
    return 0;
}

//modifying code 