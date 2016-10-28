#include <iostream>
#include "figure.h"
#include "stack.h"
#include "square.h"

using namespace std;

int main(void)
{
	Stack *stack = new Stack;
	cout << "-------------------------------------------\n";
	cout << "Commands:\n";
	cout << "a <value> - push to stack\n";
	cout << "d - pop from stack and print popped item\n";
	cout << "p - print stack\n";
	cout << "q - exit\n";
	cout << "-------------------------------------------\n";
	//int cnt = 0;
	while (true) {
		//cout << "%d\n", cnt;
		//cnt++;
		char cmd;
		Figure value = GetEmptyFigure();
		bool is_finished = false;
		scanf("%c", &cmd);
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 's':
				FSquare s_value;
				//value = (Item) FSquare(std::cin);
				cin >> s_value;
				stack->Push(s_value);
				break;
			case 't':
				//value = (Item) FSquare(std::cin);
				Trapeze t_value;
				cin >> t_value;
				stack->Push(t_value);
				break;
			case 'r':
				//value = (Item) FSquare(std::cin);
				Rectangle r_value;
				cin >> r_value;
				stack->Push(r_value);
				break;
			case 'd':
				value = stack->Pop();
				if (!value.IsEmpty)
					cout << value << endl;
				break;
			case 'p':
				//stack->Print();
				cout << *stack << endl;
				break;
			case '\n':
				break;
			default:
				cout << "Invalid command " << cmd << "\n";
				break;
		}
		if (is_finished) break;
	}
	cout << "Goodbye!\n";

	delete stack;

	return 0;
}
