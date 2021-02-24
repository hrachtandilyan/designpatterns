package com.rau;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class MediatorApp {
    public static void main(String[] args) {
        TextChat chat = new TextChat();
        User admin = new Admin(chat, "Gegham");
        User u1 = new SimpleUser(chat, "A");
        User u2 = new SimpleUser(chat, "B");
        User u3 = new SimpleUser(chat, "C");
        u2.setEnable(false);
        chat.setAdmin(admin);
        chat.addUsers(u1);
        chat.addUsers(u2);
        chat.addUsers(u3);
        admin.sendMessage("Hi.");


    }
}

abstract class User {
    Chat chat;
    String name;
    boolean isEnable = true;

    public boolean isEnable() {
        return isEnable;
    }

    public void setEnable(boolean enable) {
        isEnable = enable;
    }

    public String getName() {
        return name;
    }

    public User(Chat chat, String name) {
        this.chat = chat;
        this.name = name;
    }

    void sendMessage(String message) {
        chat.sendMessage(message, this);
    }


    abstract void getMessage(String message);

    @Override
    public String toString() {
        return "User{" +
                "chat=" + chat +
                ", name='" + name + '\'' +
                ", isEnable=" + isEnable +
                '}';
    }
}

interface Chat {
    void sendMessage(String message, User user);
}

class Admin extends User {


    public Admin(Chat chat, String name) {
        super(chat, name);
    }

    @Override
    public void getMessage(String message) {
        System.out.println("Admin " + getName() + " is getting message  " + message + "'");
    }
}

class SimpleUser extends User {


    public SimpleUser(Chat chat, String name) {
        super(chat, name);
    }

    @Override
    public void getMessage(String message) {
        System.out.println("User" + getName() + " is getting message  " + message + "'");
    }
}

class TextChat implements Chat {
    User admin;
    List<User> users = new ArrayList<>();

    public void setAdmin(User admin) {
        if (admin != null && admin instanceof Admin) {
            this.admin = admin;
        } else throw new RuntimeException("No rights");
    }

    public void addUsers(User u) {
        if (admin == null) {
            throw new RuntimeException("Chat hasnt admin");
        }
        if (u instanceof SimpleUser) {
            users.add(u);
        } else {
            throw new RuntimeException("There is already an admin in the chat");
        }
    }

    @Override
    public void sendMessage(String message, User user) {
        if (user instanceof Admin) {
            for (User u : users) {
                u.getMessage(user.getName() + ": " + message);
            }
        }
        if (user instanceof SimpleUser) {
            for (User u : users) {
                if (u != user && u.isEnable()) {
                    u.getMessage(user.getName() + ": " + message);
                }
            }
            if (admin.isEnable()) {
                admin.getMessage(user.getName() + ": " + message);
            }
        }

    }
}