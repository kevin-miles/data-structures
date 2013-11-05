#include <iostream>
#include <iomanip>

using namespace std;



		struct NODE
		{
			int info;
			NODE *next;
			NODE *prev;
		} * master, * v;

		void Create(){ master = NULL; }

		void Push(int x)
		{
			NODE *r;
			r = new NODE;
			r -> info = x;

			if(master == NULL)
			{
				r->next = NULL;
				r->prev = NULL;
				master = r;
			}
			else
			{
				v = master;
				while(v->next != NULL)
				{
					v=v->next;
				}
				v->next = r;
				r->next = NULL;
				r->prev = v;
			}

		}
		

		int Pop()
		{
			if(master != NULL)
			{
				NODE *h;
				int x;
				v = master;	
				h = v->prev;
				h->next = NULL;
				x = v->info;
				delete v;
				master = h;
				return x;
			}
		}

		bool Empty()
		{
			if(master == NULL) { return true; }
			else { return false; }
		}

		void Display()
		{
			v = master;
			while(v != NULL)
			{
				cout << v->info << '\t';
				v = v->next;
			}
			cout << endl;
		}


int main()
{
	Create();
	Push(1);
	Push(3);
	Push(2);
	Push(5);
	Display(); // 1 3 2 5

	system("pause");
	return 0;
}
