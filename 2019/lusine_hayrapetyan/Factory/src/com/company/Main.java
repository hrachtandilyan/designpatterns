package com.company;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        EditorCreator editorCreator = new EditorCreator();
        ViewCreator viewCreator = new ViewCreator();

        ArrayList<WidgetCreator> widgetArrayList = new ArrayList<WidgetCreator>();
        widgetArrayList.add(editorCreator);
        widgetArrayList.add(viewCreator);

        for (WidgetCreator widgetCreator: widgetArrayList)
        {
            Widget widget = widgetCreator.createWidget();
            System.out.print(widget.getName() + "\n");
        }
    }
}
