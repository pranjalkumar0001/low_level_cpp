#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ========================
//       MemoryScope
// ========================

// 1. Analyze Integer Array
// 2. Reverse Integer Array
// 3. Search Element
// 4. Analyze String
// 5. Character Frequency Table
// 6. Reverse String
// 7. Palindrome Checker
// 8. Substring Search


void analyse_int_array(int* arr, int size)
{
    int sum = 0;
    int min = *arr;
    int max = *arr;
    for(int i = 0; i<size; i++)
    {
        cout<< "for value "<< *arr << "the memory adderss is " << arr << endl;
        sum += *arr;
        if(*arr < min)
        {
            min = *arr;
        }
        if( *arr > max)
        {
            max = *arr;
        }
        arr++;
    }
    cout << "sum : " << sum << endl;
    cout << "average : " << sum/size << endl;
    cout << "Min : " << min << endl;
    cout << "Max : "<< max << endl;
}
void int_arr_reverse(int *arr, int size)
{
    arr = arr + size - 1;
    for(int i = 0; i < size-1; i++)
    {
        cout << *arr << ",";
        arr--;
    }
    cout<< *arr << endl;
}

void search_element(int *arr, int size)
{
    int element;
    cout<< "enter the element to search : ";
    cin >> element;
    for(int i = 0; i<size; i++)
    {
        if(*arr == element)
        {
            cout << "found at index : " << i << endl;
            cout << "address : " << arr<< endl;
            return;
        }
        arr++;
    }
}

void string_analysis(string str)
{
    cout<< "length of string is :"<<str.length()<<endl;
    int vowels = 0;
    int consonents = 0;
    int digits = 0;
    int spaces = 0;
    int special = 0;
    int ascii_sum = 0;
    for (char c : str)
    {
        if(isalpha(c))
        {
            if(c>='A' && c<='Z') 
            {
                c = c - 'A' + 'a';
            }
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels++;
            else consonents++;
        }
        else if(isdigit(c)) digits++;
        else if (isspace(c)) spaces++;
        else special++;
        ascii_sum += c;
    }
    cout<< "no. of vowels are : "<< vowels<<endl;
    cout<< "no. of consonents are: " << consonents<<endl;
    cout<< "no of digits are: " << digits<< endl;
    cout<< "no of spaces are: "<< spaces<<endl;
    cout<< "no of special symbols are: "<< special<< endl;
    cout << "ascii sum is " << ascii_sum<<endl;
}

void reverse_string(string str)
{
    string reversed = "";
    for(int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    cout << "reversed string is : " << reversed << endl;
}

void palindrome_check(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while(left < right)
    {
        while(left < right && !isalnum(str[left])) left++;
        while(left < right && !isalnum(str[right])) right--;

        if(tolower(str[left]) != tolower(str[right]))
        {
            cout << "Not a palindrome" << endl;
            return;
        }

        left++;
        right--;
    }
    cout << "Palindrome" << endl;
}

int main()
{
    int option;
    cout << "Enter 1 for numerical array analysis\nEnter 2 for string array analysis"<< endl;
    cin>>option;
    
    if(option == 1)
    {
        int size;
        cout<<"enter size of array"<<endl;
        cin>>size;
        int arr[size];
        cout << "enter the array"<<endl;
        for(int i = 0; i<size; i++)
        {
            cin >> arr[i];
        }
        int function;
        cout<<"Enter 1 for array analysis\nEnter 2 for array reversal\nEnter 3 to search element int the array"<<endl;
        cin>> function;
        if(function == 1) analyse_int_array(arr, size);
        if(function == 2) int_arr_reverse(arr, size);
        if(function == 3) search_element(arr,size);
    }

    else if(option == 2)
    {
        string str;
        cout<< "enter the string"<<endl;
        cin.ignore();
        getline(cin, str);
        int function;
        cout<<"Enter 1 for string analysis\nEnter 2 for string reversal\nEnter 3 for palindrome check"<<endl;
        cin >> function;
        if (function == 1) string_analysis(str);
        else if(function == 2) reverse_string(str);
        else if(function == 3) palindrome_check(str);
    }
}