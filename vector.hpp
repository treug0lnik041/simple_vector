#pragma once
#include <memory>
#include <cstring>

namespace skyfall
{
	template<class _Ty>
	class vector
	{
	private:
		_Ty* m_data;
		std::size_t m_size;

	public:
		vector();
		vector(std::size_t size);
		vector(const vector<_Ty>& vec);
		vector(const std::initializer_list<_Ty>& list);

		~vector();

	public:
		inline const _Ty& operator[] (std::size_t index) const;
		inline _Ty& operator[] (std::size_t index);

		inline std::size_t size() const;

	public:
		void resize(std::size_t size);

	public:
		void push_back(const _Ty& element);
		void pop_back();
	};
}

template<class _Ty> inline skyfall::vector<_Ty>::vector()
{
	this->m_data = nullptr;
	this->m_size = 0;
}

template<class _Ty> inline skyfall::vector<_Ty>::vector(std::size_t size)
{
	this->m_data = new _Ty[size];
	this->m_size = size;
}

template<class _Ty> inline skyfall::vector<_Ty>::vector(const vector<_Ty>& vec) : vector(vec.size())
{
	for (std::size_t i = 0; i < vec.size(); i++)
		this->m_data[i] = vec[i];
}

template<class _Ty> inline skyfall::vector<_Ty>::vector(const std::initializer_list<_Ty>& list) : vector()
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
		this->push_back(*iter);
}

template<class _Ty> inline skyfall::vector<_Ty>::~vector()
{
	delete[] this->m_data;
	this->m_size = 0;
}

template<class _Ty> inline const _Ty& skyfall::vector<_Ty>::operator[] (std::size_t index) const
{
	return this->m_data[index];
}

template<class _Ty> inline _Ty& skyfall::vector<_Ty>::operator[] (std::size_t index)
{
	return this->m_data[index];
}

template<class _Ty> inline std::size_t skyfall::vector<_Ty>::size() const
{
	return this->m_size;
}

template<class _Ty> void skyfall::vector<_Ty>::resize(std::size_t size)
{
	_Ty* new_vector = new _Ty[size];

	memset(new_vector, 0, size);

	if (size > this->m_size)
		for (std::size_t i = 0; i < this->m_size; i++)
			new_vector[i] = this->m_data[i];
	else
		for (std::size_t i = 0; i < size; i++)
			new_vector[i] = this->m_data[i];

	delete[] this->m_data;
	this->m_data = new_vector;
	this->m_size = size;
}

template<class _Ty> void skyfall::vector<_Ty>::push_back(const _Ty& element)
{
	this->resize(this->m_size+1);
	this->m_data[this->m_size-1] = element;
}

template<class _Ty> void skyfall::vector<_Ty>::pop_back()
{
	this->resize(this->m_size-1);
}