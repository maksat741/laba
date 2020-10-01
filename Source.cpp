#include <iostream>

using namespace std;

void show(int *mas, int n);
void sort(int *mas,int n);
void combinate(int *mas1, int n1, int *mas2, int n2, int *&mas3, int &n3);
void intersection(int *mas1, int n1, int *mas2, int n2, int *&mas4, int &n4);

int main()
{
	int *mas1, *mas2, *mas3, *mas4;
	int n1 = 0, n2 = 0, n3, n4;

	cout << "Number of elements for 1 massive = ";
	cin >> n1;

	if (n1 > 0)
	{
		mas1 = new int[n1];
		cout << "Input elements of 1 massive: " << endl;
		for (int i = 0; i < n1; i++)
		{
			cin >> mas1[i];
		}
	}
	else return 1;

	cout << "Number of elements for 2 massive = ";
	cin >> n2;

	if (n2 > 0)
	{
		mas2 = new int[n2];
		cout << "Input elements of 2 massive: " << endl;
		for (int i = 0; i < n2; i++)
		{
			cin >> mas2[i];
		}
	}
	else return 1;

	sort(mas1, n1);
	sort(mas2, n2);
	combinate(mas1, n1, mas2, n2, mas3, n3);
	intersection(mas1, n1, mas2, n2, mas4, n4);

	delete mas1;
	delete mas2;
	delete mas3;
	delete mas4;

	system("pause");
	return 0;
}
void show(int *mas, int n)
{
	for (int i = 0; i < n; i++)
		cout << mas[i] << "  ";
	cout << endl;
}
void sort(int *mas, int n)
{
	int temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if (mas[j] > mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
}
void combinate(int *mas1, int n1, int *mas2, int n2, int *&mas3, int &n3)
{
	int *temp;
	int temp1;

	temp1 = n1 + n2;
	temp = new int[temp1];
	for (int i = 0; i < n1; i++)
		temp[i] = mas1[i];
	for (int i = n1; i < temp1; i++)
		temp[i] = mas2[i-n1];

	sort(temp, temp1);
	for(int i=0;i<temp1;i++)
		for(int j=0;j<temp1-1;j++)
			if (temp[j] == temp[j + 1])
			{
				for (int k = j; k < temp1 - 1; k++)
					temp[k] = temp[k + 1];
				temp1--;
			}
	n3 = temp1;
	mas3 = new int[n3];
	for (int i = 0; i < n3; i++)
		mas3[i] = temp[i];

	show(mas3, n3);

	delete temp;
}
void intersection(int *mas1, int n1, int *mas2, int n2, int *&mas4, int &n4)
{
	int *temp;
	int temp1 = 0;

	temp = new int[n1];
	for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++)
			if (mas1[i] == mas2[j])
			{
				temp[temp1] = mas1[i];
				temp1++;
				break;
			}
	
	n4 = temp1;
	mas4 = new int[n4];
	for (int i = 0; i < n4; i++)
		mas4[i] = temp[i];

	show(mas4, n4);

	delete temp;
}