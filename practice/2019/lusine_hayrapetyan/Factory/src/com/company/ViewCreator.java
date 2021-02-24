package com.company;

public class ViewCreator extends WidgetCreator {
    @Override
    public Widget createWidget()
    {
        return new ViewWidget();
    }
}
