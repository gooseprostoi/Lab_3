#pragma once
#include <iostream>
#include <initializer_list>
#include <cassert>

template <typename T>
struct Node {
	T val;
	Node<T>* next = nullptr;
};

template <typename T>
struct List {
private:
	size_t sz = 0; // размер
	Node<T>* front = new Node<T>; // псево элемент перед массивом, позволяет просто определять пустые списки
	Node<T>* last = new Node<T>;
public:
    List() : last(front) {}; // инициализация пустого списка
    List(size_t n); // конструктор списка n неинициализированных узлов
    List(size_t n, T x); // конструктор списка n инициализированных x-ом узлов
    List(const std::initializer_list<T>& l); // конструктор через initializer_list
    auto get_node(unsigned n) const; // // получение адреса n-ого узла
    auto operator[](unsigned n) const; // получение значения n-ого узла
    List(const List<T>& l); // конструктор копирования
    void swap(List<T>& a, List<T>& b); // swap для листов
    List<T>& operator=(List<T> l); // оператор присваивания для листов
    void insert(List<T> l, const unsigned n = 0); // вставляет в лист лист с n-ого адреса
    void insert(const T& x, const unsigned n = 0); // вставляет в лист значение на с n-ый адрес
    T pop_first();
    T pop_last();
    void erase(unsigned n); // удаление c n-ого элемента
    ~List(); // деструктор
    void reverse_rec(unsigned n = 0, Node<T>* cur = nullptr); // reverse рекурсией
    void reverse_itr(); // reverse итерацией
    unsigned size() const; // возращает размер
    template <typename K> friend std::ostream& operator<<(std::ostream& out, const List<K>& list);
};

template <typename K>
std::ostream& operator<<(std::ostream& out, const List<K>& list); // перегрузка << для списка


