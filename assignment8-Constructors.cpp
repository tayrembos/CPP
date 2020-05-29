/*
EEL3834
By: Taylor Rembos
Rational Numbers
Assignment 8
*/

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#define BR cout << "\n\n";
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;

class Rational

{
     private:
          int n; // numerator
          int d; // denominator
          Rational(int a, bool b) : n(a), d(a) {};
     public:
          //constructors
          Rational() : n(0), d(1) {};
          Rational(int wholeNumber) : n(wholeNumber), d(1) 
          {
          };
          Rational(int numerator, int denominator) : 
          n(numerator), d(denominator) {standardize();};

          //void Rational::standardize()
          void standardize()
          {
            if (d < 0)
            {
              d = -d;
              n = -n;
            }
            else if (d == 0)
            {
              cout << "Zero cannot be in the denominator - program aborting!!" << endl;
              //exit(1);
            }
          }

          //operators
          bool operator==(const Rational& rhs);
          void factorRational();
          bool operator>(const Rational& rhs);
          bool operator<(const Rational& rhs);
          bool operator>=(const Rational& rhs);
          bool operator<=(const Rational& rhs);

          //Rational operators (+,-,*,/)
          Rational operator+(const Rational& rhs) const;
          Rational operator-(const Rational& rhs) const;
          Rational operator*(const Rational& rhs) const;
          Rational operator/(const Rational& rhs) const;

          //friend operators
          friend std::ostream& operator<<(std::ostream &o, const Rational &r);
          friend std::istream& operator>>(std::istream &in, Rational &r);
};

int main()
{

  BR
  Rational r1, r2, r3;

  cout << "Enter a fraction in the format integer_numerator/integer_denominator: ";
  cin >> r1 ;
  r1.factorRational();
  cout << endl;

  cout << "you entered the equivalent of: " << r1 << endl;
  cout << "Enter a fraction in the format integer_numerator/integer_denominator: ";
  cin >> r2;
  r2.factorRational();
  cout << endl;
  
  cout << "you entered the equivalent of: " << r2 << endl;

// ISSUES WITH ABORT
  cout << "Enter a fraction in the format integer_numerator/integer_denominator: ";
  cin >> r2;
  cout << endl;

  if(r2>0)
    {
      cout<< "bad input format for operator >>.Aborting!" << endl;
    }

  cout << "Enter a fraction in the format integer_numerator/integer_denominator: ";
  cin >> r3;
  r3.factorRational();
  cout << endl;

  cout << "you entered the equivalent of: " << r3 << endl;
  cout << "Testing arithmetic and relational operator overloading" << endl;

  string equals = (r1 == r2) ? "1" : "0";
  string lteq = (r1 <= r2) ? "1" : "0";
  string lteq1 = (r1 <= r1) ? "1" : "0";
  string gteq = (r1 >= r2) ? "1" : "0";
  string lt = (r1 < r2) ? "1" : "0";
  string gt = (r1 > r2) ? "1" : "0";
  string gt1 = (r1 > r1) ? "1" : "0";
  
  Rational times = r1 * r2;
  Rational div = r1 / r2;
  Rational plus = r1 + r2;
  Rational minus = r1 - r2;

  cout << r1 << " + " << r2 << " = " << plus << endl;
  cout << r1 << " - " << r2 << " = " << minus << endl;
  cout << r1 << " * " << r2 << " = " << times << endl;
  cout << r1 << " / " << r2 << " =" << div << endl;

  cout << r1 << " > " << r2 << " = " << gt << endl;
  cout << r1 << " > " << r1 << " = " << gt1 << endl;
  cout << r1 << " <" << r2 << " = " << lt << endl;
  cout << r1 << " <" << r1 << " = " << lt << endl;
  cout << r1 << " >= " << r2 << " = " << gteq << endl;
  cout << r1 << " >= " << r1 << " = " << gteq << endl;
  cout << r1 << " <= " << r2 << " = " << lteq << endl;
  cout << r1 << " <= " << r1 << " = " << lteq1 << endl;

  equals = (r3 == r2) ? "1" : "0";
  gt = (r3 > r2) ? "1" : "0";
  gt1 = (r3 > r3) ? "1" : "0";
  lt = (r3 < r2) ? "1" : "0";
  string lt1 = (r3 < r3) ? "1" : "0";
  gteq = (r3 >= r2) ? "1" : "0";
  string gteq1 = (r3 >= r3) ? "1" : "0";
  lteq = (r3 <= r2) ? "1" : "0";
  lteq1 = (r3 <= r3) ? "1" : "0";

  plus = r3 + r2;
  minus = r3 - r2;
  times = r3 * r2;
  div = r3 / r2;

  cout << r3 << " + " << r2 << " = " << plus << endl;
  cout << r3 << " - " << r2 << " = " << minus << endl;
  cout << r3 << " * " << r2 << " = " << times << endl;
  cout << r3 << " / " << r2 << " =" << div << endl;
  cout << r3 << " > " << r2 << " = " << gt << endl;
  cout << r3 << " > " << r3 << " = " << gt1 << endl;
  cout << r3 << " <" << r2 << " = " << lt << endl;
  cout << r3 << " <" << r3 << " = " << lt1 << endl;
  cout << r3 << " >= " << r2 << " = " << gteq << endl;
  cout << r3 << " >= " << r3 << " = " << gteq1 << endl;
  cout << r3 << " <= " << r2 << " = " << lteq << endl;
  cout << r3 << " <= " << r3 << " = " << lteq1 << endl;

  return 0;
}

