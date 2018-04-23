public class C1E11USPopulation {
    public static void main(String[] args) {
		System.out.println("This program calculates and prints estimated population growth, there is no user input");
		int totalSeconds = 365*60*60*24;
		int currentPopulation = 312032486;
		int birthRate = totalSeconds/7;
		int deathRate = totalSeconds/13;
		int immigrantRate = totalSeconds/45;
		System.out.println("Current Population is: " + currentPopulation);
		for(int i = 1; i <= 5; ++i){
			currentPopulation = currentPopulation + birthRate - deathRate + immigrantRate;
			System.out.println("After " + i + " year(s), the population is: " + currentPopulation);
		}
    }
}