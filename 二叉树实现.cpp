/* �ڻ��ݷ������ǰ���£����Ը������Ƶ�ʹ�ö�����ʵ�֣������߼����� 
��ʦ����ʾ�ǣ�������Ԫ�شӴ�С������������μܹ�����Ԫ�ط�����������У�ֱ���ӽ�c�����ֵ
��������c����һ���Ĳ�࣬�����뵽��һ��С��ֵ���������ҪѰ�ҵ����С��ֵ������ҵ����ͼ��벢������������
������Ҳ�����������ǰ�������һ��Ԫ��ֵ��ѡȡС�ڵ�ǰ��Ԫ�ص����Ԫ�أ������ظ��ϲ�����һ����Ϊ�ݹ���� 
һ���ҵ�����������wi����� 
/*
�����߼���ƣ�
     ���ԭʼ��ȡ�������Ѿ��������кõĻ�����ô�������ýṹ�彫ÿ����ŵ�Ԫ�ط�װ����
	 �Ƚ�����Ԫ�ش洢���ṹ�������У����Ұ���wi�е�ֵ���н�������
	 ��ʼ 
*/ 

#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include <cstdlib>
#define N 1000 
using namespace std;

int x[1000];  //��0��1����ʾ���Ƿ���뵱ǰ����
int static count3=0; //���ڼ�¼����������wi���е������ 
int static count=0,P[100]={0},count4=0; //������������������wi���ж�Ӧ������������pi����
//ʹ�ýṹ���װÿ�����ݣ�������Ϊ��š�wiֵ��piֵ 
struct Row{
	int RowNum;    //��� 
	int WiValue;    //��Ӧ�������wiֵ 
	int PiValue;    //��Ӧ�������piֵ 
};
/*
  ���һ��ReadySet�ṹ�����Դ洢ÿ������������wi���м���
  �Ӹ��ڵ㿪ʼ�����θ�������
  ÿ����������һ����������������ڴ� 
*/ 
struct ReadySet{
   struct Row *lchild;  //��������wi���е������� 
   struct Row *rchild;   	
};  
/*
���һ���Ӽ��� 
*/
class Subset{
	private:
		struct Row row01[N];   //����ʹ�ò��洢N������ 
	    
		struct ReadySet *root=NULL; 
		//int count;   //����ͳ������������wi������ϸ��� 
	public:
		int w[1000],p[1000];   //�洢����wi��pi��ֵ 
		int sum;    //��ʾ����wiԪ���ܺ� 
		
		 
		/*Ĭ�Ͽ�*/
		Subset(); // Ĭ�Ϲ��캯������ȡ.in�ļ�����������
		~Subset();  //�������� 
		
		/*���ĺ���*/ 
		void SubsetSearch(int r[],int n);   //nΪ��ֵc �Ӵ�С��䷨ 
		void SubsetSearch2(int s,int k,int r,int M);   // ���ݷ� 
		
        /*��������������*/		
		void QuickSort(int r1[],int r2[],int first,int end);  //��������
		int Partition(int r1[],int r2[],int first,int end);  //���ŵ�һ�λ���
		void ShellSort(int r1[],int r2[],int n);	 //ϣ������ 
		void HeapSort(int r1[],int n);            //������ 
        void Sift(int r1[],int k,int m);   //����Ϊ�����	
        void TimeTest(); 
		
		/*�����ض�Ԫ��*/ 
		int BinSearch(int r[],int n,int k);   //��ͷԪ�ؼ򵥲��ö��ֲ���
		//int GreatSearch(int r[],int n);   //�ض����� 
		
