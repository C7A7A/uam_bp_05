#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	fstream file;
	string word = "ipsum";
	int line_num = 1;
	file.open("../test.txt", ios::in);
	
	if(file.is_open()) {
		string line;
		while(getline(file, line)) {
			if (line.find(word) != string::npos) {
				cout << line_num << "\n";
			}
			line_num++;
		}
		
		file.close();
	}
	
	return 0;
}
