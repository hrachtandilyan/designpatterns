package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        WidgetFactory editor = new Client().getWidget(Client.Type.Writable);
        WidgetFactory view = new Client().getWidget(Client.Type.Readable);

    }
}
