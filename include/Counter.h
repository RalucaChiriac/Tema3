#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED


template <typename T>
class Counter {
private:
    inline static int count;

public:
    Counter() {
        count++;
    }

    virtual ~Counter() {
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


#endif // COUNTER_H_INCLUDED
