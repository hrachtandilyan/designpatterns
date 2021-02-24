public class HardEnemy extends Enemy {
    @Override
    public void setArmor(int armor) {
        armor = 60;
    }

    @Override
    public void setAttack(int attack) {
        attack = 60;
    }
    public HardEnemy(){
        type = "Hard";
    }
}
