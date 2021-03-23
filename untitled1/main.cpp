/*Класс «Рациональное число»(РЧ).Поля: числитель, знаменатель.Методы : перегрузка
операции приведения типа к float, операций умножения « * » двух РЧ и РЧ с целым числом,
сравнения на равенство « == » двух РЧ и РЧ с целым числом.*/

#include <iostream>
#include <string>

using namespace std;


class Rational {
    int numerator; //числитель
    int denominator; //знаменатель
public:
    const string ENTER_NUMERATOR = "Введите числитель: ";
    const string ENTER_DENOMINATOR = "Введите знаменатель: ";
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
        cout << "\nЭто число в десятичной форме имеет вид " << x << endl;
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
                numDelDem.Composition(num, dem);

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
                system("CLS");
                return 0;
                break;
        }
    } while (true);
    return 0;
}

