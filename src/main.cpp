/*
 * main.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const std::string DEFAULT_SOURCE_FILE = "source.txt";
const std::string DEFAULT_DESTINATION_FILE = "dest.txt";
const std::string ASK_FOR_FILE_OR_EXIT_CHAR =
		"Please enter a source file or X to exit";
const std::string ASK_FOR_FILE_TO_STORE_DATA =
		"Please enter a destination file to store data";

const int SUCCESS = 0;
const int USERCHOSETOEXIT = -1;
const int COULDNOTOPENFILE = -2;

//file IO bits
bool read(const std::string filename, std::string &filedata) {
	ifstream myInputfile;
	myInputfile.open(filename.c_str(), ios::in); //could open with  flags myfile.open(MYFILE, ios::in)
												 //note the .c_str() call on MYFILE
	if (!myInputfile.is_open())
		return false;

	//read the data
	std::string line;
	while (!myInputfile.eof()) {				//exits when reach end of file
		getline(myInputfile, line);				//gets a line up to '/n' char
		filedata += line;
	}
	myInputfile.close();
	return true;
}

bool write(const std::string filename, std::string &filedata) {
	ofstream myOutputfile;
	myOutputfile.open(filename.c_str());//could open with  flags myfile.open(MYFILE, ios::out)
										//note the .c_str() call on MYFILE
	if (!myOutputfile.is_open())
		return false;

	myOutputfile << filedata;
	myOutputfile.close();
	return true;
}

//data manipulation routine
void manip(std::string &s) {
	//not really doing anything here
	s = s + "-has been processed";
}

//userIO stuff
void output(const std::string &phrase) {
	cout << phrase << endl;
}
std::string input(const std::string &phrase) {
	output(phrase);
	string input;
	cin >> input;
	return input;
}

void util1() {;};
int main() {
//	1. Open default file or get src filename from user
//	2. load filename
//	3. manip filenames data
//	4. get dest filename to put manipulated data
//	5. save to dest filename
}

