#include <iostream>
#include <iomanip>

using namespace std;

struct NODE
{
	int info;
	NODE * next;
} * master;

void Create()
{
	master = NULL;
}

void Insert(int x)
{
	NODE * t, * c, * h;
	t = new NODE;
	t->info = x;

	if( master == NULL )
	{
		t->next = NULL;
		master = t;
	}
	else
	{
		c = master;
		while(c != NULL && t->info > c->info)
		{
			h = c;
			c = c->next;
		}
		if(c == master)
		{
			t->next = c;
			master = t;
		}
		else
		{
			h->next = t;
			t->next = c;
		}

	}
}

void Display()
{
	NODE * c;
	c = master;
	while(c != NULL)
	{
		cout << c->info << '\t';
		c =  c->next;
	}
	cout << endl;
}

int main()
{
	Create();
	Insert(5); // 5
	Insert(3); // 3 5 
	Insert(4); // 3 4 5
	Insert(2); // 2 3 4 5
	Insert(1); // 1 2 3 4 5
	Insert(6); // 1 2 3 4 5 6
	Display(); // 1 2 3 4 5 6

	system("pause");
	return 0;
}