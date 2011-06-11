class test3
{

	static int b = 1, a = 1;
	static int j = a+b;
	static String texto;
	
	public static boolean func(int a, double b, boolean c) {
	    return true;
	}
	
	public static boolean func2(int a, double b, boolean c) {
	    return false;
	}

	public static int main(String [] args) {
		int a=2+j, b=a+5;
		int t;
		double d=1.0;
		boolean v=!true;
		char g='h';
		int k = b-(-(a++));
		a+=5;
		a++;
	    for(b=0; a>0; System.out.println(a))
	        a--;
	    if(a==5){
		    int c_a=3;
		}
		else if(a > b){
		    int c=a++;
		    double var = 5.0;
		}
		else{
		    a=3;
		}
		a=(-b*a)/(3%2);
		b=a++;
		if(func(a,d,v) || func2(a,d,v))
		    System.out.println(1);
		return 0;
	}
}
