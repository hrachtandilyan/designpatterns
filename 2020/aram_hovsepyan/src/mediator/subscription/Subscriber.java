package mediator.subscription;

import java.util.function.Consumer;

public class Subscriber<T> {

    private final Consumer<T> consumer;
    private final Subject<T> subject;

    Subscriber(Consumer<T> consumer, Subject<T> subject) {
        this.consumer = consumer;
        this.subject = subject;
    }

    public void consume(T message) {
        consumer.accept(message);
    }

    public void unsubscribe() {
        subject.unsubscribe(this);
    }

}
