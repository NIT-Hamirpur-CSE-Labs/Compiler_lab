#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


 
int main()
{	
	char p,ch;
    char fname[50];
	FILE *f1,*f2;
	
printf("enter file name\n");
scanf("%s",fname);
f1 = fopen(fname,"r");

	if(f1==NULL)
	{
	 printf("file not found");
	 exit(0);
	}
            f2=fopen("newfile.txt","w");  //all the content gets copied to this filename and extra blank spaces are also removed from your file
 			//removing tab
            while((p=getc(f1))!=EOF)
            {
 
                
                if (p=='\t') // since the ascii code for a blank space is 32
                    {
                              while((p=getc(f1))=='\t')
                              {
                              }
                    //fputc(p,f2);
                    }
                /*else if(p=='\n')
                	{
                              while((p=getc(f1))=='\n')
                              {
                              }
                    
                  */  }    
                fputc(p,f2);
            }
            //removing comments
 
fclose(f1);
fclose(f2);
}