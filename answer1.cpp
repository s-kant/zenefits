#include<bits/stdc++.h>
using namespace std;

int get(char a){
	int x = a - '0';
	return x;
}
void fun(string s,int st,int end){
	bool check_subtrees = false;
	for(int i = st+1;i<end;i++){
		if(s[i] == '{'){
			check_subtrees = true;
			//cout<<"subtrees"<<endl;
			break;
		}
	}
	if(check_subtrees == false){
		bool one_val = true;
		for(int i = st+1;i<end;i++){
			if(s[i] == ',')
				one_val = false;
		}
		if(one_val == true){
			int j = st + 1;
			int value = 0;
			while(s[j] !=',' && s[j] !='}'){
				value = value*10+get(s[j]);
				j = j+1;
			}
			if(value != 0)
				cout<<value<<",";
		}
		else{
			int value[2] = {0};
			//cout<<value[1]<<endl;
			int j = st+1;
			for(int i = 0;i<3;i++){
				//cout<<j<<endl;
				while(s[j] !=',' && s[j] !='}'){
					value[i] = value[i]*10+get(s[j]);
					j = j+1;
				}
				j = j+1;
			}
			if(value[1] != 0)
				cout<<value[1]<<",";
			cout<<value[0]<<",";
			if(value[2] != 0)
				cout<<value[2]<<",";
			}
	}
	else{
		int val = 0;
		int l_ind , r_ind;
		int i = st+1;
		while(s[i] !=','){
			val = val*10+get(s[i]);
			i = i+1;
		}
		l_ind = i + 1;
		int m = 1,n = l_ind +1;
		while(m!=0){
			if(s[n] == '{')
				m++;
			if(s[n] == '}')
				m--;
			n++;
		}
		r_ind = n + 1;
		fun(s,l_ind,r_ind-2);
		cout<<val<<",";
		fun(s,r_ind,end);
	}
	return ;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int l = s.length();
		fun(s,0,l-1);
		cout<<endl;
	}
}
