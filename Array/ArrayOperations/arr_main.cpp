#include <iostream>

int ArrayLength = 10;

//Add Methods / Operations
void addToBeginning(int array[], int *_emptyIndexNo, int _value) { //ba?a ekle
	if(ArrayLength != *_emptyIndexNo) {
		int i = *_emptyIndexNo;
		for(i; i > 0; i--) {
			array[i] = array[i-1];
		}
		array[0] = _value;
		(*_emptyIndexNo)++;
	} else {
		std::cout << "There is no free space in the array." << std::endl;
	}
}

void addToEnd(int array[], int *_emptyIndexNo, int _value) { //sona ekle
	if(ArrayLength != *_emptyIndexNo) {
		array[*_emptyIndexNo] = _value;
		(*_emptyIndexNo)++;
	} else {
		std::cout << "There is no free space in the array." << std::endl;
	}
}

//List Methods / Operations
bool list(int array[], int _emptyIndexNo) {
	if(_emptyIndexNo != 0) {
		std::cout << "=Array / List  Items=" << std::endl;
		int i = 0;
		for(i; i < _emptyIndexNo; i++) {
			std::cout << i+1 << ". Item: " << array[i] << std::endl;
		}
		return true;
	}
	return false;
}

bool listOneIncrement(int array[], int _emptyIndexNo) {
	if(_emptyIndexNo != 0) {
		std::cout << "=Array / List  Items - One Increment=" << std::endl;
		int i = 0, j = 0;
		for(i; i < _emptyIndexNo; i++) {
			if(j % 2 == 0) {
				std::cout << i+1 << ". Item: " << array[i] << std::endl;
			}
			j++;
		}
		return true;
	}
	return false;
}

//Update Methods / Operations
bool updateAll(int array[], int _emptyIndexNo, int _newData) {
	if(_emptyIndexNo != 0){
		int i = 0;
		for(i; i < _emptyIndexNo; i++) {
			array[i] = _newData;
		}
		return true;
	}
	return false;
}

void updateFirstItem(int array[], int _newData) {
	array[0] = _newData;
}

void updateIndexAt(int array[], int index, int _newData){
	if(index <= ArrayLength){
		array[index] = _newData;
	}
}

bool updateContentAt(int array[], int _emptyIndexNo, int _oldData, int _newData, bool isAll) {
	if(_emptyIndexNo != 0){
		int i = 0;
		for(i; i < _emptyIndexNo; i++){
			if(array[i] == _oldData) {
				array[i] = _newData;
				if(!isAll) {
					break;
				}
			}
		}
		return true;
	}
	return false;
}

//Delete Methods / Operations
void deleteFirstItem(int array[], int *_emptyIndexNo){
	if(_emptyIndexNo != 0){
		int i = 0;
		for(i; i < *_emptyIndexNo; i++) {
			array[i] = array[i+1];
		}
		(*_emptyIndexNo)--;
	}
}

void deleteAll(int array[], int *_emptyIndexNo) {
	int i = 0;
	for(i; i < *_emptyIndexNo; i++) {
		array[i] = 0;
	}
	*_emptyIndexNo = 0;
}

bool deleteContentAt(int array[], int *_emptyIndexNo, int _data, bool isAll) {
	if(_emptyIndexNo != 0){
		int i = 0;
		for(i; i < *_emptyIndexNo; i++){
			if(array[i] == _data) {
				int j = i;
				for(j; j < *_emptyIndexNo; j++) {
					array[j] = array[j+1];
				}
				(*_emptyIndexNo)--;
				if(!isAll) {
					break;
				}
			}
		}
		return true;
	}
	return false;
}

bool deleteIndexAt(int array[], int *_emptyIndexNo, int _index) {
	if(_index <= ArrayLength){
		int j = _index;
		for(j; j < *_emptyIndexNo; j++) {
			array[j] = array[j+1];
		}
		(*_emptyIndexNo)--;
		return true;
	}
	return false;
}

//Find Methods / Operations
bool findNode(int array[], int *_emptyIndexNo, int _soughtData) {
	if(*_emptyIndexNo <= ArrayLength) {
		int i = 0;
		for(i; i < *_emptyIndexNo; i++) {
			if(array[i] == _soughtData) {
				std::cout << "The searched value is in the list. Index number: " << i << std::endl;
				return true;
			}
		}
		return false;
	}
	return false;
}

int minItem(int array[], int *_emptyIndexNo) {
	if(_emptyIndexNo != 0) {
		int i = 0, min = array[0];
		for(i; i < *_emptyIndexNo; i++) {
			if(array[i] < min){
				min = array[i];
			} 
		}
		return min;
	}
	return NULL;
}

int maxItem(int array[], int *_emptyIndexNo) {
	if(_emptyIndexNo != 0) {
		int i = 0, max = array[0];
		for(i; i < *_emptyIndexNo; i++) {
			if(array[i] > max){
				max = array[i];
			} 
		}
		return max;
	}
	return NULL;
}

int main(int argc, char** argv) {
	std::cout << "Please enter the string capacity: ";
	std::cin >> ArrayLength;
	int array[ArrayLength];
	int arrEmptyIndex = 0;
	addToBeginning(array, &arrEmptyIndex, 6);
	addToBeginning(array, &arrEmptyIndex, 9);
	addToBeginning(array, &arrEmptyIndex, 5);
	addToEnd(array, &arrEmptyIndex, 9);
	list(array, arrEmptyIndex);
	int b = maxItem(array,&arrEmptyIndex);
	std::cout << b << std::endl;
	list(array,arrEmptyIndex);
	return 0;
}
