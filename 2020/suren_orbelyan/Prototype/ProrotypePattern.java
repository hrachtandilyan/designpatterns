public class ProrotypePattern {
public static void main(String[] args) {
    EnemyCache.loadCache();

    Enemy clonedEnemy = (Enemy) EnemyCache.getEnemy("1");
    System.out.println("Enemy : " + clonedEnemy.getType());

    Enemy clonedEnemy2 = (Enemy) EnemyCache.getEnemy("2");
    System.out.println("Enemy : " + clonedEnemy2.getType());

    Enemy clonedEnemy3 = (Enemy) EnemyCache.getEnemy("3");
    System.out.println("Enemy : " + clonedEnemy3.getType());
}
}
