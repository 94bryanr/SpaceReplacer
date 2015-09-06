#include <iostream>

using std::cout;
using std::endl;

void changeSpace(char* string){
    // Find length of new string.
    char* lengthFinder = string;
    int length = 0;
    while(*lengthFinder != '\0'){
        if(*lengthFinder == ' ')
            length += 2;
        length++;
        lengthFinder++;
    }
    
    // Get memory for new string.
    char* newString = new char[length];
    
    // Fill out new string.
    int newLocation = 0;
    char* oldString = string;
    while(*oldString != '\0'){
        if(*oldString == ' '){
            newString[newLocation] = '%';
            newString[newLocation+1] = '2';
            newString[newLocation+2] = '0';
            newLocation += 2;
        }
        else
            newString[newLocation] = *oldString;
        newLocation++;
        oldString++;
    }
    
    // Copy memory to new location
    memcpy(string, newString, length);
    delete(newString);
}

int main(int argc, char* argv[]){
    char testString[18] = {0};
    memcpy(testString, "Are you here?", 17);
    changeSpace(testString);
    cout << testString << endl;
}