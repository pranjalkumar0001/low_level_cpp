#include <iostream>
using namespace std;
int main()
{
    int num_arr[] = {1,6,2,4,2};
    cout << num_arr<< endl; // this prints the memory location of array
    num_arr[2] = 1002;
    int a = 123;
    int b = 332;
    int* ptr1 = &a;
    int* ptr2 = &b;
    ptr1 = num_arr;
    cout<< ptr1 <<"\n"<< ptr2<< endl;
    for(int i=0; i<5; i++)
    {
        cout<< num_arr[i]<< " ";
    }
}