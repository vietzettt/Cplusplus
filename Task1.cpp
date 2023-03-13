#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;

void menu()
{
    cout << "------------------------MENU-----------------------------" << endl;
    cout << "1. Arithmetic Operators" << endl;
    cout << "2. Perform trigonometric Operators" << endl;
    cout << "3. Logical Operators" << endl;
    cout << "4. Power of a number" << endl;
    cout << "5. Factorial" << endl;
    cout << "6. Natural logarithm" << endl;
    cout << "7. Find LCM and GCD of two numbers" << endl;
    cout << "8. Number System and Base Conversions" << endl;
    cout << "9. Find the area of a regular n-gon along a given side" << endl;
    cout << "10.Find quadratic equation" << endl;
    cout << "11.Exit..." << endl;
    cout << "---------------------------------------------------------" << endl;
}

int choose(int max_choice)
{
    string input;
    int choice;
    do
    {
        cout << "Please choose the request you want (number): ";
        cin >> input;
        try
        {
            choice = stoi(input);
        }
        catch (std::out_of_range &e)
        {
            cerr << "Number is too big!!:)))" << endl;
            system("pause");
        }
        catch (std::invalid_argument &e)
        {
            cerr << "Not a number!" << endl;
            system("pause");
        }
        if (choice > max_choice)
        {
            cerr << "There is no such option. Again!!!" << endl;
            system("pause");
        }
    } while (choice > max_choice);
    return choice;
}

void t1_erithmetic()
{
    double a, b;
    int choice;
    bool done = false;
    while (!done)
    {
        system("cls");
        cout << "-----Arithmetic Operators----" << endl;
        cout << "\t1. Addition" << endl;
        cout << "\t2. Subtraction" << endl;
        cout << "\t3. Multiplication" << endl;
        cout << "\t4. Division" << endl;
        cout << "\t5. Back to menu" << endl;
        cout << "\t6. Exit" << endl;
        cout << "------------------------------" << endl;
        choice = choose(6);
        if (choice > 0 & choice < 5)
        {
            cout << "The value of a: ";
            cin >> a;
            cout << "The value of b: ";
            cin >> b;
        }
        else if (choice == 5)
        {
            done = true;
            break;
        }
        else if (choice == 6)
        {
            cout << "Exit" << endl;
            exit(0);
        }
        else
        {
            continue;
        }
        switch (choice)
        {
        case 1:
            cout << "The sum of two numbers is:" << a + b << endl;
            system("pause");
            break;
        case 2:
            cout << "The difference of two numbers is:" << a - b << endl;
            system("pause");
            break;
        case 3:
            cout << "The product of two numbers is:" << a * b << endl;
            system("pause");
            break;
        case 4:
            if (b == 0)
            {
                t1_erithmetic();
            }
            cout << "The quotient of two numbers is:" << a / b << endl;
            system("pause");
            break;
        }
    }
}

void t2_trigonometric()
{
    int choice;
    float goc, g;
    bool done = false;
    while (!done)
    {
        system("cls");
        cout << "-----Perform trigonometric operators----" << endl;
        cout << "\t1. Sin(x) operator" << endl;
        cout << "\t2. Cos(x) operator" << endl;
        cout << "\t3. Tan(x) operator" << endl;
        cout << "\t4. Cotan(x) operator" << endl;
        cout << "\t5. Back to menu" << endl;
        cout << "\t6. Exit" << endl;
        cout << "----------------------------------------" << endl;
        choice = choose(6);
        if (choice > 0 & choice < 5)
        {
            cout << "Value of angle: ";
            cin >> goc;
            g = (goc * 3.14) / 180;
        }
        else if (choice == 5)
        {
            done = true;
            break;
        }
        else if (choice == 6)
        {
            cout << "Exit" << endl;
            exit(0);
        }
        else
        {
            continue;
        }
        switch (choice)
        {
        case 1:
            cout << "Sin(" << goc << ") = " << sin(goc) << endl;
            system("pause");
            break;
        case 2:
            cout << "Cos(" << goc << ") = " << cos(goc) << endl;
            system("pause");
            break;
        case 3:

            cout << "Tan(" << goc << ") = " << tan(goc) << endl;
            system("pause");
            break;
        case 4:
            cout << "Cot(" << goc << ") = " << 1 / tan(goc) << endl;
            system("pause");
            break;
        }
    }
}

