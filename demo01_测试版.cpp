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
#include <cmath>
using namespace std;
int w[10];  //存储已经给定的若干个数
int x[10];  //以0和1来表示数是否加入当前序列 
int M;
/*
void Subset(int s,int k,int r，int M) 

s表示当前选中的w[i]*x[i]的值，
k表示当前选择的第几个数，
r为所给元素之和，起到临时变量的作用 
M为所给定值 
*/ 
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
	for(int i=0;i<10;i++)
	w[i]=i+1;
	//w[10]={1,2,3,4,5,6,7,8,9,10};
	M=10;
	Subset(0,0,55,10);
	return 0;
}
