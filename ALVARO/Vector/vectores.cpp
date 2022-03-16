#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
//vector y stack
using namespace std;

int main(){
stack<int> objeto;
for (int i = 0; i < 50; i++)
{
    objeto.push(rand());
}
for (int i = 0; i < 50; i++)
{
    printf("%i",objeto);
}


return 0;  
}