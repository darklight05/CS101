//try swapping the first and last value in an array of 3 elements but use 4
        //4 gives me 1 as the front so have to subtract one evertime i use 

//quick sort is super slow for large arrays
//quick select and search are not working
#include <stdlib.h>
using namespace std;

//#define INDEX(j) ((frontIndex + j) % capacity)
 
    template <class T> class CDA {

            bool resize(const int newCapacity){
                    T *temp;
                    temp = new T[newCapacity];
                    for (int i = 0; i < size; i++){
                        temp[i] = array[INDEX(i)]; 
                    }
                    
                    delete[] array;
                    capacity = newCapacity;
                    frontIndex = 0;
                    array = temp;
                    //temp = nullptr;
                return true;
            }
    
        public:
            T *array;
            bool ordered; 
            int capacity;
            int size;
            int frontIndex;

            CDA(){
                capacity = 1;
                size = 0;
                frontIndex = 0;b 
                array = new T[capacity];
                ordered = false;
            }

            CDA(int s){
                capacity = s;
                size = s;   
                frontIndex = 0;
                array = new T[capacity];
                ordered = false;
            }

            ~CDA(){
                delete[] array;
                //array = nullptr;
            }

            T& operator[](int i){
                if (i >= size) {
                    cout << "Out of bounds index" << endl;
                    //return array[INDEX(i)];
                    return array[((frontIndex+i)%capacity)-1];
                }
                else {
                    //int correctIndex = INDEX(i);
                    //return array[correctIndex];
                    return array[((frontIndex+i)%capacity)-1];
                }
            }

            //copy constructor
            CDA(const CDA<T>& copy) : capacity{copy.capacity}, size{copy.size}, frontIndex{0} {
                array = new T[capacity];
                for (int i = 0; i < size; i++){
                    array[i] = copy.array[(copy.frontIndex + i) % copy.capacity];
                }
            }

            //copy assignment
            CDA& operator=(const CDA<T> &rhs){
                if (this != &rhs){
                    delete[] array;

                    size = rhs.size;
                    capacity = rhs.capacity;
                    frontIndex = 0;
                    array = new T[capacity];
                    for (int i = 0; i < size; i++){
                        array[i] = rhs.array[(rhs.frontIndex + i) % rhs.capacity];
                    }
                }
                return (*this);
            }

            void AddEnd(T v){
                if (size >= capacity) resize(capacity * 2);
                array[(frontIndex + size) % capacity] = v;
                size++;
                if (ordered == true){
                    for (int i = 1; i < size; i++){
                        if (array[INDEX(i)] < array[INDEX(i-1)]) {
                            ordered = false;
                            break;
                        }
                        if (ordered == false){
                            break;
                        }
                    }
                }
            }

            void AddFront(T v){
                if (size >= capacity) resize(capacity * 2);
                if (frontIndex == 0) {
                    frontIndex = capacity - 1;
                }
                else {
                    frontIndex--;
                }
                size++;
                array[frontIndex] = v;
                if (ordered == true){
                    for (int i = 1; i < size; i++){
                        if (array[INDEX(i)] < array[INDEX(i-1)]) {
                            ordered = false;
                            break;
                        }
                        if (ordered == false){
                            break;
                        }
                    }
                }
            }

            void DelEnd(){
                if (size == (capacity * 0.25)) resize(capacity/2);
                --size;
            }

            void DelFront(){
                if (size == (capacity * 0.25)) resize(capacity/2);
                frontIndex = (frontIndex+1) % capacity;
                --size;
            }

            bool Ordered(){
                return ordered;
            }

            int Length(){
                return size;
            }

            int Capacity() {
                return capacity;
            }

            void Clear(){
                if (size == 0) return;
                capacity = 1;
                size = 0;
                frontIndex = 0;
            }

            int SetOrdered(){
                ordered = true;
                for (int i = 1; i < size; i++){
                    if (array[INDEX(i)] < array[INDEX(i-1)]) {
                        ordered = false;
                        return -1;
                    }
                }
                return 1;
            }
            
             int part(int left, int right){
                int pivotI = left + (rand() % right - left + 1);
                T pivot = array[INDEX(pivotI)];
                int i = left, x;
                swap(pivotI, right);
                for (x = left; x < right; x++){
                    if (array[INDEX(x)] <= pivot){
                        swap(i, x);
                        i++;
                    }
                }

                swap(i, right);
                return i;
            }

            T quickSelect(int left, int right, int k){
                    if (k > 0 && k < right - left +1){
                        if (left == right) return array[INDEX(left)];
                        int index = partition(left, right);

                        if (index == k) return array[INDEX(index)];

                        if (k < index){
                            return quickSelect(left, index - 1, k);
                        }

                        //else {
                            return quickSelect(index + 1, right, k);
                        //}
                    }
                   // return INT8_MAX;
            }

            T Select(int k){
                // USING QUICKSORT THEN CALLING THE SELECT FUNCTION WORKS FASTER THAN USING THE QUICKSELECT ALGORITHM
                if (ordered == true) {
                    return array[INDEX(k-1)];
                }

                else {
                    int left = 0;
                    int right = size-1;
                    T element = quickSelect(left, right, k-1);
                    //QuickSort();      
                    //Select(k);
                    return element;
                }
            }

            void InsertionSort(){
                if (ordered == true) return;
                T key;
                int j;
                for (int i = 1; i < size; i++){
                    key = array[INDEX(i)];
                    j = i - 1;
                    while (j >= 0 && array[INDEX(j)] > key){
                        array[INDEX(j+1)] = array[INDEX(j)];
                        j = j-1;
                    }
                    array[INDEX(j+1)] = key;
                }
                ordered = true;
            }

            void swap(int a, int b){
                int temp[1];
                temp[0] = array[INDEX(a)]; 
                array[INDEX(a)] = array[INDEX(b)]; 
                array[INDEX(b)] = temp[0]; 
            }

            int partition(int first, int last){
                int pivot, mid = (first + last) / 2;

                pivot = array[INDEX(first)] > array[INDEX(mid)] ? first : mid;

                if (array[INDEX(pivot)] > array[INDEX(last)]){
                    pivot = last;
                }
                
                swap(pivot, first);
                pivot = first;

                while (first < last){
                    if (array[INDEX(first)] <= array[INDEX(last)]){
                        swap(pivot, first);
                    }
                    first++;
                }
                swap(pivot, last);

                return pivot;
            }

            void qs(int first, int last){
                int Threshold = 15;
                if (last - first > Threshold) {
                    if (SetOrdered() == 1) return;

                    int pivot = partition(first, last);

                    qs(first, pivot - 1);
                    qs(pivot + 1, last);
                }
                else {
                    return;
                }
            }

            void QuickSort(){
                if (ordered == true) return;
                int lastIndex = INDEX(size)-1;
                qs(frontIndex, lastIndex);
                InsertionSort();
                ordered = true;
            }

            void CountingSort(int m){
                if (ordered == true) return;
                int countArray[m+1]; for (int i = 0; i < m+1; i++) countArray[i] = 0;
                T *tempArray; tempArray = new T[capacity];
                for (int i = 0; i < size; i++){
                    countArray[array[INDEX(i)]]++;
                }
                for (int i = 1; i < m+1; i++){
                    countArray[i] += countArray[i-1];
                }
                // for (int i = 0; i < size; i++){
                //     tempArray[countArray[array[INDEX(i)]]-1] = array[INDEX(i)];
                //     --countArray[array[INDEX(i)]];
                // }
                for (int i = size-1; i >= 0; i--){
                    tempArray[countArray[array[INDEX(i)]]-1] = array[INDEX(i)];
                    --countArray[array[INDEX(i)]];
                }
                for (int i = 0; i < size; i++){
                    array[INDEX(i)] = tempArray[i];
                }
                ordered = true;
            }

            int binarySearch(T e, int l, int r){
                if (r >= l){
                    int mid = l+(r-l)/2;

                    if (array[INDEX(mid)] == e){
                        return mid;
                    }
                    if (array[INDEX(mid)] > e){
                        return binarySearch(e, l, mid - 1);
                    }
                    return binarySearch(e, mid + 1, r);
                }
                return -1;
            }

            int Search(T e){
                if (ordered == true){
                    int itemIndex = binarySearch(e, 0, size-1);
                    if (itemIndex == -1){
                        return -1;
                    }
                    else {
                        return INDEX(itemIndex);
                    }
                }
                else {
                    for (int i = 0; i < size-1; i++){
                        if (array[INDEX(i)] == e){
                            return INDEX(i)+1;
                        }
                    }
                    return -1;
                }
            }
    };