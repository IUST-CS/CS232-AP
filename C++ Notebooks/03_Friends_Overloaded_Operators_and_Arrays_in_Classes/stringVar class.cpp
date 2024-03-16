// This is the definition for the class StringVar
// whose values are strings. An object is declared as follows.
// Note that you use (maxSize), not [maxSize]
// StringVar theObject(maxSize);
// where max_size is the longest string length allowed.
#include <iostream>
using namespace std;

class StringVar
{
public:
    StringVar(int size);
    // Initializes the object so it can accept string values up to size
    // in length. Sets the value of the object equal to the empty string.

    StringVar();
    // Initializes the object so it can accept string values of length 100
    // or less. Sets the value of the object equal to the empty string.

    StringVar(const char a[]);
    // Precondition: The array a contains characters terminated with '\0'.
    // Initializes the object so its value is the string stored in a and
    // so that it can later be set to string values up to strlen(a) in length.

    StringVar(const StringVar &stringObject);
    // Copy constructor.

    ~StringVar();
    // Returns all the dynamic memory used by the object to the freestore.

    int length() const;
    // Returns the length of the current string value.
    void inputLine(istream &ins);
    // Precondition: If ins is a file input stream, then ins has been
    // connected to a file.
    // Action: The next text in the input stream ins, up to '\n', is copied
    // to the calling object. If there is not sufficient room, then
    // only as much as will fit is copied.
    friend ostream &operator<<(ostream &outs, const StringVar &theString);
    // Overloads the << operator so it can be used to output values
    // of type StringVar
    // Precondition: If outs is a file output stream,
private:
    char *value;   // pointer to dynamic array that holds the string value.
    int maxLength; // declared max length of any string value.
};

// <The definitions of the member functions and overloaded operators go here.>

// Program to demonstrate use of the class StringVar.

void conversation(int maxNameSize);
// Carries on a conversation with the user.

int main()
{
    using namespace std;
    conversation(30); // Memory is returned to the freestore when the function call ends.
    cout << "End of demonstration.\n";
    return 0;
}

// This is only a demonstration function:
void conversation(int maxNameSize)
{
    using namespace std;

    StringVar yourName(maxNameSize), ourName("Borg"); // Determines the size of the dynamic array

    cout << "What is your name?\n";
    yourName.inputLine(cin);
    cout << "We are " << ourName << endl;
    cout << "We will meet again " << yourName << endl;
}
// This is the implementation of the class StringVar.
// The definition for the class StringVar is in Display 11.11.
#include <cstdlib>
#include <cstddef>
#include <cstring>

// Uses cstddef and cstdlib:
StringVar::StringVar(int size) : maxLength(size)
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    value[0] = '\0';
}

// Uses cstddef and cstdlib:
StringVar::StringVar() : maxLength(100)
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    value[0] = '\0';
}

// Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[]) : maxLength(strlen(a))
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    strcpy(value, a);
}
// Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar &stringObject)
    : maxLength(stringObject.length())
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    strcpy(value, stringObject.value);
}
StringVar::~StringVar()
{
    delete[] value;
}

// Uses cstring:
int StringVar::length() const
{
    return strlen(value);
}

// Uses iostream:
void StringVar::inputLine(istream &ins)
{
    ins.getline(value, maxLength + 1);
}

// Uses iostream:
ostream &operator<<(ostream &outs, const StringVar &theString)
{
    outs << theString.value;
    return outs;
}