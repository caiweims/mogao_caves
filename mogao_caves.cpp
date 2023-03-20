// mogao_caves.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "mogao_vector.h"//final implement

#include "exp_vector.h"
#include "exp_algorithm.h"
using namespace Mogao;
//using namespace experiment;
void test_exp_vector()
{
    experiment::vector<int> v_int;
    v_int.push_back(12);
    v_int.push_back(2023);
    bool val = experiment::find(v_int.begin(),v_int.end(),13);
    std::cout << v_int.size() << std::endl;
}
int main()
{
    test_exp_vector();
    //std::cout << "Hello World!\n";
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
