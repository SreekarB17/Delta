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
#ifndef DLT_EXCEPTION_INCLUDED
#define DLT_EXCEPTION_INCLUDED
#include "utility.hpp"
_DLT_BEGIN
class exception {
public:
	exception() noexcept : _info() {}
	exception(const char* inf) noexcept : _info(inf) {}
	exception(const char* inf, int) noexcept : _info(inf) {}
	exception(const exception& other) noexcept : _info(other._info) {}
	virtual ~exception() {}	
	exception& operator= (const exception& other) noexcept { _info = other._info; }
	virtual const char* info() const noexcept { return _info; }
protected:
	const char* _info;
};

class out_of_bounds : public exception {
public:
	out_of_bounds(int hi = 0) : exception("Attempted to access an out-of-bounds index."), index(hi) {}
private:
	int index;
};
_DLT_END
#endif 
