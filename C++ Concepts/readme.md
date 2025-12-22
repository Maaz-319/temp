# C++ Concepts

```c++
/*
#include <iostream>
#include <cstdint>
#include <unistd.h>
#include <vector>
#include <cmath>
#include <typeinfo>
using namespace std;
*/
```

### 1. Memory Alignment
```c++
class a{ // or struct
    char a;
    int b;
    char c;
};
class b{ // or struct
    int b;
    char a;
    char c;
};
class c{ // or struct
    int b;
    int c;
    char a;
};
int main()
{
    std::cout<<sizeof(a)<<std::endl<<sizeof(b)<<std::endl<<sizeof(c);

    return 0;
}
```

### 2. Getting Multiple Switches in same Byte
```c++
// from <cstdint>
struct on_off {
    uint8_t a: 1;
    uint8_t b: 1;
    uint8_t c: 1;
    uint8_t d: 1;
};

int main(){
    cout << sizeof(on_off);
}
```
or
```c++
struct on_off {
    int a: 1;
    int b: 1;
    int c: 1;
    int d: 1;
    int e: 1;
    int f: 1;
    int g: 1;
    int h: 1;
};

int main(){
    cout << sizeof(on_off);
}
```

### 3. Check if number is power of 2
```c++
// based on the set bit in binary representation
int main(){
    int n = 7;
    cout << (n>0&&(n&(n-1))==0);
}
```

### 4. Multiple Comparison
```c++
int main(){
    cout << (10>5>2); // gives 0
}
```

### 5. print without printf or cout
```c++
// comes from <unistd.h>
int main(){
    write(1, "NICE", 4);
}
```

### 6. Octal and Hexadecimal representation
```c++
int main(){
    int octal = 012;
    int hexa = 0xA;
    cout << octal << " " << hexa;
}
```

### 7. Reserve for vector
```c++
int main(){
    vector<int> v;
    v.reserve(10000000);
    for (int i = 0; i < 10000000; i++) v.push_back(i);
}
```

### 8. Comma Evaluation Order
```c++
int main(){
    int c = (10,20,30,-10);
    cout << c;
}
```

### 9. Get address of main function
```c++
// may show undefined behavior
int main(){
    cout << (void*)&main;
}
```

### 10. Get nth Fabonacci number
```c++
int main(){
    int n = 5;
    int fib = round(pow(1.618, n) /sqrt(5));
    cout << fib;
}
```

### 11. sizeof doesn't evaluate expression
```c++
int f() {
    cout << "called\n";
    return 10;
}

int main() {
    cout << sizeof(f());
}
```

### 12. Size of Array vs Pointer
```c++
int main() {
    int arr[10];
    int* p = arr;

    cout << sizeof(arr) << " " << sizeof(p);
}
```

### 13. Vector\<bool> is a specialized template
```c++
int main() {
    vector<bool> vb;
    vb.push_back(true);
    vb.push_back(false);

    cout << sizeof(vb);
}
```
or
```c++
// comes from <typeinfo>
int main() {
    vector<bool> v(3);
    v[0] = true;

    auto x = v[0];
    cout << typeid(x).name();
}
```

### 14. mutable allows modification in const method
```c++
struct A {
    mutable int x = 0;
    void inc() const { x++; }
};

int main() {
    const A a;
    a.inc();
    cout << a.x;
}
```

### 15. auto removes references
```c++
int main() {
    int x = 10;
    int& r = x;

    auto a = r; // use auto& to keep it as reference
    a = 20;

    cout << x;
}
```

### 17. Promotion to Int
```c++
int main() {
    unsigned char a = 200;
    unsigned char b = 100;

    cout << sizeof(a + b);
}
```

### 18. Calling method on nullptr
```c++
class A {
    int x;
public:
    void f() { cout << "ok\n"; }
    int d() {return x;}
};

int main() {
    A* p = nullptr;
    p->f(); // safe, does not access any member
    cout << p->d(); // undefined behavior, but may print garbage or nothing
}
```

### 19. Virtual Inheritance increases size
```c++
#include <iostream>
using namespace std;

class A { int x; };
class B : virtual A {};
class C : virtual A {};

int main() {
    cout << sizeof(A) << " "
         << sizeof(B) << " "
         << sizeof(C);
}
```