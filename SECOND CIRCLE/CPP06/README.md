# Additional Rule - CPP06

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense.

###### EX00

> *Allowed:* Any function to convert from a string to an int, a float or a double. This will help, but won’t do the whole job.

- ScalarConverter class
- Only contains one static method - 'convert' 
- Take in a string (the number represented using a string)(with number I mean scalar value)
- *Scalar* is a term, which encompasses our commonly used values:
     1. char
     2. int
     3. float
     4. double
- Our program is supposed to:
    1. "detect the type of literal passed"
    2. "convert it from string to its actual type"
    3. "convert it *explicitly* to the three other data types
    4. display "impossible" if the conversion does not make sense, or overflows


- The class must still follow the Coplien form
- It doesnt store anything, so it is disallowed to be instanciable


- Char literals:
    - 'c', 'a'
- Int literals:
    - 0, 3, -42, 1337
- Float literals:
    - 0.0f, -4.2f, 4.3f
    - also handle: -inff, +inff
- Double literals:
    - 0.0, 1337.45, 4.6
    - also handle: -inf, +inf and nan