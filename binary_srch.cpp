#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[100];
    cout << "Enter the numbers in sorted (ascending) order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int foundIndex = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            foundIndex = mid;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }

    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << endl;
    } else {
        cout << "Not found in the array" << endl;
    }

    return 0;
}