#include <iostream>
using namespace std;

/*!
    @author ABDO
    @brief Implementation of Dynamic Array (vector)
    @fn void push_back(const T& value) 
    add a new element \value to the end of the Dynamic array
    
    @fn bool insertAt(const T& value , int index)
    add a new element \value to the index of \index of the Dynamic array
    @return true if \value inserted 
    
    @fn bool pop_back() 
    remove last element from the Dynamic array
    @return true if \value is deleted

    @fn bool removeAt(int index)
    remove element at index \index from the Dynamic array
    @return true if \value is deleted
    
    @fn bool contains(const T& value)
    @return true if the array contains the value \value

*/


template<typename T>
class Darray {
    private:
        int size;
        int capacity;
        T* data = new T[capacity];
        T* temp_array;

        void merge(T* data, int start, int mid, int end) {
            int i = start , j = mid + 1 , k = 0;
            T* temp = new T[end - start +1];
            
            while (i <= mid && j <= end) {
                if(data[i] <= data[j]) {
                    temp[k] = data[i];
                    k++;
                    i++;
                }
                else{
                    temp[k] = data[j];
                    k++;
                    j++;
                }
            }
            
            while(i <= mid) {
                temp[k] = data[i];
                i++;
                k++;
            }
            while(j <= end) {
                temp[k] = data[j];
                j++;
                k++;
            }

            for(i=start; i <= end; i++) 
                data[i] = temp[i - start];
        }

        void mergeSort(T* data , int start, int end) {
            if(start < end) {
                int mid = (start + end) / 2;
                mergeSort(data, start, mid);
                mergeSort(data, mid + 1, end);
            
                merge(data ,start , mid, end);
            }
        }


    public:
        Darray() {
            size = 0;
            capacity = 0;
        }
        Darray(int size , int capacity = 0) {
            this->size = size;
            this->capacity = capacity;
        }
        ~Darray() {
            delete[] temp_array;
        }
        // checks if the array is empty
        bool isEmpty() {
            return size == 0;
        }
        // checks if the array is not empty
        bool isNotEmpty() {
            return size != 0;
        }
        bool enshure_capacity() {
            // checks if the capacity is inefficient
            return capacity >= size;     
        }
        void capacity_grow() {
            // capacity growth : size * 2
            capacity = size * 2;
            temp_array = new T[capacity]; // create new temp array 
            temp_array = data;
            
            data = new T[capacity];
            data = temp_array;



        }
        // add elements to the Dynamic Array
        void push_back(const T& value) {
            if (!enshure_capacity()) {
                capacity_grow();
            }
            data[size++] = value;
        }

        bool insertAt(const T& value , int index) {
            if (!enshure_capacity()) {
                capacity_grow();
            }
            if(index == size) {
                push_back(value);
            }
            else if (index > size) {
                throw runtime_error("Index out of bounds");
            }
            else {
                temp_array = new T[size + 1];
                for (int i = 0 , j = 0; i <= size;i++ , j++) {
                    if(i == index) {
                        temp_array[i] = value; 
                        j--;
                    }
                    else {
                        temp_array[i] = data[j];
                    }
                }
                size++;
                // data = new T[size];
                data = temp_array;
            }
            return true;
        }

        bool replace(const T& value , int index) {
            if(index < size && index >= 0){
                data[index] = value;
                return true;
            } 
            else {
                throw runtime_error("Index out of bounds");
            }
        }

        void pop_back() {
            if(isEmpty()) {
                throw runtime_error("Dynamic Array is empty");
            }
            else {
                data[--size] = NULL;
            }
        }
        void swap(int index1 , int index2 ) {
            T temp;
            temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
        bool deleteAt(int index) {
            if(isEmpty()) {
                throw runtime_error("Dynamic Array is empty");
            }
            else {
                temp_array = new T[size--];
                for (int i = 0 , j = 0; i <= size;i++ , j++) {
                    if(i == index) {
                        j--;
                        continue;
                    }
                    else {
                        temp_array[j] = data[i];
                    }
                }
                data = temp_array;
            }
        }

        bool contains(const T& value) {
            for (int i = 0; i < size; i++) {
                if(data[i] == value) {
                    return true;
                }
            }            
            return false;
        }
        void clear() {
            size = 0;
            capacity = 0;
        }
        // sort elements using merge sort
        void sort() {
            mergeSort(data,0, size - 1);
        }
        
        int length() {
            return this->size;
        }

        void printALL() {
            for (int i = 0; i < size; i++) {
                cout << data[i] << endl;
            }
        }
        T& operator [] (int i) {return data[i];}

};



int main(int argc, char const *argv[]) {
    
    Darray<int> a;
    a.push_back(44);
    a.push_back(45);
    a.push_back(46);
    a.push_back(47);
    a.push_back(441);
    a.push_back(449);
    a.push_back(349);
    a.push_back(1149);
    a.push_back(44669);
    a.push_back(44669);
    a.push_back(44669);
    a.push_back(-44669);
    a.push_back(44669);
    a.push_back(44456669);
    a.push_back(66943);
    a.push_back(453669);
    a.push_back(55);
    a.push_back(4445669);
    a.pop_back();

    // a.sort();
    // a.insertAt(11111,30);
    a.deleteAt(4);
    a.clear();
    a.push_back(5);
    a.push_back(-2);
    a.push_back(3);
    a.push_back(1);
    // a.sort();
    // a.replace(6,3);
    a.swap(0,1);
    a.printALL();


    return 0;
}
