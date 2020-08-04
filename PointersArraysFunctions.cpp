#include <iostream>
using namespace std;

int globArray[4];

int* createAndReturnArray(size_t size) {
  int* array = new int[size];
  return array;
}

int increment(int input) { //passing by value (copy the variable into input)
  return ++input;
  // a++ = return a, then increment
  // ++a = increment a, then return
}

void increment(int* input) { //passing pointers into function
  // input++;
  *input++;
}

void incrementByReference(int& input){ //passing by reference
  input++;
}

// void increment(int input){++input;}

int main() {
  int a = 10;
  int b = 5;
  int* c = &a;  // a=10, b=5,c->a
  *c = 6;       // value of a is now 6   a=6,b=5,c->a
  c = &b;       // a=6, b=5, c->b
  *c = 30;      // a=6, b=30, c->b

  increment(a);  // a=6, b=30, c->b
  a = increment(a); // a = 7, b=30, c->b
  increment(c);// a = 7,b=31, c->b
  increment(&a); // a = 8,b=31,c->b
  incrementByReference(a); //a = 9, b = 31, c->b


  // int* test = new int[1, 2, 3, 4];  // DOES NOT CREATE AN ARRAY {1,2,3,4}
  unsigned int size = 5;

  int* test = new int[size];  // if size is very large,
  *test = 5; //set first element of array to 5;
  *(test + 1) = 5; //str r3, [r0, #4]

  //you might forget that you moved test, test[4] = 100;  -- don't do this
  // test[-1] = valid, but don't do this
  // test++;
  // *test = 5;


  // 5=10; 5 is an invalid lvalue
  int* testInt = new int(45);
  int arrayA[size];
  int arrayB[size] = {1, 2, 3, 4};  // assuming size>=4
  int arrayC[] = {1, 2, 3, 4};      // always correct
  globArray[2] = 150;
  // arrayA[4] = Random Garbage left over from another program's memory

  // arrayA[7] = Random Garbage, or another variable in your program, or
  // possibly memory that belongs to another program
  // int* arrayD = createAndReturnArray(4);
  int* arrayD;
  for (int i = 0; i < 10; i++) arrayD = createAndReturnArray(1024);
  arrayD[2] = 5;
  delete[] test;
  delete[] arrayD;
  delete testInt;

  /*
   * This is a memory leak: Only the last array that was created will be
  deleted. The first 9 will still exist but no variable will point to them
  int* arrayD;
  for (int i = 0; i < 10; i++) arrayD = createAndReturnArray(1024);
  arrayD[2] = 5;
  delete[] test;
  delete[] arrayD;
  delete testInt;
  */

  return 0;
}