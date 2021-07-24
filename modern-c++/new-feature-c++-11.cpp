/*
 * 1. Initializer List
 */
 
 //C++ 03 Initializer List
int arr[4] = {3, 2, 4, 5};

//Initializer list wasn't supported for vectors, so initialization was done as follows
#include <vector>

vector<int> v;
v.push_back(3);
v.push_back(2);
v.push_back(4);
v.push_back(5);

//C++ 11 extended the support
vector<int> v = ( 3, 4, 1, 9 }; //calling initializer_list constructro

//All the relevent STL containers have been updated to accept initializer_list.

//Define your own initializer_list constructor:
#include <initializer_list>
class boVector
{
    vector<int> m_vec;
    public:
        boVector(const initializer_list<int>& v)
        {
            for (initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
            {
                m_vec.push_back(*itr);
            }
        }
};

boVector v = { 0, 2, 3, 4 };
boVector v { 0, 2, 3, 4 }; // effectively the same

/*
 * 2. Uniform Initialization
 */

//C++ 03
class dog //Aggregate class or struct
{
    public:
        int age;
        string name;
};
dog d1 = (5, "Henry"}; //Aggregate Initialization

// C++ 11 extended the scope of curly brace initialization
class dog 
{
    public:
        dog(int age, string name) {...};
}

dog d1 = {5, "Henry"};

/* Uniform Initialization Search Order:
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriate perameters
 * 3. Aggregate initializer
 */

dog d1{3};

class dog 
{
    public:
        int age;                                // 3rd choice

        dog (int a)                             // 2nd choice
        {
            age = a;
        }

        dog(const initializer_list<int>& vec)   // 1st choice
        {
            age = *(vec.begin());
        }
};

/*
 * 3. auto type
 */

std::vector<int> vec = {2, 3, 4, 5};

//C++ 03
for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it)
{
    m_vex.pushback(*it);
}

//C++ 11: use auto type
for (auto it = vec.begin(); it!=vec.end(); ++it)
{
    m_vec.push_back(*it);
}

auto a = 6;   // a is a integer
auto b = 9.6; // b is a double
auto c = a;   // c is an integer

    // IDE becomes more important

/*
 * 4. Foreach
 */

//C++ 03;
for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
    cout << (*itr);

// C++ 11:
for (int i : v) // works on any class that has begin() and end()
{               // readonly access
    cout << i;
}

for (auto& i : v)
{
    i++;        // changes the values in v
}

/*
 * 5. nullptr
 *
 * To replace NULL in C++ 03
 */

void foo(int i) { cout << "foo_int" << endl; }
void foo(char* pc) { cout << "foo_char*" << endl; }

int main()
{
    foo(NULL); // Ambiguity

    //C++ 11
    foo(nullptr); // call foo(char*)
}

/*
 * 6. enum class --> basically integers now
 */

//C++ 03
enum apple {green_a, red_a};
enum orange {big_o, small_o};

apple a = green_a;
orange o = big_o;

if (a == o)
    cout << "greeen apple and big orange are the same\n";
else
    cout << "green apple and big orange are not the same\n";

//Compile fails because we haven't defined == (apple, orange)


/*
 * 7. static_assert
 */

// run-time assert
assert (my pointer != NULL);

//Compile time assert (c++ 11)
static_assert(sizeof(int) == 4);

/*
 * 8. Delegating Constructor
 */

class dog 
{
    public:
        dog() {...}
        dog(int a) { dog(); doOtherThings(a); }
};

//C++ 03:
class dog
{
    public:
        dog() {...}
        dog(int a) { dog(); doOtherThings(a); }
};

//C++ 03
class dog
{
    init() {...}
    public:
     dog() { init(); }
     dog(int a) { init(); doOtherThings(); }
};

/* Cons:
 * 1. Cubersome code.
 * 2. init() could be invoked by other functions.
 */

//C++ 11:
class dog
{
    age = 9; // age will be initialized at every constructor

    public:
    dog() {...}
    dog(int a) : dog() { doOtherThings(); }
};
//limitation: dog() has to be called first.
