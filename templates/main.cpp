#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include "func.h"

//template class vectur<int>;

template< class T >
T max(T t1, T t2)
{
    if (t1 > t2)
        return t1;
    return t2;
}

template< class T >
int Sizeof(int a, int b)
{

    return sizeof(T);
}

template< class T >
T SumOfNumbers(double a, T b)
{
    T sum = T();
    sum += T(a) + T(b);
    std::cout << typeid(b).name();
    return sum;
}


template <class T1, class T2>
class Class_tmpl
{
    T1 m_x;
    T2 m_y;
    T1* m_array;
public:
    Class_tmpl(const T1& x = T1(), const T2& y = T2());
    Class_tmpl(const Class_tmpl<T1, T2>&);
    ~Class_tmpl();
    T1 getX() const { return m_x; }
    T2 getY() const { return m_y; }
    friend void swapi(Class_tmpl<T1, T2>& p1) {
        T2 y = p1.m_y;
        p1.m_y = (T2)p1.m_x;
        p1.m_x = y;
    };

    friend bool operator == (const Class_tmpl<T1, T2>& p1, const Class_tmpl<T1, T2>& p2) {
        return (p1.m_x == p2.m_x && p1.m_y == p2.m_y);
    }

    friend bool operator != (const Class_tmpl<T1, T2>& p1, const Class_tmpl<T1, T2>& p2) {
        return (p1.m_x != p2.m_x && p1.m_y != p2.m_y);
    }

    bool operator ! () const {
        return (m_x == 0 && m_y == 0);
    }

    Class_tmpl& operator=(Class_tmpl<T1, T2>& p1) {
        if (this == &p1)
            return *this;
        m_x = p1.getX();
        m_y = p1.getY();

        return *this;
    }

    Class_tmpl& operator++();
    Class_tmpl operator++(int);

    T1& operator[](const int element) {
        assert(element >= 0 && element < 5);
        return m_array[element];
    }

    const T1& operator[](const int element) const {
        assert(element >= 0 && element < 5);
        return m_array[element];
    }

    friend Class_tmpl operator+(const Class_tmpl<T1, T2>& p1, const Class_tmpl<T1, T2>& p2) {
        return Class_tmpl(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
    }

    friend Class_tmpl operator+(const Class_tmpl<T1, T2>& p1, T1 x) {
        return Class_tmpl(p1.m_x + x, p1.m_y + x);
    }

    friend Class_tmpl operator+(const Class_tmpl<T1, T2>& p1, T2 x) {
        return Class_tmpl(p1.m_x + x, p1.m_y + x);
    }

    friend Class_tmpl operator+(T1 x, const Class_tmpl<T1, T2>& p1) {
        return Class_tmpl(p1.m_x + x, p1.m_y + x);
    }

    friend Class_tmpl operator+(T2 x, const Class_tmpl<T1, T2>& p1) {
        return Class_tmpl(p1.m_x + x, p1.m_y + x);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Class_tmpl<T1, T2>& pt) {
        stream << pt.m_x << " " << pt.m_y;
        return stream;
    };

    friend std::istream& operator>>(std::istream& istream, Class_tmpl<T1, T2>& pt) {
        istream >> pt.m_x;
        istream >> pt.m_y;
        return istream;
    };

};

template<class T1, class T2>
Class_tmpl<T1, T2>::Class_tmpl(const T1& x, const T2& y) : m_x(x), m_y(y)
{
    m_array = new T1[5]{ 1,2,3,4,5 };
}

template<class T1, class T2>
Class_tmpl<T1, T2>::Class_tmpl(const Class_tmpl<T1, T2>& Class_tmpl_2) : m_x(Class_tmpl_2.m_x), m_y(Class_tmpl_2.m_y)
{
}

template<class T1, class T2>
Class_tmpl<T1, T2>::~Class_tmpl()
{
    delete[] m_array;
}

template<class T1, class T2>
Class_tmpl<T1, T2>& Class_tmpl<T1, T2>::operator++()
{
    m_x = m_x + 1;
    m_y = m_y + 1;
    return *this;
}

template<class T1, class T2>
Class_tmpl<T1, T2> Class_tmpl<T1, T2>::operator++(int)
{
    Class_tmpl p = *this;
    m_x = m_x + 1;
    m_y = m_y + 1;
    return p;
}

template <class T1, int SIZE = 1>
class Array
{
public:
    Array(const T1 & = T1(), const int = int()) :m_array{ T1() } {};
    T1& operator[](const int index);

private:
    T1 m_array[SIZE];
};


template <class T1, class T2>
class Pair
{
public:
    Pair(const T1& x = T1(), const T2& y = T2()) :m_first(x), m_second(y) {};

