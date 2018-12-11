// https://www.spoj.com/problems/ADDREV/
#include <iostream>
using namespace std;

int main() {
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int l1=a.size();
		int l2=b.size();
		int l3=max(l1,l2);
		int arr1[l3]={0},arr2[l3]={0},ans=0;
		for(int i=0; i<l3; i++){
			if(i<l1){
				arr1[i]=a[i]-'0';
			}
			if(i<l2){
				arr2[i]=b[i]-'0';
			}
		}
		int tempSum=0;
		int carry=0;
		for(int i=0; i<l3; i++){
			tempSum=arr1[i]+arr2[i]+carry;
			ans=ans*10 + tempSum%10;
			carry=tempSum/10;
		}
		if(carry){
			cout<<ans*10 +carry<<"\n";
		}
		else{
			cout<<ans+carry<<"\n";
		}
	}
	return 0;
}