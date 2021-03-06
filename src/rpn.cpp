#include<iostream>
#include<stack>
#include<string>

int main()
{
	std::stack<char> pit;
	char* expr = "5*6+7";
	std::string result; // char* result = new char[strlen(expr) + 1];
	for(size_t i = 0; i < strlen(expr); ++i)
	{	
		if(isdigit(expr[i]))
		{
			result.push_back(expr[i]); // result[i] = expr[i];
		}
		else
		{
			while(!pit.empty() && 
			(expr[i] == '+' || expr[i] == '-') && 
			(pit.top() == '*' || pit.top() == '/'))
			{
				result.push_back(pit.top());
				pit.pop();
			}
			pit.push(expr[i]);
		}
	}

	while(!pit.empty())
	{
		result.push_back(pit.top()); // inserts elements in the end
		pit.pop();
	}

	std::cout << result << std::endl;

	std::stack<int> tip;
	
	for(size_t i = 0; i < result.length(); ++i)
	{
		if(isdigit(result[i]))
		{
			tip.push(result[i] - '0');
		}
		else
		{
			int right = tip.top(); // десният аргумент е отгоре в стека
			tip.pop();
			int left = tip.top();
			tip.pop();

			if(result[i] == '+')
				tip.push(left + right);

			else if(result[i] == '-')
				tip.push(left - right);

			else if(result[i] == '*')
				tip.push(left * right);

			else if (result[i] == '/')
				tip.push(left / right);
		}

	}
	std::cout << tip.top() << std::endl;

	return 0;
}