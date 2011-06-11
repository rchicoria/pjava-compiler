class ola
{
    public static int dec(int a){
        a++;
        if(a<10)
            a=dec(a);
        return a;
    }
    
    public static void main()
    {
        int a=0;
        System.out.println(dec(a));    
    }
}
