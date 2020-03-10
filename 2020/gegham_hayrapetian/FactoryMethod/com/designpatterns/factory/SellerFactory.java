package com.designpatterns.factory;


import com.designpatterns.sellers.Seller;

public interface SellerFactory {
    Seller createSeller();
}
