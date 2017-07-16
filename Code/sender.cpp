#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
	int a[10];
	int len;
	int pos;
	cin>>len;
	for(int i=0; i<len; i++ ){
		cin>>a[i];

	}
	cin>>pos;
	int n=pos-1;
	if(n!=len-1){
		for(int i=len-1;i>=n;i--)
				a[i+2]=a[i];
		}
	else{
		
			a[n+2]=a[n];
			a[n+1]=a[n-1];
		}

		a[n]=0;
		a[n+1]=0;
		len+=2;
		int c0,c1;
		c0=c1=0;		//accumulators

		for(int i=0; i<len; i++){
			c0=(c0+a[i])%15;
			c1=(c1+c0)%15;
		}
		int t1,t2;
		t1=	(len-pos)*c0-c1;
		t2=	c1-(len-pos+1)*c0;
		if(t1<0){
			int i=0;
			while(15*i < abs(t1)){
					i++;
			}
			t1=15*i-abs(t1);
		}
		else
			t1=t1%15;

		if(t2<0){
			int i=0;
			while(15*i < abs(t2)){
					i++;
			}
			t2=15*i-abs(t2);
		}
		else
			t2=t2%15;
		
		a[n]=t1;
		a[n+1]=t2;
		//for(int i=0; i<len; i++)
		//	cout<<a[i]<<" ";
		//file
		ofstream fout;
		fout.open("message.txt",ios::out);
		fout<<len<<"\n";
		for(int i=0; i<len; i++)
			fout<<a[i]<<" ";

		return 0;
}