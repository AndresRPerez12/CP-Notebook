TRIE :: PREFIX TREE

int trie [NODES][30], cont = 1;

void insertar( string s ){
    s.push_back( '$' );
    int curr = 1;
    for( int i = 0 ; i < s.size() ; i ++ ){
        int let;
        if( s[i] == '$' ) let = 26;
        else let = s[i] - 'a';
        if( trie[curr][let] == 0 ){
            cont ++;
            trie[curr][let] = cont;
        }
        curr = trie[curr][let];
    }
}

bool check( string s ){
    s.push_back( '$' );
    int curr = 1;
    for( int i = 0 ; i < s.size() ; i ++ ){
        int let = s[i] - 'a';
        if( trie[curr][let] == 0 ) return false;
        curr = trie[curr][let];
    }
    return true;
}
