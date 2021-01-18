AHO - CORASICK

ll ans[N];
ll last[N];
ll tam[N];

int trie [NODES][28];
int parent [NODES]; /// fill -1
int suff[NODES]; /// fill -1
int exitL[NODES]; /// fill -1
char pch [NODES];
int cont = 0;
vector <int> fin [NODES];

int go( int v , char c );

int suffLink( int v ){
    if( v == 0 or parent[v] == 0 ) return 0;
    if( suff[v] != -1 ) return suff[v];
    int &ret = suff[v];
    return ret = go( suffLink( parent[v] ) , pch[v] );
}

int go( int v , char c ){
    int let;
    let = c - 'a';
    if( trie[v][let] == 0 ){
        if( v != 0 ) trie[v][let] = go( suffLink( v ) , c );
    }
    return trie[v][let];
}

int exitLink( int v ){
    if( v == 0 ) return 0;
    if( exitL[v] != -1 ) return exitL[v];
    int &ret = exitL[v];
    if( fin[v].size() > 0 ) return v;
    return ret = exitLink( suffLink(v) );
}

void addString( string s , int id ){
    int curr = 0;
    for( int i = 0 ; i < s.size() ; i ++ ){
        int let;
        let = s[i] - 'a';
        if( trie[curr][let] == 0 ){
            cont ++;
            trie[curr][let] = cont;
            parent[cont] = curr;
            pch[cont] = s[i];
        }
        curr = trie[curr][let];
    }
    fin[curr].push_back(id);
}

void process( string s ){
    int curr = 0;
    for( int i = 0 ; i < s.size() ; i ++ ){
        curr = go( curr , s[i] );
        int aux = exitLink( curr );
        while( aux != 0 ){
            for( int k : fin[aux] ){
                if( last[k] == -1 or last[k] + tam[k] <= i ){
                    ans[k] ++;
                    last[k] = i;
                }
            }
            aux = exitLink( parent[aux] );
        }
    }
}
