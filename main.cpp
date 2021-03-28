#include <iostream>
#include <string>

#define N 1
using namespace std;

const string NUMBER_A = "Число A = ";
const string NUMBER_B = "Число В = ";
const string A_AND_B = "A * B = ";
const string ENTER_NUMERATOR = "Введите числитель: ";
const string ENTER_DENOMINATOR = "Введите знаменатель: ";
const string ERROR_INPUT = "Ошибка ввода, попробуйте еще раз: ";
const string ENTER_INTEGER = "Введите целое число: ";
const string NUMBERS_EQUAL = "Числа равны!";
const string NUMBERS_NOT_EQUAL = "Числа не равны!";
const string PRODUCT_NUMBERS = "Произведение чисел = ";
const string FIRST_NUMBER = "Первое число ";

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

    friend void rationalXRational(Rational firstOperand, Rational secondOperand);

    friend void rationalOrRational(Rational firstOperand, Rational secondOperand);

    friend void rationalXInteger(Rational firstOperand);

    friend void rationalOrInteger(Rational firstOperand);

    friend void newValue(Rational obj);
};

void rationalXRational(Rational firstOperand, Rational secondOperand) {
    system("CLS");
    cout << NUMBER_A << firstOperand << endl;
    cin >> secondOperand;
    cout << NUMBER_B << secondOperand;
    cout << A_AND_B << secondOperand.operator*(firstOperand) << endl;
}

void rationalXInteger(Rational firstOperand) {
    system("CLS");
    int integer;
    cout << NUMBER_A << firstOperand << endl;
    cout << ENTER_INTEGER << NUMBER_B << endl;
    cin >> integer;
    while (cin.fail()) {
        cout << ERROR_INPUT;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> integer;
    }
    cout << "А * В = " << firstOperand.operator*(integer) << endl;
}

void rationalOrRational(Rational firstOperand, Rational secondOperand) {
    system("CLS");
    cout << NUMBER_A << firstOperand << endl;
    cin >> secondOperand;
    cout << NUMBER_B << secondOperand;
    if (operator==(firstOperand, secondOperand))
        cout << NUMBERS_EQUAL << endl;
    else
        cout << NUMBERS_NOT_EQUAL << endl;
}

void rationalOrInteger(Rational firstOperand) {
    system("CLS");
    int integer;
    cout << NUMBER_A << firstOperand << endl;
    cout << ENTER_INTEGER << NUMBER_B << endl;
    cin >> integer;
    while (cin.fail()) {
        cout << ERROR_INPUT;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> integer;
    }
    if (operator==(integer, firstOperand))
        cout << NUMBERS_EQUAL << endl;
    else
        cout << NUMBERS_NOT_EQUAL << endl;
}

void newValue(Rational obj) {
    system("CLS");
    cin >> obj;
    cout << "Значение установлено!\nТеперь А = " << obj << endl;
}

istream& operator>>(istream& in, Rational& rational) {
    int num, den;
    cout << ENTER_NUMERATOR << endl;
    in >> num;
    cout << ENTER_DENOMINATOR << endl;
    in >> den;
    rational.setNumerator(num);
    if (den != 0) {
        rational.setDenominator(den);
    }
    else {
        cout << "Знаменателя 0 быть не может!\nЗнаменать = " << N << endl;
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
    Rational secondRationalNumber(2, 5);
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
            case '1': {
                rationalXRational(secondRationalNumber, firstRationalNumber);
                end();
                break;
            }
            case '2': {

                rationalXInteger(secondRationalNumber);
                system("pause");
                system("CLS");
                break;
            }
            case '3': {
                rationalOrRational(secondRationalNumber, firstRationalNumber);
                end();
                break;
            }
            case '4': {
                rationalOrInteger(copiedRationalNumber);
                end();
                break;
            }
                /*case '5': {
                    newValue(secondRationalNumber);
                    end();
                    break;
                }*/
            case '6': {
                system("CLS");
                return 0;
                break;
            }
        }
    } while (true);
    return 0;
}

void end() {
    system("pause");
    system("CLS");
}
