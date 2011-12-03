#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void quickSort(vector<int> input, int left, int right) {
	int pivotIndex,pivotValue;
	vector<int> high,low;
	if (left < right) {
		pivotIndex = rand()%(right-left+1)+left;
		pivotValue = input[pivotIndex]; //select random pivot
		
		//partition into higher and lower values
		for (int i = left; i <= right; i++) {
			if (input[i] >= pivotValue) high.push_back(input[i]);
			else low.push_back(input[i]);
		}
		
		//rewrite partitioned lists to original vector
		for (int i = right; i >= left; i--) {
			if (high.size() > 0) {
				input[i] = high[high.size()-1];
				high.pop_back();
			}
			else {
				input[i] = low[low.size()-1];
				low.pop_back();
			}
		}
		
		//find new position of pivot
		for (int i = left; i <= right; i++) {
			if (input[i] == pivotValue) pivotIndex = i;
		}
		
		//recursively perform quicksort on smaller portions
		quickSort(input, left, pivotIndex-1);
		quickSort(input, pivotIndex+1, right);
	}
}


vector<int> merge(vector<int>& left, vector<int>& right) {
	vector<int> result;
	//reverse elements since popping from the front
	//isnt supported in vectors. probably should have
	//used a dequeue instead
	reverse(left.begin(), left.end());
	reverse(right.begin(), right.end());
	while (left.size() > 0 || right.size() > 0) {
		if (left.size() > 0 && right.size() > 0) {
			if (left.back() <= right.back()) {
				result.push_back(left.back());
				left.pop_back();
			}
			else {
				result.push_back(right.back());
				right.pop_back();
			}
		}
		else if (left.size() > 0) {
			result.push_back(left.back());
			left.pop_back();
		}
		else if (right.size() > 0) {
			result.push_back(right.back());
			right.pop_back();
		}
	}
	return result;
}

vector<int>  mergeSort(vector<int> input) {
	int middle;
	vector<int> left,right,result;
	if (input.size() <= 1) {
		return input;
	}
	else {
		middle = (input.size()-1)/2;
		for (int i = 0; i < middle; i++) {
			left.push_back(input[i]);
		}
		for (int i = middle; i < input.size(); i++) {
			right.push_back(input[i]);
		}
		left = mergeSort(left);
		right = mergeSort(right);
		result = merge(left,right);
		return result;
	}
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
