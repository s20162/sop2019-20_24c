#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>

using namespace std;

struct Node{
int number;
struct Node* Next;
struct Node* Prev;
};

struct Start_Stop{
Node* start;
Node* stop;
};

void createList(int, Start_Stop*);
void AddElement(int, Start_Stop*);
void DeleteElement(int, Start_Stop*);
void drawList(Start_Stop*);

int main()
{
    int c;
    int n, d;
    Start_Stop *p;
    p = new Start_Stop;


    cout << "Podaj dlugosc listy" << endl;
    cin >> n;
    createList(n, p);
    drawList(p);
    do{
    cout << "[1] - dodaj element\n[2] - usun element\n";
    cin >> c;
    if(c == 1){
    cout <<"Jaka wartosc dodac do listy?\n";
    cin >> d;
    AddElement(d, p);
    drawList(p);
    }
    else if (c == 2){
    cout <<"Ktora wartosc usunac z listy?\n";
    cin >> d;
    DeleteElement(d, p);
    drawList(p);
    }
    cout <<"aby wyjsc nacisnij [q]\ndowolny [klawisz] aby kontynuowac\n";
}while (getch() != 'q');

    return 0;
}

void createList(int NUMelements, Start_Stop* p){
int El;
p->start=NULL;
    p->stop=NULL;
cout <<"Podaj zawartosc listy:" << endl;
for (int i = 0; i < NUMelements; i++){
    cout << "El." << i+1 <<": ";
    cin >> El;

 AddElement(El, p);
    }
}
void AddElement(int Element, Start_Stop *p){
Node *Lista;
Lista = new Node;

if(p->start == NULL){           //dla pierwsego elementu
p->start = Lista;
p->stop = Lista;
}
else
{
    Lista->Prev = p->stop;
    p->stop->Next = Lista;  //doloaczanie elementu na koncu
    p->stop = Lista;

}
Lista->Next = NULL;
Lista->number = Element;
}


void DeleteElement(int Element, Start_Stop *p){
Node *deletor, *before, *after;
bool check;
check = false;

deletor = p->start;
if(p->start == NULL){
    cout << "Lista jest pusta\n";
}
else{
    do{
        if(Element == deletor->number){
            check = true;

            if(deletor == p->start){
                p->start = p->start->Next;
                delete deletor;
            }
            else if (deletor == p->stop){
                p->stop = p->stop->Prev;
                delete deletor;


            }
            else{
                after = deletor->Next;
                before = deletor->Prev;
                before->Next=after;
                delete deletor;
            }

        }

        else {
                if (deletor != NULL){
                before = deletor;
            deletor = deletor->Next;
}
}

    }while (deletor != NULL && check==false);
    if(check == true){
    cout << "Wezel z wybranym elementem ( " << Element <<" ) zostal usuniety\n";
    }
    else{
    cout << "Nie ma takiego elementu\n";
    }
}
}

void drawList(Start_Stop *p){
Node *drawer;
drawer = p->start;
if(p->start == NULL){
    cout <<"Lista jest pusta\n";
}
else{
    cout << "\n\n";
    while(drawer != NULL){
        if (drawer == p->stop){
            cout << "( "<< drawer->number <<" )\n";
        }
        else{
        cout << "( "<< drawer->number <<" )";
        cout <<" <-> ";
        }
        drawer = drawer->Next;
    }
}
}





