//看见别人这么写，我感动得哭了
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int a=3;a<=n;a++)
    for(int b=2;b<=n;b++)
        for(int c=b;c<=n;c++)
            for(int d=c;d<=n;d++){
                if(b*b*b+c*c*c+d*d*d>a*a*a)
                    break;
                if(a*a*a==b*b*b+c*c*c+d*d*d)
                    cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
            }
    return 0;
}