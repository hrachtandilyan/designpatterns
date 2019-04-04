package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Singelton a[]=new Singelton[100];
        for (int i=0;i<100;i++){
            a[i]=Singelton.getInstance();
        }
        System.out.println(Singelton.counter);
    }

}

class Singelton{
    public static int counter=0;
    private static Singelton instance;
    private Singelton(){
        counter++;
    }
    public static Singelton getInstance(){
        if(instance==null){
           synchronized (Singelton.class) {
               if(instance==null)
               instance = new Singelton();
           }
        }
        return instance;
    }

}