import java.util.*;

abstract class PhoneCompany {
    protected String brand;
    protected double revenue;
    protected int foundedYear;
    abstract String getBrand();  
    abstract double getRevenue();
    abstract int getFoundedYear(); 
}

class Samsung extends PhoneCompany {
    @Override  
    public String getBrand(){  
        return "Samsung";              
    }  
    
    @Override  
    public double getRevenue(){  
        return 221.6 * Math.pow(10, 9);              
    }  

    @Override  
    public int getFoundedYear(){  
        return 1969;              
    } 
}

class Huawei extends PhoneCompany {
     @Override  
    public String getBrand(){  
        return "Huawei";              
    }  
    
    @Override  
    public double getRevenue(){  
        return 121.72 *  Math.pow(10, 9);              
    }  
    
    @Override  
    public int getFoundedYear(){  
        return 1987;              
    } 
}

class Xiaomi extends PhoneCompany {
     @Override  
    public String getBrand(){  
        return "Xiaomi";              
    }  
    
    @Override  
    public double getRevenue(){  
        return 24.5 * Math.pow(10, 9);              
    }  
    
    @Override  
    public int getFoundedYear(){  
        return 2010;              
    } 
}

class GetPhoneCompanyFactory{  
      
   public PhoneCompany getPhoneCompany(String companyName){  
        if(companyName == null){  
            return null;  
        } 
        if(companyName.equals("Samsung")) {  
            return new Samsung();  
        }   
        else if(companyName.equals("Huawei")){  
            return new Huawei();  
        }   
        else if(companyName.equals("Xiaomi")){  
            return new Xiaomi();  
        }   
        return null;  
   }  
}

public class Main {
  private final static Scanner scan = new Scanner(System.in);

  public static void main(String []args) {
    GetPhoneCompanyFactory phoneCompany = new GetPhoneCompanyFactory();

    System.out.print("Enter Company name (Example: Xiaomi): ");
    String companyName = scan.nextLine();

    PhoneCompany co = phoneCompany.getPhoneCompany(companyName);

    System.out.println("The Revenue of " + companyName + " is $" + co.getRevenue() + ".");
    System.out.println("It is founded in " + co.getFoundedYear() + ".");
  }
}
