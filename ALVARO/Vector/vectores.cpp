#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
//vector y stack
using namespace std;

int main(){
stack<int> objeto;
stack<int>aux;
for (int i = 0; i < 50; i++)
{
    objeto.push(rand()%10);
    int n=objeto.top();
    cout<<n;cout<<" ";
}
cout<<endl;
for (int i = 0; i < 50; i++)
{
    aux.push(objeto.top());
    objeto.pop();
    cout<<aux.top()<<" ";

}

system("pause");
return 0;  
}