#include <iostream>

using namespace std;

// Napisz program obliczający sumę liczb wprowadzonych przez użytkownika i wypisujący wynik na standardowe wyjście. Przydatne hasła to
int main()
{
    char zgoda;
    int suma = 0;

    while (true)
    {

        cout << "Czy chcesz wprowadzic nastepna liczbe" << endl;
        cin >> zgoda;

        if (zgoda == 'T')
        {
            int liczba;

            cout << "Podaj liczbe" << endl;
            cin >> liczba;
            suma += liczba;
            cout << "Obecna suma wynosi: " << suma << endl;
        }
        else
        {
            break;
        }
    }

    return suma;
}
