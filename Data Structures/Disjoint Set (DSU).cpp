DISJOINT SET

struct DisjointSet{

    int P[1000003];
    int R[1000003];

    DisjointSet(  ){
        memset(R,0,sizeof(R));
        for( int i = 1 ; i <= 1000000 ; i ++ ){
            P[i] = i;
        }
    }

    int find ( int x ){
        if( x == P[x] ){
            return x;
        }
        return P[x] = find( P[x] );
    }

    void merge ( int x, int y ){
        int px = find(x);
        int py = find(y);
        if( px == py ){
            return;
        }
        if( R[px] > R[py] ){
            P[py] = px;
        }else{
            P[px] = py;
            if( R[px] == R[py] ){
                R[py]++;
            }
        }
    }

}Ds;
