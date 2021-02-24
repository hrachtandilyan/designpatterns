public class MediumEnemy extends Enemy {
    @Override
    public void setArmor(int armor) {
        armor = 40;
    }

    @Override
    public void setAttack(int attack) {
        attack = 40;
    }
    public MediumEnemy(){
        type = "Medium";
    }
}


