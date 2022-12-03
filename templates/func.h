#pragma once
template<class T>
class vectur
{
public:
    vectur();
    ~vectur();
    void push_back(const T& value);
    size_t size() const;
    int capacity();
    T& operator[](const int value);
    void erase(const size_t index);

private:
    size_t m_size;
    T* m_array;
    int m_capacity;
};
