#pragma once

#include <iostream>

template<typename T>

class GrowArray {
private:
    int used;
    int capacity;
    T* data;
    void checkGrow() {
        if (used <= capacity){
            return;
        } else {
            // don't grow unless you have to
            T *old = data;
            //TODO: every time the list grows, double it!!!
            data = new T[capacity * 2]; // calls T::T()
            for (int i = 0; i < used; i++){
                data[i] = old[i];
            }
            delete[]old;
        }
    }
public:
    GrowArray() : used(0), capacity(0), data(nullptr) {}
    ~GrowArray() {
        delete[]data;
    }
    GrowArray(int  initialCapacity):used(0), capacity(initialCapacity), data(new T[capacity]){} //TODO: fix!
//TODO: add destructor, copy constructor, operator =

    GrowArray(const GrowArray<T>& orig):used(orig.used), capacity(orig.capacity), data(new T[capacity]){
        memcpy(data, orig.data, used);
    }

    GrowArray& operator =(const GrowArray<T>& orig){
        GrowArray copy(orig);
        used = orig.used;
        capacity = orig.capacity;
        swap(data, copy.data);
        return *this;
    }

    void addEnd(const T& v) {
        checkGrow();
        data[used-1] = v;
    }

    T removeEnd() {
        used--;
        return data[used];
    }

    T operator [](int i) const {
        return data[i];
    }

    T& operator [](int i) {
        return data[i];
    }

    friend std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list) {
        for (int i = 0; i < list.used; i++)
            s << list[i] << ' ';
        return s;
    }
};