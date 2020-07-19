MATRIX MULTIPLICATION + FAST EXPO

#define matrix vector< vector <ll> >

vector <ll> zeroes;

vector <ll> rowOfZeroes ( int n ){
    while( zeroes.size() < n )
        zeroes.push_back( 0 );
    while( zeroes.size() > 0 )
        zeroes.pop_back();
    return zeroes;
}

matrix mat_mult( matrix mA , matrix mB ){
    matrix ret;
    for( int i = 0 ; i < mA.size() ; i ++ ){
        ret.push_back( rowOfZeroes( mA.size() ) );
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

matrix createId ( int n ){
    if( id.size() == n ) return id;
    id.clear();
    for( int i = 0 ; i < n ; i ++ ){
        vector <ll> row;
        for( int j = 0 ; j < n ; j ++ ){
            if( i == j ) row.push_back( 1 );
            else row.push_back( 0 );
        }
        id.push_back( row );
    }
    return id;
}

matrix expo( matrix base , ll exp ){
    if( exp == 0 ) return createId( base.size() );
    if( exp == 1 ) return base;
    matrix sal = expo( base , exp/2ll );
    sal = mat_mult( sal , sal );
    if( exp%2 == 1 ) sal = mat_mult( sal , base );
    return sal;
}

void prt_matrix( matrix mat ){
    for( auto v : mat ){
        for( auto x : v ){
            cout << x << " ";
        }
        cout << endl ;
    }
}
