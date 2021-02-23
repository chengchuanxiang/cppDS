
int* buildNext(const string &P){
	int n = P.size(), j = 0;
	int *N = new int [n];
	int t = N[0] = -1;
	while(j < n - 1){
		if(t < 0 || P[j] == P[t]){
			++t; ++j;
			N[j] = t;
		} else {
			t = N[t];
		}
	}
	return N;
}


int kmp(const string &T, const string &P){
	int m = T.size(), i = 0;
	int n = P.size(), j = 0;
	int *next = buildNext(P);
	while(j < n && i < m){
		if(j < 0 || P[j] == T[i]){
			++i; ++j;
		} else {
			j = next[j];
		}
	}
	delete [] next;
	return i - j;
}