void t3_logicbit()
{
    int choice, a, b;
    while (true)
    {
        system("cls");
        cout << "---------Logical Operators-------------" << endl;
        cout << "\t1. AND(Decimal)" << endl;
        cout << "\t2. OR(Decimal)" << endl;
        cout << "\t3. XOR(Decimal)" << endl;
        cout << "\t4. NOT(Decimal)" << endl;
        cout << "\t5. Back to menu" << endl;
        cout << "\t6. Exit" << endl;
        cout << "----------------------------------------" << endl;
        choice = choose(6);
        if (choice >= 1 && choice <= 3)
        {
            cout << "The value of a: ";
            cin >> a;
            cout << "The value of b: ";
            cin >> b;
        }
        else if (choice == 4)
        {
            cout << "The value of a: ";
            cin >> a;
        }
        else if (choice == 5)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            cout << "Value A&B: " << (a & b) << endl;
            system("pause");
            break;
        case 2:
            cout << "Value A~B:" << (a | b) << endl;
            system("pause");
            break;
        case 3:
            cout << "Value A^B:" << (a ^ b) << endl;
            system("pause");
            break;
        case 4:
            cout << "Value ~A:" << (~a) << endl;
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "Exit!!!";
            exit(0);
            break;
        }
    }
}

void t4_exponential()
{
    long long a, b, result;
    cout << "-----Exponential Calculations(a^b)----" << endl;
    cout << "The value of a: ";
    cin >> a;
    cout << "Please enter the exponent b: ";
    cin >> b;
    result = pow(a, b);
    cout << "Exponential " << a << "^" << b << "= " << result << endl;
    system("pause");
}

void t5_factorial()
{
    int n;
    long giaiThua = 1;
    cout << "Program to calculate factorial" << endl;
    cout << "The value of n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        giaiThua = giaiThua * i;
    }
    cout << "The factorial of " << n << " is " << giaiThua << endl;
    system("pause");
}

void t6_logarithm()
{
    float a, x, result;
    cout << "-------Calculation program LOG a (X)-------" << endl;
    cout << "The value of a: ";
    cin >> a;
    cout << "The value of X: ";
    cin >> x;
    if (a < 0 & a == 1 & x < 0)
    {
        system("cls");
        cout << "You entered it wrong, please re-enter it!!!" << endl;
        t6_logarithm();
    }
    else
    {
        result = log(x) / log(a);
        cout << "Logarit LOG" << a << "(" << x << "): " << result << endl;
        system("pause");
    }
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

int BCNN(int a, int b)
{
    int c;
    c = UCLN(a, b);
    return (a * b) / c;
}

void t7_GCD_LCM()
{
    int choice4, a, b;
    bool done = false;
    while (!done)
    {
        system("cls");
        cout << "--Greatest common divisor - Least common multiple--" << endl;
        cout << "\t1. Greatest common divisor" << endl;
        cout << "\t2. Least common multiple" << endl;
        cout << "\t3. Back to menu" << endl;
        cout << "\t4. Exit" << endl;
        cout << "---------------------------------------------------" << endl;
        choice4 = choose(4);
        if (choice4 > 0 & choice4 < 3)
        {
            cout << "The value of a: ";
            cin >> a;
            cout << "The value of b: ";
            cin >> b;
        }
        else if (choice4 == 3)
        {
            done = true;
            break;
        }
        else if (choice4 == 4)
        {
            cout << "Exit" << endl;
            exit(0);
        }
        switch (choice4)
        {
        case 1:
            cout << "The GCD of " << a << " and " << b << " is: " << UCLN(a, b) << endl;
            system("pause");
            break;
        case 2:
            cout << "The LCM of " << a << " and " << b << " is: " << BCNN(a, b) << endl;
            system("pause");
            break;
        }
    }
}

void DectoBin(long long n)
{

    int binaryNum[32];

    int i = 0;
    while (n > 0)
    {

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void DectoHex(long long num)
{
    int temp, i = 1, j, r;
    char hex[50];
    temp = num;
    while (temp != 0)
    {
        r = temp % 16;
        if (r < 10)
            hex[i++] = r + 48;
        else
            hex[i++] = r + 55;
        temp = temp / 16;
    }
    cout << "Value of Decimal to Hexdecimal: ";
    for (j = i - 1; j > 0; j--)
        cout << hex[j];
    cout << "\n----------------------------------------------" << endl;
}

int BinToDec(long long binaryNumber)
{
    int p = 0;
    int decNumber = 0;
    while (binaryNumber > 0)
    {
        decNumber += (binaryNumber % 10) * pow(2, p);
        ++p;
        binaryNumber /= 10;
    }
    return decNumber;
}

void BintoHex(long long binaryNumber)
{
    int hex[1000];
    int i = 1, j = 0, rem, dec = 0;
    while (binaryNumber > 0)
    {
        rem = binaryNumber % 2;
        dec = dec + rem * i;
        i = i * 2;
        binaryNumber = binaryNumber / 10;
    }
    i = 0;
    while (dec != 0)
    {
        hex[i] = dec % 16;
        dec = dec / 16;
        i++;
    }
    cout << "Value of Binary to Hexdecimal: ";
    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] > 9)
        {
            cout << (char)(hex[j] + 55);
        }
        else
        {
            cout << hex[j];
        }
    }
    cout << "\n----------------------------------------------" << endl;
}

