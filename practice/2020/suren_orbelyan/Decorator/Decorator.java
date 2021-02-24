import java.util.Scanner;

public class Decorator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int sum = Shaurma.getprice();
        System.out.println("if you want to add ketchup press 1");
        System.out.println("if you want to add french fries press 2");
        System.out.println("if you dont want to add something press 3 ");
        int k = input.nextInt();
        while (k != 3){
            if(k == 1){
                sum += Ketchup.getKetchupprice();
            }
            if(k == 2){
                sum += FrenchFries.getFriesprice();
            }

        }
        if(k == 3){
            System.out.println("shaurma costs you" + sum);
        }

    }
}
