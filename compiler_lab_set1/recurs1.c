#include<stdio.h>  
#include<string.h>  
#define SIZE 10  
int main () {  
       char non_terminal;  
       char beta,alpha,gamma[10];  
       int num;  
       char production[10][SIZE];  
       int index=3,j;

       printf("Enter Number of Production : ");  
       scanf("%d",&num);
  
       printf("Enter the grammar as E->E-T :\n");  
       for(int i=0;i<num;i++){  
            scanf("%s",production[i]);  
       }  
       for(int i=0;i<num;i++){  
            printf("\nGRAMMAR : : : %s",production[i]);  
            non_terminal=production[i][0];  
            if(non_terminal==production[i][index]) {  
               // alpha=production[i][index+1];
		for(j=0;production[i][index+1+j]!='|';j++)
		{
			 gamma[j]=production[i][index+1+j]
			;}gamma[j]='\0'; 
                 printf(" is left recursive.\n");  
                 while(production[i][index]!=0 && production[i][index]!='|')  
                      index++;  
                 if(production[i][index]!=0) {  
                      beta=production[i][index+1];  
                      printf("Grammar without left recursion:\n");  
                      printf("%c->%c%c\'",non_terminal,beta,non_terminal);  
			printf("\n%c\'->",non_terminal);
			for(j=0;gamma[j]!='\0';j++)
			{
				printf("%c",gamma[j]);
			}

			
			printf("%c\'|0\n",non_terminal);  
                 }  
                 else  
                      printf(" can't be reduced\n");  
            }  
            else  
                 printf(" is not left recursive.\n");  
            index=3;  
       }  
  }   
