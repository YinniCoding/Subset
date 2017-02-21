  //first try 
//1、尝试利用数学思想 
//2、尝试利用二叉树思想解决子集和数subset问题
//3、利用回溯递归思想解决 

/*
题意分析：
    若干个数求和结果为一定值w1,乘以一个0到1之间的数r,设置整型变量w2，w2=r*w1;
    从这若干个数中选取n个数，使这n个数的和等于w2;求解出所有的这样排列。
*/

/*
思路整理：
    设置一个最大个数max,其范围为1到最大个数，同时设置数组try[max]，使try中所有元素的和满足条件。
	界限条件来简化复杂度( (s+r-w[k])>=M && (s+w[k+1])<=M )     
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;
int w[1000];  //存储已经给定的若干个数
int x[1000];  //以0和1来表示数是否加入当前序列 
int M,sum=0; //sum为所有元素总和 
/*
void Subset(int s,int k,int r，int M) 

s表示当前选中的w[i]*x[i]的值，
k表示当前选择的第几个数，
r为所给元素之和，起到临时变量的作用 
M为所给定值 
*/ 

void Readfile() //读取.in文件,并求取所有元素的和 
{
   ifstream infile("D://软件/数据结构与算法/大二下学期数据结构实习/subset/1000/1000/test.01.in",ios::in);
		if(!infile)
		{
		   cout<<"Error opening file!"<<'\t';
		   exit(1);
	    }
	    int num,wi,pi;
	    //ofstream fout("D://软件/数据结构与算法/大二下学期数据结构实习/subset/1000/1000/test.01.in",ofstream::out);
	    int i=0;
	    while(infile.peek()!=EOF)
		{
			infile>>num>>wi>>pi;
			//cout<<wi<<'\t'<<pi<<'\n';
			w[i]=wi;
			sum+=w[i++];
		}	
} 
int Partition(int r[],int first,int end)    //快速排序第一次划分 
{
	int i=first;       //初始化 
	int j=end;
	while(i<j)
	{
		while(i<j && r[i]<=r[j]) j--;     //右侧扫描
		if(i<j)
		{
			int temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i++;
		} 
		while(i<j && r[i]<=r[j]) i++;     //左侧扫描
		{
			if(i<j)
			{
				int temp2;
				temp2=r[i];
				r[i]=r[j];
				r[j]=temp2;
				j--;
			}
		} 
	}
	return i; 
}
void QuickSort(int r[],int first,int end)
{
	if(first<end)
	{
		int pivot;
		pivot=Partition(r,first,end);    //一次划分
		QuickSort(r,first,pivot-1);         //递归对左侧序列进行排序
		QuickSort(r,pivot+1,end);           //递归对右侧序列进行排序 
	}
}
void Subset(int s,int k,int r,int M) {
	x[k]=1;
	if(s+w[k]==M)  //如果结果等于M,则输出结果
	{ 
	   for(int i=0;i<=k;i++) {
	   	//控制值输出x[i]=1,即已经加入数组的数 
	   	if(x[i]==1) cout<<w[i]<<'\t'; 
	   }
	   	cout<<'\n';
	} 
	else if(s+w[k]+w[k+1]<=M) //当往后添加两个元素时，结果仍然<=M,则将当前的第k个元素加入s,k取下一元素，继续递归
	{
		Subset(s+w[k],k+1,r-w[k],M);
	} 
	if ((s+r-w[k])>=M && (s+w[k+1])<=M) //当包括w[k]时，全体元素>=M,并且s+下一个元素的和<=M,则舍弃当前第k个元素，继续下一个 
	{
	  x[k]=0;
	  Subset(s,k+1,r-w[k],M);	
	} 
} 
int main() {
	//for(int i=0;i<10;i++)
	//w[i]=i+1;
	//w[10]={1,2,3,4,5,6,7,8,9,10};
	float r; 
	cout<<"请输入指定在0-1范围内的一个r："<<'\n';
	cin>>r;
	Readfile();
	cout<<"所有wi总和为："<<sum<<'\n';
	int c=r*sum;
	cout<<"根据所给r确定的c为："<<c<<'\n'; 
	QuickSort(w,0,999);
	cout<<"测试使用快排后的前10个数据："<<'\n';
	for(int i=0;i<10;i++)
	cout<<w[i]<<'\t';
	cout<<'\n'; 
	cout<<"所有可能序列元素之为"<<c<<"的具体组合如下：\n"; 
	Subset(0,0,sum,c);
	return 0;
}
