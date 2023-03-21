// mogao_caves.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "mogao_vector.h" //final implement

#include "exp_vector.h"
#include "exp_algorithm.h"
#include "exp_string.h"
using namespace Mogao;
// using namespace experiment;
class slave
{
public:
    slave(const std::string &str) : data(new std::string(str)) {}
    slave(const slave &);
    slave &operator=(const slave &);

private:
    std::string *data = nullptr;
};
void test_slave()
{
    slave ob("string");
}
void test_exp_vector()
{
    experiment::vector<int> v_int;
    v_int.push_back(12);
    v_int.push_back(2023);
    bool val = experiment::find(v_int.begin(), v_int.end(), 13);
    std::cout << v_int.size() << std::endl;
}
void test_exp_string()
{
    using mystr = experiment::string;
    const char *p_short = "a string\0";        // sizeof() return 8
    const char *p_long = "a stringa string\0"; // 16

    mystr str(p_long);
}
void test_c_string()
{
    char ch[16];
    char char_array[16] = "a string";
    char *ptr = ch;
    const char *str = "a string";
    std::cout << sizeof(ptr) << std::endl; // return 8
    std::cout << strlen(ptr) << std::endl; // danger
    strcpy_s(ptr, 16, str);
}
int main()
{
    // test_c_string();
    test_exp_string();
    // test_exp_vector();
    // std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
