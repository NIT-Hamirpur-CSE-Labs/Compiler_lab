 #include<stdio.h>  
  #include<string.h>  
  int main()  
  {  
       char gram[20],p1[20],p2[20],modifiedGram[20],newGram[20],tempGram[20];  
       int i,j=0,k=0,l=0,pos;  
       printf("Enter Production : S->");  

	scanf("%s", gram);

       //setting grammer in part 1 and 2
	for(i=0;gram[i]!='|';i++,j++)  
            p1[j]=gram[i];  
       p1[j]='\0';  
       for(j=++i,i=0;gram[j]!='\0';j++,i++)  
            p2[i]=gram[j];  
       p2[i]='\0';


  
       for(i=0;i<strlen(p1)||i<strlen(p2);i++)  
       {  
            if(p1[i]==p2[i])  
           {  
                 modifiedGram[k]=p1[i];  
                 k++;  
                 pos=i+1;  
            }  
       }  
       for(i=pos,j=0;p1[i]!='\0';i++,j++){  
            newGram[j]=p1[i];  
       }  
       newGram[j++]='|';  
       for(i=pos;p2[i]!='\0';i++,j++){  
            newGram[j]=p2[i];  
       }  
       modifiedGram[k]='A';  
       modifiedGram[++k]='\0';  
       newGram[j]='\0';  
       printf("\n S->%s",modifiedGram);  
       printf("\n A->%s\n",newGram);  
 }
