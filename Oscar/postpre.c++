#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<string.h>
#include<typeinfo>
#include<iostream>
#define TAM 250
using namespace std;
int prioridad(char simbolo);
bool Inspectordeformulas_secuencias_T_T(char[]);
float evaluar(stack<float>,stack<char>,stack<char>); 
float CtF();
int main(){   
    int opcion,tamexp;
    stack<char> pila1;
    stack<string> pilaimpresiones;
    stack<string> pila_acomodos;
    stack<string> Ex_postfiija;
    stack<string> Ex_prefija;
    queue<string> queue_evaluacion;
    stack<string> pila_evaluacion;
    stack<float> pila_operandos;
    stack<char> operadores;
    stack<char> operadores2;
    char expinf[TAM], simbolo;
    char auxiliar[TAM];
    string cadena;
    do
    {
        cout<<("\n-Seleccione la opcion que desea\n 1.-Convertir una Expresion de Infija a Postfija\n 2.-Convertir una Expresion de Infija a Prefija\n 3.-Salir del Menu\n");
        cin>>(opcion);
        switch (opcion)
        {
        case 1:
            cout<<("\n Ingrese la expresion:\n");
            cin>>(expinf);
            if(Inspectordeformulas_secuencias_T_T(expinf)){
            tamexp=strlen(expinf);
            for (int i = 0; i < tamexp; i++)
            {
                simbolo=expinf[i];
                if (simbolo == '(')
                {
                    pila1.push(simbolo);
                }
                else if (simbolo == ')')
                {
                    while (pila1.top()!= '(')
                    { auxiliar[0]=pila1.top();
                    auxiliar[1]='\0';
                        Ex_postfiija.push(auxiliar);
                        pila1.pop();
                    }
                    pila1.pop();
                }
                else if ((simbolo >= 'a') && (simbolo <= 'z') || (simbolo >= 'A') && (simbolo <= 'Z')||isdigit(simbolo))
                {   if(isdigit(simbolo)){int x=0;
                    while (isdigit(expinf[i]))
                {  
                    auxiliar[x]=expinf[i];
                    ++i;
                    ++x;
                }
                auxiliar[x]='\0';
                }
                else{auxiliar[0]=simbolo;auxiliar[1]='\0';}
                Ex_postfiija.push(auxiliar);
                i--;
                cout<<Ex_postfiija.top();
                }
                else
                {
                    while (!pila1.empty()&& (prioridad(simbolo)<=prioridad(pila1.top())))
                    {   auxiliar[0]=pila1.top();auxiliar[1]='\0';
                        Ex_postfiija.push(auxiliar);
                        pila1.pop();
                    }
                    pila1.push(simbolo);
                    }
                }
                while(!pila1.empty()){
                    auxiliar[0]=pila1.top();auxiliar[1]='\0';
                    Ex_postfiija.push(auxiliar);
                    pila1.pop();}
                while(!Ex_postfiija.empty()){
                    pila_evaluacion.push(Ex_postfiija.top());
                    pilaimpresiones.push(Ex_postfiija.top());
                    Ex_postfiija.pop();}
                    cout<<"\nLa expresion en postfija es:\n";
                while (!pilaimpresiones.empty()){
                    cout<<pilaimpresiones.top();
                    pilaimpresiones.pop();
                }
                for (size_t l = 0; l < tamexp; l++)
        {   if(!pila_evaluacion.empty()){
            //cout<<"\n"<<pila_evaluacion.top()[0];
            if(isdigit(pila_evaluacion.top()[0]))while(isdigit(pila_evaluacion.top()[0])){
                cadena=pila_evaluacion.top();
                pila_evaluacion.pop();
                for(size_t i = 0;i<cadena.length();i++)
                {
                auxiliar[i]=cadena[i];
                }
                pila_operandos.push(atof(auxiliar));
                cout<<"\n"<<pila_operandos.top()<<" ";
            }
            else{operadores2.push(pila_evaluacion.top()[0]);
            pila_evaluacion.pop();
            if(!pila_operandos.empty()){float temp=evaluar(pila_operandos,operadores,operadores2);
            pila_operandos.pop();
            pila_operandos.pop();
            operadores2.pop();
            pila_operandos.push(temp);}
            }
            }
        }
        
        cout<<"="<<evaluar(pila_operandos,operadores,operadores2);
        }
        else cout<<"Los parentesis no estan balanceados\n";
        break;
         case 2:
            printf("\n Ingrese la expresion:\n");
            cin>>(expinf);
            if(Inspectordeformulas_secuencias_T_T(expinf)){
            tamexp=strlen(expinf);
            for (int i=tamexp-1; i>=0; i--){
                simbolo=expinf[i];
                if(simbolo==')'){
                pila1.push(simbolo);
                }
                else if(simbolo=='('){
                while (pila1.top()!=')'){
                    auxiliar[0]=pila1.top();
                    auxiliar[1]='\0';
                    Ex_prefija.push(auxiliar);
                    pila1.pop();
                }
                pila1.pop();
                }
                else if((simbolo>= 'a')&&(simbolo<='z') || (simbolo>= 'A')&&(simbolo<= 'Z')||isdigit(simbolo)){
                 if(isdigit(simbolo)){
                    int x=0,y=0;
                    char temp;
                    while (isdigit(expinf[i])&&i>=0)
                    { 
                    auxiliar[x]=expinf[i];
                    ++x;
                    --i;
                    y++;
                    }
                    y--;
                    ++i;
                    for (size_t m = 0; m <y; m++)
                    {
                        temp=auxiliar[y-m];
                        cout<<temp;
                        auxiliar[y-m]=auxiliar[m];
                        auxiliar[m]=temp;
                    }
                    auxiliar[x]='\0';
                    if(isdigit(auxiliar[x+1]))
                    auxiliar[x+1]='\0';
                }
                else {auxiliar[0]=simbolo;
                auxiliar[1]='\0';}
                Ex_prefija.push(auxiliar);
                }
                else{
                while (!pila1.empty()&&(prioridad (simbolo) <prioridad (pila1.top()))){
                    auxiliar[0]=pila1.top();
                    auxiliar[1]='\0';
                    Ex_prefija.push(auxiliar);
                    pila1.pop();}
                    pila1.push(simbolo);
                }
            }
            while (!pila1.empty()){
            auxiliar[0]=pila1.top();
            auxiliar[1]='\0';
            Ex_prefija.push(auxiliar);
            pila1.pop();
        }
         cout<<"La expresion en prefija es:\n";
            while (!Ex_prefija.empty()){
            cout<<Ex_prefija.top();
            pila_evaluacion.push(Ex_prefija.top());
            Ex_prefija.pop();
            }
        for (size_t l = 0; l < tamexp; l++)
        {   if(!pila_evaluacion.empty()){
            //cout<<"\n"<<pila_evaluacion.top()[0];
            if(isdigit(pila_evaluacion.top()[0]))while(isdigit(pila_evaluacion.top()[0])){
                cadena=pila_evaluacion.top();
                pila_evaluacion.pop();
                for(size_t i = 0;i<cadena.length();i++)
                {
                auxiliar[i]=cadena[i];
                }
                pila_operandos.push(atof(auxiliar));
                cout<<"\n"<<pila_operandos.top()<<" ";
            }
            else{operadores2.push(pila_evaluacion.top()[0]);
            pila_evaluacion.pop();
            float temp=evaluar(pila_operandos,operadores,operadores2);
            pila_operandos.pop();
            pila_operandos.pop();
            operadores2.pop();
            pila_operandos.push(temp);
            }
            }
        }
        
        cout<<"="<<evaluar(pila_operandos,operadores,operadores2);
        } else cout<<"Los parentesis no estan balanceados\n";
            break;
            case 3:
            cout<<"Hasta luego ^.^";
            break;
            default: printf("\n Opcion no valida\n");
            break;}
    } 
    while (opcion!=3);
}
int prioridad(char simbolo){
     int priori;
switch(simbolo){
case '^': priori = 3; break;
case '/': priori = 2; break;
case '*': priori = 2; break;
case '-': priori = 1; break;
case '+': priori = 1; break;
case ')': priori = 0; break;
case '(': priori = 0; break;
}
return priori;
}
float evaluar(stack<float>pila,stack<char>operadores,stack<char>operadores2) {
 float op1, op2;
 //este while lo pueden poner en el main para que no se note el copypaste
         while (!operadores2.empty())
        {
            operadores.push(operadores2.top());
            operadores2.pop();
            cout<<"\n"<<operadores.top()<<" ";
        }
 while (!operadores.empty())
 {
  switch (operadores.top()) {
   case '^':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(pow(op1, op2));
    operadores.pop();
    break;
   case '*':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1*op2);
    operadores.pop();
    break;
   case '/':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 / op2);
    operadores.pop();
    break;
   case '+':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 + op2);
    operadores.pop();
    break;
   case '-':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 - op2);
    operadores.pop();
    break;
  }
 }
 return pila.top();
}
float CtF(char*elementos)
{
	float aux;
	aux = atof(elementos);
	return aux;
}
//este si pongan el suyo pq sino nos va a cachar
bool Inspectordeformulas_secuencias_T_T(char formula[]){
    if(strlen(formula)==0)return true;
    else{
    stack<char>pila1;
    for (size_t i = 0; i <strlen(formula); i++)
    {
       if(formula[i]=='('||formula[i]=='['||formula[i]=='{')pila1.push(formula[i]);
       else if(formula[i]==')'||formula[i]==']'||formula[i]=='}')
       {   if(pila1.empty())return false;
           if(formula[i]==')'&&pila1.top()=='(')pila1.pop();
           else if(formula[i]==']'&&pila1.top()=='[')pila1.pop();
           else if(formula[i]=='}'&&pila1.top()=='{')pila1.pop();
           else return false;
       }
    }
    if(!pila1.empty())return false;
    else true;
    }
}
