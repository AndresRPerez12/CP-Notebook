PERSISTENT SEGMENT TREE
struct Node{

    Node *L, *R;
    ll val;

    Node(){
        val = 0;
        L = this;
        R = this;
    }

    Node ( int num, Node *L , Node *R ):val(num),L(L),R(R) { }

    Node* insert ( int pos, int fr, int to ){
        if( fr == to ){
            return new Node ( val+1 , L , R );
        }
        if( pos <= (fr+to)/2 ){
            return new Node ( val+1  , L->insert( pos , fr , (fr+to)/2 ) , R );
        }
        return new Node ( val+1 , L , R->insert( pos , ((fr+to)/2)+1 , to ) );
    }

    ll query ( int tf, int tt , int fr , int to  ){
        if( tf == fr and tt == to ){
            return val;
        }
        if( tt <= (fr+to)/2 ){
            return L->query( tf , tt , fr , (fr+to)/2 );
        }
        if( tf > (fr+to)/2 ){
            return R->query( tf , tt , ((fr+to)/2)+1 , to );
        }
        return L->query( tf , (fr+to)/2 , fr , (fr+to)/2 ) + R->query( ((fr+to)/2)+1 , tt , ((fr+to)/2)+1 , to );
    }

};
