
// https://www.spoj.com/problems/TEST/

#include <iostream>
using namespace std;

int main() {
	int temp;
	while(cin>>temp){
		if(temp==42){
			break;
		}
		cout<<temp<<"\n";
	}
	return 0;
}