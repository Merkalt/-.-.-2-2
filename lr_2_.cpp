#include <iostream>
#include <time.h>

using namespace std;

void zad_1() {
    // Решение квадратного уравнения
    float a;
    float b;
    float c;
    float x;
    cout << "Vvedite a: ";
    cin >> a;
    cout << "Vvedite b: ";
    cin >> b;
    cout << "Vvedite c: ";
    cin >> c;

    float discriminant = (b * b - 4 * a * c);

    if (discriminant >= 0) {
        x = (-1 * b + sqrt(discriminant)) / (2 * a);
        cout << "x1 - " << x << endl;
        x = (-1 * b - sqrt(discriminant)) / (2 * a);
        cout << "x2 - " << x << endl;
    }
    else {
        cout << "Discrimminant menhe 0" << endl;
    }
}

void zad_2() {
    // Нахождение значение в диапазоне
    int a, b;
    cout << "levay granicha: " << endl;
    cin >> a;
    cout << "pravy granicha: " << endl;
    do {
        cin >> b;
        if (b < a) cout << "Pravay doljna bit bolshe levoy" << endl;
    } while (b < a);
    srand(time(NULL));
    int result = a + (rand() % b - a);
    cout << "result- " << result << endl;
}

void zad_3() {
    // Сортировка пузырьком
    const int N = 10;
    int mas[N];
    int x;
    cout << "enter value massive" << endl;
    for (int i = 0; i < N; i++)
        cin >> mas[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                x = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = x;
            }
        }
    }

    cout << "result massiv" << endl;
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
}

int main()
{
    zad_1();
    zad_2();
    zad_3();
}

