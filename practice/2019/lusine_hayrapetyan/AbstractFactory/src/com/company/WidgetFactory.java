package com.company;

abstract public interface WidgetFactory {
    abstract public WidgetFactory createScrollBar();
    abstract public WidgetFactory createWindow();
}
