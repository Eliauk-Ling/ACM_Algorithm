#include <vector>

template <typename T>
void insert_sort(std::vector<T>& elems,bool cmp) {
	if (cmp)insert_sort_increase(std::vector<T>& elems);
	else insert_sort_decrease(std::vector<T>& elems);
}

template <typename T>
void insert_sort_increase(std::vector<T>& elems) {
	for (auto i = 1; i < elems.size(); i++) {
		T key = elems[i];
		auto j = i - 1;
		while (j && elems[j] > key) {
			elems[j + 1] = elems[j];
			j--;
		}
		elems[j + 1] = key;
	}
}

template <typename T>
void insert_sort_decraese(std::vector<T>& elems) {
	for (auto i = 1; i < elems.size(); i++) {
		T key = elems[i];
		auto j = i - 1;
		while (j && elems[j] < key) {
			elems[j + 1] = elems[j];
			j--;
		}
		elems[j + 1] = key;
	}
}