class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(abs((minutes-(hour*5))*6-(0.5*minutes)),360-abs((minutes-(hour*5))*6-(0.5*minutes)));
    }
}; 