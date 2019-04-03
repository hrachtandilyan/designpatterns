package Singleton;

class Singleton 
{
	private static Singleton instance = null;
	public String str;
	
	private Singleton() { str = "String part of Singleton class"; };
	public static Singleton Instance_Singleton() { 
		if (instance == null) {
			
            instance = new Singleton(); 
        } 
        return instance; 
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