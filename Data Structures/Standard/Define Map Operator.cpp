Definir operador para mapa:
struct HealthCompare
{
    bool operator() (const health& lhs, const health& rhs) const
    {
        for( int i = 0 ; i < 5 ; i ++ ){
            if( lhs.hpA[i] != rhs.hpA[i] ) return lhs.hpA[i] < rhs.hpA[i];
        }
        for( int i = 0 ; i < 5 ; i ++ ){
            if( lhs.hpB[i] != rhs.hpB[i] ) return lhs.hpB[i] < rhs.hpB[i];
        }
        return false;
    }
};
