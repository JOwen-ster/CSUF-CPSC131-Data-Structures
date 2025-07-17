
/**
 * You don't have to modify this source file, but can if you want.
 * This will not be used for grading, so you can use it to debug your
 * vector class.
 * This is the program that runs with "make run"
 */

///	Your welcome
#include <iostream>
#include "MyVector.hpp"

///	Your welcome
using std::cout, std::endl;

//


int main()
{
	//
	cout << "Hello! Maybe use this source file for debugging?" << endl;
	MyVector<int>v1;
	//v1.push_back(3);
	for(int i = 0; i < 200; i++) v1.push_back(i);
	//for(int i = 0; i < 200; i++) v1.pop_back();
	//v1.insert(3, 12);

	return 0;
}