    friend std::ostream& operator<<(std::ostream& stream, const Pair<T1, T2>& obj)
    {
        stream << obj.m_first << " " << obj.m_second << std::endl;
        return stream;
    }
private:
    T1 m_first;
    T2 m_second;
};




template <class T1, int SIZE>
T1& Array<T1, SIZE>::operator[](const int index)
{
    return m_array[index];
}

template <class T1, class T2>
class Array_2
{
public:
    Array_2(T1 x, T2 y) :m_first(x), m_second(y) {}
    T1 m_first;
    T2 m_second;
};

class Array_100
{};

template <class T, int SIZE>
class Array_3
{
    T m_array[SIZE];
public:
    template<class T1>
    void copy(T1 array[SIZE]) {
        for (size_t i = 0; i < SIZE; ++i)
            array[i] = static_cast<T1>(m_array[i]);
    }
};

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars = 0)
    {
        m_dollars = dollars;
    }
    template<class T>
    operator T() { return m_dollars; }
    int getDollars() { return m_dollars; }
    void setDollars(int dollars) { m_dollars = dollars; }
};

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }

    operator Dollars() { return Dollars(m_cents / 100); }
};

void printDollars(Dollars dollars)
{
    std::cout << static_cast<double>(dollars); 
}
template <class T>
struct Currency
{
    T dollars;
    T cents;
    Currency(T d = T(), T c = T()) :dollars(d), cents(c) {}
    operator T() { return dollars + (double)cents / 100; }
};

template <class T2, class T3>
T2 add(T2 a, T3 b) { return a + b; }

template< typename T >
double GetAverage(T tArray[], int nElements)
{
    T tSum = T(); // tSum = 0
    for (int nIndex = 0; nIndex < nElements; ++nIndex)
    {
        tSum += tArray[nIndex];
    }

    return double(tSum) / nElements;
}

template <class T3>
class Convert
{
    T3 m_x;
public:
    Convert(const T3& x) :m_x(x) {};
    template<class T4>
    operator T4() const
    {
        return m_x;
    }
};

template <typename T>
class Item
{
    T Data;

public:
    Item() : Data(T()) {}

    void SetData(T nValue)
    {
        Data = nValue;
    }

    T GetData() const
    {
        return Data;
    }

    void PrintData()
    {
        std::cout << Data;
    }
};

class Point
{
    int X, Y;
public:
    Point(int x = 0, int y = 0) :X(x), Y(y) {};

    int getX() const { return X; }
    int getY() const { return Y; }

    friend std::ostream& operator<<(std::ostream& stream, const Point& obj);
};

std::ostream& operator<<(std::ostream& stream, const Point& obj)
{
    stream << obj.getX() << " " << obj.getY() << "\n";
    return stream;
}

template<class T1, class T2>
class Example2
{
public:
    Example2(const T1& first, const T2& second);
    ~Example2();
    T1 getFirsti() const;
    T2 getSecondi() const;
    operator T1();
    template<class T1, class T2>
    friend void print(const Example2<T1, T2>& obj2);

private:
    T1 m_first;
    T2 m_second;
};

template<class T1, class T2>
Example2<T1, T2>::operator T1()
{
    return Example2(m_first, m_second);
}

template<class T1, class T2>
Example2<T1, T2>::Example2(const T1& first, const T2& second) :m_first(first), m_second(second)
{
}

template<class T1, class T2>
Example2<T1, T2>::~Example2()
{
}

template<class T1, class T2>
T1 Example2<T1, T2>::getFirsti() const
{
    return m_first;
}

