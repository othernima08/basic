// To of Hanoi Group 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

// Program Game Tower of Hanoi using Stack Desi Christine Othernima

void awal() {
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << "|                                    T O W E R  O F  H A N O I                                  |\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    cout << "| 1. Setiap disk hanya boleh dipindah satu kali dalam satu waktu                                |\n";
    cout << "| 2. Disk yang dipindahkan hanya bisa disk paling atas                                          |\n";
    cout << "| 3. Disk yang diatas harus lebih kecil daripada disk yang dibawah                              |\n";
    cout << "-------------------------------------------------------------------------------------------------\n\n";
}

void show(stack<string> source, stack<string> auxillary, stack<string> Destination) {
    for (int i = 3; i > 0; i--) {
        if (!source.empty()) {
            if (i <= source.size()) {
                cout << source.top();
                source.pop();
            }
            else
                cout << " ";
        }
        cout << "\t\t";
        if (!auxillary.empty()) {
            if (i <= auxillary.size()) {
                cout << auxillary.top();
                auxillary.pop();
            }
            else
                cout << " ";
        }
        cout << "\t\t";
        if (!Destination.empty()) {
            if (i <= Destination.size()) {
                cout << Destination.top();
                Destination.pop();
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "Source  \tAuxillary\tDestination\n";
}

int main()
{
    int ring, pipa, attempt = 0;
    stack<string> source, auxillary, Destination;
    awal();
    source.push("***");
    source.push("**");
    source.push("*");
    show(source, auxillary, Destination);
    while (Destination.size() != 3) {
        cout << "\nPilih tower yang memuat disk yang ingin dipindahkan (1. Source, 2. Auxillarry, 3. Destination): ";
        cin >> ring;
        if (ring == 1) {
            cout << "Pindahkan disk ke tower nomor (1. Source, 2. Auxillarry, 3. Destination): ";
            cin >> pipa;
            if (pipa == 2) {
                cout << "\nProses " << attempt + 1 << " : " << source.top() << " dari Source dipindahkan ke Auxillary\n";
                if (!auxillary.empty() && (auxillary.top()).length() < (source.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    auxillary.push(source.top());
                    source.pop();
                }
            }
            else if (pipa == 3) {
                cout << "\nProses " << attempt + 1 << " : " << source.top() << " dari Source dipindahkan ke Destination\n";
                if (!Destination.empty() && (Destination.top()).length() < (source.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    Destination.push(source.top());
                    source.pop();
                }
            }
        }
        else if (ring == 2) {
            cout << "Pindahkan disk ke tower nomor (1. Source, 2. Auxillarry, 3. Destination): ";
            cin >> pipa;
            if (pipa == 1) {
                cout << "\nProses " << attempt + 1 << " : " << auxillary.top() << " dari Auxillary dipindahkan ke Source\n";
                if (!source.empty() && (source.top()).length() < (auxillary.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    source.push(auxillary.top());
                    auxillary.pop();
                }
            }
            else if (pipa == 3) {
                cout << "\nProses " << attempt + 1 << " : " << auxillary.top() << " dari Auxillary dipindahkan ke Destination\n";
                if (!Destination.empty() && (Destination.top()).length() < (auxillary.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    Destination.push(auxillary.top());
                    auxillary.pop();
                }
            }
        }
        else if (ring == 3) {
            cout << "Pindahkan disk ke tower nomor (1. Source, 2. Auxillarry, 3. Destination): ";
            cin >> pipa;
            if (pipa == 1) {
                cout << "\nProses " << attempt + 1 << " : " << Destination.top() << " dari Destination dipindahkan ke Source\n";
                if (!source.empty() && (source.top()).length() < (Destination.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    source.push(Destination.top());
                    Destination.pop();
                }                
            }
            else if (pipa == 2) {
                cout << "\nProses " << attempt + 1 << " : " << Destination.top() << " dari Destination dipindahkan ke Auxillary\n";
                if (!auxillary.empty() && (auxillary.top()).length() < (Destination.top()).length())
                    cout << "Alert: Disk yang lebih besar tidak boleh di atas disk yang lebih kecil!\n";
                else {
                    auxillary.push(Destination.top());
                    Destination.pop();
                }                
            }
        }
        cout << "Tampilan:\n";
        show(source, auxillary, Destination);
        attempt++;
    }
    cout << "\nSelamat! Anda menyelesaikan game Tower of Hanoi dengan memindahkan disk sebanyak " << attempt << " kali\n";
    cout << "\n[Program by Group9 : Desi Christine O dan Dominikus Vieri L]\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
