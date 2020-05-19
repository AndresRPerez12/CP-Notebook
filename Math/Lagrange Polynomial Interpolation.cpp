LAGRANGE POLYNOMIAL INTERPOLATION

double LagrangeInterpolation( int x , vector < pid > points ){
    double ret = 0;
    for( int i = 0 ; i < points.size() ; i ++ ){
        double term = points[i].ss;
        for( int j = 0 ; j < points.size() ; j ++ ){
            if( j != i ) term *= double(x - points[j].ff)/double(points[i].ff - points[j].ff);
        }
        ret += term;
    }
    return ret;
}
