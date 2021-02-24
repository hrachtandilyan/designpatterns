package com.designpatterns.factory;

import com.designpatterns.sellers.HouseholdChemistrySeller;
import com.designpatterns.sellers.Seller;

public class HhChemistrySellerFactory implements SellerFactory {

    @Override
    public Seller createSeller() {
        return new HouseholdChemistrySeller();
    }
}