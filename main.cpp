
#include <iostream>
#include <fstream>
#include <filesystem>
/*
* Download txt file
* Append it to the file
* Reversal method will reverse all the characters in txt file
* Result will be saved on the same txt file.
*/
int main()
{
    //Open the text file named
    //CSC450_CT5_mod.txt
    std::cout << "Your program is looking in this folder:\n";
    std::cout << std::filesystem::current_path() << std::endl;
    std::cout << "------------------------------------------\n";
    std::ofstream file("CSC450_CT5_mod5.txt", std::ios::app);

    if (file.is_open()){
        std::cout << "File is open" << std:: endl;
        //Write the string to the file
        file << "Welcome to the end of the line.";
    } else {
        std::cerr <<"Error: Could not open file" << std:: endl;
    }
    file.close();
    std::cout << "Program ending." << std:: endl;

    return 0;
}