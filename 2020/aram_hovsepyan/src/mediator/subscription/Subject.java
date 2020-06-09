package mediator.subscription;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class Subject<T> {

    private List<Subscriber<T>> subscribers;

    public Subject() {
        this.subscribers = new ArrayList<>();
    }

    public void notifySubscribers(T message) {
        subscribers.forEach(subscriber -> subscriber.consume(message));
    }

    public void subscribe(Consumer<T> consumer) {
        subscribers.add(new Subscriber<>(consumer, this));
    }

    public void unsubscribe(Subscriber<T> subscriber) {
        subscribers.remove(subscriber);
    }

}
