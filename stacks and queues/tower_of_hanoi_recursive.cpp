// https://www.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/a/towers-of-hanoi

#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char s, char d, char h){
	if(n == 1){
		cout << "Move Disk 1 From " << s << " to " << d << endl; 
		return;
	}
	hanoi(n-1, s, h, d);
	cout << "Move Disk " << n << " From " << s << " to " << d << endl;
	hanoi(n-1, h, d, s);
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 's', 'd', 'h'); 
}