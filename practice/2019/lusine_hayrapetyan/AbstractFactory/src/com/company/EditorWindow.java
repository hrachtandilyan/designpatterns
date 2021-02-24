package com.company;

import java.awt.*;

public class EditorWindow extends EditorWidget {
    private Window m_window;

    private EditorWindow(Window window)
    {
        m_window = window;
    }

    public EditorWindow()
    {
        m_window = null;
    }

    public EditorWindow createWindow()
    {
        return new EditorWindow(new Window(new Frame("Editor Window")));
    }
}
