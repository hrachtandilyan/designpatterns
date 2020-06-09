public class EasyEnemy extends Enemy {
    @Override
    public void setArmor(int armor) {
        armor = 20;
    }

    @Override
    public void setAttack(int attack) {
        attack = 20;
    }
    public EasyEnemy(){
        type = "Easy";
    }
}
