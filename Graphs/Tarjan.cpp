Tarjan:

vector <int> adj [TAM];
int disc [TAM];
int low [TAM];
int curr = 0;
stack <int> s;
bool inStack[TAM];


void tarjan ( int x ){
    if( disc[x] ) return;
    disc[x] = low[x] = ++curr;
    s.push( x );
    inStack [x] = 1;
    int v;
    for( int i = 0 ; i < adj[x].size() ; i ++ ){
        v = adj[x][i];
        if( !disc[v] ){
            tarjan(v);
            low[x] = min( low[v] , low[x] );
        }else if( inStack [v] ){
            low[x] = min( disc[v] , low[x] );
        }
    }

    bool fin = 0;
    if( disc[x] == low[x] ){
        cont ++;
        while( !fin ){
            v = s.top();
            if( v == x ){
                fin = 1;
            }
            comp [v] = cont;
            sum [cont] += cost[v];
            inStack[v] = 0;
            s.pop();
        }
    }
}
