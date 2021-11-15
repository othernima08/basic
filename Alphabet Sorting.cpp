#include <iostream>
using namespace std;

// C++ Program to do Alfabet Sorting
// By: Desi Christine Othernima

void Sorting(int ar[], int size, char alfa[]) {
    int pivot, temp;
    for (int i = 0; i < size; i++) {
        pivot = i;
        for (int k = i + 1; k < size; k++) {
            if (ar[pivot] > ar[k]) {
                pivot = k;
            }
        }
        temp = ar[pivot];
        ar[pivot] = ar[i];
        ar[i] = temp;
        for (int j = 0; j < 26; j++) {
            if (ar[i] == j)
                cout << alfa[j] << " ";
        }
    }
    cout << endl;
}

int main() {
    char alfa[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, inputan[100];
    int size, ar[100];
    cout << "Masukkan jumlah indeks = ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Indeks ke-" << i << " = ";
        cin >> inputan[i];
        for (int j = 0; j < 26; j++) {
            if (inputan[i] == alfa[j])
                ar[i] = j;
        }
    }
    cout << "\nSetelah Sorting = ";
    Sorting(ar, size, alfa);
    cout << endl;
}