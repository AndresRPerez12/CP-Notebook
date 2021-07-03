// SEGMENT TREE WITH LAZY PROPAGATION
// tested: https://codeforces.com/gym/100377/submission/121264677
struct SegmentTree{

    ll val, from, to, mi, lazy;
    SegmentTree *L;
    SegmentTree *R;

    SegmentTree( int _from , int _to ){
        val = 0;
        lazy = -1;
        from = _from;
        to = _to;
        mi = (from+to)/2ll;
        if( _from == _to ){
            L = nullptr;
            R = nullptr;
            return;
        }
        L = new SegmentTree( from , mi );
        R = new SegmentTree( mi+1 , to );
    }

    void prop(){
        if( lazy == -1 ) return;
        val = max( val , lazy );
        if( L != nullptr ){
            L->lazy = max( L->lazy , lazy );
            R->lazy = max( R->lazy , lazy );
        }
        lazy = -1;
    }

    void update( ll pos , ll nv ){
        prop();
        if( pos == from and pos == to ){
            val = max(val , nv);
            return;
        }
        if( pos <= mi ) L->update( pos , nv );
        else R->update( pos , nv );
        val = max( L->val , R->val );
    }

    void rangeUpdate( ll l , ll r , ll nv ){
        prop();
        if( l == from and r == to ){
            lazy = max( lazy , nv );
            prop();
            return;
        }
        if( r <= mi ) L->rangeUpdate( l , r , nv );
        else if( mi < l ) R->rangeUpdate( l , r , nv );
        else{
            L->rangeUpdate( l , mi , nv );
            R->rangeUpdate( mi+1 , r , nv );
        }
        val = max( L->val , R->val );
    }

    ll query( ll l , ll r ){
        prop();
        if( from == l and to == r ) return val;
        if( r <= mi ) return L->query( l , r );
        if( mi < l ) return R->query( l , r );
        return max( L->query( l , mi ) , R->query( mi+1 , r ) );
    }

};
