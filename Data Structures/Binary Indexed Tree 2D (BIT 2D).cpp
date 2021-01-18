BIT 2D FOR MAX

ll BIT[N][N]; 

void insertar ( int pi, int pj, ll val) {
    for ( int j = pj ; j < N ; j += (j&(-j)) ){
        for ( int i = pi ; i > 0 ; i -= (i&(-i)) ){
            BIT[j][i] = max ( BIT[j][i] , val );
        }
    }
}
 
ll maxVal ( int pi, int pj ) {
    ll ret = LLONG_MIN;
    for ( int j = pj ; j > 0 ; j -= (j&(-j)) ){
        for ( int i = pi ; i < N ; i += (i&(-i)) ){
            ret = max ( ret , BIT[j][i] );
        }
    }
    return ret;
}