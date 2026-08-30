#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[100];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int foundIndex = -1;   

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break;   // stop as soon as we find it
        }
    }

    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << endl;
    } else {
        cout << "Not found in the array" << endl;
    }

    return 0;
}