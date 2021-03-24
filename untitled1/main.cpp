/*Класс «Рациональное число»(РЧ).Поля: числитель, знаменатель.Методы : перегрузка
операции приведения типа к float, операций умножения « * » двух РЧ и РЧ с целым числом,
сравнения на равенство « == » двух РЧ и РЧ с целым числом.*/

#include <iostream>
#include <string>

using namespace std;


class Rational {
    int numerator; //числитель
    int denominator; //знаменатель
    int integer;
public:
    const string ENTER_NUMERATOR = "Введите числитель: ";
    const string ENTER_DENOMINATOR = "Введите знаменатель: ";
    const string ENTER_INTEGER = "Введите целое число: ";

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
    int GetInteger() {
        return integer;
    }
    void SetNumerator(int valueNumerator) {
        numerator = valueNumerator;
    }
    void SetDenominator(int valueDenominator) {
        denominator = valueDenominator;
    }
    void SetInteger(int valueInteger) {
        integer = valueInteger;
    }
    void Print() {
        cout << "Вы ввели РЧ " << numerator << "/" << (float)denominator << endl;
    }
    void Print(float x) {
        cout << "\nЭто число в десятичной форме имеет вид " << x << endl;
    }
    void Print(int x) {
        cout << "\nВы ввели целое число " << x << endl;
    }
    operator float();
    void Composition(float x, float y){
        float composition;
        composition = x * y;
        cout << "Произведение чисел " << composition << endl;
    }
    void Composition(int x, float y) {
        float composition;
        composition = x * y;
        cout << "Произведение чисел " << composition << endl;
    }
    void Equality(float x, float y){
        if (x == y)
            cout << "Числа равны" << endl;
        else
            cout << "Числа не равны!" << endl;
    }
    void Equality(int x, float y) {
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
    int num, dem, integer;
    float x, y, proizv;
    Rational numDelDem;


    char menu;
    do {
        system("CLS");
        puts("1. Посмотрить РЧ в десятичном виде");
        puts("2. Умножить РЧ на РЧ");
        puts("3. Проверить РЧ и РЧ на равенство");
        puts ("4 Умножить РЧ на целое число");
        puts ("5 Проверить РЧ и целое число на равенство");
        puts("6. Выход");
        menu = getchar();
        switch (menu)
        {
            case '1': {
                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;
                numDelDem.Print(x);
                system("pause");
                break;
            }
            case '2':
            {
                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR<< endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                y = (float)numDelDem;
                numDelDem.Composition(x, y);

                system("pause");
                break;
            }
            case '3':
            {
                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                y = (float)numDelDem;
                numDelDem.Equality(x, y);
                system("pause");
            }
            case '4':
            {
                cout << numDelDem.ENTER_INTEGER << endl;
                cin >> integer;
                numDelDem.SetInteger(integer);
                numDelDem.Print(integer);

                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR<< endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                y = (float)numDelDem;
                numDelDem.Composition(integer, y);

                system("pause");
                break;
            }
            case '5':{
                cout << numDelDem.ENTER_INTEGER << endl;
                cin >> integer;
                numDelDem.SetInteger(integer);
                numDelDem.Print(integer);

                cout << numDelDem.ENTER_NUMERATOR << endl;
                cin >> num;
                cout << numDelDem.ENTER_DENOMINATOR << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                y = (float)numDelDem;
                numDelDem.Equality(integer, y);
                system("pause");
            }
            case '6': {
                system("CLS");
                return 0;
                break;
            }
        }
    } while (true);
    return 0;
}

