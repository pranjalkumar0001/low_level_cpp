#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// analyse a string and find Length
// Number of vowels
// Number of consonants
// Number of digits
// Number of spaces
// Number of special characters

string lower_string(string s)
{
    int len = 0;
    while(s[len] != '\0')
    {
        if(s[len] >= 'A' && s[len] <= 'Z')
        {
            s[len] = s[len] -'A' + 'a';
        }
        len++;
    }
    return s;
}

void analyse(string s)
{
    int len = 0;
    int no_of_vowels = 0;
    int no_of_consonants = 0;
    int no_of_digits = 0;
    int no_of_space = 0;
    int no_of_special_char = 0;
    string lowercase_str = lower_string(s);
    while(lowercase_str[len] != '\0')
    {
        if(lowercase_str[len]>='a' && lowercase_str[len]<='z')
        {
            if(lowercase_str[len] == 'a' || lowercase_str[len] == 'e' || lowercase_str[len] == 'i' || lowercase_str[len] == 'o' || lowercase_str[len] == 'u')
            {
                no_of_vowels++;
            }
            else{
                no_of_consonants++;
            }
        }
        else if(isdigit(lowercase_str[len]))
        {
            no_of_digits++;
        }
        else if(lowercase_str[len] ==' ') no_of_space++;
        else no_of_special_char++;
        len++;
    }
    cout<<"length of string is "<<len<<endl;
    cout<<"no of vowels are "<< no_of_vowels<<endl;
    cout<<"no of consonants are "<< no_of_consonants<<endl;
    cout<<"no of digits are "<< no_of_digits<<endl;
    cout<<"no of spaces are "<< no_of_space<<endl;
    cout<<"no of special characters are "<< no_of_special_char<<endl;
}

string reverse_string(string s)
{
    int n = s.length();

    for(int i = 0; i < n/2; i++)
    {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }

    return s;
}

bool is_palindrome(string s)
{
    s = lower_string(s);

    int left = 0;
    int right = s.length()-1;

    while(left < right)
    {
        while(left < right && s[left] == ' ')
            left++;

        while(left < right && s[right] == ' ')
            right--;

        if(s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int find_substring(string text, string substr)
{
    int len_text = text.length();
    int len_substr = substr.length();

    for(int i = 0; i <= len_text - len_substr; i++)
    {
        bool match = true;

        for(int j = 0; j < len_substr; j++)
        {
            if(text[i+j] != substr[j])
            {
                match = false;
                break;
            }
        }

        if(match)
            return i;
    }

    return -1;
}

void char_frequency_table(string s)
{
    int freq[256] = {0};

    for(char c : s)
    {
        freq[(unsigned char)c]++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            cout << (char)i << " : " << freq[i] << endl;
        }
    }
}

int main(){
    string test1;
    getline(cin, test1);
    analyse(test1);
    cout << "Reversed string is: " << reverse_string(test1) << endl;
    cout << "palindrome test is: "<< is_palindrome(test1)<< endl;
    char_frequency_table(test1);
    return 0;
}