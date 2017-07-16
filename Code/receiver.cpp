#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream fin;
	fin.open("message.txt",ios::in);
	int len;
	fin>>len;
	int arr[10];
	
	for(int i=0; i<len; i++){
		fin>>arr[i];

	}
	for(int i=0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int s1=0,s2=0;
	
		
		//cout<<"s1  "<<"s2\n";
		for(int i=0;i<len;i++){
			s1=(s1+arr[i])%15;
			s2=(s2+s1)%15;
			
		}
		cout<<s1<<"  "<<s2<<endl;
		
		if(s1==0 && s2==0){
			cout<<"No errors detected in message!\n";
		}
		else{
			cout<<"Error detected in message!\n";
		}


}