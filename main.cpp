#include <fast_search.h>

#include <array>
#include <iostream>
#include <string>

using namespace std;

void findOne()
{
    cout << "--- find one occurrences" << endl;
    using TheFinder = Finder<'a'>; // The char to find.
    std::string str { "I have a string 'abc'." };
    str.append(8, '\0'); // Padding with 8 char is required.
    auto result = TheFinder::find(&*str.begin(), &*str.end());
    if (result != &*str.end())
        std::cout << "The found position is: " << result - &*str.begin() << std::endl;
    else
        std::cout << "Not found" << std::endl;
}

void findAll()
{
    cout << "--- find all occurrences" << endl;
    using TheFinder = Finder<'f'>;
    string data {"abcdefghakdjfjadff;dfjffd;jksdfdfff"};
    data.append(8, '\0'); // Padding with 8 char is required.
    for (auto finding = TheFinder::find(&*data.begin(), &*data.end());
        finding < &*data.end();
        finding = TheFinder::find(finding+1, &*data.end()))
    {
        cout << "pos = " << finding - &*data.begin() << endl;
    }
}

int main()
{
    findOne();
    findAll();
}
