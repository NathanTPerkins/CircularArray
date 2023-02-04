#ifndef CIRCULAR_ARR_H
#define CIRCULAR_ARR_H

#include <iostream>

namespace c_ds{

template<typename T, int arr_length>
class circular_array{

private:
    T* __arr;
    int __size;
public:
    circular_array();
    ~circular_array();
    circular_array(const circular_array&);
    circular_array(const T&);

    void operator=(const circular_array&);
    T& operator[](const int&)const;
    void operator()(const T&);
    void operator()(const T&, const int&);

    int size()const;
    double average()const;
    void insert(const T&);
    void insert(const T&, const int&);
};

//DEFAULT CONSTRUCTOR
template<typename T, int arr_length>
circular_array<T, arr_length>::circular_array(){
    this->__size = arr_length;
    this->__arr = new T[arr_length];
}

//DESTRUCTOR
template<typename T, int arr_length>
circular_array<T, arr_length>::~circular_array(){
    delete[] this->__arr;
    this->__arr = NULL;
}

//FILL CONSTRUCTOR
template<typename T, int arr_length>
circular_array<T, arr_length>::circular_array(const circular_array& arr){
    this->__size = arr_length;
    this->__arr = new T[arr_length];
    for(int i = 0; i < arr_length; ++i){
        this->__arr[i] = arr[i];
    }
}

//COPY CONSTRUCTOR
template<typename T, int arr_length>
circular_array<T, arr_length>::circular_array(const T& fill_num){
    this->__size = arr_length;
    this->__arr = new T[arr_length];
    for(int i = 0; i < arr_length; ++i){
        this->__arr[i] = fill_num;
    }
}

//ARRAY INDEXING OPERATOR
template<typename T, int arr_length>
T& circular_array<T, arr_length>::operator[](const int& idx)const{
    return this->__arr[idx];
}

//ASSIGNMENT OPERATOR
template<typename T, int arr_length>
void circular_array<T, arr_length>::operator=(const circular_array& arr){
    this->__size = arr.size();
    for(int i = 0; i < arr_length; ++i){
        this->__arr[i] = arr[i];
    }
}

//ARRAY INSERTION OPERATOR
template<typename T, int arr_length>
void circular_array<T, arr_length>::operator()(const T& num){
    for(int i = arr_length - 2; i >= 0; --i){
        this->__arr[i + 1] = this->__arr[i];
    }
    this->__arr[0] = num;
}

//ARRAY INSERTION OPERATOR
template<typename T, int arr_length>
void circular_array<T, arr_length>::operator()(const T& num, const int& index){
    this->__arr[index] = num; 
}

//SIZE METHOD
template<typename T, int arr_length>
int circular_array<T, arr_length>::size()const{
    return this->__size;
}

//ARRAY AVERAGE METHOD
template<typename T, int arr_length>
double circular_array<T, arr_length>::average()const{
    double sum = 0;
    for(int i = 0; i < arr_length; ++i){
        sum += this->__arr[i];
    }
    return sum / this->__size;
}

//ARRAY INSERTION METHOD
template<typename T, int arr_length>
void circular_array<T, arr_length>::insert(const T& num){
    (*this)(num);
}

//ARRAY INSERTION METHOD
template<typename T, int arr_length>
void circular_array<T, arr_length>::insert(const T& num, const int& index){
    (*this)(num, index);
}

};

//ARRAY COUT OVERLOAD
template<typename T, int arr_length>
std::ostream& operator << (std::ostream& out, const c_ds::circular_array<T, arr_length>& arr){
    out << "{";
    for(int i = 0; i < arr_length - 1; ++i){
        out << arr[i] << ",";
    }
    out << arr[arr_length - 1];
    out << "}";
    return out;
}

#endif
