package com.company;

public class Client {

    enum Type
    {
        Readable, Writable
    }
    public WidgetFactory getWidget(Type type)
    {
        if (type == Type.Readable)
        {
            return new ViewWidget();
        }
        else if (type == Type.Writable)
        {
            return new EditorWidget();
        }

        System.out.print("Invalid type of widget:" + type.toString());
        return null;
    }
}
