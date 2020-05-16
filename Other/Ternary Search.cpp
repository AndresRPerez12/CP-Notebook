TERNARY SEARCH
/// Finds minimal value of solve function

ll lo = arr[0] , hi = arr[n-1];
while( ( hi - lo ) >= 3 ){
    ll mi_1 = lo + (hi-lo)/3ll;
    ll mi_2 = hi - (hi-lo)/3ll;
    if( solve( mi_1 ) < solve( mi_2 ) ) hi = mi_2;
    else if( solve( mi_1 ) > solve( mi_2 ) ) lo = mi_1;
    else{
        hi = mi_2;
        lo = mi_1;
    }
}
ll h, best = LLONG_MAX;
for( int i = lo ; i <= hi ; i ++ ){
    ll sal = solve( i );
    if( sal < best ){
        best = sal;
        h = i;
    }
}
