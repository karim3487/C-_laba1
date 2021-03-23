/*����� ������������� �����(��).����: ���������, �����������.������ : ����������
�������� ���������� ���� � float, �������� ��������� � * � ���� �� � �� � ����� ������,
��������� �� ��������� � == � ���� �� � �� � ����� ������.*/

#include <iostream>
#include <string>

using namespace std;


class Rational {

public:
    int numerator; //���������
    int denominator; //�����������
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
        cout << "�� ����� " << numerator << "/" << (float)denominator << endl;
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
            cout << "����� �����" << endl;
        else
            cout << "����� �� �����!" << endl;
    }
    void Ravenstv(int x, float y) {
        if (x == y)
            cout << "����� �����" << endl;
        else
            cout << "����� �� �����!" << endl;
    }
};
Rational::operator float()
{
    return (float)numerator / denominator;
}


int main() {
    setlocale(LC_ALL, "Russian");
   /* float num, dem;
    do
    {
        cout << "������� ��������" << endl;
        cout << "���������: ";
        cin >> num;
        cout << "�����������: ";
        cin >> dem;
        if (dem == 0) cout << "��������� ����� ����, ��� �� ������������ �����!" << endl;
    } while (dem == 0);
    Rational fraction(num, dem);
    fraction.Print();*/
    int num, dem;
    float x, y, proizv;
    Rational numDelDem;
    

        char menu;
        do {
            system("CLS");
            puts("1. ���������� �� � ���������� ����");
            puts("2. �������� ��� �� ��� �� � ����� �����");
            puts("3. ��������� ����� �� ���������");
            puts("4. �����");
            menu = getchar();
            switch (menu)
            {
            case '1': {cout << "������� ���������: " << endl;
                cin >> num;
                cout << "������� �����������: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;
                cout << "\n��� ����� � ���������� ����� ����� ��� " << x << endl;
                system("pause");
                break;
            }
            case '2': 
            {
                cout << "������� ���������: " << endl;
                cin >> num;
                cout << "������� �����������: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << "������� ���������: " << endl;
                cin >> num;
                cout << "������� �����������: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                y = (float)numDelDem;
                proizv = x * y;
                cout << "������������ ����� " << proizv << endl;
                system("pause");
                break;
            }
            case '3':
            {
                cout << "������� ���������: " << endl;
                cin >> num;
                cout << "������� �����������: " << endl;
                cin >> dem;
                numDelDem.SetDenominator(dem);
                numDelDem.SetNumerator(num);
                numDelDem.Print();
                x = (float)numDelDem;

                cout << "������� ���������: " << endl;
                cin >> num;
                cout << "������� �����������: " << endl;
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

