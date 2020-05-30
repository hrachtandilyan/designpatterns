package singleton.singleton;

import java.util.HashMap;
import java.util.Map;

public class Entity {

    private final String id;
    private final Map<String, Object> fields;

    public Entity(String id) {
        this.id = id;
        this.fields = new HashMap<>();
    }

    public void addField(String fieldName, Object fieldValue) {
        fields.put(fieldName, fieldValue);
    }

    @Override
    public String toString() {
        return "Entity " + id;
    }

}