template<class T1, class T2>
T2 Example2<T1, T2>::getSecondi() const
{
    return m_second;
}

template<class T1, class T2>
class Example
{
public:
    Example(const T1& first, const T2& second);
    ~Example();
    Example(const Example<T1, T2>& obj1);
    T1 getFirst() const;
    T2 getSecond() const;
    Example& operator+(const Example<T1, T2>& obj2);
    Example& operator++();
    Example& operator++(int);
    bool operator==(const Example<T1, T2>& obj2);
    template<class T1, class T2>
    friend std::ostream& operator<< (std::ostream& stream, const Example<T1, T2>& obj);
    template<class T1, class T2>
    friend std::istream& operator>> (std::istream& stream, Example<T1, T2>& obj);
    T1& operator[](const int index);
    T1& operator()(const int i, const int j);
    Example& operator=(Example<T1, T2>& obj2);
    operator Example2<T1, T2>();
    Example& swap(Example<T1, T2>& obj2);

    template<class U1, class U2>
    friend class Example;

private:
    T1 m_first;
    T2 m_second;
};

template<class T1, class T2>
Example<T1, T2>::Example(const T1& first, const T2& second)
    :m_first(first), m_second(second)
{

}

template<class T1, class T2>
Example<T1, T2>::~Example()
{
}

template<class T1, class T2>
Example<T1, T2>::Example(const Example<T1, T2>& obj2)
{
    m_first = obj2.m_first;
    m_second = obj2.m_second;
}

template<class T1, class T2>
T1 Example<T1, T2>::getFirst() const
{
    return m_first;
}

template<class T1, class T2>
T2 Example<T1, T2>::getSecond() const
{
    return m_second;
}

template<class T1, class T2>
Example<T1, T2>& Example<T1, T2>::operator+(const Example<T1, T2>& obj2)
{
    m_first += obj2.m_first;
    m_second += obj2.m_second;
    return *this;
}

template<class T1, class T2>
Example<T1, T2>& Example<T1, T2>::operator++()
{
    m_first++;
    m_second++;
    return *this;
}

template<class T1, class T2>
Example<T1, T2>& Example<T1, T2>::operator++(int)
{
    Example temp(m_first, m_second);

    *this++;

    return temp;
}

template<class T1, class T2>
bool Example<T1, T2>::operator==(const Example<T1, T2>& obj2)
{
    return m_first == obj2.m_first && m_second == obj2.m_second;
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& stream, const Example<T1, T2>& obj)
{
    stream << obj.getFirst() << " " << obj.getSecond();
    return stream;
}

template<class T1, class T2>
std::istream& operator>>(std::istream& stream, Example<T1, T2>& obj)
{
    stream >> obj.getFirst() >> obj.getSecond();
    return stream;
}

template<class T1, class T2>
T1& Example<T1, T2>::operator[](const int index)
{
    //assert(index>=0 && index<10);
    //return m_data[index];
}

template<class T1, class T2>
T1& Example<T1, T2>::operator()(const int i, const int j)
{
    //assert(i >= 0 && i < 10 && j >= 0 && j < 10);
    //return m_data[i][j];
}

template<class T1, class T2>
Example<T1, T2>& Example<T1, T2>::operator=(Example<T1, T2>& obj2)
{
    if (this == &obj2)
        return *this;

    m_first = obj2.m_first;
    m_second = obj2.m_second;

    return *this;

}

template<class T1, class T2>
Example<T1, T2>::operator Example2<T1, T2>()
{
    m_first = m_first * 100;
    m_second = m_second * 100;
    return (Example2<int, int>) * this;
}

template<class T1, class T2>
Example<T1, T2>& Example<T1, T2>::swap(Example<T1, T2>& obj2)
{
    Example temp = *this;
    *this = obj2;
    obj2 = temp;
    return *this;
}

template<class T1, class T2>
void print(const Example2<T1, T2>& obj2)
{
    std::cout << obj2.m_first << " " << obj2.m_second;
}

