#include<iostream>
#include "stdlib.h"
using namespace std;

class SafeArray {
  private:
    int N;
    int *arr;

    // disardan kimse değiştirmesin diye private sectiona aldık
    void put(int i, int val) {
    	arr[i] = val;
    }

  public:
    // default constructor
    SafeArray() {
      N = 0;
      arr = NULL;
    }
    // overloaded constructor
    SafeArray(int SIZE, int FILL = 0) {
      if (SIZE != 0) {
      	N = SIZE;
      	arr = new int[SIZE];
      	if (FILL == 0) {
      	  for (int i = 0; i < SIZE; i++) arr[i] = 0;
      	}
        else {
        	unsigned int t = static_cast<unsigned int>(time(NULL));
        	srand(t);
        	for (int i = 0; i < SIZE; i++) arr[i] = rand()%FILL;
        }
      }
    }
    // i inci elemani veren method
    int at(int i){
    	if (i < N && i >= 0) {
    		return arr[i];
    	}
    	else {
    		cout << "out of bound !!!" << endl;
    		return 0;
    	}
    }

    SafeArray operator + (SafeArray &other) {
    	SafeArray tmp(N);
    	for (int i = 0; i < N; i++) {
    		tmp.put(i, arr[i]+other.arr[i]);
    	}
    	return tmp;
    }
};

    int main(){
    	SafeArray sa1(10,100);
    	SafeArray sa2(10,5);
    	SafeArray sa3 = sa1+sa2;

    	// perform arithmetic operator


    	// print content
    	for (int i = 0; i < 10; i++){
    		cout <<sa1.at(i)<<"+"<<sa2.at(i)<<"="<<sa3.at(i)<< endl;
    	}
    }