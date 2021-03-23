/*Класс «Рациональное число»(РЧ).Поля: числитель, знаменатель.Методы : перегрузка
операции приведения типа к float, операций умножения « * » двух РЧ и РЧ с целым числом,
сравнения на равенство « == » двух РЧ и РЧ с целым числом.*/

#include <iostream>
#include <string>

using namespace std;


class Rational {

public:
    int numerator; //числитель
    int denominator; //знаменатель
    Rational(int valueNumerator = 2, int valueDenominator = 4) {
        numerator = valueNumerator;
        denominator = valueDenominator;
    }
    int GetNumerator() {
        return numerator;
    }
    int GetDenomirator() {
        return denominator;
    }
    void SetNumerator(int valueNumerator) {
        numerator = valueNumerator;
    }
    void SetDenominator(int valueDenominator) {
        denominator = valueDenominator;
    }
    void Print() {
        cout << "Вы ввели " << numerator << "/" << (float)denominator << endl;
    }
    void Print(float x) {
        cout << x << endl;
    }
    operator float();
    float Proizv(float x, float y){
        return x * y;
    }
    float Proizv(int x, float y) {
        return x * y;
    }
    void Ravenstv(float x, float y){
        if (x == y)
            cout << "Числа равны" << endl;
        else
            cout << "Числа не равны!" << endl;
    }
    void Ravenstv(int x, float y) {
        if (x == y)
            cout << "Числа равны" << endl;
        else
            cout << "Числа не равны!" << endl;
    }
};
Rational::operator float()
{
    return (float)numerator / denominator;
}


int main() {
    system("chcp 65001");
    int num, dem;
    float x, y, proizv;
    Rational numDelDem;


    char menu;
    do {
        system("CLS");
        puts("1. Посмотрить РЧ в десятичном виде");
        puts("2. Умножить два РЧ или РЧ и целое число");
        puts("3. Проверить числа на равенство");
        puts("4. Выход");
        menu = getchar();
        switch (menu)
        {
            case '1': {cout << "Введите числитель: " << endl;
                cin >> num;
                cout << "Введите знаменатель: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;
                cout << "\nЭто число в десятичной форме имеет вид " << x << endl;
                system("pause");
                break;
            }
            case '2':
            {
                cout << "Введите числитель: " << endl;
                cin >> num;
                cout << "Введите знаменатель: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << "Введите числитель: " << endl;
                cin >> num;
                cout << "Введите знаменатель: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                y = (float)numDelDem;
                proizv = x * y;
                cout << "Произведение чисел " << proizv << endl;
                system("pause");
                break;
            }
            case '3':
            {
                cout << "Введите числитель: " << endl;
                cin >> num;
                cout << "Введите знаменатель: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << "Введите числитель: " << endl;
                cin >> num;
                cout << "Введите знаменатель: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                y = (float)numDelDem;
                numDelDem.Ravenstv(x, y);
                system("pause");
            }
            case '4':
                system("CLS");
                return 0;
                break;
        }
    } while (true);
    return 0;
}

