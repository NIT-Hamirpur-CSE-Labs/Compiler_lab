#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<cstring>
using namespace std;
struct pgm
 {
   char line[20];
 } s[100];
void check(char s[])
 {
    cout<<"\n";
    if(!strcmp(s,"If"))
     {
        cout<<"keyword:If";
        return;
     }
    if(!strcmp(s,"Then"))
     {
       cout<<"keyword:Then";
       return;
     }
    if(!strcmp(s,"Else"))
     {
       cout<<"keyword:else";
       return;
     }
    if(!strcmp(s,"[END]"))
     {
       return;
      }
    cout<<"expression:"<<s;
 }
int main()
 {
   char t[20];
   int i=0,j=0,k=0;
   cout<<"\n\n enter the program code:(to stop input type End)\n";
   do
    {
      cin>>(s[i].line);
    }
 while(strcmp(s[i++].line,"END"));
  k = k-1;
  do
   {
     k++;
     for(i=0;s[k].line[i]!='\0';i++,j++)
   {
     if(s[k].line[i]==' ')
      {
        t[j]='\0';
        j=-1;
       check(t);
      }
    else
       t[j]=s[k].line[i];
  }
 t[j]='\0';
 j=0;
check(t);
  }
 while(strcmp(s[k].line,"END"));
}