template<class T>
class Memory
{
public:
    Memory(T* mem = NULL);
    ~Memory();
    Memory& operator=(const Memory<T>& mem);
    T& operator*();
    T operator*() const;
    operator T();
    T* operator->();
    const T* operator->() const;


private:
    T* m_mem;
};

template<class T>
Memory<T>::Memory(T* mem) : m_mem(mem)
{

}

template<class T>
Memory<T>::~Memory()
{
    delete m_mem;
}

template<class T>
T& Memory<T>::operator*()
{
    return *m_mem;
}

template<class T>
T Memory<T>::operator*() const
{
    return *m_mem;
}

template<class T>
Memory<T>& Memory<T>::operator=(const Memory<T>& mem)
{
    if (mem = &this)
        return *this;
    m_mem = mem.m_mem;
    return *this;
}

template<class T>
Memory<T>::operator T()
{
    return (T)m_mem;
}

template<class T>
T* Memory<T>::operator->()
{
    return m_mem;
}

template<class T>
const T* Memory<T>::operator->() const
{
    return m_mem;
}

struct DisplayHelper
{
    void operator()(float nValue)
    {
        std::cout << nValue << " ";
    }
};

typedef void (*TDisplayFunc)(int);
template<class TDisplayFunc>
void RenderValues(int nStart, int nEnd)
{
    TDisplayFunc func;
    for (; nStart <= nEnd; ++nStart)
        func(nStart); 
}

template< class TDerived >
class WorkerCoreT
{
public:
    void ProcessNumbers(int nStart, int nEnd)
    {
        TDerived& tDerivedObj = (TDerived&)*this;
        for (; nStart <= nEnd; ++nStart)
        {
            tDerivedObj.ProcessOne(nStart);
        }
    }
};

class ActualWorkerT : public WorkerCoreT< ActualWorkerT >
{
public:
    void ProcessOne(int nNumber)
    {
        std::cout << nNumber * nNumber << std::endl;
    }
};
template<class T>
size_t vectur<T>::size() const
{
    return m_size;
}

template<class T>
vectur<T>::vectur() :m_array(nullptr), m_size(0), m_capacity(0)
{

}

template<class T>
vectur<T>::~vectur()
{
    delete[] m_array;
}

template<class T>
T& vectur<T>::operator[](const int value)
{
    return m_array[value];
}

template<class T>
void vectur<T>::push_back(const T& value)
{
    T* newArray = new T[m_size + 1];
    m_capacity++;
    for (size_t i = 0; i < m_size; ++i)
        newArray[i] = m_array[i];
    delete[] m_array;
    newArray[m_size] = value;
    m_array = newArray;
    m_size++;
}

template<class T>
int vectur<T>::capacity()
{
    return m_capacity;
}

template<class T>
void vectur<T>::erase(const size_t index)
{
    assert(index >= 0 && index < m_size);
    T* newArray = new T[m_size - 1];

    for (size_t i = index; i < m_size - 1; ++i)
        newArray[i] = m_array[i + 1];
    for (size_t j = 0; j < index; ++j)
        newArray[j] = m_array[j];

    delete m_array;
    m_array = newArray;
    m_size--;
}

template<class Container>
void DisplayCollection(const Container& lcContainer)
{
    //typename Container::const_iterator iter;
    for (auto iter = lcContainer.begin(); iter != lcContainer.end(); ++iter)
        std::cout << *iter;
}

template<class U>
class Check
{

};


template<class T>
void foo(int x);

template<typename T>
class DetectFind
{
    struct Fallback { int find; }; // add member name "find"
    struct Derived : Fallback { };

    template<typename U, U> struct Check;

    typedef char Yes[1];  // typedef for an array of size one.
    typedef char No[2];  // typedef for an array of size two.

    template<typename U>
    static No& func(Check<int Fallback::*, &U::find>*);

    template<typename U>
    static Yes& func(...);

public:
    typedef DetectFind type;
    enum { value = sizeof(func<Derived>(0)) == sizeof(Yes) };
};




template <class T>
class Dollarsi
{
private:
    T m_dollars;
public:
    Dollarsi(T dollars = T())
        : m_dollars(dollars)
    {
    }

