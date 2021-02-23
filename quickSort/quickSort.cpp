void quickSort(vector<int> &i_vec, int lo, int hi){  //[lo, hi) low high
	if(hi - lo < 2){
		return;
	}
	int mi = partition(i_vec, lo, hi - 1); //[lo, hi-1]
	quickSort(i_vec, lo, mi);
	quickSort(i_vec, mi + 1, hi);
}

int partition(vector<int> &i_vec, int lo, int hi){  //[lo, hi]
	swap(i_vec[lo], i_vec[lo + rand() % (hi - lo + 1)]);
	int pivot = i_vec[lo];
	while(lo < hi){
		while((lo < hi) && (i_vec[hi] >= pivot)){
			--hi;
		}
		i_vec[lo] = i_vec[hi];
		while((lo < hi) && (i_vec[lo] <= pivot)){
			++lo;
		}
		i_vec[hi] = i_vec[lo];
	}
	i_vec[lo] = pivot;
	return lo;
}
	
	
