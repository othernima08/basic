// EncryptDecrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

/*
    Nama        : Desi Christine Othernima
    Campus ID   : 201904560016
    Tujuan      : Program Enkripsi dan Dekripsi Vignere Cippher
*/

int main() {
    string pesan, key;
    int pilihan, indekspesan, indekskunci, urutan;
    int i, j, k, l, o;
    char alfabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int panjangalfa = sizeof(alfabet) / sizeof(char);
    //cout << "Banyak data pada array = " << panjangalfa << endl;
    cout << "Enkripsi dan Dekripsi" << endl;
    cout << "1. Enkripsi\n2. Dekripsi\nPilihan: ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
        int enkripsi;
        cout << "\nPlaintext > ";
        cin.ignore();
        getline(cin, pesan);
        cout << "Key > ";
        cin >> key;

        cout << "\nCiphertext = ";

        for (i = 0; i < pesan.size(); i++) {
            if (pesan.at(i) != ' ') {
                for (j = 0; j < panjangalfa; j++) {
                    if (pesan.at(i) == alfabet[j])
                        indekspesan = j;
                }
                urutan = i % key.length();
                for (k = 0; k < panjangalfa; k++) {
                    if (key.at(urutan) == alfabet[k])
                        indekskunci = k;
                }
                enkripsi = indekspesan + indekskunci;
                enkripsi = enkripsi % 26;
                for (int o = 0; o < panjangalfa; o++)
                    if (enkripsi == o)
                        cout << alfabet[o];
            }
            else {
                cout << ' ';
            }
        }
        break;

    case 2:
        int dekripsi;
        cout << "\nCiphertext > ";
        cin.ignore();
        getline(cin, pesan);
        cout << "Key > ";
        cin >> key;

        cout << "\nPlaintext = ";
        for (int i = 0; i < pesan.size(); i++) {
            if (pesan.at(i) != ' ') {
                for (int j = 0; j < panjangalfa; j++) {
                    if (pesan.at(i) == alfabet[j])
                        indekspesan = j;
                }
                urutan = i % key.length();
                for (k = 0; k < panjangalfa; k++) {
                    if (key.at(urutan) == alfabet[k])
                        indekskunci = k;
                }
                dekripsi = indekspesan - indekskunci;
                if (dekripsi < 0)
                    dekripsi += 26;
                for (int o = 0; o < panjangalfa; o++)
                    if (dekripsi == o)
                        cout << alfabet[o];
            }
            else {
                cout << ' ';
            }
        }
        break;
    }

}