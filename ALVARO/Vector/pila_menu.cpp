#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;



stack<string> palabra_ini(stack<string> pila);
stack<string> palabra_fin(stack<string> pila);
stack<string> palabra_pos(stack<string> pila);
stack<string> imp_ini(stack<string> pila);
stack<string> imp_fin(stack<string> pila);
/*stack<string> elim_inicio(stack<string> pila);
stack<string> elim_fin(stack<string> pila);
stack<string> elim_pos(stack<string> pila);*/





int main(){
    stack<string> pila;

	int opt=0;
    do
    {
        cout<<endl<<"introduce la opción deseada"<<endl<<"1.-Agregar palabra a inicio"<<endl<<"2.-Agregar palabra fin"<<endl<<"3.-Agregar palabra pos N"<<endl<<"4.-Imprimir inicio a fin"<<endl<<"5.-Imprimir fin a inicio"<<endl<<"6.-Elimina al inicio"<<endl<<"7.-Elimina al final"<<endl<<"8.-Elimina en posicion"<<endl<<"9.-Salir"<<endl;
		cin>>opt;
		switch (opt)
        {
        case 1:
            pila=palabra_ini(pila);
            break;
        case 2:
            pila=palabra_fin(pila);
            break;
        case 3:
            pila=palabra_pos(pila);
            break;
        case 4:
            imp_ini(pila);
            break;
        default:
            break;
        }
		
	
	
	
	
	system("cls");
    } while (opt!=9);
    
	return 0;
}

stack<string> palabra_ini(stack<string> pila){
        string aux;
        cout<<"Introduce la palabra que quieras poner"<<endl;
        cin>>aux;
        pila.push(aux);
        return pila;
}

stack<string> palabra_fin(stack<string> pila){
        //se copia toda la estructura y se procede a escribir al final
        stack<string> aux_str;
        int tam=pila.size();
        for (int i = 0; i < tam; i++)
        {
            aux_str.push(pila.top());
            pila.pop();
        }
        cout<<"Introduce tu palabra";
        string aux;
        cin>>aux;
        pila.push(aux);
        for (int i = 0; i < tam; i++)
        {
            pila.push(aux_str.top());
            aux_str.pop();
        }
        
        return pila;
}




stack<string> palabra_pos(stack<string> pila){

}





stack<string> imp_ini(stack<string> pila){
    int tam=pila.size();
            for (int i = 0; i < tam; i++)
            {
                cout<<pila.top()<<" ";
                pila.pop();
            }
            cout<<endl;
            system("pause");
}


stack<string> imp_fin(stack<string> pila){
    int tam=pila.size();
    stack<string> str_aux;
    for (int i = 0; i < tam; i++)
    {
        str_aux.push(pila.top());
        pila.pop();
    }
    
}