		/**/ 
		void show1();   //չʾ��ȡ���ļ����ǰ�������� 
};  
//���캯����ȡ.in�ļ�����������    
Subset::Subset() {
	    ifstream infile("D://���/���ݽṹ���㷨/�����ѧ�����ݽṹʵϰ/almost/1000/1000/test.01.in",ios::in);
		if(!infile)
		{
		   cout<<"Error opening file!"<<'\t';
		   exit(1);
	    }
	    else {
	    	cout<<"�ɹ���ȡ�ļ��������ļ�ΪalmostĿ¼��test.01.in�ļ�����1000�����ݣ�\n";
		}
	    sum=0;
	    int i=0;    //ͳ�ƴ������ݸ��� 
	    int num,wi,pi; //�ݴ�ÿ������
		while(infile.peek()!=EOF) {
			infile>>num>>wi>>pi;
			//�����ֶδ��뵽�ڴ��� 
			row01[i].RowNum=num;
			row01[i].WiValue=wi;
			row01[i].PiValue=pi;
			w[i]=wi; 
			p[i]=pi;
			i++;
		}
		
		//���м򵥶�ȡ��� 
		cout<<"\n����������"<<i-1<<"��\n";
		
		/*cout<<"���ǰ10�����ݽ��м򵥼��1:\n";
		for(int j=0;j<10;j++) {
		   cout<<row01[j].RowNum<<'\t'<<row01[j].WiValue<<'\t'<<row01[j].PiValue<<'\n';
		}*/
		w[0]=390; 
		p[0]=380;	
		for(int i=0;i<1000;i++)
		sum+=w[i];
	    cout<<"\nwi������Ԫ���ܺ�Ϊ��\n";
	    cout<<sum<<'\n';	 
			 
}
Subset::~Subset() {
	
}

