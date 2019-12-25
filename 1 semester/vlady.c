#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void print_file (FILE *f)
{
    int a;
    a = fgetc(f);

    while (a != EOF)
    {
        if (a == 'a')
          { printf("?"); }
        else
          { printf("%c", a);}
        a = fgetc(f);
    }
    printf("\n");

}


void create_files (void)
{
    int  i = 0, j=1, n;
    printf ("Number of files: ");
    scanf("%d", &n);
    char y[] = "a.dat";
    FILE* f;
    for(i = 0; i<n; i++){
        j=1;
        f=fopen( y , "w");
        if(f!=NULL){
            while (j < 6)
            {
                fprintf (f,"Record %d in file \"%s\"\n", j, y);
                j++;
            }
            }
            else printf("error");
        fclose(f);
        y [0]++;
    }
}


void analyze_file (const char *file_name)
/*{
    int l;
    int a = 0, Enter=0;
    while (l=getc(file_name) != EOF)
    {
        if(l == 'a')
            { a++; }
        else if ( l == '\n')
            { Enter++;}
       printf("%c",getc(file_name));

    }
    printf("\n a = %d\n", a);
    printf(" \n = %d\n", Enter);
}*/
{
    int l;
    int a = 0, Enter=0;
    FILE *f=fopen(file_name, "r");
    l = getc(f);
    while (l != EOF)
    {
        if(l == 'a')
            { a++; }
        else if ( l == '\n')
            { Enter++;}
       printf("%c",l);
        l = getc(f);
    }
    printf("\n a = %d\n", a);
    printf(" /n = %d\n", Enter);
}



int main()
{
//    FILE *f;
//    f = fopen("file.txt", "r");
    create_files();
    analyze_file ("a.dat");
//    printf("\n");
    return 0;
}
