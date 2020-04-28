package com.rau;

public class Adapter {
    public static void main(String[] args) {
        VectorGraphicsInterface vectorGraphicsInterface= new VectorAdapter();
        vectorGraphicsInterface.drawLine();
        vectorGraphicsInterface.drawSquare();

    }

}

interface VectorGraphicsInterface {
    void drawLine();

    void drawSquare();

}

class RasterGraphics {
    void drawRasterLine() {
        System.out.println("Рисуем линию");
    }

    void drawRasterSquare() {
        System.out.println("Рисуем квадрат");
    }
}

class VectorAdapter extends RasterGraphics implements VectorGraphicsInterface {

    @Override
    public void drawLine() {
        drawRasterLine();
    }

    @Override
    public void drawSquare() {
        drawRasterSquare();
    }
}
