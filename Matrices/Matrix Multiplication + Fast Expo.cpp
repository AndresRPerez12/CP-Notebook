MATRIX MULTIPLICATION + FAST EXPO

#define matrix vector< vector <ll> >

matrix mat_mult( matrix mA , matrix mB ){
    matrix ret;

    for( int i = 0 ; i < mA.size() ; i ++ ){
        ret.push_back( aux );
        for( int j = 0 ; j < mB[0].size() ; j ++ ){
            ll val = 0;
            for( int k = 0 ; k < mB.size() ; k ++ ){
                val = val + mA[i][k] * mB[k][j];
            }
            ret[i].push_back( val );
        }
    }
    return ret;
}

matrix id;

matrix expo( matrix base , ll exp ){
    if( exp == 0 ) return id;
    if( exp == 1 ) return base;
    matrix sal = expo( base , exp/2ll );
    sal = mat_mult( sal , sal );
    if( exp%2 == 1 ) sal = mat_mult( sal , base );
    return sal;
}
