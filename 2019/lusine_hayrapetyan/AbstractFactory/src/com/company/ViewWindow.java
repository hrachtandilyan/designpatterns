package com.company;

import javax.swing.*;
import java.awt.*;

public class ViewWindow extends ViewWidget {
    private JWindow m_window;

    private ViewWindow(JWindow window)
    {
        m_window = window;
    }

    public ViewWindow()
    {
        m_window = null;
    }

    public ViewWindow createWindow()
    {
        return new ViewWindow(new JWindow(new JFrame("View Window")));
    }

}
