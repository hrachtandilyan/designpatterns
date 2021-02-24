package com.company;

public class EditorWidget implements WidgetFactory {
    @Override
    public EditorWidget createScrollBar()
    {
        return new EditorWidget();
    }
    @Override
    public EditorWidget createWindow()
    {
        return new EditorWidget();
    }
}
