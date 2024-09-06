#include <iostream>
#include <string>

using namespace std;

class stack {
private:
    int* values;
    int k;
    int max_size;
public:
    stack() {
        max_size = 100;
        values = new int[max_size];
        k= 0;
         
    }
    void add(int x) {
        if (k < max_size) {
            values[k] = x;
            k++;
        }
    }
    int pop() {
        if (!isEmpty()) {
            int x = values[k];
            k--;
            return x;
        }

    }
    void print() {
        for (int i = 0; i < k; i++) {
            cout << values[i]<<" ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return k == 0;
    }
};

class queue {
private:
    int* values;
    int k;
    int max_size;
    int u;
public:
    queue() {
        max_size = 3;
        values = new int[max_size];
        k = 0;
        u = 0;
    }
    void add(int x) {
        if (k < max_size) {
            values[(k+u)%max_size] = x;
            k++;
        }
    }
    int pop() {
        int x = values[u];
        u++;
        if (u == max_size)u = 0;
        k--;
        return x;
    }
    void print() {
        for (int i = 0; i < k; i++) {
            cout << values[u+i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return k == 0;
    }
};

class list {
private:
    int* values;
    int k;
    int max_size;
public:
    list() {
        max_size = 100;
        values = new int[max_size];
        k = 0;
    }
    void insert(int x, int pos) {
        if (pos >= 0 and pos <= k) {
            for (int i = k-1; i >= pos; i--) {
                values[i + 1] = values[i];
            }
            values[pos] = x;
            k++;
        }
    }
    void print() {
        for (int i = 0; i < k; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

class set {
private:
    bool* values;
    string* names;
    int max_size;
    int getEmptyPos() {
        for (int i = 0; i < max_size; i++) {
            if (!values[i])return i;
        }
        return -1;
    }
    int findElemenent(string element) {
        for (int i = 0; i < max_size; i++) {
            if (names[i] == element) {
                return i;
            }
        }
        return -1;
    }
public:
    set() {
        max_size = 100;
        values = new bool[max_size];
        names = new string[max_size];
        for (int i = 0; i < max_size; i++) {
            values[i] = false;
        }
    }
    void add(string newName) {
        int index = getEmptyPos();
        if (index>=0) {
            names[index] = newName;
            values[index] = true;
        }
            
        
    }
    bool check(string element) {
        return findElemenent(element) >= 0;
    }
    void print() {
        for (int i = 0; i < max_size; i++) {
            if (values[i])cout << names[i] << " ";
        }
    }
    void pop(string element) {
        int index = findElemenent(element);
        if (index>=0)values[index] = false;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    /*queue* test = new queue();
    
    test->add(3);
    test->add(4);
    test->add(5);
    test->print();
    test->pop();
    test->pop();
    test->pop();
    test->print();
    test->add(6);
    test->print();
    test->pop();
    test->print();*/
    set* test = new set();

    test->add("Димка");
    test->add("Петька");
    test->add("Санька");
    test->print();
    cout<<test->check("Димка");
}

