class gcd_rec {
  public static int gcd(int a, int b) {
    if (a == b || b == 0)
      return a;
    else if (a == 0)
      return b;
    else if (a > b)
      return gcd(a % b, b);
    else
      return gcd(a, b % a);
    return 0;
  }
  
  public static void main(String [] args) {
    int a, b;
    a = 315;
    b = 1932;
    System.out.println(gcd(a,b));
  }
}

