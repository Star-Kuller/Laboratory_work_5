#include <iostream>     
#include <string>

using namespace std;

struct Fraction //структура дроби (используется в заданиях 1)
{
    int up;
    int down;
};

Fraction reduction(Fraction f)
{
    int NOD = 1;
    if (f.up < f.down) {
        for (int i = 1; i < f.down; i++) {
            if ((f.up % i == 0) & (f.down % i == 0)) { // нахождение НОД, если знаменатель больше числителя
                NOD = i;
            }
        }
    }
    else {
        for (int i = 1; i < f.up; i++) {
            if ((f.up % i == 0) & (f.down % i == 0)) { // нахождение НОД, если числитель больше знаменателя
                NOD = i;
            }
        }
    }

    f.up = f.up / NOD;
    f.down = f.down / NOD;
    return f;
}

Fraction fractionMean(Fraction* f, int size)
{
    Fraction answer = f[0];
    Fraction sum = { 0, 1 };
    for (int i = 0; i < size; i++)
    {
        sum.up = (sum.up * f[i].down)+(sum.down * f[i].up);
        sum.down = sum.down * f[i].down;
        sum = reduction(sum);
    };
    answer.up = sum.up;
    answer.down = sum.down * size;
    return reduction(answer);
}

template <typename T>
void pushBack(T *&arr, int &size, T newValue) { // увеличивает размер динамического массива на 1 ячейку и вноссит в него новые данные, инкрементирует size
    T *newArr = new T[size+1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue;
    size++;
    delete[] arr;

    arr = newArr;
}

void N_1()
{
    char dummychar;
    cout << "\n>----------------[Начало выполнения N_1]----------------<\n";
    int size = 0;
    Fraction temp;
    Fraction *arrFraction = new Fraction[size];
    do {
        cout << "Введите " << size + 1 << "-ую дробь или 0x0 чтобы найти среднее значение: ";
        cin >> temp.up >> dummychar >> temp.down;
        if (!((dummychar == 'х') | (dummychar == 'Х') | (dummychar == 'x') | (dummychar == 'X'))) {
            pushBack(arrFraction, size, temp);
        }
    } while (!((dummychar == 'х')|(dummychar == 'Х')|(dummychar == 'x') | (dummychar == 'X')));
    cout << "---------------------------------------------\n";
    if (size == 0) {
        cout << "Вы не ввели ни одной дроби\n";
    } else {
        cout << "Средняя дробь: " << fractionMean(arrFraction, size).up << '/' << fractionMean(arrFraction, size).down;
    }
    cout << "\n\n>----------------[Конец выполнения N_1]----------------<\n";
    delete [] arrFraction;
    return;
}

int maxint(int *arr, int size) {
    int temp = arr[0];
    int maxIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>temp) {
            temp = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void N_2()
{
    cout << "\n>----------------[Начало выполнения N_2]----------------<\n";
    string userInput;
    int size = 0;
    int temp = 0;
    int* arr = new int[size];
    bool reading = true;
    do {
        cout << "Введите " << size << "-ое число или \"Start\", чтобы найти максимальное значение: ";
        cin >> userInput;
        for (int i = 0; userInput[i] != '\0'; i++) {
            if (!((userInput[i] == '1') | (userInput[i] == '2') | (userInput[i] == '3') | (userInput[i] == '4') | (userInput[i] == '5') | (userInput[i] == '6') | (userInput[i] == '7') | (userInput[i] == '8') | (userInput[i] == '9') | (userInput[i] == '0') | (userInput[i] == '-'))) {
                reading = false;
            }
        }
        if (reading) {
            temp = stoi(userInput);
            pushBack(arr, size, temp);
        }
    } while (reading);
    cout << "---------------------------------------------\n";
    if (size == 0) {
        cout << "Вы не ввели ни одного числа\n";
    }
    else {
        cout << "Максимальное число \"" << arr[maxint(arr, size)] << "\" под индексом - " << maxint(arr, size);
    }
    cout << "\n\n>----------------[Конец выполнения N_2]----------------<\n";
    delete[] arr;
}

void N_3()
{
    cout << "\n>----------------[Начало выполнения N_3]----------------<\n";
    
    cout << "\n\n>----------------[Конец выполнения N_3]----------------<\n";
}

void N_4()
{
    cout << "\n>----------------[Начало выполнения N_4]----------------<\n";

    cout << "\n\n>----------------[Конец выполнения N_4]----------------<\n";
}

void N_5()
{
    cout << "\n>----------------[Начало выполнения N_5]----------------<\n";
    
    cout << "\n\n>----------------[Конец выполнения N_5]----------------<\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int selected;
    while (true) {
        cout << "\n\n>--------------------[Главное меню]--------------------<\n";
        cout << "0 - Завершить работу\n1,2,3,4,5 - доступные задания\n";
        cout << "Выберите задание или 0: "; cin >> selected;
        switch (selected)
        {
        case 0:
            return 0;
            break;
        case 1:
            N_1();
            break;
        case 2:
            N_2();
            break;
        case 3:
            N_3();
            break;
        case 4:
            N_4();
            break;
        case 5:
            N_5();
            break;
        default:
            break;
        }
    }
    return 0;
}