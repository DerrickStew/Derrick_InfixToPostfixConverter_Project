// Derrick_InfixToPostfixConverter_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "InfixToPostfixConverter.h"

int main()
{
    InfixToPostfixConverter convert;
    ifstream textFile ("InfixData.txt");
    // check if file is open
    if (!textFile.is_open())
    {
        cout << "Error opening file";
        return 1;
    }

    string infix;
    // convert InfixData.txt infix expressions into postfix expressions
    while (getline(textFile, infix))
    {
        convert.convertToPostfix(infix);
        cout << "Infix expression: " << infix << endl;
        cout << "Postfix expression: " << convert.getPostfix() << "\n\n";
    }
    textFile.close();
    return 0;
}
