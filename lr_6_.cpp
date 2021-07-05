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
    for (int i = 0; i < size; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}



int zad_1(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int vvod_v_predelax(int low, int upper, double chislo) {
    if (chislo == int(chislo)) {
        if (chislo >= low && chislo <= upper) {
            return int(chislo);
        }
        else {
            return -1;
        }
    }
    else {
        return 0;
    }
}

void zad_2() {
    bool dly_chikla = true;
    int low = -1;
    int upper = -1;
    double chislo = -1;
    while (dly_chikla) {
        if (low != -1 && upper != -1 && chislo != -1) {
            cout << "____Vse dannie vvedeni____: low-" << low << " upper-" << upper << " chislo-" << chislo << endl;
        }
        cout << "1) Vvod verhnego" << endl;
        cout << "2) Vvod nignego" << endl;
        cout << "3) Vvod chisla" << endl;
        cout << "4) Exit" << endl;

        int vibor;
        do {
            cin >> vibor;
        } while (vibor < 1 || vibor > 4);

        switch (vibor) {
        case 1:
            cout << "Vvedite verxniy: ";
            if (low != -1) {
                do {
                    cin >> upper;
                    if (upper <= low) cout << "Vverxniy doljen bit bolshe nignego" << endl;
                } while (upper <= low);
            }
            else
                cin >> upper;
            break;
        case 2:
            cout << "Vvedite nigniy: ";
            if (upper != -1) {
                do {
                    cin >> low;
                    if (low >= upper) cout << "Nigniy doljen bit menshe verxnego" << endl;
                } while (low >= upper);
            }
            else
                cin >> low;
            break;
        case 3:
            cout << "Vvedite chislo: "; cin >> chislo;
            break;
        case 4: dly_chikla = false; break;
        }

        if (low != -1 && upper != -1 && chislo != -1) {
            int result = vvod_v_predelax(low, upper, chislo);
            switch (result) {
            case 0:
                cout << "Vvedennoe chislo ne chelochislennoe, vixod iz programmi" << endl;
                dly_chikla = false;
                break;
            case -1:
                cout << "Chislo ne vxodit v predeli, vozvrat k menu" << endl;
                continue;
                break;
            default:
                cout << "Chislo " << chislo << ", vxodit v predeli - " << endl;
                break;
            }
        }

    }
}


void zad_3() {
    int x;
    int n = 15;
    int* mas = create_mas(n);
    cout << "massiv" << endl;
    print_mas(mas, n);

    // Сортировка
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) {
            x = mas[j];
            mas[j] = mas[j - 1];
            mas[j - 1] = x;
        }
    }
    cout << "massiv" << endl;
    print_mas(mas, n);

    delete[]mas;
}


int main()
{
    cout << "max-" << zad_1(43, 32, 5) << endl;
    zad_2();
    zad_3();
}

