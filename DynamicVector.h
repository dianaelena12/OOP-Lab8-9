#pragma once

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& v);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& v);
	T& operator[] (int pos);
	void add(const T& e);
	DynamicVector<T> operator+(const T& object);
	void deleteE(int index);
	int getSize() const;

private:
	void resize(int factor = 2);

};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity ;
	this->elems = new T[capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	delete[] this->elems;
	this->capacity = v.capacity;
	
	this->elems = new T[v.capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
	
	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(const T& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
DynamicVector<T> DynamicVector<T> :: operator+( const T& object)
{
	this->add(object);
	return *this;
}

template <typename T>
void DynamicVector<T>::deleteE(int index)
{
	if (this->size == this->capacity)
		this->resize();
	for (int i = index; i < this->size - 1; i++)
	{
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}

template <typename T>
void DynamicVector<T>::resize(int factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}
template <typename T>
DynamicVector<T>& operator+(const T& object, DynamicVector<T>& v)
{
	v.add(object);
	return v;
}