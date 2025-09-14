#include <iostream>
#include <vector>

using namespace std;

vector<int> findIndices(int arr[], int size, int key) {
    vector<int> indices;
    // Find all occurrences of key in array
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

void printResult(const string& testName, const vector<int>& result) {
    cout << testName << ": ";
    if(result.empty()) {
        cout << "No indices found";
    } else {
        cout << "Indices found at: ";
        for(int index : result) {
            cout << index << " ";
        }
    }
    cout << endl;
}

int main() {
    // Test Case 1: Multiple occurrences
    cout << "\nTest Case 1: Multiple occurrences" << endl;
    int arr1[] = {1, 2, 3, 2, 4, 2, 5};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> result1 = findIndices(arr1, size1, 2);
    printResult("Finding all 2's", result1);  // Expected: 1, 3, 5

    // Test Case 2: Key not present
    cout << "\nTest Case 2: Key not present" << endl;
    int arr2[] = {1, 3, 4, 5};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> result2 = findIndices(arr2, size2, 2);
    printResult("Finding 2 (not present)", result2);  // Expected: empty vector

    // Test Case 3: Empty array
    cout << "\nTest Case 3: Empty array" << endl;
    int arr3[] = {};
    vector<int> result3 = findIndices(arr3, 0, 1);
    printResult("Empty array search", result3);  // Expected: empty vector
    return 0;
}