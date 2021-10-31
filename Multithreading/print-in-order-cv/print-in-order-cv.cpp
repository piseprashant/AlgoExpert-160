class Foo {
    mutex mu;
    condition_variable cond;
    int state = 1;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mu);
        cond.wait(lock,[this](){return state==1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 2;
        cond.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mu);
        cond.wait(lock,[this](){return state==2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 3;
        cond.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mu);
        cond.wait(lock,[this](){return state==3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        state = 1;
        cond.notify_all();
    }
};
