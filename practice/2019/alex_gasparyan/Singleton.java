class Test {
	public static void main(String[] args) {
		MySingleton singleton = MySingleton.getInstance();
	}
}

class MySingleton {

    private MySingleton() {
        
    }

    private static class Holder {
        private static MySingleton instance = new MySingleton();
    }

    public static MySingleton getInstance() {
        return Holder.instance;
    }
}