package com.company;

public class EditorWidget implements Widget {
    private String name;

    public EditorWidget()
    {
        this.name = "Editor";
    }

    @Override
    public String getName()
    {
        return name;
    }
}
