LONGEST PALINDROME PREFIX WITH KMP
int kmp [TAM];

string findPal( string x ){
    kmp[0] = -1;
    int p;
    for(int i = 0 ; i < x.size() ; i++){
        p = kmp[i];
        while( x[p] != x[i] and p >= 0 ){
            p = kmp[p];
        }
        kmp[i+1] = p+1;
     }
    return x.substr( 0 , kmp[x.size()-1]+1 );
}

KMP

void match( string p ){
    prec[0] = 0;
    for ( int i = 1 ; i < p.size() ; i++ ) {
        int aux = prec[i - 1];
        while ( aux > 0 and p[i] != p[aux] ){
            aux = prec[aux - 1];
        }
        if( p[i] == p[aux] ) aux ++;
        prec[i] = aux;
    }
}
