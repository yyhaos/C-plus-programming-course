## Group 2 Exercises

In small groups, you should create a small presentation about one of the topics below. Your presentation should not exceed 5 minutes.

#### Topic 1:

What is a Pure Virtual Function? How would you define it? Why and when is it needed?

#### Topic 2:

Explain how the following program ([rational.cpp](https://www.wolearn.org/pluginfile.php/3725/mod_page/content/1/rational.cpp)) is working. Do you find any weaknesses in the design?

#### Topic 3:

If in the program [rational.cpp](https://www.wolearn.org/pluginfile.php/3725/mod_page/content/1/rational.cpp?time=1543775394163) you add this line in main  cout << 14 << " + " << b << " = " << 14 + b << endl; the program is not working can you explain why and how you would go about solving it?

#### Topic 4:

Explain how the following program ([pmain4.cpp](https://www.wolearn.org/pluginfile.php/3725/mod_page/content/1/pmain4.cpp)) is working. You will also need to download [point.h](https://www.wolearn.org/pluginfile.php/3725/mod_page/content/1/point.h)



Last modified: Monday, 3 December 2018, 2:39 AM





```c++
// rational.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <iostream>
using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};	// copy constructor
    ~Rational ();
    inline int numerator() const { return _n; };
    inline int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    Rational operator / ( const Rational & ) const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// useful for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    return o << r.numerator() << '/' << r.denominator();
}

int main( int argc, char ** argv ) {
    
    Rational a = 7;		// 7/1
    cout << "a is: " << a << endl;
    Rational b(5, 3);	// 5/3
    cout << "b is: " << b << endl;
    Rational c = b;		// copy constructor
    cout << "c is: " << c << endl;
    Rational d;			// default constructor
    cout << "d is: " << d << endl;
    d = c;				// assignment operator
    cout << "d is: " << d << endl;
    Rational & e = d;	// reference
    d = e;				// assignment to self!
    cout << "e is: " << e << endl;
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}
```

```c++
/*
 ** pmain4.cpp
 ** Demonstrates complete class
 ** construction / destruction
 ** setter / getter (with const)
 ** printing
 ** stream insertion << and
 ** stream extraction >> operators
 ** assignment operator
 ** addition assignment operator
 ** friends and globals
 */

#include <string>
#include <iostream>
#include <cassert>

#include "point.h"

void opInput(Point&);
void opOutput(const Point&);
void opAssn(const Point&);
void opAdd(void);
void opMult(void);
void mixedModeOps(void);
void printAndSet(void);
void refsStuff(void);

/*
** includes demonstration of c++ references (from week 4, references.cpp)
** 
** 
** std::move() returns rvalue reference to argument
*/

void f1(Point& lvalue, double setx, double sety); // mod input
void f2(const Point& c_lvalue); // immutable lvalue
void f3(Point&& rvalue); // binding rvalue to temp argument, to modify
// overloads
void f4(const Point& c_lvalue); // cannot modify parameter
void f4(Point&& rvalue); // can modify parameter


/*
** See the following discussion on returning rvalues and RVO
** http://stackoverflow.com/questions/4986673/c11-rvalues-and-move-semantics-confusion-return-statement
*/

int main(int argc, char* argv[])
{
  using std::cin;
  using std::cout;
  using std::cerr;
  using std::endl;

  // set debugging on
  Point::debug = true ;
  
  cerr << "PrintAndSet()\n"; printAndSet();

  Point p;
  cerr << "\n\nopInput()\n"; opInput(p); 
  cerr << "\n\nopOutput()\n"; opOutput(p); 
  cerr << "\n\nopAssn()\n"; opAssn(p);

  cerr << "\n\nopAdd()\n"; opAdd();
  cerr << "\n\nopMult()\n"; opMult();
  cerr << "\n\nmixedModeOps()\n";mixedModeOps();  

  cerr << "\n\nrefsStuff()\n";refsStuff();
}

void opInput(Point& mypoint)
{
  std::cout << "Operator Input\n\tenter a point using format ( xxx.xxx, yyy.yyy ): " ;
  std::cin >> mypoint;
}

void opOutput(const Point& a)
{
  std::cout << "Operator output\n" ; 
  std::cout << '\t' << a << '\n' ;
}

void opAssn(const Point& p)
{
  Point a,b,c ;
  std::cout << "Operator assignments\n\tAssignment chaining, with = \n" ; 
  a = b = c = p;
  std::cout << "\toriginal:" << p << '\n';
  std::cout << "\tcopies: " ;
  std::cout << a << ' ' << b << ' '  << c << '\n' ;
  assert( a == b ) ;
  assert( b == c ) ;
  assert( c == p ) ;
  std::cout << "After assignment chaining\n" ; 
}

void opMult(void)
{
  Point d(5,5);
  Point e(10,10);
	
  std::cout << "Operator compound multiply\n\tOperator *= modification of first argument\n" ; 
  std::cout << "\tBefore: " << d << " *= " << e << '\n' ;
  d *= e ;
  assert( d == Point(50,50) ) ;
  std::cout << "\tAssert OK, After: " << d << '\n' ;

  Point g ;
  d.x(5).y(5); // set d, back to starting value

  std::cout << "\tOperator * produces new value from two others\n" ; 
  std::cout << "\tBefore: " << g << " = " << d << " * " << e << std::endl ;
  g = d * e ;
  assert( g == Point(50,50) );
  std::cout << "\tAssert OK, After: " << g << std::endl ;
}

void opAdd(void)
{
  Point::debug = false;
  Point d(5,5);
  Point e(10,10);
	
  std::cout << "Operator compound addition\n\tOperator += modification of first argument\n" ; 
  std::cout << "\tBefore: " << d << " += " << e << '\n' ;
  d += e ;
  assert( d == Point(15,15) ) ;
  std::cout << "\tAssert OK, After: " << d << '\n' ;

  Point g ;
  std::cout << "\tOperator + produces new value from two others\n" ; 
  std::cout << "\tBefore: " << g << " = " << d << " + " << e << std::endl ;
  g = d + e ;
  assert( g == Point(25,25) );
  std::cout << "\tAssert OK, After: " << g << std::endl ;
}

void mixedModeOps(void)
{
  Point::debug = true;
  Point z = 10.0 ; // explicit conversion
  double d{10.0};
  Point a;
  Point b({5,5});
  
  /*
  ** won't work with explicit conversion
  ** 
  */
  std::cout << "Conversion of double 'd' to Point, note y() == x() == 10, followed by * \n";
  std::cout << a << '=' << d << '*' << b << '\n';
  std::cout << "a = d * b \n";
  a = d * b ; // explicit conversion
  // mixed mode i.e. a = Point(10.0) + b ;
  std::cout << a << '=' << d << '*' << b << '\n';
  /* d.operator*(b); */
  assert( a == Point(50.0, 50.0) );

  a.x(0.0).y(0.0); // reset a

  std::cout << "\nDitto above\n";
  std::cout << a << '=' << b << '*' << d << '\n';
  std::cout << "a = b * d \n";
  a = b * d ; // explicit conversion 
  // mixed mode i.e. a = b + Point(10.0) ;
  std::cout << a << '=' << b << '*' << d << '\n';
  assert( a == Point(50.0, 50.0) );
  /* 
  ** error: no match for ‘operator*’ (operand types are ‘double’ and ‘Point’)
  ** no known conversion for argument 1 from ‘double’ to ‘Point’
  */

  {
     std::cout << "z = x * y\n";
     Point x{10,10};
     Point y{10,10};
     Point z = x * y ;
     std::cout << z << "\n";
  }
  
  Point::debug = false; 
}
void printAndSet(void)
{
  Point temp ;
  std::cout << "\tDefault object: " ; temp.print(&std::cout) ; std::cout << std::endl ;
  temp.x(10.45).y(12.96); // set x, set y - chained
  std::cout << "\t...and after: " ; temp.print(&std::cout); std::cout << std::endl ;
}


void refsStuff(void)
{
  Point::debug = true;
  // non-const lvalue
  
  Point p;//def
  std::cerr << "\n\nnon-const lvalue to change p in f1\n";
  std::cerr << "before:" << p;
  f1(p,10,10); // p to change
  std::cerr << "\nafter:" << p;


  Point q;//def
  std::cerr << "\n\nnon-const lvalue to change p in f1\n";
  f1(q,10,10); // q to change
  f2(q); // will not compile
  
  std::cerr << "\n\nbinding rvalue to temp argument, to modify #1\n";
  f3(Point(10,10)); // this is a temp, change in function

  q = Point(99,99);
  std::cerr << "\n\nmoving q (make q an rvalue) should call move cons()\n";
  std::cerr << "before:" << q;
  Point r(std::move(q)) ; // evacute q
  std::cerr << "after:" << q;
  std::cerr << "\n\nalso after:" << r;
  
}

void f1(Point& lvalue, double setx, double sety) // mod input
{
  lvalue.x(setx);
  lvalue.y(sety);
}

void f2(const Point& c_lvalue) // immutable lvalue
{
  /* compile error, 
  ** x and y both take (first invisible this argument, which in non-const
  */
  //c_lvalue.x(42.0);
  //c_lvalue.y(42.0);
}


void f3(Point&& rvalue)
{
  std::cerr << "temporary before:" << rvalue;
  f1(rvalue,42,42); // temp to change
  std::cerr << "\ntemporary after:" << rvalue;
  std::cerr << "\ntemporary destroyed on return\n";
}
```

```c++
/*
** point.h
** Header file for point.cpp
** Used with programs to demonstrate use of basic class programming
**
** ... 
** default constructor
** named constructor
** initialisation list (c++ 11)
** move operations (c++ 11)
** print
** constant functions
** static data
** this pointer
** chaining
**
** Use of explicit constructor
** operator<< and operator>>
** operator+= , operator+ , operator*
** operator== , operator!=
*/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <initializer_list> // for demo of initializer list

using std::ostream;
using std::istream;
using std::string;

class Point {
private: // private member data follows
  double _x ; // member _x
  double _y ; // member _y
public:

  Point( ); // default constructor
  Point(double, double) ; // construct a point with two doubles

  Point(double) ; 
  // explicit Point(double) ; 
  // used in mixed mode as conversion occurs
  // if explicit various implicit conversions will fail
  // e.g. Point z=10.0 

  // build with initializer list c++11 and later
  Point(std::initializer_list<double>) ; 
  
  ~Point() ; // destructor

  // copy constructor  and copy assignment, use lvalues
  Point(const Point& ) ; // copy constructor 
  Point& operator=(const Point&) ; // cpy assign
  
  // move using rvalues c++ 11
  Point(Point&& ); // move constructor
  Point& operator=(Point&&) ; // move assign
  
  Point& x(double ) ; // set member _x / return class instance
  Point& y(double );  // set member _y / return class instance
  double x(void) const ; // get member _x / constant function
  double y(void) const ; // get member _y / constant function

  void print(ostream*) const ; // print to stream, can work across any stream
 
  Point& operator+=(const Point&) ; // needs access 
  friend Point operator+(Point, const Point& ); // global (friend) use representation via +=
  
  Point& operator*=(const Point&) ; // as with += requires access to representation
  friend Point operator*(Point, const Point& ); // global (friend) use representation via *=

  bool operator==(const Point&) ; // equality
  bool operator!=(const Point&) ; // not equal

  friend ostream& operator<<(ostream&, const Point&); // write out point
  // output point
  // use as:-
  // Point p;
  // std::cout << p ;  cout is RHS, object is LHS
  // so cout.operator<<(p) implies adding methods to cout, which cannot be done  
  // so operator << must be a global function, not member to cout
  // 

  friend istream& operator>>(istream&, Point&) ; // requires access to representation, read into point

  static const string classname ;
  static Point origin;
  static bool debug ; // static for class level debugging
};

Point rvo(Point p); // for return value optimisation code
```