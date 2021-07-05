#include <iostream>
#include <time.h>

using namespace std;

int* create_mas(int size = 10) {
    srand(time(NULL));
    int* mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = -100 + (rand() % 201);
    return mas;
}

void print_mas(int* mas, int size = 10) {
    cout << "Massiv:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}


void zad_1() {
    // вивод цифр
    int chislo;
    cout << "enter chislo ot 10000 do 99999: ";
    do {
        cin >> chislo;
        if (chislo < 10000 || chislo > 99999) cout << "Povtorite vvod" << endl;
    } while (chislo < 10000 || chislo > 99999);

    for (int i = 0; i < 5; i++)
    {
        cout << chislo % 10 << " ";
        chislo /= 10;
    }
    cout << endl;
}

void zad_2() {
    // Перевод буквы в верхний регистр
    int step_ascii = 32;
    char bykva;
    cout << "vvedite bykvy: ";
    do {
        cin >> bykva;
        if (int(bykva) < 97 || int(bykva) > 122)
            cout << "povtorite vvod" << endl;
    } while (int(bykva) < 97 || int(bykva) > 122);
    char bykva_upper = bykva - step_ascii;
    cout << bykva_upper << endl;
}


void zad_3() {
    // Среднее арифметическое массива
    int n = 10;
    int* mas = create_mas(n);
    print_mas(mas, n);

    int summ = 0;
    for (int i = 0; i < n; i++) {
        summ += mas[i];
    }

    double srednee = summ / n;
    cout << "srednee = " << srednee << endl;
    delete[]mas;

}

int main()
{
    zad_1();
    zad_2();
    zad_3();
}