#include <iostream>

class Fraction
{
    int numerator;
    int denominator;
    
    int Nod(int a, int b)
    {
        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                int r = a % b;
                a = b;
                b = r;
            }
            else
            {
                int r = b % a;
                b = r;
            }
        }
        return (a) ? a : b;
    }

    void Shorten()
    {
        int nod = Nod(numerator, denominator);
        numerator /= nod;
        denominator /= nod;
    }
public:

    /*
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    */

    //Fraction(int numerator, int denominator)
    //{
    //    this->numerator = numerator;
    //    this->denominator = denominator;
    //    //std::cout << "ctor(args)" << this << " " << &numerator << "\n";
    //}


    Fraction() : numerator{ 0 }, 
                 denominator{ 1 } {}

    Fraction(int numerator, int denominator) 
        : numerator{ numerator },
        denominator{ denominator }{}

    ~Fraction() {}
    
    int GetNumerator() { return numerator; }
    void SetNumerator(int value) { numerator = value; }
    
    int GetDenominator() { return denominator; }
    bool SetDenominator(int value)
    {
        if (value != 0)
        {
            denominator = value;
            return true;
        }
        return false;
    }

    void Cout()
    {
        std::cout << "[" << numerator << "/" << denominator << "]";
    }

    Fraction Add(Fraction f)
    {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator *= f.denominator;
        Shorten();

        return *this;
    }

    Fraction Delete(Fraction f)
    {
        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator *= f.denominator;
        Shorten();

        return *this;
    }

    Fraction Plus(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        result.Shorten();
        return result;
    }

    Fraction Plus(int number)
    {
        Fraction f;
        f.SetNumerator(number * denominator);
        f.SetDenominator(denominator);
        return this->Plus(f);
    }

    Fraction Minus(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        result.Shorten();
        return result;
    }
};

int main()
{
    Fraction f1{ 2, 7 };
    f1.Cout();
    std::cout << "\n";

    Fraction f2(2, 7);
    f2.Cout();
    std::cout << "\n";

    
    Fraction f3;
    f3.SetNumerator(2);
    f3.SetDenominator(5);
    f3.Cout();
    std::cout << "\n";

    /*Fraction f4 = f1.Plus(f2)
                    .Minus(f3)
                    .Plus(f1);*/
    
}
