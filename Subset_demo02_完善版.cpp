  //first try 
//1������������ѧ˼�� 
//2���������ö�����˼�����Ӽ�����subset����
//3�����û��ݵݹ�˼���� 

/*
���������
    ���ɸ�����ͽ��Ϊһ��ֵw1,����һ��0��1֮�����r,�������ͱ���w2��w2=r*w1;
    �������ɸ�����ѡȡn������ʹ��n�����ĺ͵���w2;�������е��������С�
*/

/*
˼·����
    ����һ��������max,�䷶ΧΪ1����������ͬʱ��������try[max]��ʹtry������Ԫ�صĺ�����������
	�����������򻯸��Ӷ�( (s+r-w[k])>=M && (s+w[k+1])<=M )     
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;
int w[1000];  //�洢�Ѿ����������ɸ���
int x[1000];  //��0��1����ʾ���Ƿ���뵱ǰ���� 
int M,sum=0; //sumΪ����Ԫ���ܺ� 
int static count3=0; //���ڼ�¼����������wi���е������ 
/*
void Subset(int s,int k,int r��int M) 

s��ʾ��ǰѡ�е�w[i]*x[i]��ֵ��
k��ʾ��ǰѡ��ĵڼ�������
rΪ����Ԫ��֮�ͣ�����ʱ���������� 
MΪ������ֵ 
*/ 

void Readfile() //��ȡ.in�ļ�,����ȡ����Ԫ�صĺ� 
{
   ifstream infile("D://���/���ݽṹ���㷨/�����ѧ�����ݽṹʵϰ/subset/1000/1000/test.01.in",ios::in);
		if(!infile)
		{
		   cout<<"Error opening file!"<<'\t';
		   exit(1);
	    }
	    int num,wi,pi;
	    //ofstream fout("D://���/���ݽṹ���㷨/�����ѧ�����ݽṹʵϰ/subset/1000/1000/test.01.in",ofstream::out);
	    int i=0;
	    while(infile.peek()!=EOF)
		{
			infile>>num>>wi>>pi;
			//cout<<wi<<'\t'<<pi<<'\n';
			w[i]=wi;
			sum+=w[i++];
		}	
} 
int Partition(int r[],int first,int end)    //���������һ�λ��� 
{
	int i=first;       //��ʼ�� 
	int j=end;
	while(i<j)
	{
		while(i<j && r[i]<=r[j]) j--;     //�Ҳ�ɨ��
		if(i<j)
		{
			int temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i++;
		} 
		while(i<j && r[i]<=r[j]) i++;     //���ɨ��
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
		pivot=Partition(r,first,end);    //һ�λ���
		QuickSort(r,first,pivot-1);         //�ݹ��������н�������
		QuickSort(r,pivot+1,end);           //�ݹ���Ҳ����н������� 
	}
}
void Subset(int s,int k,int r,int M) {
	x[k]=1;
	if(s+w[k]==M)  //����������M,��������
	{ 
	   count3++;
	   for(int i=0;i<=k;i++) {
	   	//����ֵ���x[i]=1,���Ѿ������������ 
	   	if(x[i]==1) cout<<w[i]<<'\t'; 
	   }
	   	cout<<'\n';
	} 
	else if(s+w[k]+w[k+1]<=M) //�������������Ԫ��ʱ�������Ȼ<=M,�򽫵�ǰ�ĵ�k��Ԫ�ؼ���s,kȡ��һԪ�أ������ݹ�
	{
		Subset(s+w[k],k+1,r-w[k],M);
	} 
	if ((s+r-w[k])>=M && (s+w[k+1])<=M) //������w[k]ʱ��ȫ��Ԫ��>=M,����s+��һ��Ԫ�صĺ�<=M,��������ǰ��k��Ԫ�أ�������һ�� 
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
	cout<<"������ָ����0-1��Χ�ڵ�һ��r��"<<'\n';
	cin>>r;
	Readfile();
	cout<<"����wi�ܺ�Ϊ��"<<sum<<'\n';
	int c=r*sum;
	cout<<"��������rȷ����cΪ��"<<c<<'\n'; 
	QuickSort(w,0,999);
	cout<<"����ʹ�ÿ��ź��ǰ10�����ݣ�"<<'\n';
	for(int i=0;i<10;i++)
	cout<<w[i]<<'\t';
	cout<<'\n'; 
	cout<<"���п�������Ԫ��֮Ϊ"<<c<<"�ľ���������£�\n"; 
	Subset(0,0,sum,c);
	cout<<"�������������"<<count3<<"��\n"; 
	return 0;
}
