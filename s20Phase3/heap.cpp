//min heap class with circulary dynamic arary

#include <iostream>

using namespace std;

template<typename keytype, typename valuetype>
class Heap {
    private:
        keytype *keyArray;
        valuetype *valArray;
        int capacity;
        int size;
        // struct Node{
        //     keytype key;
        //     valuetype value;
        // }
    
    public:
        Heap(){
            size = 0;
            capacity = 1;
            keyArray = new keytype[capacity];
            valArray = new valuetype[capacity];
        }
        Heap(keytype k[], valuetype[], int s){
            size = 0;
            capacity = s;
            keyArray = new keytype[capacity];
            valArray = new valuetype[capacity];
            
            //for loop that runs through both key and value arrays and inserts 
            //each k[i] and v[i] into their respective arrays at the same position
            //position will be based on the key 
            //(if smaller heapify up, if larger leave it)
            for (int i = 0; i < s+1; i++){
                
            }
        }
};