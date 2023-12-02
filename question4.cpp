// vowel count
#include <iostream>
#include <string.h>
using namespace std;

int main() {
        char str[100];
        cout<<"Enter the string"<<endl;
        gets(str);
        
        char *ptr = str;
        int vowelcount = 0;
        int length = strlen(str);
        
        while(length--) {
          if(*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U' || *ptr == 'a' || *ptr =='e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
               vowelcount++;
          }
          ptr++;
        }
        cout<<"The total count of vowel is :"<<vowelcount<<endl;
        return 0;
}