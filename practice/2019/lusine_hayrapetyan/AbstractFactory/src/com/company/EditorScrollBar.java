package com.company;

import java.awt.*;

public class EditorScrollBar extends EditorWidget {
    private Scrollbar m_scrollBar;

    private EditorScrollBar(Scrollbar scrollbar)
    {
        m_scrollBar = scrollbar;
    }

    public EditorScrollBar()
    {
        m_scrollBar = null;
    }

    public EditorScrollBar createScrollBar()
    {
        return new EditorScrollBar(new Scrollbar(1));
    }
}
