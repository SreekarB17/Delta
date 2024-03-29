/*
MIT License
Copyright (c) 2021 Delta17x
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef DLT_CONTAINERS_INCLUDED
#define DLT_CONTAINERS_INCLUDED
#include "memory.hpp"
#include "exception.hpp"
#include "iterator.hpp"
_DLT_BEGIN
template<class T, class size_type = size_t, class Alloc = allocator<T >>
class array {
	using _Iter_traits = iterator_traits<T>;
public:
	using iterator = ::dlt::iterator<_Iter_traits>;
	using reverse_iterator = ::dlt::reverse_iterator<_Iter_traits>;
	array() : alloc(), ptr(alloc.allocate(1)), _size(1) {}
	array(size_type s) : alloc(), _size(s) {
		ptr = alloc.allocate(s + 2);
	}
	inline iterator begin() noexcept {
		return iterator(&ptr[0]);
	}
	inline iterator end() noexcept {
		return iterator(&ptr[_size]);
	}
	T& operator[] (size_type index) {
		if (index < 0 || index >= _size) {
			throw new out_of_bounds();
		}
		return ptr[index];
	}
	size_type size() {
		return _size;
	}
private:
	Alloc alloc;
	T* ptr;
	size_type _size;
};
_DLT_END
#endif
