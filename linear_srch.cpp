#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[10000000];
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
            break;
        }
    }
    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << endl;
    } else {
        cout << "Not found in the array" << endl;
    }

    return 0;
}