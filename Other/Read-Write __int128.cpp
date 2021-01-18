typedef __int128 i128;

istream & operator >> (istream &is, i128 &x) {
  lli y;
  is >> y;
  x = y;
  return is;
}

ostream & operator << (ostream &os, i128 &x) {
  string s;
  while (x > 0) {
    s.pb(char('0' + x % 10));
    x /= 10;
  }
  reverse(all(s));
  return os << s;
}
