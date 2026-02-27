#include "NumberList.h"
#include <iostream>

int main() {
	NumberList mylist;
	mylist.Init();
	mylist.Add(54);
	mylist.Add(12);
	mylist.Add(11);
	mylist.Add(10);
	mylist.Add(4);
	
	mylist.Print();

	mylist.Sort();

	mylist.Print();
}