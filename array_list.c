#include "list.h"
#include <stdlib.h>

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  int* array; // динамический массив, в котором будут раниться все данные
  int length; // размер списка: последний занятый индекс в array
  int capacity; // ёмкость списка: реальный размер массива array
  // если нужно, то добавьте дополнительные поля
  int size; // Размер списка: количество элементов
};

static void NewMemory(List* this){ //Функция добавления памяти
    this->capacity*=2;
    int* new=malloc(sizeof(int)*this->capacity);
    for (int i=0 ; i < this->size ; i++){
        new[i]=this->array[i];
    }
    free(this->array);
    this->array=new;
}
static void DeleteMemory(List *this){ //Функция удаления памяти
    this->capacity/=2;
    int* new=malloc(sizeof(int)*this->capacity);
    for (int i=0 ; i < this->size ; i++){
        new[i]=this->array[i];
    }
    free(this->array);
    this->array=new;
}

List *NewList() {
    List* list=malloc(sizeof(List));
    list -> length = -1;
    list -> capacity= 2;
    list -> size = 0;
    list -> array = malloc(sizeof(int)*list->capacity);
    return list;
}

void DestroyList(List* this) {
    this-> length = -1;
    this -> capacity =0;
    this -> size = 0;
    free(this->array);
    free(this);
}

void Append(List *this, int value) {
    this->length++;
    this->size++;
    if (this->capacity==this->size){ NewMemory(this); }
    this->array[this->length]=value;
}

void Prepend(List *this, int value) {
    this->size++;
    this->length++;
    if (this->capacity==this->size){ NewMemory(this); }
    for (int i=this -> length; i > 0 ; i--){
        this->array[i]=this->array[i-1];
    }
    this->array[0]=value;
}

void AppendAll(List *this, const List *that) {
    if (that->size > 0) {
        int size_all = this->size + that->size;
        if (this->capacity == size_all) {
            while (this->capacity <= size_all) { NewMemory(this); }
        }
        for (int i = 0; i < that->size ; i++) { Append(this, that->array[i]); }
        this->size=size_all;
        if (this->capacity / 4 >= size_all) { DeleteMemory(this); }
    }
    else {return exit(1);}
}
void InsertAt(List *this, int index, int value) {
    if ((index >= 0) && (index <= this->length)) {
        this->size++;
        this->length++;
        if (this->capacity==this->size) {NewMemory(this);}
        for (int i=this->length; i>index+1; i--){
            this->array[i]=this->array[i-1];
        }
        this->array[index+1]=value;
    }
}

void RemoveAt(List *this, int index) {
    if (index >=0 && index <= this->length){
        this->size--;
        this->length--;
        for (int i = index; i < this->size ; i++) {
            this->array[i] = this->array[i + 1];
        }
        if (this->capacity / 4 >= this->size) DeleteMemory(this);
    }
}

void RemoveAll(List *this) {
    this->length=-1;
    this->capacity=2;
    this->size=0;
    free(this->array);
    this->array=malloc(sizeof(int)*this->capacity);
}

int Pop(List *this){
    if (this->size>0){
        int x=this->array[this->length];
        this->size--;
        this->length--;
        if (this->capacity/4 >= this-> size){ DeleteMemory(this);}
        return x;
    }
    else exit(-1);
}

int Dequeue(List *this) {
    if (this->size>0){
        int x=this->array[0];
        this->size--;
        this->length--;
        for (int i=0; i<this->size; i++){
            this->array[i]=this->array[i+1];
        }
        if (this->capacity/4 == this->size){ DeleteMemory(this);}
        return x;
    }
    else { exit(-1);}
}

int Length(const List *this) {
    return this->size;
}
int GetAt(const List *this, int index) {
    if (this->size<=0 || index < 0 || index > this->length) {exit(-1);}
    return this->array[index];
}

