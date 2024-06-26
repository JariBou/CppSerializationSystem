// SerializationTests.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "Serializer.h"
#include "Deserializer.h"

int main()
{
    
    Serialization::Serializer s = Serialization::Serializer("test.dat");

    s.WriteString("Hi, is this working?");
    uint32_t test = 2;
    s.WriteRaw(test);
    s.WriteRaw(20);
    s.WriteRaw(200);

    s.Close();

    Serialization::Deserializer d = Serialization::Deserializer("test.dat");

    std::string deserializedString = "hum...";
    d.ReadString(deserializedString);
    uint32_t t = 0;
    d.ReadRaw<uint32_t>(t);
    int t2 = 0;
    d.ReadRaw<int>(t2);

    std::cout << deserializedString << std::endl;
    std::cout << "t=" << t << std::endl;
    std::cout << "t2=" << t2 << std::endl;

    d.Close();

    
    std::cout << "Hello World!\n";
    return 1;
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
