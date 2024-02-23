# fast_search
A utility code for finding char in a string with high performance.

It utilizes the benefit of vectorization. Although no special SIMD is used, it could be able to process 8 ASCII characters per iteration.

## Usage
```c++
// Search for character in the given string `str`. The string `str` should be padded with 8.
using TheFinder = Finder<'a'>; // The char to find.
std::string str { "I have a string 'abc'." };
str.append(8, '\0'); // Padding with 8 char is required.
auto result = TheFinder::find(&*str.begin(), &*str.end());
if (result != &*str.end())
    std::cout << "The found position is: " << result - &*str.begin() << std::endl;
else
    std::cout << "Not found" << std::endl;
```

## Limitation
It must be run on 64-bits CPU.

## Improvement in future
There is big room for improving the implementation. Please contact me at [email: 313259456@qq.com](mailto:313259456@qq.com), if you have any suggestions or ideas.
