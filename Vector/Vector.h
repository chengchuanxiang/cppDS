typedef int Rank;
#define DEFAULT_CAPACITY 3

template<typename T>
class Vector{
protected:
	RANK _size; int _CAPACITY; T* _elem;//规模，容量，数据区

	void copyFrom(T const *A, Rank lo, Rank hi);//ok
	void expand();//ok
	void shrink();//ok
	bool bubble(Rank lo, Rank hi);//ok
	void bubbleSort(Rank lo, Rank hi);//ok
	Rank max(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mi, Rank hi);//ok
	void mergeSort(Rank lo, Rank hi);//ok
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
	
public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0);//ok
	Vector(T const* A, Rank n);//ok
	Vector(T const* A, Rank lo, Rank hi);//ok
	Vector(Vector<T> const& V);//ok
	Vector(Vector<T> const& V, Rank lo, Rank hi);//ok

	~Vector() { delete [] _elem;}//ok
//只读访问接口
	Rank size() const{ return _size;}//ok
	bool empty() const{ return !_size;}//ok
	int disordered() const;//ok
	Rank find(T const& e) const{ return find(e, 0, _size);}//ok
	Rank find(T const& e, Rank lo, Rank hi) const;//ok
	Rank search(T const& e) const;
	Rank search(T const& e, Rank lo, Rank hi) const;
//可写访问借口
	T& operator[](Rank e) const;//ok
	vector<T>& operator=(Vector<T> const&);//ok
	T remove(Rank r);//ok
	int remove(Rank lo, Rank hi);//ok
	Rank insert(Rank r, T const& e);//ok
	Rank insert(T const& e){ return insert(_size, e);}//ok
	void sort(Rank lo, Rank hi);//ok
	void sort(){ sort(0, _size);}//ok
	void unsort(Rank lo, Rank hi);
	void unsort(){ unsort(0, _size);}//ok
	int deduplicate();//ok
	int uniquify();//ok
//遍历
	void traverse (void (*) (T&));//ok

	template<typename VST>
	void traverse(VST&);//ok

};

template<typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi){
	_capacity = 2 * (hi - lo);
	_elem = new T[_capacity];
	_size = 0;
	while(lo < hi){
		_elem[_size++] = A[lo++];
	}
}
template<typename T>
Vector<T>::Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){//s <= c
	_capacity = c;
	_size = s;
	_elem = new T[c];
	for(int i = 0; i < s; ++i){
		_elem[i] = v;
	}
}

template<typename T>
Vector<T>::Vector(T const* A, Rank n){
	copyFrom(A, 0, n);
}

template<typename T>
Vector<T>::Vector(T const* A, Rank lo, Rank hi){
	copyFrom(A, lo, hi);
}

template<typename T>
Vector<T>::Vector(Vector<T> const& V){
	copyFrom(V.elem, 0, V.size);
}

template<typename T>
Vector<T>::Vector(Vector<T> const& V, Rank lo, Rank hi){
	copyFrom(V.elem, lo, hi);
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V){//异常安全的写法
	if(this != &V){
		Vector<T> temp(V);

		T* tp = temp._elem;
		temp._elem = _elem;
		_elem = tp;
	}
	return *this;
}

template<typename T>
void Vector<T>::expand(){
	if(_size < _capacity){
		return;
	}

	if(_capacity < DEFAULT_CAPCACITY){
		_capacity = DEFAULT_CAPACITY;
	}
	
	T *oldELem = _elem;
	_capacity <<= 1;
	_elem = new T[_capacity];
	for(int i = 0; i < _size; ++i){
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
void Vector<T>::shrink(){
	if((_capacity >> 1) < DEFAULT_CAPACITY){
		return;
	}
	if(_size > (_capacity >> 2)){
		return ;
	}
	T *oldElem = _elem;
	_capacity >>= 1;
	_elem = new T[_capacity];
	for(int i = 0; i < _size; ++i){
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
T& Vector<T>::operator[](Rank r) const{//0 <= r < _size
	return _elem[r];
}

template<typename T>
void permute(Vector<T> &V){
	for(int i = V.size(); i > 0; --i){
		swap(V[i-1],V[rand()%i]);
	}
}

template<typename T>
void Vector<T>::unsort(Rank lo, Rank hi){
	T *V = _elem + lo;
	for(int i = hi - lo; i > 0; --i){
		swap(V[i - 1], V[rand() % i]);
	}
}

template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const{
	while((lo < hi--) && (_elem[hi] != e))
		;
	return hi;
}

template<typename T>
Rank Vector<T>::insert(Rank r, T const& e){
	expand();
	for(int i = _size; i > r; --i){
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size++;
	return r;
}

template<typename T>
Rank Vector<T>::remove(Rank lo, Rank hi){
	if(lo == hi){
		return 0;
	}
	while(hi < _size){
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return hi - lo;
}

template<typename T>
Rank Vector<T>::remove(Rank r){
	T e = _elem[r];
	remove(r, r + 1);
	return 0;
}

template<typename T>
int Vector<T>::deduplicate(){
	int oldSize = _size;
	Rank i = 1;
	while(i < _size){
		(find(_elem[i], 0, i) < 0)? i++ : remove(i);
	}
	return oldSize - _size;
}

template<typename T>
void Vector<T>::traverse(void (*visit) (T&)){
	for(int i = 0; i < _size; i++){
		visit(_elem[i]);
	}
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST& visit){
	for(int i = 0; i < _size; i++){
		visit(_elem[i]);
	}
}

template<typename T>
int Vector<T>::disordered() const{
	int n = 0;
	for(int i = 1; i < _size; ++i){
		if(_elem[i - 1] == _elem[i]){
		   ++n;
		}
	}
	return n;
}

template<typename T>
int Vetcor<T>::uniquify(){
	Rank i = 0, j = 0;
	while(++j < _size){
		if(_elem[i] != _elem[j]){
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	shrink();
	return j - i;
}

template<typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi)const{
	return (rand()%2)? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template<typename T>
void Vector<T>::sort(Rank lo, Rank hi){
	switch(rand() % 5){
		case 1 : bubbleSort(lo, hi); break;
		case 2 : selectionSort(lo, hi); break;
		case 3 : mergeSort(lo, hi); break;
		case 4 : heapSort(lo, hi); break;
		default : quickSort(lo, hi); break;
	}
}

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi){
	bool sorted = true;
	while(++lo < hi){
		if(_elem[lo - 1] > _elem[lo]){
			swap(_elem[lo - 1], _elem[lo]);
			sorted = false;
		}
	}
	return sorted;
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
	while(!bubble(lo, hi--));
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi){
	if(hi - lo < 2) return;
	Rank mi = lo + (hi - lo) / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){
	T *A = _elem + lo;
	int sizeb = (int)(mi - lo);
	T *B = new T[sizeb];
	int sizec = (int)(hi - mi);
	T *C = new T[sizec];
	for(int i = 0; i < sizeb; ++i){
		B[i] = A[i];
	}
	for(int j = 0; j < sizec; ++j){
		C[j] = _elem[mi + j];
	}

	int i = 0, j = 0, k = 0;
	while(i < sizeb && j < sizec){
		if(B[i] < C[j]){
			A[k++] = B[i++];
		}
		else{
			A[k++] = C[j++];
		}
	}

	while(i < sizeb){
		A[k++] = B[i++];
	}
	while(j < sizec){
		A[k++] = C[j++];
	}
}


