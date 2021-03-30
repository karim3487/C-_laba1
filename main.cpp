#include <iostream>
#include <string>

#define N 1
using namespace std;

const string NUMBER_A = "Число A = ";
const string NUMBER_B = "Число В = ";
const string A_AND_B = "A * B = ";
const string ENTER_NUM_DEN = "Введите число В (сначала знаменатель, затем числитель)";
const string ENTER_NUM_DEN_A = "Введите число A (сначала знаменатель, затем числитель";
const string ERROR_INPUT = "Ошибка ввода, попробуйте еще раз: ";
const string ENTER_INTEGER = "Введите целое число: ";
const string NUMBERS_EQUAL = "Числа равны!";
const string NUMBERS_NOT_EQUAL = "Числа не равны!";

class Rational {
private:
    int numerator; //числитель
    int denominator; //знаменатель

public:
    Rational(int valueNumerator = 2, int valueDenominator = 3) {
        numerator = valueNumerator;
        denominator = valueDenominator;
    }

    ~Rational() {
    }

    int getNumerator() {
        return numerator;
    }

    int getDenomirator() {
        return denominator;
    }

    void setNumerator(int valueNumerator) {
        numerator = valueNumerator;
    }

    void setDenominator(int valueDenominator) {
        denominator = valueDenominator;
    }


    float operator*(float val) {
        return operator float() * val;
    }

    float operator*(int val) {
        return operator float() * val;
    }

    operator float() {
        return (float)numerator / denominator;
    }

    friend ostream& operator<<(ostream& out, const Rational rational);

    friend istream& operator>>(istream& in, Rational& rational);

    friend bool operator==(Rational r1, Rational r2);

    friend bool operator==(int integer, Rational r2);
};

istream& operator>>(istream& in, Rational& rational) {
    int num, den;
    in >> num;
    in >> den;
    rational.setNumerator(num);
    if (den != 0)
        rational.setDenominator(den);
    else {
        rational.setDenominator(N);
    }
    return in;
}

bool operator==(Rational r1, Rational r2) {
    return (r1.operator float() == r2.operator float());
}

bool operator==(int integer, Rational r2) {
    return ((float)integer == r2.operator float());
}

ostream& operator<<(ostream& out, Rational rational) {
    out << rational.getNumerator() << "/" << rational.getDenomirator()
        << "(" << rational.operator float() << ")" << endl;
    return out;
}

void end();

int main() {
    setlocale(LC_ALL, "rus");

    Rational firstRationalNumber;
    Rational secondRationalNumber = Rational(2, 5);
    Rational copiedRationalNumber(secondRationalNumber);
    char menu;
    do {
        system("CLS");
        puts("1. Умножить РЧ на РЧ");
        puts("2. Умножить РЧ на целое число");
        puts("3. Проверить РЧ и РЧ на равенство");
        puts("4. Проверить РЧ и целое число на равенство");
        puts("5. Изменить значение А");
        puts("6. Выход");
        menu = getchar();
        switch (menu) {
            case '1':
                system("CLS");
                cout << NUMBER_A << secondRationalNumber << endl;
                cout << ENTER_NUM_DEN << endl;
                cin >> firstRationalNumber;
                cout << NUMBER_B << firstRationalNumber;
                cout << A_AND_B << secondRationalNumber * firstRationalNumber << endl;
                end();
                break;
            case '2': {
                system("CLS");
                int integer;
                cout << NUMBER_A << secondRationalNumber << endl;
                cout << ENTER_INTEGER << NUMBER_B << endl;
                cin >> integer;
                while (cin.fail()) {
                    cout << ERROR_INPUT;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> integer;
                }
                cout << A_AND_B << integer * secondRationalNumber << endl;
                end();
                break;
            }
            case '3': {
                system("CLS");
                cout << NUMBER_A << secondRationalNumber << endl;
                cout << ENTER_NUM_DEN << endl;
                cin >> firstRationalNumber;
                cout << NUMBER_B << firstRationalNumber;
                string result = operator==(secondRationalNumber, firstRationalNumber) ? NUMBERS_EQUAL : NUMBERS_NOT_EQUAL;
                cout << result << endl;
                end();
                break;
            }
            case '4': {
                system("CLS");
                int integer;
                cout << NUMBER_A << secondRationalNumber << endl;
                cout << ENTER_INTEGER << NUMBER_B << endl;
                cin >> integer;
                while (cin.fail()) {
                    cout << ERROR_INPUT;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> integer;
                }
                string result = operator==(integer, secondRationalNumber) ? NUMBERS_EQUAL : NUMBERS_NOT_EQUAL;
                cout << result << endl;
                end();
                break;
            }
            case '5': {
                system("CLS");
                cout << ENTER_NUM_DEN_A << endl;
                cin >> secondRationalNumber;
                cout << "Значение установлено!\nТеперь А = " << secondRationalNumber << endl;
                end();
                break;
            }
            case '6': {
                system("CLS");
                return 0;
            }
        }
    } while (true);
}

void end() {
    system("pause");
    system("CLS");
}
