// SerializationTests.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <map>
#include "Serializer.h"
#include "Deserializer.h"

int main()
{
    
    Serialization::Serializer s = Serialization::Serializer("test.dat");

    std::map<std::string, uint32_t> testMap {{"Hi", 5}, {"Second, this is going to be fun, wait not long enough, ok lemme break you down even further HOW TF IS THIS STILL WORKING", 10}};
    std::map<uint32_t, uint32_t> testMap2 {{2, 4}, {3, 9}};
    std::vector<uint32_t> testVector{ 1, 2, 3, 4 };

    s.WriteString("Hi, is this working?");
    uint32_t test = 2;
    s.WriteRaw(test);
    s.WriteRaw(20);
    s.WriteMap(testMap);
    s.WriteVector(testVector);

    s.Close();

    Serialization::Deserializer d = Serialization::Deserializer("test.dat");

    std::map<std::string, uint32_t> testReadMap {};
    std::map<uint32_t, uint32_t> testReadMap2 {};
	std::vector<uint32_t> testReadVector{};

    std::string deserializedString = "hum...";
    d.ReadString(deserializedString);
    uint32_t t = 0;
    d.ReadRaw<uint32_t>(t);
    int t2 = 0;
    d.ReadRaw<int>(t2);
    d.ReadMap(testReadMap);
    d.ReadVector(testReadVector);

	d.Close();

    std::cout << deserializedString << std::endl;
    std::cout << "t=" << t << std::endl;
    std::cout << "t2=" << t2 << std::endl;

    for (const auto& [key, value] : testReadMap)
    {
        std::cout << key << " | " << value << std::endl;
    }

	std::cout << "===========" << std::endl;

	for (const auto& value : testReadVector)
	{
		std::cout << value << std::endl;
	}


    
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
