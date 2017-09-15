#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// formula JD =	367K - <(7(K+<(M+9)/12>))/4> + <(275M)/9> + I + 1721013.5 + UT/24 - 0.5sign(100K+M-190002.5) + 0.5
  
class JulianDate {
private:
	double jday;
	
public:
	JulianDate(int k, int m, int i, double ut, double min, double sec ) : jday(jday){
		min += (sec/60);
		ut += (min/60);
		jday = 367 * k - trunc(7*(k+int((m+9)/12))/4) + trunc(275*m/9)+ i + 1721013.5 + (ut/24) - (0.5 * (100 * k + m - 190002.5) / abs(100 * k + m - 190002.5)) + 0.5;
	}
	JulianDate(int k, int m, int i) : jday(jday){
		double ut = 0;
		jday = 367 * k - trunc(7*(k+int((m+9)/12))/4) + trunc(275*m/9)+ i + 1721013.5 + (ut/24) - (0.5 * (100 * k + m - 190002.5) / abs(100 * k + m - 190002.5)) + 0.5;
	}
	
	friend ostream& operator <<(ostream& s, JulianDate d){
		return s << setprecision(15) << d.jday;
	}
	friend double operator -(JulianDate d1 , JulianDate d2){
		return d1.jday - d2.jday;
	}
	friend JulianDate operator +(JulianDate d1, int n){
		JulianDate ans = d1;
		ans.jday = d1.jday + n;
		return ans;
	}
	
	int getYearMonthDay(int i) const {
		int L= jday+68570; //changed from 68569 ---> 68570
		int N= 4*L/146097;
		L= L-(146097*N+3)/4;
		int I= 4000*(L+1)/1461001;
		L= L-1461*I/4+31;
		int J= 80*L/2447;
		int K= L-2447*J/80;
		L= J/11;
		J= J+2-12*L;
		I= 100*(N-49)+I+L;
		if (i == 1)
			return I;
		if (i == 2)
			return J;
		if (i == 3)
			return K;
	}
	int getYear()const {
		return getYearMonthDay(1);
	}
	int getMonth() const{
		return getYearMonthDay(2);
	}
	int getDay() const{
		return getYearMonthDay(3);
	}
	
	int getHourMinSec(int i) const{
		double remainder = jday - int(jday) + 0.5;
		int secs = remainder * 86400;
		int hours = (secs/3600) % 24;
		int minutes = secs/60 % 60;
		int seconds = secs % 60;
		if (i == 1)
			return hours;
		if (i == 2)
			return minutes;
		if (i == 3)
			return seconds;
	}
	int getHour() const{
		return getHourMinSec(1);
	}
	int getMin() const{
		return getHourMinSec(2);		
	}
	int getSec() const{
		return getHourMinSec(3);		
	}
};

int main() {
        const JulianDate d1(2017, 2, 13, 20, 00, 00);
        const JulianDate d1b(2017, 2, 13, 22, 00, 00);

        cout << d1b - d1 << '\n';

        const JulianDate tomorrow = d1 + 1;
        cout << tomorrow;
        cout << tomorrow - d1 << '\n';
        const JulianDate d2(2017, 2, 19);
		const JulianDate d3 = d2 + 3;
        double days   = d3 - d1;
        int year = d3.getYear();
        int month = d3.getMonth();
        int day = d3.getDay();
        int hour = d3.getHour();
        int min = d3.getMin();
        int sec = d3.getSec();
        cout << d1 << '\n';
        cout << d2 << '\n';
        cout << d3 << '\n';
        cout << year << " " << month << " " << day << " "<<  
                hour << " " << min << " " << sec << '\n';
        JulianDate torture(2017, 2, 27);
        for (int i = 0; i < 3; i++) {
                cout << torture.getYear() << " " << torture.getMonth() << " " << torture.getDay() << '\n';
                torture = torture + 1;
        }
	return 0;
}