    template <class T>
    friend bool operator>(const T& d1, const T& d2)
    {
        return (d1.m_dollars > d2.m_dollars);
    }

    template <class T>
    friend std::ostream& operator<< (std::ostream& out, const T& dollars)
    {
        out << dollars.m_dollars << " dollars ";
        return out;
    }
    operator T();

    T& operator+=(T& obj);
};

template <class T>
Dollarsi<T>::operator T()
{
    return (T)m_dollars;
}

template <class T>
T& Dollarsi<T>::operator+=(T& obj)
{
    m_dollars += obj.m_dollars;
    return *this;
}

template <class T>
T average(T* array, int length)
{
    T sum = T();
    for (int count = 0; count < length; ++count)
        sum += array[count];

    sum /= length;
    return sum;
}

template <class T>
class A
{
public:
    A(T value = T());
    ~A();
    T print();

private:
    T m_value;
};

template <class T>
A<T>::A(T value) :m_value(value)
{

}

template <>
A<char*>::A(char* value)
{
    int length = 0;
    while (value[length] != '\0')
        length++;
    length++;
    m_value = new char[length];
    for (size_t i = 0; i < length; ++i)
        m_value[i] = value[i];
}

template <class T>
A<T>::~A()
{
}

template <>
A<char*>::~A()
{
    delete[] m_value;
}

template <class T>
T A<T>::print()
{
    return m_value;
}


template <class T, int SIZE>
class B
{
public:
    B(const T* value = nullptr);
    virtual ~B();

    virtual void print();

protected:
    T* m_value;
};

template <class T, int SIZE>
B<T, SIZE>::B(const T* value)
{
    if (value) {
        m_value = new T[SIZE];
        for (size_t i = 0; i < SIZE; ++i)
            this->m_value[i] = value[i];
    }
}

template <class T, int SIZE>
B<T, SIZE>::~B()
{
    delete[] m_value;
}

template<class T, int SIZE>
void B<T, SIZE>::print()
{
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << this->m_value[i];
}

template <class T, int SIZE>
class C :public B<T, SIZE>
{
public:
    C(const T* value = nullptr);
    ~C();
};
template <class T, int SIZE>
C<T, SIZE>::C(const T* value) : B<T, SIZE>(value)
{
    if (value) {
        this->m_value = new T[SIZE];
        for (size_t i = 0; i < SIZE; ++i)
            this->m_value[i] = value[i];
    }
}
template <class T, int SIZE>
C<T, SIZE>::~C()
{
    delete[] this->m_value;
}

template <int SIZE>
class C<double, SIZE> :public B<double, SIZE>
{
public:
    C(const double* value = nullptr);
    ~C();
    void print() override;
};

template <int SIZE>
C<double, SIZE>::C(const double* value) : B<double, SIZE>(value)
{
    if (value) {
        this->m_value = new double[SIZE];
        for (size_t i = 0; i < SIZE; ++i)
            this->m_value[i] = value[i];
    }
}

template <int SIZE>
C<double, SIZE>::~C()
{
    delete[] this->m_value;
}

template <int SIZE>
void C<double, SIZE>::print()
{
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << this->m_value[i] << "  ";
}

//template <int SIZE>
//void print(B<char*,SIZE> bi)
//{
//
//}

