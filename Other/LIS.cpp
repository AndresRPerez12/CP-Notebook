#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int TAM = 5e3+3;

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int n;
int arr [TAM];

int sz = 0;
int dp [TAM];

int findSeq ( int val ){
    int lo = 0, hi = sz, mi;
    while( lo < hi ){
        mi = (lo+hi+1)/2;
        if( dp[mi] < val ) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
        cin >> arr[i] ;
    sz = 0;
    dp[0] = -1;
    for( int i = 0 ; i < n ; i ++ ){
        int pos = findSeq( arr[i] );
        if( pos == sz ){
            sz ++;
            dp[pos+1] = arr[i];
        }else if( dp[pos+1] > arr[i] ) dp[pos+1] = arr[i];
    }
    cout << sz << endl ;

	return 0;
}