#include <iostream>
#include <initializer_list>

/*unsigned minpower2(unsigned x) {
	unsigned res = 1;
	while (x > res) {
		res *= 2;
	}
	return res;
}*/

class DynArr {
public: // потом удалить
	unsigned capacity = 0, size = 0;
	int* elem = nullptr;
public:
	DynArr() = default;
	DynArr(unsigned size, int init = 0) : capacity(size), size(size), elem(new int[capacity]) { // изначально capacity(minpower2(size)), как в vector, но далее нужно проверить стратегии поэтому так
		for (unsigned i = 0; i < size; ++i) {
			elem[i] = init;
		}
	}
	DynArr(const std::initializer_list<int>& list): DynArr(list.size()){
		int i = 0;
		for (auto x: list) {
			elem[i] = x;
			++i;
		}
	}
	DynArr(const DynArr& darr): DynArr(darr.size){
		for (unsigned i = 0; i < size; ++i) {
			elem[i] = darr.elem[i];
		}
	}
	friend void swap(DynArr& darr1, DynArr& darr2);
	DynArr& operator=(DynArr darr){
		swap(*this, darr);
		return *this;
	}
	~DynArr(){
		delete[] elem;
	}

	int& operator[](unsigned i){
		return this->elem[i];
	}
	
	DynArr& reserve(unsigned capacity){
		if (this->capacity >= capacity) return *this;
		auto newelem = new int[capacity];
		for (int i = 0; i < this->size; ++i){
			newelem[i] = this->elem[i];
		}
		auto elem = this->elem;
		this->elem = newelem;
		this->capacity = capacity;
		delete[] elem;
		return *this;
	}

	friend DynArr clone(const DynArr& darr);

	// нет assign тк это тоже что и operator=

	DynArr& push_back1(int val){
		if (size == capacity){
			reserve(capacity + 1);
		}
		(*this)[size] = val;
		++size;
		return *this;
	}

	DynArr& push_back2(int val){
		const int CAP_NUMBER = 10;
		if (size == capacity){
			reserve(capacity + CAP_NUMBER);
		}
		(*this)[size] = val;
		++size;
		return *this;
	}

	DynArr& push_back3(int val){
		const int CAP_FACTOR = 2;
		if (size == capacity){
			reserve(capacity * CAP_FACTOR);
		}
		(*this)[size] = val;
		++size;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const DynArr& darr);
};

void swap(DynArr& darr1, DynArr& darr2){
	std::swap(darr1.size, darr2.size);
	std::swap(darr1.capacity, darr2.capacity);
	std::swap(darr1.elem, darr2.elem);
}

DynArr clone(const DynArr& darr){
	DynArr res;
	res.capacity = res.size = darr.size;
	auto elem = new int[darr.size];
	for (int i = 0; i < darr.size; ++i){
		elem[i] = darr.elem[i];
	}
	res.elem = elem;
	return res;
}

std::ostream& operator<<(std::ostream& out, const DynArr& darr) {
	out << "( ";
	for (int i = 0; i < darr.size; ++i) {
		out << darr.elem[i] << ' ';
	}
	out << ")\n";
	return out;
}
