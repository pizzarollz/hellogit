#include "list.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions
using namespace std;
class List::Node //self-referential Node class
{
public:
int data;
Node* link;
//link is a data member which is a pointer
//to an object of the same type (i.e. Node)
Node()//default constructor
{
data = 0;
link = nullptr;
}
Node(int new_data)//an overloaded constructor
{
data = new_data;
link = nullptr;
}
Node(int new_data, Node* new_link)//another overloaded constructor
{
data = new_data;
link = new_link;
}
};//end Node class definition (can only be seen by the List class)
List::List()
{
frontPtr = nullptr;
num_elements = 0;
}
List::~List()
{
while(num_elements > 0)
remove(1);
}
int List::size()
{
return num_elements;
}
void List::insert(int num, int k)
{
if (k < 1 || k > num_elements +1) //if the location is invalid
throw out_of_range("List::insert(...)");//throw an "out_of_range" exception
Node* newPtr = new Node(num);//Step 1
if(k == 1)
{
newPtr->link = frontPtr;//Step 1a
frontPtr = newPtr;//Step 1b
}
else
{
Node* prevPtr = frontPtr;//Step 2a
for(int loc = 1; loc != k-1; loc++) //Step 2b
prevPtr = prevPtr->link;//Step 2b
newPtr->link = prevPtr->link;//Step 3a
prevPtr->link = newPtr; //Step3b
}
num_elements++;
}
int List::remove(int k)
{
if (k < 1 || k > num_elements)//if the location is invalid
throw out_of_range("List::remove(...)");//throw an "out_of_range" exception
Node* delPtr;
int del_data;
if(k == 1)
{
delPtr = frontPtr;
frontPtr = frontPtr->link;
}
else
{
Node* kPrevPtr = frontPtr;
for(int loc = 1; loc != k-1; loc++)
kPrevPtr = kPrevPtr->link;
delPtr = kPrevPtr->link;
kPrevPtr->link = delPtr->link;
}
del_data = delPtr->data;
delete delPtr;
num_elements--;
return del_data;
}
void List::display()//For debugging purposes only
{
for(Node* curPtr = frontPtr; curPtr != nullptr; curPtr = curPtr->link)
cout<<curPtr->data<<" ";
}