//��Ѱ��Сֵ(��ͷ)���������մӴ�С��� 
void Subset::SubsetSearch(int r[],int n) {
	int static count=0;  //���ڼ�¼wi�������и��� 
	int i,j;          //j���ڼ�¼���������Ԫ�ص����һ��Ԫ��λ��
	int s1=0;       //�Ѽӽ���ǰi�����ĺ�
	for(i=0;i<N;i++) {
		s1+=w[i];
		//�ٽ������ 
		if(s1<n && (s1+w[i+1])>n) {
			j=i;              //��¼���һ��λ��
			//n-=s1;         //��ͷ����n
			break; 
		}
	} 
	//Ѱ����Сֵ
	int n2=n-s1;
	for(int k=j+1;k<N;k++) {
		if(n2>w[k]) break;
	    if(n==w[k]) {
	    	//count++; 
	    	cout<<"\n���ҵ�����������һ��wi����,��������Ԫ�ظ���Ψһ��Ԫ��Ϊ��"<<w[k]<<",���������������Ԫ�ظ���Ϊ��"<<j+1<<'\n';
			return; 
		}	 
	} 
    //��Ѱ������Сֵ
	for(int l=j;l>=0;l--) {
		n2=n-s1+w[l];    //���滻��ͷ 
		int n3=n2/2,m;   //��ȡ��ͷ����ʲ��洢 
		for(int l2=j+1;l2<N;l2++) {
		    if(n3==w[l2] || (n3>w[l2] && n3<w[l2+1])) {
		    	m=l2;
			}	
			int m2=m-1;
			//��m���������˽��м��� 
			for(int l3=m2;l3>j;l3++) {
				for(int l4=m;l4<N;l4++) {
					if(w[l3]+w[l4]<n2) {
						//cout<<"��ǰ���δ�ҵ�����������wi����!\n";
						break; 
					}
					if(w[l3]+w[l4]==n2) {
						//count++;
						cout<<"\n���ҵ�����������һ��wi����,��������Ԫ�ظ���Ψһ��Ԫ��Ϊ��"<<w[l4]<<",���������������Ԫ�ظ���Ϊ��"<<j+1<<'\n';
					}
				}
			}	
		}
	}
	//cout<<count<<'\n';
	cout<<"δ�ҵ���������wi���У�\n";	 
}
void Subset::SubsetSearch2(int s,int k,int r,int M) {
	x[k]=1;
	if(s+w[k]==M)  //����������M,��������
	{ 
	   count3++;
	   int count2=0,p2[100]={0}; 
	   int j=0;
	   for(int i=0;i<=k;i++) {
	   	//����ֵ���x[i]=1,���Ѿ������������ 
	   	if(x[i]==1) 
		   {
		    cout<<w[i]<<'\t';
		    count2+=w[i];
		    p2[j++]=w[i];
		   } 
	   }
	   	cout<<'\n';
	   	if(count2>count) {
	   		count=count2;
	   		count4=j;
	   		for(int l=0;l<j;l++)
	   		P[l]=p2[l];
		   } 
	} 
	else if(s+w[k]+w[k+1]<=M) //�������������Ԫ��ʱ�������Ȼ<=M,�򽫵�ǰ�ĵ�k��Ԫ�ؼ���s,kȡ��һԪ�أ������ݹ�
	{
		SubsetSearch2(s+w[k],k+1,r-w[k],M);
	} 
	if ((s+r-w[k])>=M && (s+w[k+1])<=M) //������w[k]ʱ��ȫ��Ԫ��>=M,����s+��һ��Ԫ�صĺ�<=M,��������ǰ��k��Ԫ�أ�������һ�� 
	{
	  x[k]=0;
	  SubsetSearch2(s,k+1,r-w[k],M);	
	}
}
//����  
int  Subset::Partition(int r1[],int r2[],int first,int end)    //���������һ�λ��� 
{
	int i=first;       //��ʼ�� 
	int j=end;
	while(i<j)
	{
		while(i<j && r1[i]<=r1[j]) j--;     //�Ҳ�ɨ��
		if(i<j)
		{
			int temp=r1[i];
			r1[i]=r1[j];
			r1[j]=temp;
			int temp3=r2[i];
			r2[i]=r2[j];
			r2[j]=temp3;
			i++;
		} 
		while(i<j && r1[i]<=r1[j]) i++;     //���ɨ��
		{
			if(i<j)
			{
				int temp2;
				temp2=r1[i];
				r1[i]=r1[j];
				r1[j]=temp2;
				int temp4=r2[i];
				r2[i]=r2[j];
				r2[j]=temp4;
				j--;
			}
		} 
	}
	return i; 
}
void Subset::QuickSort(int r1[],int r2[],int first,int end)
{
	if(first<end)
	{
		int pivot;
		pivot=Partition(r1,r2,first,end);    //һ�λ���
		QuickSort(r1,r2,first,pivot-1);         //�ݹ��������н�������
		QuickSort(r1,r2,pivot+1,end);           //�ݹ���Ҳ����н������� 
	}
}
//ϣ������
void Subset::ShellSort(int r1[],int r2[],int n) {
	int r3[n+1],r4[n+1];
	for(int i=0;i<n;i++) {
		r3[i+1]=r1[i];
		//r4[i+1]=r2[i];
	} 
	
	for(int d=n/2;d>=1;d--)  //0�ŵ�Ԫ�����ݴ浥Ԫ������d����ֱ������ 
	{ 
		for(int j=d+1;j<n;j++)
		{
			r3[0]=r3[j];    //�ݴ汻���¼
			//r4[0]=r4[j];
			int k; 
			for(k=j-d;k>=0 && r3[0]<r3[k];k-=d) 
			   r3[k+d]=r3[k];
			   r3[k+d]=r3[0];
			   //r4[k+d]=r4[k];
			   //r4[k+d]=r4[0];
		} 
	}
	for(int l=0;l<n;l++) {
		r1[l]=r3[l+1];
	}
	
} 
//������
void Subset::HeapSort(int r1[],int n) {
	int r3[n+1];
	for(int k=0;k<1000;k++)
	r3[k+1]=r1[k];
	for(int i=n/2;i>=1;i--)
	Sift(r3,i,n);
	int temp;
	for(int j=1;j<n;j++)
	{
		temp=r3[1];
		r3[1]=r3[n-j+1];
		r3[n-j+1]=temp; 
		Sift(r3,1,n-j);
	}
	for(int l=0;l<1000;l++)
	r1[l]=r3[l+1];
} 
void Subset::Sift(int r1[],int k,int m) {
	int i=k;
	int j=2*i;
	while(j<=m)
	{
		if(j<m && r1[j]<r1[j+1]) j++;
		if(r1[i]>r1[j]) break;
		else 
		{
			int temp;
			temp=r1[i];
			r1[i]=r1[j];
			r1[j]=temp;
			i=j;
			j=2*i;
		}
	}
}

