#include "stuff.h"

#include <iostream>
using std::cout, std::endl;

int main()
{
    Stuff my_stuff(8, 3.14, "woot");
    Stuff more_stuff(-23456, 4546.2344e23, "epic");
    
    cout << "I have stuff: " << endl;
    cout << my_stuff << endl;
    cout << "...and more stuff: " << endl;
    cout << more_stuff << endl;

    cout << "This works because Stuff::get_word() is const: " << more_stuff.get_word() << endl;
}