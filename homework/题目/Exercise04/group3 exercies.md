## Group 3 Exercises

Programming Exercises. These exercises are used to apply the concepts learned in this session. Please do attempt them in small groups if possible. 

You are invited to ask questions during the seminar time.



#### Exercise 1:

Develop class Polynomial. The internal representation of a Polynomial is an array of terms. Each term contains a coefficient and an exponent—e.g., the term 2x4 has the coefficient 2 and the exponent 4. 

Develop a complete class containing proper constructor and destructor functions as well as set and get functions. The class should also provide the following overloaded operator capabilities:



1. Overload the addition operator (+) to add two Polynomials. 
2. Overload the subtraction operator (-) to subtract two Polynomials. 
3. Overload the assignment operator to assign one Polynomial to another. 
4. Overload the multiplication operator (*) to multiply two Polynomials. 
5. Overload the addition assignment operator (+=), subtraction assignment operator (-=), and multiplication assignment operator (*=).



#### Exercise 2:

Create a class called Quadratic for performing arithmetic on and solving quadratic equations. A quadratic equation is an equation of the form ax2 + bx + c = 0 where a ≠ 0. 

Use double variables to represent the values of a, b, and c and provide a constructor that enables objects of this class to be initialized when they are created. 

Give default values of a = 1, b = 0, and c = 0. Create a char variable called variable to represent the variable used in the equation and give it a default value of x. The constructor should not allow the value of a to be 0. If 0 is given, assign 1 to a). Provide public member functions that perform the following tasks.



1.  add—adds two Quadratic equations by adding the corresponding values of a, b, and c. The function takes another object of type Quadratic as its parameter and adds it to the calling object.
2. subtract—subtracts two Quadratic equations by subtracting corresponding values of a, b, and c. The function takes another object of type Quadratic as its parameter and subtracts it from the calling object. 
3. toString—returns a string representation of a quadratic equation in the form ax2 + bx + c = 0 using the actual values of the data members.
4. solve—solves a quadratic equation using the quadratic formula and displays the solutions if (b2 − 4ac) is greater than 0. Otherwise, it displays “No Real Roots.”





Last modified: Monday, 3 December 2018, 2:23 AM