#include <iostream>
using namespace std;

class MyClass {
   public:
      MyClass();
      ~MyClass();
      void SetSubobj(const int i) {*subobj = i;}
      int GetSubobj() const {return *subobj;}
   private:
      int* subobj;
};

MyClass::MyClass() {
   cout << "Constructor called." << endl;
   subobj = new int; //Allocate sub-object
   *subobj = 0;
}

MyClass::~MyClass() {
   cout << "Destructor called." << endl;
   delete subobj;
}

int main() {
   cout << "\n\nCreate two objects of type MyClass - obj1 & obj2.\n\n";
   MyClass obj1;
   MyClass obj2;
   
   cout << "Set obj1 subobj to 9.\n\n";
   obj1.SetSubobj(9);
   
   cout << "Assign obj1 to obj 2:  obj2 = obj1\n\n";
   obj2 = obj1;
   
   cout << "obj1:" << obj1.GetSubobj() << endl;
   cout << "obj2:" << obj2.GetSubobj() << endl;
   cout << "Now set subobj of obj1 integer to 7 and subobj of obj2 integer to 8.\n\n";
   obj1.SetSubobj(7);
   obj2.SetSubobj(8);
   cout << "obj1:" << obj1.GetSubobj() << endl;
   cout << "obj2:" << obj2.GetSubobj() << endl;
   return 0;
}






