// https://leetcode.com/problems/number-of-days-between-two-dates

int days[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
isLeap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
int daysFrom1971(char * date){
    int y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);
    int totalDays = d;

    for (int iy = 1971; iy < y; iy++) {
        totalDays += isLeap(iy) ? 366 : 365;
    }

    if (m > 2 && isLeap(y)) {
        totalDays++;
    }

    for (int i = 0; i < m - 1; i++) {
        totalDays += days[i];
    }

    return totalDays;

}
int daysBetweenDates(char* date1, char* date2) {
 
    return abs(daysFrom1971(date1) - daysFrom1971(date2));
}