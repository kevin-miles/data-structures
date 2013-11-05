#include <iostream>
#include <iomanip>

using namespace std;

	struct NODE
	{
		int info;
		NODE* next;
	} * first, * last;

	void Create()
	{
		first = NULL;
		last = NULL;
	}

	void Push(int x)
	{
		NODE *p;
		p = new NODE;
		p->info = x;
		if(first == NULL)
		{
			first = p;
			last = p;
		}
		else
		{
			last->next = p;
			last = p;
			p->next = first;
		}
	
	}

	void Display()
	{
		NODE* p;
		p = first;
		do
		{
			cout << p->info << '\t';
			p = p->next;
		}
		while(p != first);
		cout << endl;
	}



int main()
{
	Create();
	Push(54);
	Push(23);
	Push(8);
	Display();// 54      23      8

	cout << "Proof that its circular: " << endl;
	int counter=0;
	NODE* current = first;
	while(counter < 3)
	{
		if(current == last){ counter++; }
		cout << current->info << '\t';
		current = current->next;
		
	}
	cout << endl;

	system("pause");
	return 0;
}
