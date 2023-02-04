#include <CircularArr.h>
#include <iostream>


int main(){

    c_ds::circular_array<int, 3> a1(2);
    c_ds::circular_array<int, 3> a2(10);
    a2(3);
    a2(5);
    a2.insert(6);
    a2(1,2);
    std::cout << a2 << a2.average() << std::endl;
    return 0;
}