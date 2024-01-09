#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

template <typename T>
class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
    }

    ~Counter() {
        count--;
    }

    static int getCount() {
        return count;
    }

    static void decrement() {
        count--;
    }

    static void increment() {
        count++;
    }
};

// Initialize the count to 0
template <typename T>
int Counter<T>::count = 0;

#endif // COUNTER_H_INCLUDED
