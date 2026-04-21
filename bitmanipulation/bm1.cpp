/*
     Bit Masking: There are 2 parts of an array of bits
     1.MSB(Most Significant Bit): It is the Nth bit of the bits 
     2.LSB(Least Significant Bit): It is the 0th bit of the bits






#include<bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for (int i = 10; i >= 0; --i) {
        cout<< ((num >> i) & 1);
    }
    cout << endl;
}

int main () {
    printBinary(9);
    int a = 9;
    int i = 3;
    if((a&(1 << i)) != 0) {
        cout << "Set Bit";
    }else {
        cout << "Not set Bit";
    }
}
    */


/*
Question:



*/
