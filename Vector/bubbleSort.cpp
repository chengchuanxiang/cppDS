#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void bubbleSort(vector<T> &V, int lo, int hi);

template<typename T>
bool bubble(vector<T> &V, int lo, int hi);


template<typename T>
void bubbleSort(vector<T> &V, int lo, int hi){
	while(!bubble(V, lo, hi--))
			;
}

template<typename T>
bool bubble(vector<T> &V, int lo, int hi){
	bool sorted = true;
	while(++lo < hi){
		if(V[lo - 1] > V[lo]){
			sorted = false;
		 	swap(V[lo - 1], V[lo]);
		}
	}
	return sorted;
}

void Bubble(vector<int> &V, int lo, int hi){
	for(int i = hi; i > lo; --i)
		for(int j = 1; j < i; ++j){
			if(V[j-1] > V[j]){
				swap(V[j-1], V[j]);
			}
		}
}
	

int main(){
	vector<int> v{1,3,7,2,83,12,89,23,44};
	for(auto i : v){
		cout << i << " ";
	}
	cout<<endl;

	bubbleSort(v, 0, 9);

	for(auto i : v){
		cout << i << " ";
	}
	cout<<endl;

	return 0;
}

	
