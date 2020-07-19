MY MODULAR OPERATIONS

ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}
ll add ( ll a, ll b ){
    ll ret = a+b;
    if( ret >= MOD ) ret -= MOD;
    return ret;
}
ll sub ( ll a, ll b ){
    return add( a , MOD - b );
}
ll mult ( ll a, ll b ){
    ll ret = a*b;
    if( ret >= MOD or ret < 0 ) ret %= MOD;
    return ret;
}
ll dvd ( ll a, ll b ){
    ll ret = mult( a , modinv( b , MOD ) );
    return ret;
}
