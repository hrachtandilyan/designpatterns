package com.designpatterns.factory;

import com.designpatterns.sellers.FoodSeller;
import com.designpatterns.sellers.Seller;

public class FoodSellerFactory implements SellerFactory {
    @Override
    public Seller createSeller() {
        return new FoodSeller();
    }
}
