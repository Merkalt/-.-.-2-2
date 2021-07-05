#include <iostream>
#include <string>
#include <time.h>
using namespace std;


int* create_mas(int size = 10){
    srand(time(NULL));
    int *mas = new int[size];
    for(int i = 0; i < size; i++)
        mas[i] = -100 + (rand() % 201);
    return mas;
}

void print_mas(int *mas, int size = 10){
    for(int i = 0; i < size; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
}


void zad_1() {
    // Исключение из массива всех отрицательных чисел
    int n = 20;
    int* mas = create_mas(n);
    cout << "start massiv" << endl;
    print_mas(mas, n);

    int polojit = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] >= 0)
            polojit++;
    }

    int* new_arr = new int[polojit];
    for (int i = 0, j = 0; i < n; i++) {
        if (mas[i] >= 0)
            new_arr[j++] = mas[i];
    }

    cout << "end massiv" << endl;
    print_mas(new_arr, polojit);

    delete[]mas;
    delete[]new_arr;
}


void zad_2() {
    // Вывод гласных
    int ascii[6] = {97, 101, 105, 111, 117, 121}; // номера ASCII гласных
    int step = 32;
    string str;
    cout << "vvedine stroky: " << endl;
    cin >> str;
    bool glasnoe;
    for (int i = 0; i < str.size(); i++) {
        glasnoe = false;
        for (int j = 0; j < 6; j++) {
            if (int(str[i]) == ascii[j] || int(str[i]) == (ascii[j] - 32)) {
                glasnoe = true;
                break;
            }
        }
        if (glasnoe) {
            cout << str[i] << " ";
        }
    }
    cout << endl;
}


int main()
{
    zad_1();
    zad_2();

}
