/* I learned a lot more than I expected in this project. One of the first problems I ran into was getting my insert to update the pointers properly. Luckily when you put 
* it in a drawing, the circular buffer makes a lot more sense. Shrink was also another one, I had to think about references much more and use some cout statements
* to see why that function was struggling. Overall, I learned a lot about circular buffers and just exactly what they are. When coding one, it makes a lot more sense than reading about 
* them online.
* Garrett Cook, CS 3370
*/


#include "CircBuf.h"
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <stdexcept>
CircBuf::CircBuf(size_t reserve)
{
	_size = 0;

	_capacity = reserve == 0 ? 0 :((reserve / CHUNK) + 1)*CHUNK;
	_data = new char[_capacity];
}

CircBuf::~CircBuf()
{
	delete[] _data;
}

size_t CircBuf::size()
{

	return _size;
}

size_t CircBuf::capacity()
{
	return _capacity;
}

bool CircBuf::iswrapped()
{
	return head > tail || ( head == tail && isFull());
}

bool CircBuf::isFull()
{
	return _size == _capacity;

}
void CircBuf::insert(char s)
{
	if (isFull()) {

		size_t new_n = CHUNK + _capacity;
		char* new_a = new char[new_n];
		if (iswrapped()) {
			memcpy(new_a, &_data[head], _capacity - head); // Only works for char due to memory size. Int would need to be multiplied size.
			memcpy(new_a + _capacity - head, _data, tail);

		}
		else {
			memcpy(new_a, _data, _capacity);
		}
		delete _data;
		_data = new_a;
		tail = _capacity;
		head = 0;
		_capacity = new_n;

		
	}
	
	if (tail == _capacity)
	{
		tail = 0;
	}
	_data[tail++] = s;
	_size += 1;

}

void CircBuf::insert(const char* ch, size_t sz)
{
	for (size_t i = 0; i < sz; i++)
	{
		insert(ch[i]);
	}
}

void CircBuf::insert(const string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		insert(str[i]);
	}
}

char CircBuf::get()
{
	char element;
	element = _data[head];
	if (head == tail && !isFull())
	{
		return '\0';

	}
	if (head == _capacity - 1)
	{
		head = 0;
	}
	else {
		head = (head + 1);
	}
	_size -= 1;
	return (element);
}

string CircBuf::get(size_t t)
{
	string y;
	for (size_t i = 0; i < t; i++)
	{
		char c = get();
		if (c == '\0') {
			break;
		}
		y += c;
	}
	return y;
}

string CircBuf::flush()
{
	//Returns everything in string format, and reduces data to 0.
	
	string flush1;
	for (size_t i = 0; i < _size; i++)
	{
		flush1 += _data[i];
	}
	head = 0;
	tail = 0; 
	_capacity = 0;
	_size = 0;
	return flush1;
}

string CircBuf::examine()
{
	string let = "[";
		for (size_t i = 0; i < _capacity; i++)
		{
			if (!isFull() && ((!iswrapped() && (i >= tail || i < head)) || (iswrapped() && (tail <= i && i < head)))) {
				let += '-';
				continue;
			}
			let += _data[i];
		}
		return let + ']';
}

void CircBuf::shrink()
{	//Shrinks the buffer to remove unwanted space.
	size_t new_n = _size == 0 ? 0 : ((_size / CHUNK) + 1) * CHUNK;
	char* new_a = new char[new_n];
	//If the size is 0, we check as we don't need to remove anything due to this.
	if (_size == 0) {
		_data = new_a;
		tail = _size;
		head = 0;
		_capacity = new_n;
		return;
	}
	if (iswrapped()) {
		memcpy(new_a, &_data[head], _capacity - head); // Only works for char due to memory size. Int would need to be multiplied size.
		memcpy(new_a + _capacity - head, _data, tail);

	}
	else {
		memcpy(new_a, &_data[head], _capacity);
	}
	delete _data;
	_data = new_a;
	tail = _size;
	head = 0;
	_capacity = new_n;
}
