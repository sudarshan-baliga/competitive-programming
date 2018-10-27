#include<bits/stdc++.h>
// #include</Users/sudhirpratap/Desktop/stdc++.h>
using namespace std;
#define MAX 10000000000000000
long long  ar1[10],ans;
struct node{
	long long  ld , rd , d;
	node* left =NULL; 
	node* right= NULL;
};
long long  d_sum(long long  a){
	long long  sum =0;
	while(a>0){
		sum+=(a%10);
		a=a/10; 
	}
	return sum;
}
node* get_node(long long  ld, long long  d, long long  rd ){
	node* temp = new node;
	temp->ld = ld;
	temp->rd = rd ;
	temp-> d = d;
	return temp;
}
/*
	Now I have two options for a number.
	1) Add the D in it ,
	2) digit sum

	so I made a binary tree , in which left child is digit sum and right one is Addition.
	like:
		     22
		   /    \
		  4	 34
		 / \	/  \	
		4  16  7   46

*/
void solve(long long  n ,long long  m){
	long long store=0,ld1=0,ld2=0,num = n+m;
	node * temp = new node;
	node* root = get_node(d_sum(n) , n , n+m);
	vector<node* > v;
	//I have used vector as a queue.
	v.push_back(root);
	double count =1;
	while(v[0]->d != ans){
			ld1 = d_sum(v[0]->ld);
			v[0]->left = get_node(ld1,v[0]->ld , v[0]->ld+m);
			ld2 = d_sum(v[0]->rd );
			v[0]->right = get_node(ld2 ,v[0]->rd ,v[0]->rd+m );
			v.push_back(v[0]->left);
			v.push_back(v[0]->right);
			v.erase(v.begin());
			count++;
	}
	double two=1;
	double f=0;
	while(count>=two){
		two*=2;
		f++;
	}
	cout<<ans<<" "<<f-1<<'\n';
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

		
		long long  t;
		cin>>t;
		while(t--){
			long long n, d, sum_n=0, index,minimum=100000000000,count =0,temp =0,count1=-1;
			cin>>n>>d;
			for(long long  i=0;i<10;i++)ar1[i]=0;
			index =n;
			bool flag=0;
/* we can find the minimum value of given number in at most 10 steps,
Example : if given number is 22 and D = 12;
then 
1) 2+2 = 4
2) 4 + 	12 = 16 = 1 + 6 = 7
3) 7 + 12 = 19 = 1 + 9 = 10 = 1+0 = 1
4) 1 + 12 = 13 = 1 +  = 4
5) 4 + 12 = 16 = 1 + 6 = 7
6) 7 + 12 = 19 = 1 + 9 = 10 =1 + 0 =1
so the digits are
4 ,7 ,1 ,4 ,7 ,1
as you can see a pattern is formed . 
Now , I have found the minimum value using this pattern. 
(I have used While loop to find the pattern)

Now it is time to find the minimum steps , for which I have used Tree.
*/
			while(flag==0){
				if(n>=10){
					count=0;
					temp = n;
					count++;
					while(n>0){
						sum_n += n%10;
						n=n/10;
						if(n==0 && sum_n>=10){
							n=sum_n;
							sum_n =0;
							count++;
						}
					}
					n = temp;
					ar1[sum_n]++;
					if(ar1[sum_n]>1)break;
				}
				n+=d;
				sum_n=0;
			}
			for(long long  i=0;i<10;i++){
				if(ar1[i]>0){
					if(minimum > i )minimum =i;
				}
			}
			ans = minimum;
			solve(index,d);
		}
return 0;
}