int main()
{   
    int array[10]{ 0,1,2,3,4,5,6,7,8,9 };
    double array_1[10]{ 0,1,2,3,4,5,6,7,8,9 };
    //C<int, 10> ci(array);
    //ci.print();
    C<double, 10>di(array_1);
    di.print();
    char* string = new char[40];

    std::cout << "Input your name!\n";
    std::cin >> string;

    A<char*> pochtalyon(string);
    delete[] string;
    std::cout << pochtalyon.print();

    /*char* pet = (char*)"pet";
    std::cout << pet;*/

    //Dollars array3[] = { Dollars(7), Dollars(12), Dollars(18), Dollars(15) };
    //std::cout << (int)average(array3, 4) << '\n';

    //vectur<double> vec;
    //vec.push_back(10);
    //DetectFind<int> detecti;
    //DetectFind<int>::Check<int DetectFind<int>::Fallback::*> cheki;
    //int *x = new int();
    //detecti.func(&cheki);
    //Check<int*> check;
    //delete x;
    /*setlocale(LC_ALL, "Russian");
    vectur<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);
    vec.push_back(90);
    vec.push_back(100);
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n" << vec.size();
    std::cout << "\n" << vec.capacity() << std::endl;
    vec.erase(5);
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n" << vec.size();
    std::cout << "\n" << vec.capacity();*/

    /*std::vector<int> lev;
    lev.push_back(10);
    lev.push_back(10);
    lev.push_back(10);
    lev.push_back(10);
    std::vector<int>::iterator iter;
    for (iter = lev.begin(); iter < lev.end(); iter++)
        std::cout << *iter << " ";
    std::cout << lev.capacity() << std::endl;*/

    /*std::vector<int> seti{1,2,3};
    DisplayCollection <std::vector<int>> (seti);

    Pair< int, Array< double, 50 >> PairOfArray(10);
    Array<Pair<int, int>> pps(Pair<int, int>(), 50);
    pps = Array<Pair<int,int>>(Pair<int,int>(10,10),50);
    pps[0] = Pair<int, int>(100, 200);*/

    //std::cout << pps[0];
    //std::cout << SumOfNumbers(10.8, 20);
    //Class_tmpl<int, int>p;
    //Class_tmpl<int, double>pp(4, 6.7);
    //std::cout << pp.getY();
    //Class_tmpl<int, double> pp_2(pp);
    //std::cout << pp_2.getY();
    //Class_tmpl<int, double>pp_3(6, 7.7);
    //if (pp == pp_2)
    //    std::cout << "Class_tmpl!!!\n";
    //else
    //    std::cout << "Vasya!!!\n";
    //std::cout << pp_3++;

   /* Class_tmpl <int, double> p4;
    std::cin >> p4;
    std::cout << "Object 1: " << p4 << "\n";
    std::cout << "Sum: " << 90.5 + p4 << "\n";*/

    /*Class_tmpl <int, double> p5(2, 4.5);
    swapi(p5);
    std::cout << p5;
    Class_tmpl <int, double> p5(2, 4.5);*/
    //Pair<int, Array<int, 50>> pp(20, Array<int, 50>());
    //Array<Pair<int, int>, int> pps;
   // pps = Array<Pair<int,int>,int>(Pair<int,int>(1,2),30);
    //pp.m_second.m_array[10] = 0;
    //pps.m_array[0] = Pair<int,int>(0,1);
    //std::cout<<pps.m_array[0].m_second;
    //Array_2<int,int>pps_2(10,20);
    //pps_2 = Array_2<int,int>(0,0);
   /* Array_3 <int, 10> petya;
    float arr[10];
    petya.copy(arr);*/

    //Convert<int> conv(10);
    //float fl = conv;
    //std::cout << fl;

   /* Currency <double> c1;
    c1.cents = 100.6;
    c1.dollars = 10.3;
    Currency <int> c2;
    c2.cents = 200;
    c2.dollars = 20;
    Currency <double> c3;
    std::cout << add(c1, c2);
    const int size = 5;
    double array[size]{ 0,1,2,3,5 };*/
    //std::cout<<GetAverage(array,size);
    //std::cout<<c3;

    /*Point pt1(12, 40), pt2(120, 400);
    Item <Point> item;

    item.SetData(pt1);
    item.PrintData();
    std::cout << item.GetData();*/

    /* Example <int, int> ex1(10, 20);
     Example <int, int> ex2(30, 40);
     ex1.swap(ex2);
     std::cout << ex1 << ex2;
     print<int, int>(ex1);*/

     /*Memory<Example<int, int>> mem(new Example<int, int>(1, 1));
     int* first = new int;
     Memory<int> mem_2(first);
     *mem_2 = 10;
     std::cout<<mem->getFirst();*/


     //RenderValues<DisplayHelper>(1, 40);    
     //RenderValues<DisplayHelper>(1, 20);

    /*WorkerCoreT<ActualWorkerT> worker;
    worker.ProcessNumbers(1, 200);*/

    return 0;
}