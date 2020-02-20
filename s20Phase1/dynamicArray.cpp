#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

    // create an array that can be dynamically allocated (can create extra space when the array is full (2*capacity))
    
    //array may have to be a pointer
        /*this is because its a circular array, or becuase you are going to be storing multiple data values and you wnt to access them from anywhere withought having to create 
            the space everywhere*/
        int capacity = 5;
        int *CDA;
        CDA = new int[capacity];
        CDA[capacity] = {0};
        int size = 0;

        for (int i = 0; i < capacity; i++){
            CDA[i] = 1;
        }
        
        //first array print
        cout << "first array [ ";
        for (int i = 0; i < capacity; i++){
            cout << CDA[i] << " ";
        }
        cout << "]" << endl;

        for (int i = 0; i < capacity; i++){
            if (CDA[i] != 0 ){
                size++;
            }
        }
        
        if (size == capacity){
            int *tArray;
            tArray = new int[capacity];
            tArray[capacity] = {0};
            for (int i = 0; i < capacity; i++){
                tArray[i] = CDA[i];
            }
            capacity = capacity*2;
            CDA = new int[capacity];
            CDA[capacity] = {0};
            for (int i = 0; i < size; i++){
                CDA[i] = tArray[i];
            }
        }

        //final array test
        cout << "second array [ ";
        for (int i = 0; i < capacity; i++){
            cout << CDA[i] << " ";
        }
        cout << "]" << endl;

    return 0;
}