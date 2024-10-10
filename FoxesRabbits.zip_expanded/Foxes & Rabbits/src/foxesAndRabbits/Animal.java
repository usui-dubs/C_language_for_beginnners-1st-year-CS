package foxesAndRabbits;

public abstract class Animal{

	private int age; // t9dr dirhhm protected w nahi getage()....
    private boolean alive;
    private Location location;
    private Field field;
    
    public Animal(boolean randomAge, Field field, Location location)
    {
        age = 0;
        alive = true;
        this.field = field;
        setLocation(location);
    }
    
    private abstract void giveBirth();
    private abstract void incrementAge();
    private abstract int breed();
    private abstract boolean canBreed();
    
    public boolean isAlive()
    {
        return alive;
    }

    public int getAge() {
		return age;
	}
	public void setAge(int add) {
		this.age += add ;
	}
	public Location getLocation()
    {
        return location;
    }
    protected void setLocation(Location newLocation)
    {
        if(location != null) {
            field.clear(location);
        }
        location = newLocation;
        field.place(this, newLocation);
    }
    
    public Field getField() {
		return field;
	}
	public void setField(Field field) {
		this.field = field;
	}
	public void setDead()
    {
        alive = false;
        if(location != null) {
            field.clear(location);
            location = null;
            field = null;
        }
    }
}
