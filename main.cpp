
#include <iostream>
#include <fstream>
#include <string>

/*
* Download txt file
* Append it to the file
* Reversal method will reverse all the characters in txt file
* Result will be saved on the same txt file.
*/
void reverseAll(std::string &text, int size, std::string &altString){
    for (int i = 0; i < size; i++) {
        char letter = text.back();
        altString.push_back(letter);
        text.pop_back();
    }
}
int main()
{
    //Open the text file named
    //CSC450_CT5_mod.txt
    std::string fileLocation = "CSC450_CT5_mod5.txt";
    std::ofstream file(fileLocation, std::ios::app);

    //Check to see if file did open
    if (file.is_open()){
        std::cout << "File is open" << std:: endl;
    } else {
        std::cerr <<"Error: Could not open file" << std:: endl;
    }
    //Get user string
    std::string userInput;
    std::cout <<"Input from User: ";
    getline(std::cin,userInput);
    //Write to file
    file << userInput;
    file.close();

    //Read from the text file 
    std::ifstream readFile(fileLocation);

    std::string myText;
    std::string fullText;
    //Reads the file and saves the new line char
    while(getline(readFile,myText)){
        fullText.append(myText);
        fullText.append("\n");
    }
    readFile.close();
    std::cout << fullText << std::endl;
    int length = fullText.size();

    //reversal method
    reverseAll(fullText, length, myText);
    std::cout<<myText;
    std::cout << "Program ending." << std:: endl;
    return 0;
}