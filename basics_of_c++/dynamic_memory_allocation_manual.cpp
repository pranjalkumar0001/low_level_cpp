#include <iostream>
using namespace std;

int main()
{
    int size;
    cout<<"enter the size of array:: ";
    cin>>size;
    float* arr = new float[size];
    cout<<"enter the array:: ";
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout << "Array elements:\n";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
