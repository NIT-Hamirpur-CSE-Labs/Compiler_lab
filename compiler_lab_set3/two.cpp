#include<iostream>
#include<cstdlib>
 
using namespace std;
 
int main()
{
    int i,j,temp;
    char str[100]={"This is a pattern matching"};
    char substr[20]={"pattern"};
 
    for(i=0;str[i]!=' ';i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
 
            if(substr[j]==' ')
            {
                cout<<"The substring is present in given string at position "<<temp<<"n";
                exit(0);
            }
            else
            {
                i=temp;
                temp=0;
            }
        }
    }
 
    if(temp==0)
        cout<<"The substring is not present in given stringn";
 
    return 0;
}
