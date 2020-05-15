LOWEST COMMON ANCESSTOR & RMQ
int go( int i, int p ){

    if( rmq[i][p] != 0 ){
        return rmq[i][p];
    }

    if( p == 0 ){
        rmq[i][p] = parent[i];
        return rmq[i][p];
    }

    if( i == n ){
        rmq[i][p] = n;
        return rmq[i][p];
    }

    rmq[i][p] = go( go(i,p-1),p-1 );
    return rmq[i][p];

}


int lca ( int a, int b ){

    if( a == b ){
        return a;
    }

    if( depth[a] > depth[b] ){
        swap(a,b);
    }

    for( int i = 0 ; i < 20 ; i++ ){
        if( ((depth[b]-depth[a])>>i)&1 ){
            b = go(b,i);
            //cout<<"Sube "<<i<<" hasta "<<b<<endl;
        }
    }

    if( a == b ){
        return a;
    }

    for( int i = 20 ; i >=0 ; i-- ){
        if( go(a,i) != go(b,i) ){
            a = go(a,i);
            b = go(b,i);
        }
    }

    return go(a,0);

}
