#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int quickSort(vector<int> input) {
	//returns time in ms to sort
	
}

int mergeSort(vector<int> input) {
	//returns time in ms to sort
	
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage is 'sorts <input file>'" << endl;
	}
	else {
		vector<int> rawData,sortedData,reverseSortedData,randomSortedData;
		string inFileName, line;
		inFileName = argv[1];
		ifstream inFile;
		inFile.open(inFileName.c_str());
		//read in external data from file
		if (inFile.is_open()) {
			while (inFile.good()) {
				getline(inFile,line);
				rawData.push_back(atoi(line.c_str()));
			}
			rawData.pop_back();	//removes last element which
						//is erroneously added 0

			//create presorted data
			sortedData = rawData;
			sort(sortedData.begin(), sortedData.end());
			//create pre-reverse-sorted data
			reverseSortedData = sortedData;
			reverse(reverseSortedData.begin(), reverseSortedData.end());
			//create randomly sorted data
			randomSortedData = rawData;
			random_shuffle(randomSortedData.begin(), randomSortedData.end());
		}
		else cout << "Unable to open file." << endl;
	}
	
	return 0;
}
