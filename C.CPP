#include <iostream>
using namespace std;

int main() {
    int a[5];
    cout <<"enter any 5 numbers : ";
    for(int i=0; i<5; i++){
        cin >> a[i];
    }
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5-i; j++){
            if(a[i] > a[j+1]){
                swap(a[i], a[j+1]);
            }
        }
    }
    cout <<" shorted array : ";
    for (int i = 0; i<5; i++){
        cout << a[i] << " ";
    }
    return 0;
}         