#pragma once

template <typename T1, typename T2>
struct pair{
	T1 key = 0;
	T2 value = 0;
	int ind = 0;
};

template <typename T1, typename T2>
class Map {
	pair<T1,T2> array[100];
	int size = 100;
	int index = 0;
public:
	Map() {
		//array = new pair<T1, T2> [size];
	};
	/*~Map()
	{
		delete[] array;
	}*/
	T2& operator[](T1 key)
	{
		for(int i = 0; i < index; ++i)
			if (array[i].key == key)
				return array[i].value;

		array[index].key = key;
		if (index > 0)
			array[index].ind = array[index - 1].ind + 1;
		else
			array[index].ind = 0;
		return array[index++].value;
	}
	void Set(T1 key, T2 value)
	{
		for (int i = 0; i < index; ++i)
			if (array[i].key == key)
				array[i].value = value;
	}
	bool Get(const T1& key, T2& value)
	{
		for (int i = 0; i < index; ++i)
			if (array[i].key == key)
			{
				array[i].value = value;
				return true;
			}
		return false;
	}
	bool Find(const T1& key, T2& value)
	{
		for (int i = 0; i < index; ++i)
			if (array[i].key == key and array[i].value == value)
				return true;
		return false;
	}
	int Count()
	{
		return index;
	}
	void Clear()
	{
		for (int i = 0; i < index; ++i)
		{
			array[i].key = NULL;
			array[i].value = NULL;
		}
		index = 0;
	}
	void print()
	{
		for(int i = 0; i < index; ++i)
			printf("Index:%d, Key=%d, Value=%s\n", i, array[i].key, array[i].value);
	}
	bool Delete(const T1& key)
	{
		for(int i = 0; i < index; ++i)
			if (array[i].key == key)
			{
				for (int j = i; j < index - 2; ++j)
				{
					array[j].key = array[j + 1].key;
					array[j].value = array[j + 1].value;
				}
				array[index-1].key = NULL;
				array[index-1].value = NULL;
				index--;
			}
	}
	bool Includes(const Map<T1, T2>& map)
	{
		int size2 = map.Count();
		if (size > size2)
			return false;
		for (int i = 0; i < size; ++i)
		{
			bool found = false;
				for(int j = 0 ; j < size2; ++j)
					if(map.Find(array[i].key, array[i].value)) found = true;
			if(!found)
				return false;
		}
		return true;
	}
	pair<T1,T2>* begin()
	{
		return &array[0];
	}
	pair<T1, T2>* end()
	{
		return &array[index];
	}
};