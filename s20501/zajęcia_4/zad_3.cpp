
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Napisz program wczytujący z pliku tekstowego ciąg liczb. Format pliku jest taki:
//
//     liczba elementów ciągu
//     Kolejne liczby
//
// Niech program wypisze je w odwrotnej kolejności.
int main()
{

    ifstream inFile;
    int liczba;
    int count;

    inFile.open("test.txt");

    if (!inFile)
    {
        cout << "Nie udalo sie otworzyc pliku";
        return 0;
    }

    while (inFile >> liczba)
    {
        count = liczba;
        break;
    }

    int *tab;
    tab = new int[count];

    int index = 0;

    while (inFile >> liczba)
    {

        tab[index] = liczba;
        index++;
    }

    inFile.close();

    for (int i = count; i > 0; i--)
    {
        cout << tab[i - 1] << endl;
    }
    return 0;
}
