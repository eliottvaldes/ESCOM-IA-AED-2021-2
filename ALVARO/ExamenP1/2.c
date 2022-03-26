/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
 #include<stdio.h>/*   []  \n */
 #include<stdlib.h>
 #include<string.h>



void main(){
    FILE *flujo=fopen("datos.txt","r");
    if (flujo==NULL)
    {
        puts("error en abrir el archivo");
        system("pause");
        exit(1);
    }
    char c;
    while (c!=EOF)
    {
        printf("%c",c);
        c=getc(flujo);
    }
    puts("\n");
    system("pause");
}