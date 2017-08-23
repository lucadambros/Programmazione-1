#include <iostream>

using namespace std;

struct nodo {
    int info;
    nodo *next;
    nodo(int a=0, nodo* b=0){info = a; next = b;}
};


nodo* ordine(int k, nodo *L){
   
    if (!L)
        return new nodo(k,NULL);

    if (k<(L->info)){
        return new nodo(k,L);
    }

    L->next = ordine(k,L->next);
    
    return L;
}


nodo* inserisci_in_ordine(int k, nodo *L)
{   if(k==-1) return L->next;
    L = ordine(k,L);
    cin>>k;
    L=inserisci_in_ordine(k,L);
    return L;
}

void stampa(nodo* L){
    if(!L){ cout<<endl; return;}
    cout<<L->info << " ";
    stampa(L->next);
}


int main() 
{
    cout << "start" << endl;
    nodo* L= new nodo();
    int c;
    cin>>c;
    L = inserisci_in_ordine(c, L);
    stampa(L);
    cout << "end" << endl;
}