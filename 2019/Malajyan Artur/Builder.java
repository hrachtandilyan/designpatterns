package com.company;

public class Main {

    public static void main(String[] args) {

     Director director=new Director();
     director.setPhonebuilder(new SumsungBuilder());
     Phone phone =director.buildphone();
       phone.print();

    }
}
class Phone{
    private String make;
    private String OC;
    private String memory;

    public void setMake(String make) {
        this.make = make;
    }

    public void setOC(String OC) {
        this.OC = OC;
    }

    public void getMemory(String memory) {
        this.memory=memory;
    }


    public void print(){
        System.out.println(make + OC + memory);
    }
}
abstract class Phonebuilder{
    Phone phone;
    void createphone(){
        phone=new Phone();
    }
    abstract public void BuildMake();
    abstract public void BuildOC();
    abstract public void BuildMemory();

    Phone getPhone(){
        return phone;
    }
}
class SumsungBuilder extends Phonebuilder{

    @Override
    public void BuildMake() {
            phone.setMake("Samsung Galaxy S8+");
    }

    @Override
    public void BuildOC() {
             phone.setOC("Android");
    }

    @Override
    public void BuildMemory() {
           phone.getMemory("64 GB");
    }
}

class IphoneBuilder extends Phonebuilder{

    @Override
    public void BuildMake() {
        phone.setMake("Apple iPhone 8");
    }

    @Override
    public void BuildOC() {
        phone.setOC("iOS");
    }

    @Override
    public void BuildMemory() {
        phone.getMemory("256 GB");
    }
}

class Director{
    Phonebuilder phonebuilder;
    void setPhonebuilder(Phonebuilder a){
        phonebuilder=a;
    }

    Phone buildphone(){
        phonebuilder.createphone();
        phonebuilder.BuildMake();
        phonebuilder.BuildOC();
        phonebuilder.BuildMemory();
        Phone phone=phonebuilder.getPhone();
        return phone;
    }
}