package com.rau;

public class ChainOfResponsibility {

    public static void main(String[] args) {
        NoteModule note20000 = new NoteModule20000();
        NoteModule note10000 = new NoteModule10000();
        NoteModule note5000 = new NoteModule5000();
        NoteModule note1000 = new NoteModule1000();
        note20000.setNextModule(note10000);
        note10000.setNextModule(note5000);
        note5000.setNextModule(note1000);
        note20000.takeMoney(new Money(900_000));

    }
}

class Note {
    public static final int AMD1000 = 1000;
    public static final int AMD5000 = 5000;
    public static final int AMD10000 = 10000;
    public static final int AMD20000 = 20000;

}

class Money {
    private int amt;

    public Money(int amt) {
   setAmt(amt);

    }

    public int getAmt() {
        return amt;
    }

    public void setAmt(int amt) {
        if (amt > 0 && amt <= 800_000 && amt % Note.AMD1000 == 0) {
            this.amt = amt;
        }
        else{ throw new RuntimeException("Amount is incorrect");}
    }
}


abstract class NoteModule {
    protected NoteModule next;

    abstract void takeMoney(Money money);

    void setNextModule(NoteModule module) {
        next = module;
    }
}

class NoteModule20000 extends NoteModule {

    @Override
    void takeMoney(Money money) {
        int countNote = money.getAmt() / Note.AMD20000;
        int remind = money.getAmt() % Note.AMD20000;
        if (countNote > 0) {
            System.out.println("Give " + countNote + " notes with values of  " + Note.AMD20000);
        }
        if (remind > 0 && next != null) {
            next.takeMoney(new Money(remind));
        }
    }
}

class NoteModule10000 extends NoteModule {

    @Override
    void takeMoney(Money money) {
        int countNote = money.getAmt() / Note.AMD10000;
        int remind = money.getAmt() % Note.AMD10000;
        if (countNote > 0) {
            System.out.println("Give " + countNote + " notes with values of  " + Note.AMD10000);
        }
        if (remind > 0 && next != null) {
            next.takeMoney(new Money(remind));
        }
    }
}

class NoteModule5000 extends NoteModule {

    @Override
    void takeMoney(Money money) {
        int countNote = money.getAmt() / Note.AMD5000;
        int remind = money.getAmt() % Note.AMD5000;
        if (countNote > 0) {
            System.out.println("Give " + countNote + " notes with values of  " + Note.AMD5000);
        }
        if (remind > 0 && next != null) {
            next.takeMoney(new Money(remind));
        }
    }
}

class NoteModule1000 extends NoteModule {

    @Override
    void takeMoney(Money money) {
        int countNote = money.getAmt() / Note.AMD1000;
        int remind = money.getAmt() % Note.AMD1000;
        if (countNote > 0) {
            System.out.println("Give " + countNote + " notes with values of  " + Note.AMD1000);
        }
        if (remind > 0 && next != null) {
            next.takeMoney(new Money(remind));
        }
    }
}
