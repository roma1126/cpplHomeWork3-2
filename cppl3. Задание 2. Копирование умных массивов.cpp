#include <iostream>
#include <exception>
#include <string>

class smart_array {
private:
	int A;
	int* arr;
	int curent_index;
public:
	smart_array(int size) 
	{
		this->A = size;
		this->arr = new int[A] {};
		this->curent_index = 0;
	}

	smart_array(const smart_array& other) 
	{
		this->A = other.get_arr_size();
		this->curent_index = other.get_curent_index();
		this->arr = new int[A] {};
		for (int i = 0; i < A; i++) {
			this->arr[i] = other.get_element(i);
		}
	}

	void add_element(int element) 
	{
		if (this->curent_index > (A - 1)) 
		{
			throw std::runtime_error("Максимальное значение");
		}

		arr[this->curent_index] = element;
		this->curent_index++;
	}

	int get_element(int index) const 
	{
		if ((index < 0) || (index > curent_index)) 
		{
			std::string buf = std::to_string(index);
			throw std::runtime_error("index " + buf + " out of range");
		}

		return arr[index];
	}

	int get_curent_index() const 
	{
		return this->curent_index;
	}


	int get_arr_size() const
	{
		return A;
	}
	void arr_copy(const smart_array& source_arr) 
	{ 
		this->A = source_arr.get_arr_size();
		this->curent_index = source_arr.get_curent_index();
		delete[] this->arr;
		this->arr = new int[A] {};

		for (int i = 0; i < A; i++)
		{
			this->arr[i] = source_arr.get_element(i);
		}
	}

	~smart_array() 
	{
		delete[] this->arr;
	}

	smart_array& operator=(const smart_array& copyFrom) 
	{
		if (this == &copyFrom) 
		{
			return *this;
		}

		smart_array::arr_copy(copyFrom);

		return *this;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	
	try {
		smart_array arr(5);
		smart_array arr2 = arr;
		arr = arr;
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		std::cout << arr.get_element(1) << std::endl;
	}

	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}