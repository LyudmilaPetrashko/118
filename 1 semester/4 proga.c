#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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


void create_files (void)// нужно сздать файлы через цикл и проверить их на открытие
{
    //FILE *f1, *f2, *f3;
    int  i = 0, j=1, n;
    scanf("%d", &n);
    int k=97;
    char y[] = "a.dat";
    FILE* f;
    for(i; i<n; i++){
    //f1 = fopen ("a.dat","w");
    //f2 = fopen ("b.dat","w");
    //f3 = fopen ("c.dat","w");
        j=1;
        f=fopen( y , "w");
        if(f!=NULL){
            while (j < 6)
            {
                fprintf (f,"Record %d in file \"%s\"\n", j, y);
          //fprintf (f2,"Record %d in file \"b.dat\"\n", j);
          //fprintf (f3,"Record %d in file \"c.dat\"\n", j);
                j++;
            }
            }
            else printf("don't work");
        fclose(f);
        y [0]++;
    }
    //fclose (f1);
    //fclose (f2);
    //fclose (f3);
}


void analyze_file ( FILE *file_name)
{
    char l;
    int a = 0, Enter=0;
    l = getc(file_name);
    while (l != EOF)
    {
        if(l == 'a')
            { a++; }
        else if ( l == '\n')
            { Enter++;}
       printf("%c",l);
        l = getc(file_name);
    }
    printf("\n a = %d\n", a);
    printf(" /n = %d\n", Enter);
}


int main()
{
    FILE *f;
    f = fopen("file.txt", "r");
    create_files();
    printf("\n");
    if(f==NULL) printf("don't work");
    else{
    //char* z;
    //float k;
    //fscanf(f, "%s%f", z, &k);
    analyze_file(f);
    printf("\n\n");
    fclose (f);
    f = fopen("file.txt", "r");
    print_file(f);
    fclose (f);
    }
    return 0;
}
