
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
    std::string newFileLoc = "CSC450-CT5-reverse.txt";
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
    //Reads the file to myText it gets appeneded to fullText to have a full file
    while(getline(readFile,myText)){
        fullText.append(myText);
        fullText.append("\n");
    }
    readFile.close();
    //Clear the string to be used for reversal
    myText.clear();

    //
    std::cout << fullText << std::endl;
    int length = fullText.size();

    //reversal method
    reverseAll(fullText, length, myText);
    std::cout<<myText;

    //Creating a new file to write to in location newFile
    std::ofstream reverseFile(newFileLoc);
     //Check to see if file did open
    if (reverseFile.is_open()){
        std::cout << "New file is open" << std:: endl;
    } else {
        std::cerr <<"Error: Could not open file" << std:: endl;
    }
    //Writing to new file
    reverseFile << myText;
    reverseFile.close();
    std::cout << "\nProgram ending." << std:: endl;
    return 0;
}