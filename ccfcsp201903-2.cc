#include<stdio.h>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string str;
	stack<int> num;
	stack<char> op;
	int n=0;
	cin>>n;
	while(n--){
		//num.clear();
		//op.clear();
		
		cin>>str;
		for(int i=0;i<str.length();i++){
			if(i%2==0) num.push(str[i]-'0');
			else{
				if(str[i]=='x'){
					int temp = num.top()*(str[i+1]-'0');
					i++;
					num.pop();
					num.push(temp);
					continue;
				}
				if(str[i]=='/'){
					int temp = num.top()/(str[i+1]-'0');
					i++;
					num.pop();
					num.push(temp);
					continue;
				}
        if(str[i]=='-'){
          num.push(-(str[i+1]-'0'));
          i++;
          op.push('+');
        }
				else{
					//cout<<str[i]<<endl;
					op.push(str[i]);
				}
			}
		}
		//cout<<"dsasd"<<endl;
		int sum=0;
		sum+=num.top();
		num.pop();
		while(!num.empty()&&!op.empty()){
			//cout<<sum<<endl;
			//cout<<op.top()<<endl;
			if(op.top()=='+'){
				
				sum=num.top()+sum;
				num.pop();
				op.pop();
				continue;
			}
			if(op.top()=='-'){
				sum=num.top()-sum;
				num.pop();
				op.pop();
			}
		}
		printf("%d\n",sum);
		if(sum==24)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		
	}
}
