package mediator;

import mediator.subscription.Subject;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Consumer;

/**
 * Represent mediator.
 */
public class Notifier {

    private static Notifier instance;

    private Map<String, Subject<?>> events;

    private Notifier() {
        this.events = new HashMap<>();
    }

    public static Notifier getInstance() {
        if (instance == null) {
            instance = new Notifier();
        }
        return instance;
    }

    public <T> void subscribe(String eventKey, Consumer<T> consumer) {
        Subject<T> subject = (Subject<T>) events.get(eventKey);
        if (subject == null) {
            subject = new Subject<T>();
            events.put(eventKey, subject);
        }
        subject.subscribe(consumer);
    }

    public <T> void publish(String eventKey, T message) {
        Subject<T> subject = (Subject<T>) events.get(eventKey);
        if (subject == null) {
            return;
        }
        subject.notifySubscribers(message);
    }

    public void clearEventSubscriptions(String eventKey) {
        events.remove(eventKey);
    }

}
