package com.company;

import javax.swing.*;

public class ViewScrollBar extends ViewWidget {
    private JScrollBar m_scrollBar;

    private ViewScrollBar(JScrollBar scrollBar)
    {
        m_scrollBar = scrollBar;
    }

    public ViewScrollBar()
    {
        m_scrollBar = null;
    }

    public ViewScrollBar createScrollBar()
    {
        return new ViewScrollBar(new JScrollBar(1));
    }

}
