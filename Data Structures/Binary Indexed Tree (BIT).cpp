BIT
int BIT [10050];

void insertar( int x, int val ){
    for( int i = x; i <= n ; i+=(i&(-i)) ){
        BIT[i]+=val;
    }
    return;
}

int consultar ( int pos ){
    int s = 0;
    for( int i = pos ; i > 0 ; i-=(i&(-i)) ){
        s+=BIT[i];
    }
    return s;
}
