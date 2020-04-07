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
  AssertEq(11,GetAt(list,4),"AppendAll_1");
  AssertEq(10,GetAt(list,3),"AppendAll_2");
  AssertEq(42,GetAt(list,1),"AppendAll_3");
  InsertAt(list,1, 123);
  AssertEq(123,GetAt(list,2),"InsertAt_1");
  AssertEq(5,GetAt(list,3),"InsertAt_2");
  AssertEq(42,GetAt(list,1),"InsertAt_3");
  RemoveAt(list,2);
  AssertEq(11,GetAt(list,4),"RemoveAt_1");
  AssertEq(10,GetAt(list,3),"Remove_2");
  AssertEq(42,GetAt(list,1),"Remove_3");
  RemoveAll(b);
  Append(b,10);
  Append(b,2);
  Append(b,3);
  Append(b,4);
  AssertEq(10,GetAt(b,0),"RemoveAll_1");
  AssertEq(2,GetAt(b,1),"RemoveAll_2");
  AssertEq(3,GetAt(b,2),"RemoveAll_3");
  AssertEq(4,Pop(b),"Pop");
  for (int i=0; i<Length(b);i++){
      printf("%d ",GetAt(b,i));
  }
  printf("\n");
  AssertEq(10,Dequeue(b),"Deque");
    for (int i=0; i<Length(b);i++){
        printf("%d ",GetAt(b,i));
    }
  AssertEq(2,Length(b),"Length");
  AssertEq(2,GetAt(b,0),"GetAt");
  DestroyList(list);
}   