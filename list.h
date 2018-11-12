class List //begin List definition
{
private:
class Node;//forward declaration (defined in the implementation file)
Node* frontPtr;
int num_elements;
public:
List(); //default constructor
~List();//destructor
void insert(int element,int k);//insert element at location k
int remove(int k);//remove element at location k
void display();
int size();//return the number of elements in the List
};//end List definition
