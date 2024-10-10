package TP4;

import java.util.ArrayList;

public class Parking {
    private ArrayList<Vehicule> cars = new ArrayList<>();
    private int size;
    
    public Parking(int size)
    {
        this.size = size;
    }
    
    public void addVehicule(Vehicule v)
    {
        if(cars.size() < size)
            cars.add(v);
        else
            System.out.println("There's no place for your car:)");
    }
    
    public String affiche()
    {
        return "Parking[ size = " + size + ", Vehiculs : " + cars.toString();//doesnt work when toString is named afficher in list types, we have to write an each loop and affiche eache car and make it void
    }
}