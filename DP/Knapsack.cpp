KNAPSACK
int knapsack( int n , int k ){
    if( res[n][k] != -1 ){
        return res[n][k];
    }

    if( n <= 0 ){
        return 0;
    }

    if( k >= nn ){
        return 0;
    }

    int td = w * depth[k];
    int ta = (2 * w) * depth[k];
    int tt = td + ta;

    if( tt <= n ){
        if( knapsack( n-tt , k+1 ) + gold[k] >= knapsack( n , k+1 ) ){
            res[n][k]=knapsack( n-tt , k+1 ) + gold[k];
            cam[n][k]=true;
        }else{
            res[n][k]=knapsack( n , k+1 );
            cam[n][k]=false;
        }
        return res[n][k];
    }else{
        res[n][k]=knapsack( n , k+1 );
        cam[n][k]=false;
        return res[n][k];
    }

}