//���ֲ��� 
int Subset::BinSearch(int r[],int n,int k)
{
	int low=1,high=n;           //���ò������䣬lowΪ�����λ��highΪ���λ
	while(low<=high)
	{
		int mid;
		mid=(low+high)/2;
		if(k<r[mid]) high=mid-1;           //����������С���м�������������ѹ��Ϊ����
		else if(k>r[mid]) low=mid+1;           //���������������м�������������ѹ��Ϊ�Ұ��
		else return mid; 
    }
}
void Subset::TimeTest() {
	int i;
	cout<<"\n1��2��3���α�ʾ��������ϣ�����򡢶�����ѡ������һ��������ԭʼ��������\n";
	cin>>i;
	double start,end;
	switch(i) {
		case 1:
			start=clock();
			QuickSort(w,p,0,999);
			end=clock();
			cout<<"������ɣ�ʹ�ÿ������򹲻���ʱ��Ϊ��"<<(end-start)<<"ms��\n";
			break;
		case 2: 
			start=clock();
			ShellSort(w,p,1000);
			end=clock();
			cout<<"wi��������ɣ�ʹ��ϣ�����򹲻���ʱ��Ϊ��"<<(end-start)<<"ms��\n";
			break;
		case 3:
			start=clock();
			HeapSort(w,999);
			end=clock();
			cout<<"wi��������ɣ�ʹ�ö����򹲻���ʱ��Ϊ��"<<(end-start)<<"ms��\n";
			break;
		default: 
		    cout<<"�밴��Ҫ��������룡\n";
		    TimeTest();
	}
	
} 
void Subset::show1() {
    //QuickSort(obj.w,obj.p,0,999);
    //cout<<'\n';
	for(int i=0;i<10;i++)
	//cout<<row01[i].RowNum<<'\t'<<row01[i].WiValue<<'\t'<<row01[i].PiValue<<'\n';
	cout<<w[i]<<'\t'<<p[i]<<'\n';

}

int main()
{
	Subset test;
	cout<<"\n���ǰ10�����ݽ��м򵥲��ԣ��ж��Ƿ�洢�ɹ�:\n";
	test.show1();
	//cout<<"\n���Կ��ź���wi�д�С����ǰ10�����ݣ�\n";
	//test.QuickSort(test.w,test.p,0,999);
	test.TimeTest();
	//test.QuickSort(test.w,test.p,0,999); 
	cout<<"\n���������wi��pi���У�\n";
	test.show1(); 
    float r; 
	cout<<"\n������ָ����0-1��Χ�ڵ�һ��r��"<<'\n';
	cin>>r;
	int c=r*test.sum;
	cout<<"��������rȷ����cΪ��"<<c<<'\n'; 
    cout<<"\nѡ������㷨1���������£�\n";
	cout<<"\n���п�������Ԫ��֮Ϊ"<<c<<"�ľ���������£�\n"; 
	double start=clock(); 
	test.SubsetSearch2(0,0,test.sum,c);
	double end=clock();
	cout<<"�����㷨1����test.01.in��1000�����ݹ�����ʱ�䣺"<<(end-start)<<"ms��\n"; 
	cout<<"\n�������������"<<count3<<"��\n"; 
	cout<<"\n����������wi��϶�Ӧ��pi��������������Ϊ��\n";
	for(int j=0;j<count4;j++)
	cout<<P[j]<<'\t';
	cout<<'\n';
    cout<<"\nѡ������㷨2���������£�\n";
    start=clock();
    test.SubsetSearch(test.w,c);
    end=clock();
	cout<<"\n�����㷨2����test.01.in��1000�����ݹ�����ʱ�䣺"<<(end-start)<<"ms��";
	return 0;
}
