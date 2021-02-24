package com.company;

public class EditorCreator extends WidgetCreator {
    @Override
    public Widget createWidget()
    {
        return new EditorWidget();
    }
}
