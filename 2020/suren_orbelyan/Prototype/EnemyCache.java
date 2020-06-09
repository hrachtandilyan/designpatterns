import java.util.Hashtable;

public class EnemyCache {
    private static Hashtable<String,Enemy> enemyMap = new Hashtable<String,Enemy>();
    public static Enemy getEnemy(String enemyId) {
        Enemy cachedShape = enemyMap.get(enemyId);
        return (Enemy) cachedShape.clone();
    }
    public static void loadCache() {
        EasyEnemy easyEnemy = new EasyEnemy();
        easyEnemy.setId("1");
        enemyMap.put(easyEnemy.getId(),easyEnemy);

        MediumEnemy mediumEnemy = new MediumEnemy();
        mediumEnemy.setId("2");
        enemyMap.put(mediumEnemy.getId(),mediumEnemy);

        HardEnemy hardEnemy = new HardEnemy();
        hardEnemy.setId("3");
        enemyMap.put(hardEnemy.getId(), hardEnemy);
    }
}

