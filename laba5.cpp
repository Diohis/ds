﻿#include <iostream>
#include <string>
#include <stdio.h> 
#include <time.h>
#include <chrono>
using namespace std;

class queue {
private:
    int* values;
    int k;
    int max_size;
    int u;
public:
    queue(int max_size) {
        this->max_size = max_size;
        values = new int[max_size];
        k = 0;
        u = 0;
    }
    int get() {
        return values[u];
    }
    void add(int x) {
        if (k < max_size) {
            values[(k + u) % max_size] = x;
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
        cout << "Состав очереди: ";
        for (int i = 0; i < k; i++) {
            cout << values[u + i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return k == 0;
    }
};

class stack {
private:
    int* values;
    int k;
    int max_size;
public:
    stack(int max_size) {
        this->max_size = max_size;
        values = new int[this->max_size];
        k = 0;
    }
    int get() {
        return values[k-1];
    }
    void add(int x) {
        if (k < this->max_size) {
            values[k] = x;
            k++;
        }
    }
    int pop() {
        if (!isEmpty()) {
            k--;
            int x = values[k];
            return x;
        }

    }
    void print() {
        for (int i = 0; i < k; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return k == 0;
    }
};

class Graph {
private:
    int* points;
    int n_points = 0;
    int n_vertex = 0;
    int max_vertex = 0;
    int** vertex;
    int* used;
    int* p;
    int* point_path;
    int n_path;
    int n_used = 1;
    int n_fast_cycle = 123123;
    int* fast_cycle;
public:
    Graph(int points) {
        n_points = points;
        this->points = new int[n_points];
        for (int i = 0; i < n_points; i++) {
            this->points[i] = i;
        }
        max_vertex = (n_points * (n_points - 1)) / 2;
        vertex = new int* [max_vertex];
    }
    void addVertex(int A, int B) {
        if (A >= 0 and A < n_points and B >= 0 and B < n_points) {
            if (n_vertex < max_vertex) {
                int* new_vertex = new int[2] {A, B};
                vertex[n_vertex] = new_vertex;
                n_vertex++;
            }
        }
    }

    void print_points() {
        for (int i = 0; i < n_points; i++) {
            cout << points[i] << endl;
        }
    }



    void print_connection() {
        for (int i = 0; i < n_vertex; i++) {
            cout << vertex[i][0] << " -> " << vertex[i][1] << endl;
        }
    }

    void bfs(){
        int xk;
        cout << "Введите начальную вершину для обхода в ширину: "; cin >> xk;
        string carcas = "";
        used = new int[n_points];

        used[0] = xk;
        n_used = 1;
        queue q(n_points);
        q.add(xk);
        while (!q.isEmpty()) {
            q.print();
            int x = q.pop();
            for (int i = 0; i < n_vertex; i++) {
                int y = xk;
                if (vertex[i][0] == x) {
                    y = vertex[i][1];
                }
                else if (vertex[i][1] == x) {
                    y = vertex[i][0];
                }
                if (!check_in_used(y)) {
                    add_used(y);
                    q.add(y);
                    carcas += to_string(x) + " -> " + to_string(y) + "\n";
                }
            }
            
        }
        cout << "Каркас:" << endl<< carcas << endl;
    }

    void dfs() {
        int xk;
        cout << "Введите начальную вершину для обхода в глубину: "; cin >> xk;
        string carcas = "";
        used = new int[n_points];

        used[0] = xk;
        n_used = 1;
        stack q(n_points);
        q.add(xk);
        while (!q.isEmpty()) {
            q.print();
            int x = q.get();
            bool newVertex = false;
            for (int i = 0; i < n_vertex; i++) {
                int y = xk;
                if (vertex[i][0] == x) {
                    y = vertex[i][1];
                }
                else if (vertex[i][1] == x) {
                    y = vertex[i][0];
                }

                if (!check_in_used(y)) {
                    newVertex = true;
                    add_used(y);
                    q.add(y);
                    carcas += to_string(x) + " -> " + to_string(y) + "\n";
                    break;
                }
            }
            if (!newVertex) {
                q.pop();
            }

        }
        cout << "Каркас:" << endl << carcas << endl;
    }

    void add_used(int k) {
        int* new_used = new int[n_used + 1];
        for (int i = 0; i < n_used; i++) {
            new_used[i] = used[i];
        }
        new_used[n_used] = k;
        this->used = new_used;
            
        n_used++;
    }



    bool check_in_used(int k) {
        for (int i = 0; i < this->n_used; i++) {
            if (this->used[i] == k)return true;
        }
        return false;
    }

    bool in_array(int element, int* array, int n) {
        for (int i = 0; i < n; i++) {
            if (element == array[i])return true;
        }
        return false;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    Graph test(8);
    test.addVertex(0, 2);
    test.addVertex(2, 3);
    test.addVertex(2, 4);
    test.addVertex(2, 6);
    test.addVertex(4, 7);
    test.addVertex(3, 5);
    test.addVertex(5, 1);
    test.addVertex(6, 1);
    test.addVertex(7, 1);
    test.dfs();
    test.print_connection();
    //test.start_fire_while();
    //test.start_fire(0);
    return 0;
}