package com.company;

public class ViewWidget implements WidgetFactory{
    @Override
    public ViewWidget createScrollBar()
    {
        return new ViewWidget();
    }
    @Override
    public ViewWidget createWindow()
    {
        return new ViewWidget();
    }
}
