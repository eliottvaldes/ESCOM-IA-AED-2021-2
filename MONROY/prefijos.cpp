#include <iostream>
#include <stack>

using namespace std;
stack<char> infijo (int, char, stack<char>, stack<char>);

int main()
{
    string expresion;
    int aux;
    char objeto;
    stack<char> salida;
    stack<char> operador;
    cout << "Porfavor digite la expresion en su forma infija" << endl;
    cin >> expresion;
    aux = expresion.size();
    string expresionaux;
    for (int i = 0; i < expresion.size(); i++)
    {
        expresionaux[aux] = expresion[i];
        aux--;
    }
    // *Imprimir La funcion invertida
    /*for (int i = 0; i <= expresion.size(); i++)
    {
        cout << expresionaux[i];
    }
    */
    int posision=0;
    objeto = expresionaux[posision];
    
}

stack<char> infijo(int posision, char objeto, stack<char>salida, stack<char>operador)
{
    if (objeto == ')')
    {
        do
        {
            posision++;
            salida.push(objeto);
        } 
        while (objeto == '+' | objeto == '-' | objeto == '*' | objeto == '/');
        {
            operador.push(objeto);
        }
    }
    else
    {
        posision++;
    }
}