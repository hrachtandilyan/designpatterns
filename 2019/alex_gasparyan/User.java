public class User {
    private String name;
    private String lastname;
    private int age;
    private int gender;
    private int height;
    private int weight;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getGender() {
        return gender;
    }

    public void setGender(int gender) {
        this.gender = gender;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    private User(Builder builder) {
        this.name = builder.name;
        this.lastname = builder.lastname;
        this.age = builder.age;
        this.gender = builder.gender;
        this.height = builder.height;
        this.weight = builder.weight;
    }

    public static class Builder {
        private String name;
        private String lastname;
        private int age;
        private int gender;
        private int height;
        private int weight;

        public Builder setName(String name) {
            this.name = name;
            return this;
        }

        public Builder setLastname(String lastname) {
            this.lastname = lastname;
            return this;
        }

        public Builder setAge(int age) {
            this.age = age;
            return this;
        }

        public Builder setGender(int gender) {
            this.gender = gender;
            return this;
        }

        public Builder setHeight(int height) {
            this.height = height;
            return this;
        }

        public Builder setWeight(int weight) {
            this.weight = weight;
            return this;
        }

        public User build() {
            return new User(this);
        }
    }
}