#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

string tolower(string wd) {
	for (size_t i=0; i<wd.size(); ++i) {
		wd.at(i) = tolower(wd.at(i));
	}
	return wd;
}

string getReplace(string wd) {
	return "***";
}

int main() {
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "frozen.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams
	ifstream censorIn(censorWordsFilename);
	ifstream origIn(originalTextFilename);
	ofstream censorOut(censoredTextFilename);

	// make sure all files were opened and give feedback if not
	if (!censorIn.is_open()) {
		cout << "Unable to open: " << censorWordsFilename << endl;
		return 1; // return with error
	}
	if (!origIn.is_open()) { 
		cout << "Unable to open: " << originalTextFilename << endl;
		return 1; // return with error
	}
	if (!censorOut.is_open()) {
		cout << "Unable to open: " << censoredTextFilename << endl;
		return 1; // return with error
	}

	// get list of words to censor from file
	string censorWords;
	string censorWord;
	while (censorIn>>censorWord) { // built in if you got something
		censorWords += (" " + tolower(censorWord));
	}

	// print out list of censored words (for debugging) remove later from final program
	cout << "censorWords: " << censorWords << endl;

	// read original, process and send to output
	// process line by line
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line
	while (!origIn.eof()) {
		string line;
		getline(origIn, line);
		if (origIn.bad()) {
			return 1; // in hw throw an exception
		}
		string oLine = line;
		line = tolower(line);
		istringstream iCensorW(censorWords);
		string censorWord;
		while (iCensorW >> censorWord) { // for each censor word
			size_t position = line.find(censorWord);
			while (position != string::npos) {
				line.replace(position, censorWord.size(), "***");
				oLine.replace(position, censorWord.size(), "***");
				position = line.find(censorWord);
			}
		}
		censorOut << oLine << endl;
	}
}