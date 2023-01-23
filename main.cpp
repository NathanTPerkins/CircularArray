#include <CircularArr.h>
#include <iostream>


int main(){

    circular_array<int, 5> test1;
    for(int i = 0; i < test1.getSize(); ++i){
        test1[i] = i;
    }
    return 0;
}