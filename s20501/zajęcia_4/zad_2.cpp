#include <iostream>
#include <cstdlib>

using namespace std;

void draw_sign_line(int count, char sign)
{
    for (int i = 0; i < count; i++)
    {
        cout << sign;
    }
}

// Napisz program wyświetlający tradycyjną choinkę o zadanej wysokości. Wysokość niech będzie podana jako parametr wywołania
int main(int argc, char **argv)
{
    string argumnet(argv[1]);
    const int height = atoi(argumnet.c_str());
    int stars = 1;

    for (int i = height; i > 0; i--)
    {
        draw_sign_line(i, ' ');
        draw_sign_line(stars, '*');
        stars += 2;
        cout << endl;
    }
    return 0;
}
