#include <iostream>

using namespace std;

typedef int (*functions)(int a, int b);

int sum (int a, int b);
int maks( int a, int b);
int min (int a, int b);

int getFunctionsIndex ();
int getNumOfElements();
void createArray(int tab [], int n);
void processArray(int, int[], functions [], int, int);

int main(int argc, char **argv){
int v;
functions fun [] = {maks, min, sum};
int FunctionID = getFunctionsIndex();
int NumOfElements = getNumOfElements();
int tab [NumOfElements];
createArray(tab, NumOfElements);


processArray(v, tab, fun, FunctionID, NumOfElements);

return 0;
}

int sum(int a, int b){
	return a+b;
}

int maks(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int getFunctionsIndex (){
	int z = 0;
	cout << "Podaj numer indexu [0 - 2] 0-maksimum, 1-minimum, 2-suma"<< endl;
	cin >> z;
	return z;
}
int getNumOfElements(){
	int n = 0;
	cout << "Podaj liczbe elementow ciagu" << endl;
	cin >> n;
	return n;
}
void createArray(int tab[], int n){
	int i = 0;
	for (i = 0; i < n; i++){
	cout <<	"Podaj " << i+1<< " liczbe ciagu: "<<endl;
    cin >> tab[i];
	}
}
void processArray(int v, int tab[], functions fun[], int FunctionID, int NumElements){
v = tab[0];
int i;
for (i = 1; i < NumElements; i++){
    v = fun[FunctionID](v, tab[i]);
    cout << "Process #" << i <<": " << v <<endl;
}
}
