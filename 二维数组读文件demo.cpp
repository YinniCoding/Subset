#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() {
	ifstream infile("D://软件/数据结构与算法/大二下学期数据结构实习/subset/1000/1000/test.01.in",ios::in);
		if(!infile)
		{
		   cout<<"Error opening file!"<<'\t';
		   exit(1);
	    }
	    int num,wi,pi;
	    //ofstream fout("D://软件/数据结构与算法/大二下学期数据结构实习/subset/1000/1000/test.01.in",ofstream::out);
	    while(infile.peek()!=EOF)
		{
			infile>>num>>wi>>pi;
			cout<<wi<<'\t'<<pi<<'\n';
		 } 
	    /*int i=0;
	    string s,s2,s3;
	    int a[1000][2];
	    while(getline(infile,s) && i<1000) {
	    	//cout<<s<<'\n';
	    	
	    	int j=0;char a1[5],a2[5],a3[5];
	    	for(;s[j]!=' ';j++)
	    	a1[j]=s[j];
			a1[j+1]='\0';
			int k1=0;
			for(j+=1;s[j]!=' ';j++)
	    	a2[k1++]=s[j];
			a2[k1+1]='\0';
			int k2=0;
			for(j+=1;s[j];j++)
	    	a3[k2++]=s[j];
			a3[k2+1]='\0';
	    	for(int k=0;k<=k1;k++)
	    	cout<<a2[k];
	    	cout<<'\t';
	    	for(int l=0;l<=k2;l++)
			cout<<a3[l];
			cout<<'\n'; 
	    	int wi=0;
			int n=1;
	    	for(int m=k1-1;m>=0;m--)
	    	{ 
			  wi+=(a2[m]-'0')*n;
			  n*=10;
			}
			cout<<wi<<'\n';
			
	    	
	    	
	    	/*int j;
	    	char a1[5],a2[5],a3[5];
	    	for(j=0;s[j]!='\t';j++) {
	    		a1[j]=s[j];
			}
			for(j+=1;s[j]!='\t';j++) {
				int k=0;
	    		a2[k++]=s[j];
			}
			for(j+=1;s[j]!='\n';j++) {
				int l=0;
	    		a3[l++]=s[j];
			}
			cout<<a2<<'\t'<<a3<<'\n';
	    	*/
		//}
	return 0;
}
