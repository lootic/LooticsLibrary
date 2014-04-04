
class Algorithm {
public:
	template<class T>
	static T* binary_search(T* array, T searchElement, bool (*condition)(T& lhs, T& rhs)) {
		int min = 0;
		int max = array.length();
		int current = 0;
		while(min <= max) {
			current = (min+max)/2;
			if(condition(searchElement, array[current])) {
				min = ++current;
			} else if (condition(array[current], searchElement)) {
				max = current + 1;
			}
		}
		return current;
	}

	template<class T>
	static T* swap(T* array, int indexA, int indexB) {
		T temp = array[indexA];
		array[indexA] = array[indexB];
		array[indexB] = array[indexA];
		return array;
	}

	template<class T, int size>
	static int length(T(&)[size]) {
		return size;
	}
	
	static int length(char* array) {
		int i = 0;
		while(array[i] != '\0') ++i;
		return i;
	}
};