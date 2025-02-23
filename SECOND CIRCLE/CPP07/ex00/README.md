# Template Functions in C++

Template functions allow you to write a single function that can work with multiple data types. To create a template function, you add the `template<typename T>` before your function definition—this tells the compiler to generate a function for every type T used when you call that function.

For example, in `whatever.hpp` we define a swap function as:

```cpp
template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
```

```cpp
// Code in main should output:
// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2
// 6
// Thus--> We will define
// 1) swap
// 2) min
// 3) max

// But how? Well to be able to call it like this, we will define them as a "Global Template functions"
// 
//
// template<typename T>
// void swap(T &a, T &b)
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// template<typename T>
// const T& min(const T &a, const T &b)
// {
//     return (b < a) ? b : a;
// }

// template<typename T>
// const T& max(const T &a, const T &b)
// {
//     return (a < b) ? b : a;
// }
```

This function can swap two variables of any type. When you call it in your code like this:

```cpp
::swap(a, b);
```

the compiler looks in the global namespace for a function named `swap` that can take the given types.

## Using the Global Namespace Resolver `::`

The `::` operator here is known as the scope resolution operator. When it is used at the beginning (as in `::swap`), it forces the lookup to start in the global namespace. This is helpful when you want to ensure that you are calling your global template function and not some other function named `swap` in a local or different namespace.

This means you can have functions with the same name in different namespaces; using `::swap` guarantees that the compiler uses the one defined in the global scope.

## How It Works Together

When you include `whatever.hpp` in your source file, the compiler sees the template definition for `swap`. Later, when you write `::swap(a, b)`, the compiler generates an instantiation of the template function for the type of `a` and `b`.

This all happens at compile-time, providing the flexibility of type safety while keeping your code generic.


--------------


:: operator is the scope resolution operator

It is used to access identifiers (such as functions or variables) that are defined within a particular scope or namespace.

What Does :: Do?
When used at the beginning (i.e., ::swap), it forces the lookup to occur in the global namespace.
This is useful if you have multiple definitions (perhaps one in a namespace and one in the global scope) and want to ensure you are accessing the correct function.
Implementing Functions with Namespaces
In your .cpp file, you can define functions within a specific namespace like this:

namespace MyNamespace {
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

To call this function from outside the namespace, you would use the scope resolution operator:

MyNamespace::swap(a, b);

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

When you call ::swap(a, b), you're ensuring that the compiler finds the function in the global scope, not in any nested namespace. This can be especially useful if a different swap exists in another scope and you want to avoid collisions.


