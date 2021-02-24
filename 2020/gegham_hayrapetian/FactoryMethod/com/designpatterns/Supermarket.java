package com.designpatterns;

import com.designpatterns.factory.FoodSellerFactory;

import com.designpatterns.factory.HhChemistrySellerFactory;
import com.designpatterns.factory.SellerFactory;
import com.designpatterns.sellers.Seller;

import java.util.Scanner;

public class Supermarket {
    static SellerFactory createSellerBySpeciality(String speciality) {
        if (speciality.equalsIgnoreCase("food")) {
            return new FoodSellerFactory();
        } else return new HhChemistrySellerFactory();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("What do you want to buy?");
        String speciality = in.nextLine();//u can choose "food" or "household"
        SellerFactory sellerFactory = createSellerBySpeciality(speciality);
        Seller seller=sellerFactory.createSeller();
        seller.sellGoods();


    }
}
