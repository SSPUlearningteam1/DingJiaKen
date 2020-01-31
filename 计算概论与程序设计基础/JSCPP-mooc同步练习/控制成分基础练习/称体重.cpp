#include <iostream>
using namespace std;
struct roster;
void PRINT(int, int, int, int);

struct roster
{
	char name = '\0';
	int weight = 0;
};

int main()
{
	for(int z = 10; z <= 50; z += 10)
		for(int q = 10; q <= 50; q += 10)
			for(int s = 10; s <= 50; s += 10)
				for(int l = 10; l <= 50; l += 10)
					if (z != q && z!= s && z!= l && q != s && q!= l && s != l)
						if( z + q  == s + l && z + l > s + q && z + s < q)
						    PRINT(z,q,s,l);
				

    return 0;
}
void PRINT(int z, int q, int s, int l) //由于jscpp的编译器问题，我没办法给结构体数组初始化（其他方法我也不会）
{
	roster people[4];//主要是字符变量初始化过程中老是出错，原因未知
	roster *p = people;
	p->name = 'z';
    p->weight = z;
    p++;
	p->name = 'q';
	p->weight = q;
	p++;
	p->name = 's';
	p->weight = s;
	p++;
	p->name = 'l';
	p->weight = l;
	p = people;
	
	roster *p_max = people;
	for(int j = 0; j < 4; j++)
	{
		for(int k = 0; k < 4; k++)
		{
			if(p_max->weight < p->weight)
				p_max = p;
			
			p++;
		}
		cout<<p_max->name<<" "<<p_max->weight<<endl;
		p_max->weight = 0;
		p = people;
	}
}