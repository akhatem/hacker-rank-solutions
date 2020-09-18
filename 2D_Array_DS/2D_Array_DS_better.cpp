#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int> > arr) {
    int maxx =0;
    int ii =3, jj =3;
    for(int i=0; i<=ii; ++i){
        for(int j=0; j<=jj; ++j){
            int sum =0;
            int ci = i, cj = j;
            sum += arr[ci][cj] + arr[ci][cj+1] + arr[ci][cj+2] + arr[ci+1][cj+1] + arr[ci+2][cj] + arr[ci+2][cj+1] + arr[ci+2][cj+2];
            if(ci == 0 && cj ==0) maxx = sum;
            if(sum > maxx) maxx = sum;
        }
    }
    return maxx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int> > arr(6);
    int n;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
        arr[i].resize(6);
        cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
