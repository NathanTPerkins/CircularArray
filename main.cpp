#include <CircularArr.h>
#include <iostream>


int main(){

    circular_array<int, 5> test1;
    for(int i = 0; i < test1.getSize(); ++i){
        test1[i] = i;
    }
    // test1.printArr();
    circular_array<int, 5> test2 = test1;
    // circular_array<int, 5> test3;
    // test3 = test2;
    // test3.printArr();
    // test2.printArr();
    return 0;
}