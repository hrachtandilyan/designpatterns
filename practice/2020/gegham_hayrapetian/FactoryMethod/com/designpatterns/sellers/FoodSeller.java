package com.designpatterns.sellers;

public class FoodSeller implements Seller {
    @Override
    public void sellGoods() {
        System.out.println("Hey, I am a food seller. How can I help you?");

    }
}
