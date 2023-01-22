#ifndef CIRCULAR_ARR_H
#define CIRCULAR_ARR_H

#include <stdio.h>

template<typename T, int arr_length>
class circular_array{

private:
    T data[arr_length];
    int size;

public:
    circular_array():size(arr_length){};

    ~circular_array() = default;

    circular_array(circular_array<T, arr_length>& arr){
        for(int i = 0; i < size; ++i){
            printf("%d, %d\n", this->data[i], arr[i]);
            this->data[i] = arr[i];
        }
    }

    void operator =(circular_array<T, arr_length>& arr){
        if(this->size == arr.getSize()){
            for(int i = 0; i < size; ++i){
                this->data[i] = arr[i];
            }
        }
    }

    T& operator [](int i){
        return this->data[i];
    }

    int getSize(){
        return this->size;
    }

    void printArr(){
        for(int i = 0; i < arr_length; ++i){
            printf("%d\n", data[i]);
        }
    }

    





};

#endif
