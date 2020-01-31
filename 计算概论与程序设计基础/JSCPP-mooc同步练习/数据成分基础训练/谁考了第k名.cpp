#include <iostream>
using namespace std;

void reline_max_to_min (double a[],int n)
{
	double temp = 0;
	for (int i = 0; i < (n-1); i++)
		for (int j = (i+1); j < n; j++)
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

void copy (double a[], double b[],int n)
{
	for (int i = 0; i <= (n-1); i++)
		b[i] = a[i];
}

int main()
{
	int id[100] = {0};
	double score[100] = {0};
	double c_score[100] = {0};
	int n = 0;
	int k = 0;
	
	cin>>n>>k;
	
	for (int i = 0; i < n; i++)
		cin>>id[i]>>score[i];
	
	copy(score,c_score,n);
	
	reline_max_to_min(c_score,n);
	
	for (int j = 0; j < n; j++)
        if(score[j] == c_score[k-1])
        {
			cout<<id[j]<<" "<<score[j];
			break;
		}

    return 0;	
}