#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int CadenaNum[4];
    CadenaNum[0] = 6;
    CadenaNum[1] = 9;
    CadenaNum[2] = 1;
    CadenaNum[3] = 7;
    int Caract = 4;
    int temp, i, j;
        for(int i=0; i<Caract; i ++)
    {
        printf("%d\n", CadenaNum[i]);
    }
    for (i = 0; i < 4; i++)
    {
        j=i;
        temp = CadenaNum[i];
        while((j > 0) && (temp<CadenaNum[j-1]))
        {
            CadenaNum[j] = CadenaNum[j - 1];
            j --;
        }
        CadenaNum[j] = temp;
    }
    for(int i=0; i<Caract; i ++)
    {
        printf("%d", CadenaNum[i]);
    }
}