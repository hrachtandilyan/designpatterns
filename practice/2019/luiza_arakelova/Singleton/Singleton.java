package Singleton;

class Singleton 
{
	private static Singleton instance = null;
	public String str;
	
	private Singleton() { str = "String part of Singleton class"; };
	private static class BillPughSingleton {
		
		private static final Singleton instance = new Singleton();
	}
	public static Singleton Instance_Singleton() { 
		
        return BillPughSingleton.instance; 
    }
	public static void main(String []args) {
		
		Singleton ins1 = Singleton.Instance_Singleton();
		System.out.println(ins1.str);
		
		Singleton ins2 = Singleton.Instance_Singleton();
		System.out.println(ins2.str);
		
		Singleton ins3 = Singleton.Instance_Singleton();
		System.out.println(ins3.str);
	}
}
