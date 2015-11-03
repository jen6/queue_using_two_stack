#include <iostream>
#include <stack>
#include <string>
#include <exception>

using namespace std;

stack<int> st1, st2;

enum : int { STACK_MIN = 0 ,STACK_MAX = 10};

void push(int val)
{
	if(st1.size() == STACK_MAX)
	{
		throw "stack overflow";
	}
	st1.push(val);
	std::cout << val << " pushed" << std::endl;
}
int pop()
{
	int ret;
	size_t len;
	if(st1.size() == 0)
	{
		throw "stack underflow";
	}
	len = st1.size();
	for(size_t i = 0; i < len; ++i)
	{
		st2.push( st1.top() );
		st1.pop();
	}
	ret = st2.top();
	st2.pop();

	len = st2.size();
	for(size_t i = 0; i < len; ++i)
	{
		st1.push( st2.top() );
		st2.pop();
	}
	return ret;
}

int main()
{
	int val, option;
	try{
	while(true)
	{	
		std::cout << "1.push 2.pop 3.end" << std::endl;
		std::cin >> option;
		switch(option)
		{
			case 1: 
				std::cout << "push : ";
				std::cin >> val;
				push(val);
				break;
			case 2:
				std::cout << "pop : " << pop() << std::endl;
				break;
			case 3:
				return 0;
				break;
			default:
				std::cout << "no options" << std::endl;
		}
	}
	}catch(const char * e) {
		std::cerr << e << std::endl;
	}

}
