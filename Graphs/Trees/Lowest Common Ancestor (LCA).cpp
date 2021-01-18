LOWEST COMMON ANCESSTOR & RMQ
int parent [N];
int depth [N];
int rmq [N][30];

int go( int i, int p ){
    if( rmq[i][p] != 0 ) return rmq[i][p];
    if( p == 0 ) rmq[i][p] = parent[i];
    else rmq[i][p] = go( go(i,p-1) , p-1 );
    return rmq[i][p];
}

int lca ( int a, int b ){
    if( a == b ) return a;
    if( depth[a] > depth[b] ) swap(a,b);

    for( int i = 0 ; i <= 20 ; i++ ){
        if( (depth[b]-depth[a])&(1<<i) ) b = go(b,i);
    }
    if( a == b ) return a;
    for( int i = 20 ; i >= 0 ; i-- ){
        if( go(a,i) != go(b,i) ){
            a = go(a,i);
            b = go(b,i);
        }
    }
    return go(a,0);
}
