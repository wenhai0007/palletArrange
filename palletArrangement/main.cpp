#include<iostream>

using namespace std;

struct pallet
{
	int width;
	int weight; 
	int id;

	void getData()
	{
		cout << "enter id " << endl;
		cin >> id;
		cout << "enter width " << endl;
		cin >> width;
		cout << "enter weight " << endl;
		cin >> weight;
		cout << id << "  " << width << "  " << weight << endl;
	}
};

void outPut(pallet* a,int n);

int main()
{
	while(1){
		int n;
		cout << endl;
		cout << "enter number of items" << endl;
		cin >> n;

		pallet *a;
		a = new pallet[3];
		pallet aHoulder;

		//data input
		for (int i = 0; i < n; i++)
		{
			a[i].getData();
		}

		//iems arrangement
		for (int j = 0; j < n - 2; j++)
		{
			for (int i = 0; i < n-1; i++)
			{
				if (a[i].width < a[i + 1].width)
				{
					aHoulder = a[i + 1];
					a[i + 1] = a[i];
					a[i] = aHoulder;
				}
			}
		}
		
		for (int j = 0; j < n - 2; j++)
		{
			for (int i = 0; i < n-1; i++) {
				if (a[i].width == a[i + 1].width)
				{
					if (a[i].weight < a[i + 1].weight)
					{
						aHoulder = a[i + 1];
						a[i + 1] = a[i];
						a[i] = aHoulder;
					}
				}
			}
		}
		
		for (int j = 0; j < n - 2; j++)
		{
			for (int i = 0; i < n-1; i++) {
				if (a[i].width == a[i + 1].width&&a[i].weight == a[i + 1].weight)
				{
					if (a[i].id > a[i + 1].id)
					{
						aHoulder = a[i + 1];
						a[i + 1] = a[i];
						a[i] = aHoulder;
					}
				}
			}
		}
		///data output
		outPut(a, n);	
	}
}

void outPut(pallet* a, int n)
{
	static int index = 0;
	static int indexa, indexb;
	static int totalWidth = a[0].width;
	static int totalWeight = a[0].weight;
	static int widthInC;
	static int weightInC;
	static int weightInB;
	static int widthInB;

	if (index > n - 1 || widthInC > 1100 || weightInC > 1000)
	{
		if (widthInC > 1100 || weightInC > 1000)
		{
			cout << endl;
			cout<< "Warehouse is full." << endl;
		}
		else
		{
			cout << endl;
			cout << "all items are stored" << endl;
		}
		return;
	}
	else
	{
		index++;
		cout << a[index].id<<", ";
		outPut(a, n);
		if (index < n - 1)
		{
			totalWeight += a[index + 1].weight;
			totalWidth += a[index + 1].width;
		}
	}
	
}


/*if (totalWeight <= 3000 && totalWidth <= 3300 && n>0)
	{
		if (totalWeight <= 1000 && totalWidth <= 1100)
		{			
			if (index==0)
			{
				cout << "A: ";
			}
			cout << a[index].id<<", ";
			if (index < myN-1)
			{
				totalWidth += a[index + 1].width;
				totalWeight += a[index + 1].weight;
				index++;
				outPut(a, n - 1);
			}
			else
			{
				cout << "all items loaded before A is full." << endl;
				return;
			}
			indexa = index;
		}

		else
		{		
			weightInB = a[index].weight;
			widthInB = a[index].width;
			if (totalWeight <= 2000 && totalWidth <= 2200 && weightInB <= 1000 && widthInB <= 1100)
			{
				    
				if (index == indexa)
				{
					cout << endl;
					cout << "B: ";
				}
				cout << a[index].id << ", ";
				if (index < myN-1)
				{
					totalWidth += a[index + 1].width;
					totalWeight += a[index + 1].weight;
					weightInB += a[index + 1].weight;
					widthInB += a[index + 1].width;
					index++;
					outPut(a, n - 1);
				}
				else
				{
					cout << "all items loaded before B is full." << endl;
					return;
				}
				
				indexb = index;
			}
			else
			{
				if (index == indexb)
				{
					cout << endl;
					cout << "C: ";
					widthInC = a[index].width;
					weightInC = a[index].weight;
				}
				if (weightInC <= 1000 && widthInC <= 1100)
				{
					cout << a[index].id << ", ";
					if (index < myN-1)
					{
						totalWidth += a[index + 1].width;
						totalWeight += a[index + 1].weight;
						index++;
						widthInC += a[index + 1].width;
						weightInC += a[index + 1].weight;
						outPut(a, n - 1);
					}
					else
					{
						cout << "all items loaded before C is full." << endl;
						return;
					}
					
				}
				else
				{
					cout << "C warehouse is full!" << endl;
					return ;
				}
			}

		}
	}
	
	else
	{
		if (totalWeight > 3000 || totalWeight > 3300)
		{
			cout << endl;
			cout << "cannot load anymore!" << endl;;
		}
		else
		{
			cout << "all items have benn loaded." << endl;
		}
		return;
	}*/


