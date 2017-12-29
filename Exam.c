#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noob
{
    char name[30];
    char SDT[12];
    struct noob *next;
};

typedef struct noob noob;

int menu()
{
    printf("1.Doc File danhsach.txt\n2.Them Nguoi Mua\n3.Ban Hang\n4.Ghi thong tin sau 1 ngay\n5.Thong Ke thong tin ban hang\n6.Yeu Cau Dac Biet\n7.Thoat\n");
    char s[10];
    scanf("%[^\n]%*c", s);
    int c = (int)atoi(s);
    return c;
}

int rFile(char *file, noob ** tree)
{
    FILE *f;
    f = fopen(file, "r");
    if (f==NULL) {perror("LOI"); return 1;}
    while (1)
    {
        //////// doc mot dong trong file
        char line[100];
        if (fscanf(f, "%[^\n]%*c", line) == EOF) break;
        
        ///////////////////////////// doc cau truc cua 1 dong
        char name[30];
        char SDT[12];
        sscanf(line, "%s %s", name, SDT);
        
        /////////////////////// dua vao cay
        noob *new = makeNoob(key);
        addNoob(tree, &new); // 
    }
    return 1;
}

int main()
{
    int c;
    while (c!=7)
    {
        c = menu();
        switch (c)
        {
            case 1: //docFile("danhsach.txt", &khach, &rearKhach);
            break;          
        }
    }
    return 1;
}