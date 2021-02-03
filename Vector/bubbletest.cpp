#include<iostream>
#include<vector>
using namespace std;

bool bubble(vector<int> &v, int lo, int hi){
	bool sorted = true;
	while(++lo < hi){
		if(v[lo - 1] > v[lo]){
			swap(v[lo - 1], v[lo]);
			sorted =  false;
		}
	}
	return sorted;
}

void bubbleSort(vector<int> &v, int lo, int hi){
	while(!bubble(v, lo, hi--));
}

int main(){
	vector<int> v{1,7,2,83,21,11,22,13,32};

	for(int i : v){
		cout << i << " ";
	}
	cout << endl;

	bubbleSort(v, 0, 9);

	for(int i : v){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
			
