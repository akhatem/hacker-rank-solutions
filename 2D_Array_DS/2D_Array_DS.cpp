#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int> > arr){
	vector<int> sum;
	int ii =3, jj =3;
	for(int i=0; i<=ii; ++i){
		for(int j=0; j<=jj; ++j){
            int sumab = 0;
			for(int a =i; a < i+3; ++a){
				for(int b =j; b < j+3; ++b){
					if (a != i+1){
						//printf("arr[%d][%d]: %d\n",a,b,arr[a][b]);
						sumab += arr[a][b];
					}
					else{
                        //printf("arr[%d][%d]: %d\n",a,b+1,arr[a][b+1]);
						sumab += arr[a][b+1];
						break;
					}
				}
			}
			sum.push_back(sumab);
			//cout << "==============================================\n";
		}

		cout << '\n';
	}
	int n = sizeof(sum) / sizeof(sum[0]);
//	for(int s = 0; s < sum.size(); ++s){
//            cout << sum[s];
//            if(s+1 <sum.size()) cout << ',';
//            else cout << '\n';
//	}
    int maxx = *max_element(sum.begin(), sum.end());
	return maxx;
}

int main(){
	vector< vector<int> > arr(6);
	for (int i=0; i< 6; ++i){
	        arr[i].resize(6);
		for (int j=0; j< 6; ++j){
			cin >> arr[i][j];
		}
	}
	printf("\n");
	int result = hourglassSum(arr);
	cout << result << '\n';
	return 0;
}
