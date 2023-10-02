/* 
Zachary Carr
F to C
CS-210


*/

#include <iostream>
#include <string>
#include <fstream> // operator to edit and read the files.
using namespace std;





int main() {
    //Open our file we are wanting to read and edit.
    ifstream inputFile("FahrenheitTemperature.txt");
    // this will throw an error if there is an issue with the file
    if (!inputFile) {
        cerr << "Error opening the file, try again." << endl;
        return 1; // will exit and give error code
    }




    // assuming the file is good and no problems, this will open the file
    ofstream outputFile("CelsiusTemperature.txt");
    // if there is an issue opening the file it will error here
    if (!outputFile) {
        cerr << "Error opening the file, try again." << endl;
        return 1; // will exit and give error code
    }




    // Here we read data from the file and write to the output file
    string cityName;
    int fahrenheitTemp;
     // Math things loop 
    while (inputFile >> cityName >> fahrenheitTemp) {
        // convert F to C formula
        double celsiusTemp = (fahrenheitTemp - 32) * 5.0 / 9.0;

        // Write to the output file
        outputFile << cityName << " " << celsiusTemp << endl;
    }




    // closes both of the files
    inputFile.close();
    outputFile.close();
    //  our output confirming it worked
    cout << "Conversion F to C completed successfully." << endl;




    return 0; // Exit successfully
}