#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void AssertEq(int expected, int actual, const char* msg) {
  if (expected != actual) {
    printf("Test failed: %s\n expected %d but got %d\n", msg, expected, actual);
    exit(-1);
  }
}

int main(void) {
  List* list = NewList();
  List* b= NewList();
  Append(b,5);
  Append(b,10);
  Append(b,11);
  AssertEq(0, Length(list), "empty list length should be zero");
  Append(list, 42);
  AssertEq(1, Length(list), "Length([42]) should be 1");
  AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
  Prepend(list, 1);
  AssertEq(1,GetAt(list,0),"Prepend");
  AppendAll(list,b);
  AssertEq(11,GetAt(list,4),"AppendAll");
  InsertAt(list,1, 123);
  AssertEq(123,GetAt(list,2),"InsertAt");
  AssertEq(5,GetAt(list,3),"InsertAt_2");
  RemoveAt(list,4);
  AssertEq(11,GetAt(list,4),"RemoveAt");
  RemoveAll(b);
  Append(b,10);
  Append(b,2);
  Append(b,3);
  AssertEq(10,GetAt(b,0),"RemoveAll");
  AssertEq(2,GetAt(b,1),"RemoveAll_2");
  AssertEq(3,Pop(b),"Pop");
  AssertEq(10,Dequeue(b),"Deque");
  DestroyList(list);
}   