int HextoDec(string hex)
{
    unsigned long result = 0;
    for (int i = 0; i < hex.length(); i++)
    {
        if (hex[i] >= 48 && hex[i] <= 57)
        {
            result += (hex[i] - 48) * pow(16, hex.length() - i - 1);
        }
        else if (hex[i] >= 65 && hex[i] <= 70)
        {
            result += (hex[i] - 55) * pow(16, hex.length() - i - 1);
        }
        else if (hex[i] >= 97 && hex[i] <= 102)
        {
            result += (hex[i] - 87) * pow(16, hex.length() - i - 1);
        }
    }
    return result;
}

void HexToBin(string hexa)
{
    long int i = 0;
    while (hexa[i])
    {
        switch (hexa[i])
        {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        default:
            cout << "\nPlease enter valid hexadecimal digit " << hexa[i];
        }
        i++;
    }
}

void t8_bin_dec_hex()
{
    int choice5;
    long long a;
    string s;
    bool done = false;
    while (!done)
    {
        system("cls");
        cout << "-------------Radix conversion--------------" << endl;
        cout << "\t1. Binary to Decimal, Hexdecimal" << endl;
        cout << "\t2. Decimal to Binary, Hexdecimal" << endl;
        cout << "\t3. Hexdecimal to Binary, Decimal" << endl;
        cout << "\t4. Back to menu" << endl;
        cout << "\t5. Exit" << endl;
        cout << "------------------------------------------" << endl;
        choice5 = choose(5);
        if (choice5 == 1 || choice5 == 2)
        {
            cout << "Please enter the value: ";
            cin >> a;
        }
        else if (choice5 == 3)
        {
            cout << "Please enter the value: ";
            cin >> s;
        }
        else if (choice5<1 & choice5> 4)
        {
            system("cls");
            cout << "Enter incorrectly, please re-enter!!!";
            t8_bin_dec_hex();
        }
        else if (choice5 == 4)
        {
            done = true;
            break;
        }
        else if (choice5 == 5)
        {
            cout << "Exit" << endl;
            exit(0);
        }
        switch (choice5)
        {
        case 1:
            cout << "Value of Binary to Decimal: " << BinToDec(a) << endl;
            BintoHex(a);
            system("pause");
            break;
        case 2:
            cout << "Value of Decimal to Binary: ";
            DectoBin(a);
            cout << endl;
            DectoHex(a);
            system("pause");
            break;
        case 3:
            cout << "Value of Hexdecimal to Decimal: " << HextoDec(s) << endl;
            cout << "Value of Hexdecimal to Binary: ";
            HexToBin(s);
            cout << endl;
            system("pause");
            break;
        }
    }
}

void t9_AreaNGon()
{
    int a, n;
    float s;
    cout << "How many scenes do you want to calculate the area of a regular polygon: ";
    cin >> n;
    cout << "What is the length of each side of the polygon (M): ";
    cin >> a;
    if (n > 0)
    {
        s = (n * pow(a, 2) * (1 / tan(3.14159265359 / n))) / 4;
        cout << "Area of regular polygon with " << n << " equals " << s << endl;
        system("pause");
    }
    else
    {
        system("cls");
        cout << "Please enter the number of edges greater than 0" << endl;
        t9_AreaNGon();
    }
}

void t10_quadratic()
{
    float a, b, c;
    cout << "The quadratic equation 2" << endl;
    cout << "The value of a = ";
    cin >> a;
    cout << "The value of b = ";
    cin >> b;
    cout << "The value of c = ";
    cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "The equation has no solution!" << endl;
        }
        else
        {
            cout << "The equation has one solution: x = " << (-c / b) << endl;
        }
        return;
    }
    float delta = b * b - 4 * a * c;
    float x1;
    float x2;
    if (delta > 0)
    {
        x1 = (float)((-b + sqrt(delta)) / (2 * a));
        x2 = (float)((-b - sqrt(delta)) / (2 * a));
        cout << "The equation has 2 solutions: x1 = " << x1 << " va x2 = " << x2 << endl;
    }
    else if (delta == 0)
    {
        x1 = (-b / (2 * a));
        cout << "The equation has a double solution: x1 = x2 = " << x1 << endl;
    }
    else
    {
        cout << "The equation has no solution!" << endl;
    }
}

int main()
{
    int choice = 0;
    while (true)
    {
        menu();
        choice = choose(11);
        switch (choice)
        {
        case 1:
            system("cls");
            t1_erithmetic();
            break;
        case 2:
            system("cls");
            t2_trigonometric();
            break;
        case 3:
            system("cls");
            t3_logicbit();
            break;
        case 4:
            system("cls");
            t4_exponential();
            break;
        case 5:
            system("cls");
            t5_factorial();
            break;
        case 6:
            system("cls");
            t6_logarithm();
            break;
        case 7:
            system("cls");
            t7_GCD_LCM();
            break;
        case 8:
            system("cls");
            t8_bin_dec_hex();
            break;
        case 9:
            system("cls");
            t9_AreaNGon();
            break;
        case 10:
            system("cls");
            t10_quadratic();
            cout << endl;
            system("pause");
            break;
        case 11:
            system("cls");
            cout << "Exit!!!";
            exit(0);
        }
    }
}