#include <iostream>
using namespace std;


void zad_1(double a, double b) {
    int count = 2;
    double invent_a = 1 / a;
    double invent_b = 1 / b;
    double h = count / (invent_a + invent_b);
    cout << "sred garmonicka - " << h << endl;
}


void zad_2(double* a, double* b, double* c) {
    double min;
    double max;
    double sred;
    min = *a;
    max = *a;

    if (*b > max) max = *b;
    if (*c > max) max = *c;

    if (*b < min) min = *b;
    if (*c < min) min = *c;

    double sum = *a + *b + *c;
    sred = sum / 3;

    *a = min;
    *b = sred;
    *c = max;
}


int main()
{
    zad_1(44.2, 2.22);

    double a = 4;
    double b = 7;
    double c = 12;
    cout << "a-" << a  << " b-" << b << " c-" << c << endl;
    zad_2(&a, &b, &c);
    cout << "a-" << a  << " b-" << b << " c-" << c << endl;

}
