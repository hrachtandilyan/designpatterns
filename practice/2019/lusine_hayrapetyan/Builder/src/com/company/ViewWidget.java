package com.company;

import java.awt.*;

public class ViewWidget {
    private Scrollbar scrollbar;
    private Window window;

    private ViewWidget(ViewBuilder viewBuilder)
    {
        this.scrollbar = viewBuilder.scrollbar;
        this.window = viewBuilder.window;
    }

    public ViewWidget()
    {
        this.window = null;
        this.scrollbar = null;
    }

    public static class ViewBuilder
    {
        private Scrollbar scrollbar;
        private Window window;


        public ViewBuilder()
        {
            this.scrollbar = new Scrollbar(1);
            this.window = new Window(new Frame("Window"));
        }

        public void setScrollbar(Scrollbar scrollbar)
        {
            this.scrollbar = scrollbar;
        }

        public void setWindow(Window window)
        {
            this.window = window;
        }

        public ViewWidget buildView()
        {
            return new ViewWidget(this);
        }
    }
}
