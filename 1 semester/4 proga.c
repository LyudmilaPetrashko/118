#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void create_files (void)// нужно сздать файлы через цикл и проверить их на открытие
{
    //FILE *f1, *f2, *f3;
    int  i = 0, j=1, n;
    scanf("%d", &n);
    int k=97;
    char y[6];
    y[1]='.';
    y[2]='d';
    y[3]='a';
    y[4]='t';
    y[5]='\0';
    FILE* f;
    for(i; i<n; i++){
        y[0]=(k+i);
        f=fopen( y , "w");
        if(f!=NULL){
            while (j < 6){
            fprintf (f,"Record %d in file \"%s\"\n", j, y);
                j++;
            }
         }
        else printf("don't work");
        fclose(f);
    }
    f = fopen ("a.dat","r");
    print_file(f);
    fclose(f);
}


void analyze_file (const char *file_name)
{
    char l;
    int a = 0, Enter;
    l = getc(file_name);
    if(l==EOF)  Enter=0;
    else{
        Enter=1;
        while (l != EOF)
        {
            if(l == 'a')
                { a++; }
            else if ( l == '\n')
                { Enter++;}
            printf("%c",l);
            l = getc(file_name);
        }
    }
    printf("\n a = %d\n", a);
    printf(" /n = %d\n", Enter);
}

void print_file (FILE *f)
{
    char a;
    a = fgetc(f);
    while (a != EOF) //NULL
    {
        if (a == 'a')
          { printf("?"); }
        else
          { printf("%c", a);}
        a = fgetc(f);
    }
    printf("\n");

}


int main()
{

    FILE *f;
    f = fopen("file.txt", "r");
    create_files();
    if(f==NULL) printf("don't work");
    else{
    analyze_file(f);
    fclose (f);
    }
    return 0;
}