bool Rational::operator==(const Rational& rhs)
{
  if ( (rhs.n == this->n) && (rhs.d == this->d) )
    return true;

    else
    return false;
}

Rational Rational::operator+(const Rational& rhs) const
{
  Rational out, temp1 = *this, temp2 = rhs;
  if (temp1.d != temp2.d)
  {
  //multiply the denominators to make them equal
    temp1 = *this * Rational(rhs.d, true);
    temp2 = rhs * Rational(this->d, true); //TODO
  }

//cout << "\ntemp1: " << temp1 << " temp2: " << temp2 << endl;
  out.d = temp1.d;
  out.n = temp1.n + temp2.n;

  return out;
}

void Rational::factorRational()
{
  const int prime[4] = {2,3,5,7}; // setup four lowest primes to try factoring
    bool notFactored = true;
    int count = 0;
  
  do
  {
    for (int i = 0; i < 4; i++) {
      count++; // track number of times this loops

      if ((this->n % prime[i] == 0) && (this->d % prime[i] == 0))
      {
      // if both numerator and denominator are evenly divisible by 2,3,5, or 7
      // then factor the fraction
        this->n /= prime[i];
        this->d /= prime[i];
      
      break; // exit for loop so do/while executes again

      } 
      else if (i == 3) {
      // if numerator and denominator are not evenly divisible by 2,3,5, or 7
      // then set condition to false so do/while stops
        notFactored = false;
      } 
      else {
      // Default is not factored.
        notFactored = true;
      } // end of if
    } // end for loop

     } while (notFactored);

     cout << this->n << "/" << this->d << endl;

     //cout << "factorRational count = " << count << endl;
}

Rational Rational::operator-(const Rational& rhs) const
{
  Rational out, temp1 = *this, temp2 = rhs;

  if (temp1.d != temp2.d)
  {
    //multiply the denominators
    temp1 = *this * Rational(rhs.d, true);
    temp2 = rhs * Rational(this->d, true);
  }

  out.d = temp1.d;
  out.n = temp1.n - temp2.n;

  return out;
}

Rational Rational::operator*(const Rational& rhs) const
{
  Rational out;

  out.n = this->n * rhs.n;
  out.d = this->d * rhs.d;

  return out;
}

Rational Rational::operator/(const Rational& rhs) const
{
  int tempN;

  Rational out;
  Rational tempR = *this;

  //invert then multiply

  tempN = tempR.n;
  tempR.n = tempR.d;
  tempR.d = tempN;

  out = tempR * rhs;

  return out;
}

bool Rational::operator>(const Rational& rhs)
{
//first check if denominators are the same. calculate and return if they are
//otherwise, make them the same first.
  int tempL, tempR;
  
  if( (this->d == rhs.d) && (this->n > rhs.n) )
    return true;

  tempL = this->n * rhs.d;
  tempR = this->d * rhs.n;

  //cout << "tempL: " << tempL << "tempR: " << tempR <<     "\n\n";

  return (tempL > tempR);
}

bool Rational::operator<(const Rational& rhs)
{
  //first check if denominators are the same. calculate and return if they are
  //otherwise, make them the same first.

  int tempL, tempR;

  if( (this->d == rhs.d) && (this->n < rhs.n) )
      return true;

    tempL = this->n * rhs.d;
    tempR = this->d * rhs.n;

  return (tempL < tempR);
}

bool Rational::operator>=(const Rational& rhs)
{
  if (*this == rhs)
    return true;

  if(*this > rhs)
    return true;

  return false;
}

bool Rational::operator<=(const Rational& rhs)
{
  if (*this == rhs)
    return true;

  if(*this < rhs)
    return true;

  return false;
}

std::istream& operator>>(std::istream &in, Rational &r)
{
  string tempString;
  int tempInt1, tempInt2;
  stringstream ss;

  std::getline(in, tempString, '/');
  in >> tempInt2;
  ss << tempString;
  ss >> tempInt1;

  r.n = tempInt1;
  r.d = tempInt2;

  return in;
}

std::ostream& operator<<(std::ostream &o, const Rational &r)
{
  o << r.n << "/" << r.d;

  return o;
}