#include<stdio.h>

main(int argc , char *argv[])
{
    FILE *fp,*fp1;
    char ch;
    fp=fopen(argv[1],"r");
    fp1=fopen(argv[2],"w");

    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
                break;
        else
        {
                if(ch=='/')
                {
                        ch=fgetc(fp);
                        if(ch=='/')
                        {
                                while(1)
                                {
                                        ch=fgetc(fp);
                                        if(ch=='\n')
                                                goto label;
                                }
                        }
                        if(ch=='*')
                        {
                                while(1)
                                {
                                        ch=fgetc(fp);
                                        if(ch=='*')
                                        {
                                                ch=fgetc(fp);
                                                if(ch=='/')
                                                {
                                                        while(1)
                                                        {
                                                                ch=fgetc(fp);
                                                                goto label;
                                                         }
                                                }
                                                else
                                                        printf("*");
                                        }
                                }
                        }
                        else
                                printf("/");
                }
        }
        label:
                fputc(ch,fp1);
    }
    fclose(fp);
    fclose(fp1);
}
